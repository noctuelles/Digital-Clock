#include "SevenSegmentDisplay.hpp"
#include <Arduino.h>
#include <string.h>

const uint8_t SevenSegmentDisplay::bitsMapping[SevenSegmentDisplay::nbrAvailableNumbers] = {
    /* Numbers */

    0b11111010, // 0
    0b00001010, // 1
    0b11011100, // 2
    0b10011110, // 3
    0b00101110, // 4
    0b10110110, // 5
    0b11110110, // 6
    0b00011010, // 7
    0b11111110, // 8,
    0b10111110  // 9

    /* Letters not yet implemented */
};

SevenSegmentDisplay::SevenSegmentDisplay(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin) : latchPin(latchPin),
                                                                                                clockPin(clockPin),
                                                                                                dataPin(dataPin)
{
    pinMode(this->latchPin, OUTPUT);
    pinMode(this->clockPin, OUTPUT);
    pinMode(this->dataPin, OUTPUT);
}

SevenSegmentDisplay::~SevenSegmentDisplay() {}

void SevenSegmentDisplay::display(char toDisplay)
{
    uint8_t displayBitsMapping = 0;

    if (!(toDisplay >= '0' && toDisplay <= '9'))
    {
        return;
    }

    displayBitsMapping = this->bitsMapping[toDisplay - '0'];

    digitalWrite(this->latchPin, LOW);
    for (uint8_t i = 0; i < 8; i++)
    {
        digitalWrite(this->clockPin, LOW);
        digitalWrite(this->dataPin, displayBitsMapping & (1U << i));
        digitalWrite(this->clockPin, HIGH);
    }
    digitalWrite(this->latchPin, HIGH);
}