/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SevenSegmentDisplay.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:48:06 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 13:28:22 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display/SevenSegmentDisplay.hpp"

#include <Arduino.h>
#include <limits.h>
#include <string.h>

const uint8_t SevenSegmentDisplay::numberBitsMapping[SevenSegmentDisplay::nbrAvailableNumbers] = {
    0b11111010,  // 0
    0b00001010,  // 1
    0b11011100,  // 2
    0b10011110,  // 3
    0b00101110,  // 4
    0b10110110,  // 5
    0b11110110,  // 6
    0b00011010,  // 7
    0b11111110,  // 8,
    0b10111110   // 9
};

SevenSegmentDisplay::SevenSegmentDisplay(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t outputEnablePin)
    : latchPin(latchPin), clockPin(clockPin), dataPin(dataPin), outputEnablePin(outputEnablePin) {
    pinMode(this->latchPin, OUTPUT);
    pinMode(this->clockPin, OUTPUT);
    pinMode(this->dataPin, OUTPUT);
    pinMode(this->outputEnablePin, OUTPUT);

    this->turnOn();
}

void
SevenSegmentDisplay::display(char c) const {
    uint8_t registerBits = 0b00000000;

    if (c != '#') {
        registerBits = numberBitsMapping[c - '0'];
    }

    for (uint8_t i = 0; i < 8; i++) {
        digitalWrite(this->clockPin, LOW);
        digitalWrite(this->dataPin, registerBits & (1U << i));
        digitalWrite(this->clockPin, HIGH);
    }
}

void
SevenSegmentDisplay::turnOff() const {
    digitalWrite(this->outputEnablePin, HIGH);
}

void
SevenSegmentDisplay::turnOn() const {
    digitalWrite(this->outputEnablePin, LOW);
}

void
SevenSegmentDisplay::setLightIntensity(uint8_t intensity) const {
    uint8_t trueIntensity = UINT8_MAX - map(intensity, 0, 100, 0, UINT8_MAX);

    analogWrite(this->outputEnablePin, trueIntensity);
}