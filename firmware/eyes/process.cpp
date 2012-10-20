#include "Arduino.h"
#include "process.h"

void Process::execute()
{
  if(!tryWaking()) return;
  
  ledState = !ledState;
  digitalWrite(pin, ledState ? HIGH : LOW);
  
  hibernate(random(500,2000));
}

void Process::hibernate(unsigned long aMilliseconds)
{
  wakeTime = millis() + aMilliseconds;
  state = psSleeping;
}

  
void Process::initialize()
{
  pinMode(pin, OUTPUT);
  ledState = false;
}

bool Process::tryWaking()
{
  if(state == psSleeping && millis() >= wakeTime)
    state = psRunning;
        
  return state == psRunning;
}

