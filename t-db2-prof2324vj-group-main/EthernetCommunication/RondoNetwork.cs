using System;
using System.Threading;

namespace EthernetCommunication
{
    internal class RondoNetwerk
    {
        private static int nextClientEnding = IPsettings.getipEnding()+1;
        private static string nextCLientIP = $"{IPsettings.getipNetmask()}{nextClientEnding}";
        //private static Messaging messageStream = new Messaging(IPsettings.getipEnding());
        private static SendStream sendStream; //= new SendStream(nextCLientIP.Trim(), IPsettings.getPort());
        private static bool running = true;
        public static RondoNetwerk? rondo;
        Thread listenThread;

        public RondoNetwerk()
        {
            listenThread = new Thread(listenRondo);
            listenThread.Start();
        }

        private bool checkQuit()
        {
                if (Console.KeyAvailable)
                {
                    var key = Console.ReadKey(true);

                    if (key.Key == ConsoleKey.Delete)
                    {
                        running = false;
                        return true;
                    }
                }
            return false;
        }
        
        public bool sendRondo()
        {
            bool started = false;
            Print.colored("What do you want to send in rondo?", MessageVarient.USERINPUTS);
            string input = Print.getInput();
            input = Protocol.EncodeProtocol(["rondo", IPsettings.getipEnding().ToString(), input]);
            while (!checkQuit())
            {
                if (rondoLoop(input)) return true;
            }
            return false;
        }
        public void listenRondo()
        {
            Print.colored($"Started listening for rondo", MessageVarient.INFO);
                string lastMessage = ListenServer.getLastMessage();
                if (lastMessage != string.Empty)
                {
                    string[] decodedLastMessage = Protocol.DecodeProtocol(lastMessage);
                    if (decodedLastMessage[0] == "rondo")
                    {
                        if (decodedLastMessage[1] != IPsettings.getipEnding().ToString())
                        {
                            decodedLastMessage[1] = IPsettings.getipEnding().ToString();
                            rondoLoop(lastMessage);
                        }
                    }
                }
            
        }

        public void Close()
        {
            listenThread.Join();
        }
        private bool rondoLoop(string input)
        {
            Print.colored($"Trying to send to {nextCLientIP}", MessageVarient.INFO);
            try
            {
                sendStream = new SendStream(nextCLientIP.Trim(), IPsettings.getPort(), true);
                Messaging.message.sendMessage(sendStream.getMessageStream(), input, true);
            }
            catch {
                if (ListenServer.getLastMessage() != $"Message received '{input}'")
                {
                    nextClientEnding++;
                    if (nextClientEnding > 6)
                    {
                        nextClientEnding = 2;
                    }
                    if (nextClientEnding == IPsettings.getipEnding())
                    {
                        nextClientEnding++;
                    }
                    nextCLientIP = $"{IPsettings.getipNetmask()}{nextClientEnding}";
                    return false;
                }
            }
            sendStream.Dispose();
            return true;
        }
    }
}