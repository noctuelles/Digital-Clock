#include <Arduino.h>
#include "SevenSegmentDisplay.hpp"

SevenSegmentDisplay *dsp1 = nullptr;

void setup()
{
  dsp1 = new SevenSegmentDisplay(2, 3, 4);
}

void loop()
{
  for (char c = '0'; c <= '9'; c++)
  {
    dsp1->display(c);
    delay(2000);
  }
}