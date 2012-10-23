#include "Arduino.h"
#include "process.h"

Process::Process(byte aPin, Tape* aCatalogue, byte aCount)
{
  player.configure(this, aPin, aCatalogue, aCount); 
  resume();
}

bool Process::execute()
{
  if(!SCMProcess::execute()) return false;
  
  player.play();
  return true;
}

