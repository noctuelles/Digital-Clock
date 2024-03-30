/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SevenSegmentDisplay.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:47:01 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 12:47:40 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEVENSEGMENTDISPLAY_HPP
#define SEVENSEGMENTDISPLAY_HPP

#include <stdint.h>

#include "IDisplay.hpp"

class SevenSegmentDisplay : public IControllableIntensityDisplay<1> {
   public:
    static constexpr uint8_t nbrAvailableNumbers = 10;

    SevenSegmentDisplay(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t outputEnablePin);
    SevenSegmentDisplay()                                          = delete;
    SevenSegmentDisplay(const SevenSegmentDisplay &src)            = delete;
    SevenSegmentDisplay &operator=(const SevenSegmentDisplay &rhs) = delete;
    ~SevenSegmentDisplay()                                         = default;

    void display(char c) const override;
    void turnOff() const override;
    void turnOn() const override;
    void setLightIntensity(uint8_t) const override;

   private:
    static const uint8_t numberBitsMapping[nbrAvailableNumbers];

    uint8_t latchPin;
    uint8_t clockPin;
    uint8_t dataPin;
    uint8_t outputEnablePin;
};

#endif