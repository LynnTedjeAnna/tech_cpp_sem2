/* COLOR GUIDE  (! Note only the headers of each element will be colors unless doesn't have data printed after !)
 * DarkRed = Error / Exceptions
 * Red = Invalid Inputs
 * Yellow = Information
 * Blue = Questions / Inputs
 * DarkYellow = Functional Logging
 * Magenta = Received Messages
 * White = Default coloring
 * Green = Starting "~! "
*/

public enum MessageVarient
{
    ERROR = ConsoleColor.DarkRed,
    INVALIDINPUT = ConsoleColor.Red,
    INFO = ConsoleColor.Yellow,
    USERINPUTS = ConsoleColor.Blue,
    LOGGING = ConsoleColor.DarkYellow,
    RECEIVEDMESSAGE = ConsoleColor.Magenta,
    DEFAULT = ConsoleColor.White,
    STARTINGINPUT = ConsoleColor.Green,
}

namespace EthernetCommunication
{
    internal class Print
    {
        private static string dir = Path.GetDirectoryName(Path.GetDirectoryName(Directory.GetCurrentDirectory()))!;
        private static string filePath = Path.Combine(dir, "messagelog.txt");
        public static string lastMsg = string.Empty;
        public static string lastReceivedMsg = string.Empty;
        public static string lastSerialMsg = string.Empty;

        public static void colored(string msg, MessageVarient varient, string needsDefault = "", bool enableLogging = false)
        {
            Console.ForegroundColor = (ConsoleColor)varient;
            if (varient == MessageVarient.USERINPUTS)
            {
                lastMsg = msg;
            }
            else if (varient == MessageVarient.RECEIVEDMESSAGE || enableLogging)
            {
                writeToLog(msg + needsDefault);
            }
            if (needsDefault != null)
            {
                Console.Write(msg);
            }
            else
            {
                Console.WriteLine(msg);
            }
            Console.ForegroundColor = ConsoleColor.White;
            if (needsDefault != null) Console.Write(needsDefault + "\n");
        }

        public static Exception exception(Exception exception)
        {
            Console.ForegroundColor = (ConsoleColor)MessageVarient.ERROR;
            return exception;
        }

        private static void startingSymbol()
        {
            Console.ForegroundColor = (ConsoleColor)MessageVarient.STARTINGINPUT;
            Console.Write("~! ");
            Console.ForegroundColor = ConsoleColor.White;
        }


        public static string getInput()
        {
            string input = string.Empty;
            Console.ForegroundColor = (ConsoleColor)MessageVarient.STARTINGINPUT;
            Console.Write("~! ");
            Console.ForegroundColor = ConsoleColor.White;
            input = Console.ReadLine()!.Replace("~! ", "");
            return input;
        }

        private static void writeToLog(string msg)
        {
            using (StreamWriter sw = new StreamWriter(filePath, true))
            {
                sw.WriteLine($"{DateTime.Now}:: {msg}");
            }
        }

        public static void readLogAndPrint()
        {
            colored("Message history: ", MessageVarient.INFO);
            using (StreamReader reader = new StreamReader(filePath, true))
            {
                string line;
                while ((line = reader.ReadLine()!) != null)
                {
                    colored(line, MessageVarient.DEFAULT);
                }
            }
        }

        public static void printLastMessages()
        {
            if (!(lastSerialMsg == string.Empty))
            {
                colored("Received message from serial: ", MessageVarient.RECEIVEDMESSAGE, lastSerialMsg);
            }

            if (!(lastReceivedMsg == string.Empty))
            {
                colored("Received message from client: ", MessageVarient.RECEIVEDMESSAGE, lastReceivedMsg);
            }

            colored(Print.lastMsg, MessageVarient.USERINPUTS);
            startingSymbol();
            Console.SetCursorPosition(4, Console.CursorTop);
        }

        public static void clearLog()
        {
            using (StreamWriter sw = new StreamWriter(filePath, false))
            {
                sw.WriteLine();
            }
        }

        public static void resetReceiver()
        {
            int lastKnownLine = Console.CursorTop + 1;
            Console.SetCursorPosition(0, lastKnownLine - 3);
            Console.WriteLine(new String(' ', 255));
            Console.WriteLine(new String(' ', 255));

            Console.SetCursorPosition(0, lastKnownLine - 3);

        }
    }
}
