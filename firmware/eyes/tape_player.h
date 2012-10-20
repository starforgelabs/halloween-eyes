#ifndef TAPE_PLAYER_H
#define TAPE_PLAYER_H

#include "Arduino.h"
#include "tape.h"

class Process;

class TapePlayer
{
  public:
  TapePlayer();
  
  void configure(Process* aProcess, byte aPin, Tape* aCatalogue, byte aCount);
  bool play();

  private:
  // Reference to the tape catalogue
  Tape* catalogue;
  byte catalogue_size;
  
  // Current tape
  Tape* tape;
  byte pc; // program counter
  
  byte pin;
  Process* process;

  private:
  bool chooseNewTape();
  bool eot();
  void setTape(byte aTapeIndex);
};



#endif // TAPE_PLAYER_H
