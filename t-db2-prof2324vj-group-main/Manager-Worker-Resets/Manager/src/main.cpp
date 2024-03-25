#include <Arduino.h>
#include "manager.h"

Manager manager(5, 6);

void setup()
{
    while (!reset())
    {
    }
    manager.initShield();
    manager.serialBegin();
}
void loop()
{
    while (!manager.handshake())
    {
    }
    while (true)
    {
        if (manager.listenForMessageFromPC())
        {
            manager.sendMessageToArduino();
        }
        if (manager.listenForMessageFromArduino())
        {
            // manager.sendMessageToPC();
        }
    }
}
