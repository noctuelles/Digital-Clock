#include <Arduino.h>
#include "Pins.hpp"
#include "CompositeSevenSegmentDisplay.hpp"
#include "SevenSegmentDisplay.hpp"
#include <stdlib.h>

CompositeSevenSegmentDisplay<4> *sevenSegmentDisplays = NULL;

void setup()
{
  sevenSegmentDisplays = new CompositeSevenSegmentDisplay<4>();

  sevenSegmentDisplays->push(new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA, DisplayPins::HOURS_OUTPUT_ENABLE_1));
  sevenSegmentDisplays->push(new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA, DisplayPins::HOURS_OUTPUT_ENABLE_2));
  sevenSegmentDisplays->push(new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA, DisplayPins::MINUTES_OUTPUT_ENABLE_1));
  sevenSegmentDisplays->push(new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA, DisplayPins::MINUTES_OUTPUT_ENABLE_2));

  sevenSegmentDisplays->display("1#2#");
}

void loop()
{
  sevenSegmentDisplays->turnOff();
  delay(500);
  sevenSegmentDisplays->turnOn();
  delay(500);
}