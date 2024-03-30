/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CompositeSevenSegmentDisplay.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 13:37:53 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPOSITESEVENSEGMENTDISPLAY_HPP
#define COMPOSITESEVENSEGMENTDISPLAY_HPP

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "IDisplay.hpp"

template <size_t NbrDisplay>
class CompositeSevenSegmentDisplay : public IControllableIntensityDisplay<NbrDisplay> {
   public:
    CompositeSevenSegmentDisplay(uint8_t latchPin) : registeredDisplay(0) {
        for (size_t i = 0; i < NbrDisplay; i++) {
            this->displays[i] = NULL;
        }
    }
    CompositeSevenSegmentDisplay(const CompositeSevenSegmentDisplay &src)            = delete;
    CompositeSevenSegmentDisplay &operator=(const CompositeSevenSegmentDisplay &rhs) = delete;
    ~CompositeSevenSegmentDisplay()                                                  = default;

    void
    push(IControllableIntensityDisplay<1> *display) {
        if (this->registeredDisplay >= NbrDisplay) {
            return;
        }

        this->displays[this->registeredDisplay++] = display;
    }

    void
    pop() {
        if (this->registeredDisplay == 0) {
            return;
        }

        this->displays[this->registeredDisplay--] = NULL;
    }

    void
    display(const char str[NbrDisplay]) const override {
        for (size_t i = NbrDisplay; i > 0; i--) {
            this->displays[i - 1]->display(str[i - 1]);
        }
    }

    void
    turnOff() const override {
        for (uint8_t i = 0; i < this->registeredDisplay; i++) {
            this->displays[i]->turnOff();
        }
    }
    void
    turnOn() const override {
        for (uint8_t i = 0; i < this->registeredDisplay; i++) {
            this->displays[i]->turnOn();
        }
    }
    void
    setLightIntensity(uint8_t intensity) const override {
        for (uint8_t i = 0; i < this->registeredDisplay; i++) {
            this->displays[i]->setLightIntensity(intensity);
        }
    }

   private:
    size_t                            registeredDisplay;
    IControllableIntensityDisplay<1> *displays[NbrDisplay];
};

#endif