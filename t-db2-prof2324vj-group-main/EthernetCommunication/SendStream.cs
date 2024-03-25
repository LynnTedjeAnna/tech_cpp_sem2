using System.Net.Sockets;

namespace EthernetCommunication
{
    internal class SendStream : IDisposable
    {
        private TcpClient messageClient = new TcpClient();
        private NetworkStream? messageStream;
        public SendStream(string ip, int port, bool rondo = false)
        {
            try
            {
                if (rondo)
                {
                    messageClient.ConnectAsync(ip, port).Wait(500);
                } else
                {
                    messageClient.Connect(ip, port);
                }
                messageStream = messageClient.GetStream();
            }
            catch (SocketException ex)
            {
                if (!rondo)
                {
                    Print.colored(
                        Print.exception(new Exception("SocketException creating sendstream: " + ex.Message)).Message,
                        MessageVarient.ERROR
                    );
                }
                else if(rondo)
                {
                    Print.colored($"No connection on {ip}", MessageVarient.ERROR);
                }
            }
        }
        public NetworkStream getMessageStream()
        {
            if (messageStream != null) return messageStream;
            else throw Print.exception(new ArgumentNullException("Message stream is not available. Stream is null"));
        }
        public void Dispose()
        {
            if (messageStream != null)
            {
                messageStream.Close();
                messageStream.Dispose();
            }

            if (messageClient != null)
            {
                messageClient.Close();
                messageClient.Dispose();
            }
        }
    }
}