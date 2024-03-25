using System.Net;
using System.Net.Sockets;

namespace EthernetCommunication
{
    internal class IPsettings
    {
        private static int port = 8888;
        private static string ipAddressPersonal = string.Empty;
        private static string ipAddressSending = string.Empty;
        private static int ipEnding = 0;
        private static string ipMask = string.Empty;
        private static List<string> openIPs = new List<string>();
        private static List<int> openIPEndings = new List<int>();
        private string ipInputStr = string.Empty;
        private int ipInput;
        public static int getPort() 
        {
            return port; 
        }
        public static string getPersonalIP() 
        { 
            return ipAddressPersonal; 
        }
        public static int getipEnding() 
        { 
            return ipEnding; 
        }
        public static string getipNetmask() 
        { 
            return ipMask; 
        }
        public static string getipAddressSending() 
        { 
            if (ipAddressSending != string.Empty) return ipAddressSending;
            else throw new Exception("Sending IPaddress is Null"); 
        }
        public IPsettings()
        {
            List<string> addresses = new List<string>();
            Print.colored("Which ipaddress should be used?", MessageVarient.USERINPUTS);
            string hostName = Dns.GetHostName();
            for (int i = 0, j = 0; i < Dns.GetHostEntry(hostName).AddressList.Length; i++)
            {
                if (Dns.GetHostEntry(hostName).AddressList[i].AddressFamily == AddressFamily.InterNetwork)
                {
                    Print.colored(j + ") " + Dns.GetHostEntry(hostName).AddressList[i].ToString(), MessageVarient.DEFAULT);
                    addresses.Add(Dns.GetHostEntry(hostName).AddressList[i].ToString());
                    j++;
                }
            }
            do
            {
                if (!numberInput(addresses.Count())) 
                { 
                    Print.colored($"Invalid input '{ipInputStr}'", MessageVarient.INVALIDINPUT);
                    ipInput = -1;
                }
            } while (!(ipInput >= 0 && ipInput < addresses.Count()));

            ipAddressPersonal = addresses[ipInput];
            ipAddressPersonal.Trim();
            string[] components = ipAddressPersonal.Split('.');
            ipEnding = Int32.Parse(components[components.Length - 1]);
            ipMask = ipAddressPersonal.Substring(0, ipAddressPersonal.LastIndexOf('.') + 1);
        }

        private bool numberInput(int max)
        {
            ipInputStr = Print.getInput();
            try
            {
                if (ipInputStr == "quit")
                {
                    Environment.Exit(0);
                }
                ipInput = int.Parse(ipInputStr);
                if (ipInput >= 0 && ipInput < max)
                {
                    return true;
                }
                else return false;
            }
            catch
            {
                return false;
            }
        }

        public void setTargetIP(string targetIP)
        {
            string[] components = ipAddressPersonal.Split('.');
            components[components.Length - 1] = targetIP;
            ipAddressSending = String.Join(".", components);
            ipAddressSending.Trim();
        }
        public static void scanipPorts()
        {
            Print.colored("Started scanning network for open IP's", MessageVarient.LOGGING);
            openIPs.Clear();
            for (int i = 2; i <= 255; i++)
            {
                try
                {
                    string ip = $"{ipMask}{i}";
                    TcpClient client = new TcpClient();
                    if (client.ConnectAsync(ip, 8888).Wait(5))
                    {
                        ip.Trim();
                        string[] components = ip.Split('.');
                        int openIPEnding = Int32.Parse(components[components.Length - 1]);
                        openIPs.Add(ip);
                        openIPEndings.Add(openIPEnding);
                        client.Close();
                    }
                    client.Dispose();
                }
                catch
                {
                    continue;
                }
            }
        }
        public static void printOpenIps()
        {
            Print.colored("\nList of available IP's:", MessageVarient.INFO);

            for (int i = 0; i < openIPs.Count; i++)
            {
                Print.colored(openIPs[i], MessageVarient.DEFAULT);
            }
        }
        public static List<int> getOpenIPEnds()
        {
            if (openIPEndings.Any()) return openIPEndings; // returns complete list
            else throw Print.exception(new ArgumentNullException("There are no open IP endings in the list"));

        }
    }
}
