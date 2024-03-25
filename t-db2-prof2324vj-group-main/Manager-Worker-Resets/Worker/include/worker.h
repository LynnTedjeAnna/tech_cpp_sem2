#ifndef WORKER_H
#define WORKER_H
#include <SoftwareSerial.h>
class Worker
{
private:
    int id = 0;
    String arduinoMessage;
    void sendShake();
    bool receiveShake();
    SoftwareSerial softSerial;

public:
    Worker(int rx, int tx);
    void serialBegin();
    bool handshake();
    bool listenForMessage();
    void forwardMessage();
    void handleMessage();
};
#endif