#include "process.h"
#include "scheduler.h"
#include "tape.h"

////////////////////////////////////////////////////////////////////////////////
//
// Tapes with different eye behaviours
//
// Each step consists of LED on (true/false) and min/max random time.
//
////////////////////////////////////////////////////////////////////////////////
#define SILENCE_COUNT 1
TapeStep Silence[SILENCE_COUNT] = {false, 5000, 20000};

#define SIMPLE_OPEN_COUNT 2
TapeStep SimpleOpen[SIMPLE_OPEN_COUNT] = {{true, 500, 2000},{false, 2000, 10000}};

#define BLINK_OPEN_COUNT 6
TapeStep BlinkOpen[BLINK_OPEN_COUNT] = 
  {
    {true, 100, 100},
    {false, 100, 100},
    {true, 100, 100},
    {false, 100, 100},
    {true, 500, 2000},
    {false, 2000, 10000}
  };

#define BLINK_OPEN_BLINK_COUNT 10
TapeStep BlinkOpenBlink[BLINK_OPEN_BLINK_COUNT] = 
  {
    {true, 100, 100},
    {false, 100, 100},
    {true, 100, 100},
    {false, 100, 100},
    {true, 500, 2000},
    {false, 100, 100},
    {true, 100, 100},
    {false, 100, 100},
    {true, 100, 100},
    {false, 2000, 10000}
  };

// Catalogue of eye behaviours
// The first tape is the one that runs first.
#define CATALOGUE_COUNT 4
Tape Catalogue[CATALOGUE_COUNT] = 
  {
    Tape(Silence, SILENCE_COUNT),
    Tape(SimpleOpen, SIMPLE_OPEN_COUNT),
    Tape(BlinkOpen, BLINK_OPEN_COUNT),
    Tape(BlinkOpenBlink, BLINK_OPEN_BLINK_COUNT)
  };

////////////////////////////////////////////////////////////////////////////////
//
// Cooperative multitasking system
//
////////////////////////////////////////////////////////////////////////////////
#define PROCESS_COUNT 8
Process processList[PROCESS_COUNT];
byte processPins[PROCESS_COUNT] = {5,6,7,8,9,10,11,12};

Scheduler::Scheduler scheduler(processList, PROCESS_COUNT);

void setup()
{
  randomSeed(analogRead(0));
  
  for(int i=0; i<PROCESS_COUNT; i++)
    processList[i].configure(processPins[i], Catalogue, CATALOGUE_COUNT);
}

void loop()
{
  scheduler.run();
}

