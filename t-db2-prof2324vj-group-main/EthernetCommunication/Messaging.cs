using System.Net.Sockets;
using System.Text;

namespace EthernetCommunication
{
    internal class Messaging
    {
        public static Messaging? message;
        private int id = 0;
        private string _sendMessage = string.Empty;
        private string receiver = string.Empty;
        private string formattedMessage = string.Empty;
        private string receiveID = string.Empty;
        private string arduinoSendID = string.Empty;
        private RondoNetwerk rondo = null;
        public string setSendMessage { set { formattedMessage = value; } }

        public string getReceiveID() 
        { 
            if (receiveID != string.Empty) return receiveID;
            else throw Print.exception(new ArgumentNullException("Receiver is null")); 
        }
        public Messaging(int id)
        {
            this.id = id;
        }
        public bool receiverInput()
        {
            Thread.Sleep(100);
            Print.colored("\nEnter command/ reciever (2-255) with arduino id. Example: 6-2 (or type 'help' to see a list of commands)", MessageVarient.USERINPUTS);
            receiver = Print.getInput();
            switch (receiver.ToLower())
            {
                case "help":
                    Print.colored("\nCommands:", MessageVarient.USERINPUTS);
                    Print.colored("" +
                        "[quit] to exit the application\n" +
                        "[list] to see all available IP's\n" +
                        "[scan] to scan available IP's again\n" +
                        "[log] get list of all saved send messages\n" +
                        "[portscan] scan for valid COM port\n" +
                        "[log clear] clears the current log\n" +
                        "[serial disconnect] disconnects the serial port\n" +
                        "[rondo] do rondo.\n"

                        , MessageVarient.INFO);
                    return false;
                case "quit":
                    Environment.Exit(0);
                    break;
                case "list":
                    IPsettings.printOpenIps();
                    return false;
                case "scan":
                    IPsettings.scanipPorts();
                    IPsettings.printOpenIps();
                    return false;
                case "ssnd":
                    Print.colored("Enter your message: ", MessageVarient.USERINPUTS);
                    _sendMessage = Print.getInput();
                    Serial.Send(_sendMessage);
                    return false;
                case "portscan":
                    Program.serial = new Serial();
                    break;
                case "log":
                    Print.readLogAndPrint();
                    return false;
                case "log clear":
                    Print.clearLog();
                    return false;
                case "serial disconnect":
                    Program.serial!.Dispose();
                    return false;
                case "rondo":
                    RondoNetwerk.rondo.sendRondo();
                    return false;
                default:

                    List<int> openIPs = IPsettings.getOpenIPEnds();
                    if (receiver.Contains('-'))
                    {
                        try
                        {
                            string[] splitIntParse = receiver.Split('-');
                            if (int.TryParse(splitIntParse[0], out int recId) && int.TryParse(splitIntParse[1], out int recArdId))
                            {
                                if (openIPs.Contains(recId))
                                {
                                    receiveID = splitIntParse[0];
                                    arduinoSendID = splitIntParse[1];
                                    return true;
                                }
                                else
                                {
                                    Print.colored("This ip is not open", MessageVarient.INVALIDINPUT);
                                    return false;
                                }
                            }
                            else
                            {
                                Print.colored($"Invalid input '{receiver}'", MessageVarient.INVALIDINPUT);
                                return false;
                            }
                        }
                        catch (Exception e)
                        {
                            Print.colored(e.Message, MessageVarient.ERROR);
                            return false;
                        }
                    }
                    else
                    {
                        if (int.TryParse(receiver, out int IP))
                        {
                            if (openIPs.Contains(IP))
                            {
                                receiveID = receiver;
                                return true;
                            }
                            else
                            {
                                Print.colored("This ip is not open", MessageVarient.INVALIDINPUT);
                                return false;
                            }
                        }
                        else
                        {
                            Print.colored($"Invalid input '{receiver}'", MessageVarient.INVALIDINPUT);
                        }
                    }
                    return false;
            }
            return false;
        }
        public bool messageInput()
        {
            if(arduinoSendID != string.Empty)
            {
                Print.colored($"Enter the pin: ", MessageVarient.USERINPUTS);
                _sendMessage = Print.getInput();
                if (int.TryParse(_sendMessage, out int pin))
                {
                    Print.colored($"Enter the action you want to take (high/100p/255): ", MessageVarient.USERINPUTS);
                    _sendMessage += ";" + Print.getInput();
                    _sendMessage.Trim();
                    formattedMessage = Protocol.EncodeProtocol(["cmd", id.ToString(), $"{receiveID}-{arduinoSendID}", _sendMessage]);
                    arduinoSendID = string.Empty;
                    return true;
                }
            }
            else
            {
                Print.colored($"Enter your message (user: {receiveID}): ", MessageVarient.USERINPUTS);
                _sendMessage = Print.getInput();
            }
            if (_sendMessage == "quit")
            {
                Environment.Exit(0);
            }
            else if (_sendMessage != "")
            {
                _sendMessage.Trim();
                formattedMessage = Protocol.EncodeProtocol(["msg", id.ToString(), receiveID, _sendMessage]);
                return true;
            }
            return false;
        }
        public void sendMessage(NetworkStream messageStream) // send message to 
        {
            Print.colored("Sending message: '" + formattedMessage + "' to " + receiver + "\n", MessageVarient.LOGGING);
            if (formattedMessage != string.Empty)
            {
                byte[] data = Encoding.ASCII.GetBytes(formattedMessage);
                if (data.Length > 0)
                {
                    messageStream.Write(data, 0, data.Length);
                }
            }
        }
        public void sendMessage(NetworkStream messageStream, string returnMSG, bool rondo = false) // callback message sending
        {
            string msg = $"Message received '{returnMSG}'";
            if (rondo)
            {
                msg = returnMSG;
                byte[] msgBytes = Encoding.ASCII.GetBytes(msg);
                messageStream.WriteAsync(msgBytes, 0, msgBytes.Length);
            } else
            {

                byte[] msgBytes = Encoding.ASCII.GetBytes(msg);
                messageStream.Write(msgBytes, 0, msgBytes.Length);
            }
        }
    }
}