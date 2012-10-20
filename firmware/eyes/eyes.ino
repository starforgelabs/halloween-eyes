#include "process.h"
#include "scheduler.h"

#define PROCESS_COUNT 8
Process processList[PROCESS_COUNT] = 
  {
    Process(12),
    Process(11),
    Process(10),
    Process(9),
    Process(8),
    Process(7),
    Process(6),
    Process(5),
  };

Scheduler::Scheduler scheduler(processList, PROCESS_COUNT);

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  scheduler.initialize();
}

void loop()
{
  scheduler.run();
}

