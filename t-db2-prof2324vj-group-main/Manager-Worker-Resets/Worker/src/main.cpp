#include <Arduino.h>
#include "worker.h"

Worker worker(5, 6);

void setup()
{
  worker.serialBegin();
}

void loop()
{
  while (!worker.handshake())
  {
  }
  while (true)
  {
    if (worker.listenForMessage())
    {
      worker.forwardMessage();
      worker.handleMessage();
    }
  }
}
