#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <stdlib.h>

#include "Pins.hpp"
#include "display/CompositeSevenSegmentDisplay.hpp"
#include "display/SevenSegmentDisplay.hpp"

CompositeSevenSegmentDisplay<2> *hoursDisplay = NULL;

void
setup() {
    hoursDisplay = new CompositeSevenSegmentDisplay<2>();

    hoursDisplay->push(new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA,
                                               DisplayPins::HOURS_OUTPUT_ENABLE_1));
    hoursDisplay->push(new SevenSegmentDisplay(DisplayPins::LATCH, DisplayPins::CLOCK, DisplayPins::DATA,
                                               DisplayPins::HOURS_OUTPUT_ENABLE_2));
}

void
custom_itoa(uint8_t i, char *buffer) {
    buffer[0] = i / 10 + '0';
    buffer[1] = i % 10 + '0';
    buffer[2] = '\0';
}

uint8_t lightIntensity = 0;

void
loop() {
    char hoursDisplayBuffer[3];
    lightIntensity = 100 / 24;

    for (uint8_t i = 0; i < 25; i++) {
        hoursDisplay->setLightIntensity(lightIntensity);
        lightIntensity = (lightIntensity + 100 / 24);
        custom_itoa(i, hoursDisplayBuffer);

        digitalWrite(DisplayPins::LATCH, LOW);

        hoursDisplay->display(hoursDisplayBuffer);

        digitalWrite(DisplayPins::LATCH, HIGH);

        delay(150);
    }
}