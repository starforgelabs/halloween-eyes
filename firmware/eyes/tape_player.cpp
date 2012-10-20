#include "tape_player.h"
#include "process.h"

TapePlayer::TapePlayer()
{
  catalogue = NULL;
  tape = NULL;
}

bool TapePlayer::chooseNewTape()
{
  if(catalogue == NULL) return false;
  
  if(catalogue_size == 1)
    setTape(0);
  else
    setTape(random(catalogue_size));
    
  return true;
}

void TapePlayer::configure(Process* aProcess, byte aPin, Tape* aCatalogue, byte aCount)
{
  process = aProcess;
  pin = aPin;
  catalogue = aCatalogue;
  catalogue_size = aCount;
  
  pinMode(pin, OUTPUT);
  
  // Initial program is zero
  setTape(0);
}

bool TapePlayer::eot()
{
  return tape == NULL || pc < 0 || pc >= tape->count;
}

bool TapePlayer::play()
{
  if(eot() && !chooseNewTape()) return false;
  
  TapeStep* current = &(tape->strip[pc++]);
  digitalWrite(pin, current->lightOn ? HIGH : LOW);
  
  process->hibernate(random(current->minDelay,current->maxDelay));
  return true;
}

void TapePlayer::setTape(byte aTapeIndex)
{
  tape = &catalogue[aTapeIndex];
  pc = 0;
}

