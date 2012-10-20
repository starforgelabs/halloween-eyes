#include "Arduino.h"
#include "process.h"

Process::Process()
{ 
  state = psSuspended;
}

void Process::configure(byte aPin, Tape* aCatalogue, byte aCount)
{
  player.configure(this, aPin, aCatalogue, aCount); 
  state = psRunning;
}

void Process::execute()
{
  if(!tryWaking()) return;
  
  player.play();
}

void Process::hibernate(unsigned long aMilliseconds)
{
  wakeTime = millis() + aMilliseconds;
  state = psSleeping;
}

  
bool Process::tryWaking()
{
  if(state == psSuspended) return false;
  
  if(state == psSleeping && millis() >= wakeTime)
    state = psRunning;
        
  return state == psRunning;
}

