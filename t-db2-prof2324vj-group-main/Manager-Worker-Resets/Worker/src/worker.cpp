#include "worker.h"
#include <Arduino.h>

Worker::Worker(int rx, int tx) : softSerial(rx, tx)
{
    pinMode(rx, INPUT);
    pinMode(tx, OUTPUT);
}
void Worker::serialBegin()
{
    pinMode(LED_BUILTIN, OUTPUT);
    softSerial.begin(9600);
    Serial.begin(115200);
}
void Worker::sendShake()
{
    String sending = "<hnd;" + (String)id + ">\n";
    softSerial.write(sending.c_str());
}
bool Worker::receiveShake()
{
    String incoming = "";
    while (softSerial.available() > 0)
    {
        incoming = softSerial.readStringUntil('\n');
        incoming.trim();
    }
    if (incoming != "")
    {
        Serial.println(incoming);
        id = incoming.substring(incoming.indexOf(';') + 1, incoming.indexOf('\n')).toInt();
        if (id >= 0)
        {
            id++;
            return true;
        }
    }
    return false;
}
bool Worker::handshake()
{
    while (!receiveShake())
    {
    }
    sendShake();
    digitalWrite(LED_BUILTIN, HIGH);
    return true;
}
bool Worker::listenForMessage()
{
    arduinoMessage = "";
    while (softSerial.available() > 0)
    {
        arduinoMessage = softSerial.readStringUntil('\n');
        arduinoMessage.trim();
        if (arduinoMessage != "")
        {
            softSerial.flush();
            return true;
        }
    }
    return false;
}
void Worker::forwardMessage()
{
    softSerial.write(arduinoMessage.c_str());
}
void Worker::handleMessage()
{
    char arduinoChar[50];
    char protocol[5];
    char action[5];
    int targetID = 0;
    int pin = 0;
    float actionPercentage = 0;
    arduinoMessage.toCharArray(arduinoChar, arduinoMessage.length() + 1);
    sscanf(arduinoChar, "<%[^;];%*[^;];%*[^-]-%d;%d;%[^>]>", protocol, &targetID, &pin, action);
    if (!strcmp(protocol, "cmd"))
    {
        if (targetID == id)
        {
            if (!strcmp(action, "high"))
            {
                pinMode(pin, OUTPUT);
                digitalWrite(pin, HIGH);
            }
            else if (!strcmp(action, "low"))
            {
                pinMode(pin, OUTPUT);
                digitalWrite(pin, LOW);
            }
            else if (action[strlen(action) - 1] == 'p')
            {
                bool valid = true;
                for (size_t i = 0; i < strlen(action) - 1; ++i)
                {
                    if (!isdigit(action[i]))
                    {
                        valid = false;
                    }
                }
                if (valid)
                {
                    char percentage[5];
                    strncpy(percentage, action, strlen(action) - 1);
                    actionPercentage = atoi(percentage) * 2.55;
                    pinMode(pin, OUTPUT);
                    analogWrite(pin, actionPercentage);
                }
                else if (!valid)
                {
                    digitalWrite(LED_BUILTIN, LOW);
                    delay(200);
                    digitalWrite(LED_BUILTIN, HIGH);
                }
            }
            else if (action[strlen(action) - 1] != 'p')
            {
                bool valid = true;
                for (size_t i = 0; i < strlen(action); ++i)
                {
                    if (!isdigit(action[i]))
                    {
                        valid = false;
                    }
                }
                if (valid)
                {
                    pinMode(pin, OUTPUT);
                    analogWrite(pin, atoi(action));
                }
                else if (!valid)
                {
                    digitalWrite(LED_BUILTIN, LOW);
                    delay(200);
                    digitalWrite(LED_BUILTIN, HIGH);
                }
            }
        }
    }
    Serial.println((String)protocol + " " + (String)targetID + " " + (String)pin + " " + (String)action + " " + (String)actionPercentage);
    arduinoMessage = "";
    arduinoChar[0] = '\0';
}