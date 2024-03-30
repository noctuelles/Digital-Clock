/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SeparatorDisplay.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:49:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 12:49:24 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display/SeparatorDisplay.hpp"

#include <Arduino.h>

SeparatorDisplay::SeparatorDisplay(uint8_t pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void
SeparatorDisplay::display() const {
    this->turnOn();
}

void
SeparatorDisplay::turnOff() const {
    digitalWrite(this->pin, LOW);
}

void
SeparatorDisplay::turnOn() const {
    digitalWrite(this->pin, HIGH);
}

void
SeparatorDisplay::setLightIntensity(uint8_t intensity) const {
    analogWrite(this->pin, intensity);
}