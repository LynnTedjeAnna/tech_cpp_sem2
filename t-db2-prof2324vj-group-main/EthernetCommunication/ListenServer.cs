using System.Net;
using System.Net.Sockets;
using System.Text;

namespace EthernetCommunication
{
    internal class ListenServer
    {
        private TcpClient? listeningClient;
        private NetworkStream? listeningStream;
        private TcpListener? server;
        private Thread? listenServerThread;
        private static List<string> messages = [];
        private string lastSender = string.Empty;

        public static string[] Messages = [];
        //public static string getLastMessage { get { return messages.Last(); } }

        public ListenServer(string ip, int port)
        {
            IPAddress ipAddress = IPAddress.Parse(ip);
            server = new TcpListener(ipAddress, port);
            server.Start();

            listenServerThread = new Thread(ListenForClients);
            listenServerThread.Start();

            Print.colored("Listening for clients on IP: " + ip + ", Port: " + port, MessageVarient.LOGGING);
        }
        private void ListenForClients()
        {
            try
            {
                while (server != null)
                {
                    listeningClient = server.AcceptTcpClient();

                    Thread clientThread = new Thread(HandleClient);
                    clientThread.Start();
                }
            }
            catch (SocketException ex)
            {
                Print.colored("SocketException while accepting client: " + ex.Message, MessageVarient.ERROR);
            }
        }
        public void sendCallBack(string returnMSG)
        {
            try
            {
                SendStream sendStream = new SendStream($"{IPsettings.getipNetmask()}{lastSender}".Trim(), IPsettings.getPort());
                Messaging messageCallBack = new Messaging(IPsettings.getipEnding());
                messageCallBack.sendMessage(sendStream.getMessageStream(), returnMSG);
                sendStream.Dispose();
            }
            catch (SocketException ex)
            {
                Print.colored("SocketException while sending call: " + ex.Message, MessageVarient.ERROR);
            }
        }
        private void HandleClient()
        {
            try
            {
                if (listeningClient != null)
                {
                    listeningStream = listeningClient.GetStream();
                    byte[] buffer = new byte[1024];
                    int bytesRead;
                    string receivedMessage = string.Empty;
                    if ((bytesRead = listeningStream.Read(buffer, 0, buffer.Length)) > 0)
                    {
                        //Print.resetReceiver();
                        receivedMessage = Encoding.ASCII.GetString(buffer, 0, bytesRead);
                        if (!receivedMessage.StartsWith('<'))
                        {
                            Print.colored("Received message from client: ", MessageVarient.RECEIVEDMESSAGE, receivedMessage);
                            return;
                        }
                        lastSender = receivedMessage.Split(';')[1];
                        string[] decodedMessage = Protocol.DecodeProtocol(receivedMessage);
                        string[] splitIntParse = decodedMessage[2].Split('-');
                        if (splitIntParse.Count() > 1)
                        {
                            if (decodedMessage.Length > 0 && int.TryParse(splitIntParse[1], out int recArdId))
                            {
                                if (recArdId <= Serial.getSlaves && recArdId > 0)
                                {
                                    Serial.Send(receivedMessage);
                                }
                                else
                                {
                                    Print.colored("Worker invalid could not send to workers", MessageVarient.ERROR);
                                    sendCallBack("Worker invalid could not send to workers");
                                }
                            }
                        }
                        messages.Add(receivedMessage);
                    }
                    listeningClient.Close();
                    listeningClient.Dispose();
                    if (lastSender != string.Empty && char.IsDigit(lastSender[0]))
                    {
                        sendCallBack(receivedMessage);
                        lastSender = string.Empty;
                    }
                }
            }
            catch (Exception e)
            {
                Print.colored("Exception handling client: " + e.Message, MessageVarient.ERROR);
            }
        }

        public static string getLastMessage()
        {
            if (messages != null && messages.Count > 0)
            {
                return messages.Last();
            }
            else
            {
                //Print.colored(Print.exception(new ArgumentNullException("Last Message is null")).ToString(), MessageVarient.ERROR);
                return string.Empty;
            }
        }
        public List<string> getAllMessages()
        {
            if (messages.Any()) return messages; // returns complete list
            else throw Print.exception(new ArgumentNullException("Message List is null"));
        }
    }
}