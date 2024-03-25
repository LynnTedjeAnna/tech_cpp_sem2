namespace EthernetCommunication
{
    internal class Protocol
    {

        public static string[] DecodeProtocol(string message)
        {
            string[] splitted = [];
            if (message[0] == '<' && message[message.Length - 1] == '>')
            {
                string subMessage = message.Substring(1, message.IndexOf('>') - 1);
                splitted = subMessage.Split(';');
            }
            return splitted;
        }

        public static string EncodeProtocol(string[] messages)
        {
            string encodedString = "<";
            foreach (string message in messages)
            {
                encodedString += message + (messages.Last() == message == false ? ";" : "");
            }
            encodedString += ">";
            return encodedString;
        }
    }
}
