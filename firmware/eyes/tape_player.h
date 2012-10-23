#ifndef TAPE_PLAYER_H
#define TAPE_PLAYER_H

#include "Arduino.h"
#include "tape.h"
#include <SCMProcess.h>

class TapePlayer
{
  public:
  TapePlayer() : tape(NULL), catalogue(NULL) {}
  
  void configure(SCMProcess* aProcess, byte aPin, Tape* aCatalogue, byte aCount);
  
  bool play();
  
  byte getPin() { return pin; }

  private:
  // Reference to the tape catalogue
  Tape* catalogue;
  byte catalogue_size;
  
  // Current tape
  Tape* tape;
  byte pc; // program counter
  
  byte pin;
  SCMProcess* process;

  private:
  bool chooseNewTape();
  bool eot();
  void setTape(byte aTapeIndex);
};



#endif // TAPE_PLAYER_H
