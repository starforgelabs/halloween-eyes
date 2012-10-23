/*
* Copyright 2012 James Knowles. 
*
* This work is licensed under a Creative Commons
* Attribution-ShareAlike 3.0 Unported License.
*
* https://creativecommons.org/licenses/by-sa/3.0/
*
* This code is strictly "as is". Use at your own risk.
*
*/

#include "tape_player.h"

bool TapePlayer::chooseNewTape()
{
  if(catalogue == NULL) return false;
  
  if(catalogue_size == 1)
    setTape(0);
  else
    setTape(random(catalogue_size));
    
  return true;
}

void TapePlayer::configure(SCMProcess* aProcess, byte aPin, Tape* aCatalogue, byte aCount)
{
  process = aProcess;
  pin = aPin;
  catalogue = aCatalogue;
  catalogue_size = aCount;
  
  pinMode(pin, OUTPUT);
  
  tape = NULL;
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

