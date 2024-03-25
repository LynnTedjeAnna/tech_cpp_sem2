using System.ComponentModel;
using System.IO.Ports;

namespace EthernetCommunication
{
    internal class Serial : IDisposable
    {
        private static SerialPort? serialPort;
        private readonly static int baudrate = 115200;
        private static int slaves = 0;
        public static int getSlaves {  get { return slaves; } }
        private string port = string.Empty;
        private Thread readThread;
        public Serial()
        {
            readThread = new Thread(Read);
            if (AutomaticCOM())
            {
                readThread.Start();
            }
            else
            {
                Print.colored("No available serial port found", MessageVarient.ERROR);
            }
        }

        public void Dispose()
        {
            if (port != string.Empty)
            {
                port = string.Empty;
                serialPort.Close();
                serialPort.Dispose();
            }
            else
            {
                Print.colored("No serial has been connected", MessageVarient.ERROR);
            }
        }

        public static bool Send(string message)
        {
            if (serialPort.IsOpen == false) return false;
            serialPort.WriteLine(message);
            return true;
        }

        public void Read()
        {
            while (serialPort.IsOpen)
            {
                try
                {
                    string message = serialPort.ReadLine().Trim();
                    if (message != "")
                    {
                        Print.resetReceiver();
                    }
                }
                catch (Exception ex)
                {
                    Print.colored(Print.exception(new Exception("Serial reading exception: " + ex.Message)).Message, MessageVarient.ERROR);
                }
            }
        }
        private bool AutomaticCOM()
        {
            string[] ports = [];
            port = string.Empty;
            try
            {
                ports = SerialPort.GetPortNames();
            }
            catch (Win32Exception ex)
            {
                Console.WriteLine($"No ports found. {ex}");
            }
            foreach (string port in ports)
            {
                try
                {
                    serialPort = new SerialPort(port, baudrate);
                    serialPort.Open();
                    serialPort.DtrEnable = true;
                    serialPort.ReadTimeout = 7000;
                    try
                    {
                        string response = serialPort.ReadLine().Trim();
                        if (response != "")
                        {
                            slaves = int.Parse(response.Substring(response.IndexOf(';') + 1, response.IndexOf('>') - response.IndexOf(';') - 1));
                            Print.colored($"Arduino found on port {port} with {slaves} workers", MessageVarient.INFO, enableLogging: true);
                            serialPort.ReadTimeout = -1;
                            this.port = port;
                            return true;
                        }
                    }
                    catch (TimeoutException)
                    {
                        Print.colored($"No response from Arduino on port {port}", MessageVarient.ERROR);
                    }
                    serialPort.DtrEnable = false;
                    serialPort.Close();

                }
                catch (Exception)
                {

                }
            }
            return false;
        }
    }
}
