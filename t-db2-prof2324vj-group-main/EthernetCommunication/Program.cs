namespace EthernetCommunication
{
    internal class Program
    {
        public static Serial? serial;
        public static void Main()
        {
            // Reset Console Color
            Console.ForegroundColor = (ConsoleColor)MessageVarient.DEFAULT;

            IPsettings ipSettings = new IPsettings();
            ListenServer listenServer = new ListenServer(IPsettings.getPersonalIP(), IPsettings.getPort());
            Messaging.message = new Messaging(IPsettings.getipEnding());
            IPsettings.scanipPorts();
            IPsettings.printOpenIps();
            RondoNetwerk.rondo = new RondoNetwerk();

            serial = new Serial();

            while (true)
            {
                while (!Messaging.message.receiverInput()) ;
                ipSettings.setTargetIP(Messaging.message.getReceiveID());
                while (!Messaging.message.messageInput()) ;
                SendStream messageStream = new SendStream(IPsettings.getipAddressSending(), IPsettings.getPort());
                Messaging.message.sendMessage(messageStream.getMessageStream());
                messageStream.Dispose();
            }
        }
    }
}
