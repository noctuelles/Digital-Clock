#include <Arduino.h>
#include "Pins.hpp"
#include "CompositeSevenSegmentDisplay.hpp"
#include "SevenSegmentDisplay.hpp"
#include <stdlib.h>

SevenSegmentDisplay *displayOne = NULL;
SevenSegmentDisplay *displayTwo = NULL;
CompositeSevenSegmentDisplay<2> *displays = NULL;

void setup()
{
  displayOne = new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA, DisplayPins::MINUTES_OUTPUT_ENABLE_1);
  displayTwo = new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA, DisplayPins::MINUTES_OUTPUT_ENABLE_2);
  displays = new CompositeSevenSegmentDisplay<2>();

  displays->push(displayOne);
  displays->push(displayTwo);

  displays->display("12");
}

void loop()
{
  displays->turnOff();
  delay(500);
  displays->turnOn();
  delay(500);
}