#ifndef PROCESS_H
#define PROCESS_H

#include <SCMProcess.h>

#include "Arduino.h"
#include "tape_player.h"

class Process : public SCMProcess
{
  public:
  Process(byte aPin, Tape* aCatalogue, byte aCount);
  virtual bool execute();
  
  private:
  TapePlayer player;
};

#endif//PROCESS_H
