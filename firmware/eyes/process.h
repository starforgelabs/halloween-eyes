#ifndef PROCESS_H
#define PROCESS_H

#include "Arduino.h"

class Process
{
  public:
  enum State {psSleeping, psRunning};
  typedef unsigned long Time;

  public:
  Process(int aPin) 
  { 
    state = psRunning;
    pin = aPin; 
  }
  
  void execute();
  
  // Run once in the setup() section. 
  // Use this to initialize pin modes, etc.
  void initialize();
  
  private:
  State state;
  int pin;
  Time wakeTime;
  bool ledState;
  
  private:
  bool tryWaking();
  void hibernate(unsigned long aMilliseconds);
};

#endif//PROCESS_H
