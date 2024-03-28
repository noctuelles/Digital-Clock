/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SevenSegmentDisplay.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:47:01 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 16:06:03 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEVENSEGMENTDISPLAY_HPP
#define SEVENSEGMENTDISPLAY_HPP

#include "IDisplay.hpp"
#include <stdint.h>

class SevenSegmentDisplay : public IDisplay
{
public:
    static constexpr uint8_t nbrAvailableNumbers = 10;

    SevenSegmentDisplay(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t outputEnablePin);
    ~SevenSegmentDisplay();

    void display(char *str) const override;
    void turnOff() const override;
    void turnOn() const override;
    void setLightIntensity(LightIntensity intensity) const override;

private:
    SevenSegmentDisplay() = delete;
    SevenSegmentDisplay(const SevenSegmentDisplay &other) = delete;
    SevenSegmentDisplay operator=(const SevenSegmentDisplay &other) = delete;

    static const uint8_t numberBitsMapping[nbrAvailableNumbers];

    uint8_t latchPin;
    uint8_t clockPin;
    uint8_t dataPin;
    uint8_t outputEnablePin;
};

#endif