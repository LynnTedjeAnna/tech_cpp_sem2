#include "manager.h"
#include <Arduino.h>
#include <EEPROM.h>
void (*resetFunc)(void) = 0;
bool reset()
{
    byte firstReset = EEPROM.read(4);
    switch (firstReset)
    {
    case 0:
        pinMode(3, OUTPUT);
        digitalWrite(3, HIGH);
        EEPROM.write(4, 1);
        delay(100);
        reset();
    case 1:
        EEPROM.write(4, 2);
        delay(10);
        resetFunc();
        break;
    case 2:
        EEPROM.write(4, 3);
        delay(10);
        resetFunc();
        break;
    case 3:
        EEPROM.write(4, 0);
        delay(10);
        return true;
    default:
        EEPROM.write(4, 0);
        delay(10);
        reset();
        break;
    }
    return false;
}
Manager::Manager(int rx, int tx) : softSerial(rx, tx)
{
    pinMode(rx, INPUT);
    pinMode(tx, OUTPUT);
}
void Manager::initShield()
{
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}
void Manager::serialBegin()
{
    softSerial.begin(9600);
    Serial.begin(115200);
}
void Manager::sendShake()
{
    String sending = "<hnd;" + (String)id + ">\n";
    softSerial.write(sending.c_str());
}
bool Manager::receiveShake()
{
    String incoming = "";
    while (softSerial.available() > 0)
    {
        incoming = softSerial.readStringUntil('\n');
        incoming.trim();
    }
    if (incoming != "")
    {
        workers = incoming.substring(incoming.indexOf(';') + 1, incoming.indexOf('\n')).toInt();
        if (workers > 0)
        {
            Serial.flush();
            Serial.println(incoming);
            return true;
        }
    }
    return false;
}
bool Manager::handshake()
{
    digitalWrite(9, HIGH);
    while (!receiveShake())
    {
        sendShake();
        delay(80);
    }
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    return true;
}
bool Manager::listenForMessageFromPC()
{
    pcMessage = "";
    while (Serial.available() > 0)
    {
        pcMessage = Serial.readStringUntil('\n');
        pcMessage.trim();
        if (pcMessage != "")
        {
            return true;
        }
    }
    return false;
}
void Manager::sendMessageToPC()
{
}
bool Manager::listenForMessageFromArduino()
{
    arduinoMessage = "";
    while (softSerial.available() > 0)
    {
        arduinoMessage = softSerial.readStringUntil('\n');
        arduinoMessage.trim();
        if (arduinoMessage != "")
        {
            return true;
        }
    }
    return false;
}
void Manager::sendMessageToArduino()
{
    softSerial.flush();
    softSerial.println(pcMessage);
    pcMessage = "";
}