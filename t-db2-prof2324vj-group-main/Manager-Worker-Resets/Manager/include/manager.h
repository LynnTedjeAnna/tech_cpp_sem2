#ifndef MANAGER_H
#define MANAGER_H
#include <SoftwareSerial.h>
bool reset();
class Manager
{
private:
    const int id = 0;
    int workers;
    String pcMessage;
    String arduinoMessage;
    void sendShake();
    bool receiveShake();
    SoftwareSerial softSerial;

public:
    Manager(int rx, int tx);
    void initShield();
    void serialBegin();
    bool handshake();
    bool listenForMessageFromPC();
    void sendMessageToPC();
    bool listenForMessageFromArduino();
    void sendMessageToArduino();
};

#endif