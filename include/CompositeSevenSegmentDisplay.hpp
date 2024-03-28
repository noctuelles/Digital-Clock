/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CompositeSevenSegmentDisplay.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 21:44:17 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPOSITESEVENSEGMENTDISPLAY_HPP
#define COMPOSITESEVENSEGMENTDISPLAY_HPP

#include "IDisplay.hpp"
#include <stddef.h>
#include <stdint.h>
#include <string.h>

template <size_t NbrDisplay>
class CompositeSevenSegmentDisplay : public IDisplay<NbrDisplay>
{
public:
    CompositeSevenSegmentDisplay() : registeredDisplay(0)
    {
        for (size_t i = 0; i < NbrDisplay; i++)
        {
            this->displays[i] = NULL;
        }
    }

    ~CompositeSevenSegmentDisplay()
    {
    }

    CompositeSevenSegmentDisplay(const CompositeSevenSegmentDisplay &src) = delete;
    CompositeSevenSegmentDisplay &operator=(const CompositeSevenSegmentDisplay &rhs) = delete;

    void push(IDisplay<1> *display)
    {
        if (this->registeredDisplay >= NbrDisplay)
        {
            return;
        }

        this->displays[this->registeredDisplay++] = display;
    }

    void pop()
    {
        if (this->registeredDisplay == 0)
        {
            return;
        }

        this->displays[this->registeredDisplay--] = NULL;
    }

    const IDisplay<1> &getDisplay(size_t index) const
    {
        if (index >= this->registeredDisplay)
        {
            return NULL;
        }

        return this->displays[index];
    }

    void display(const char str[NbrDisplay + 1]) const override
    {
        for (size_t i = NbrDisplay; i > 0; i--)
        {
            this->displays[i - 1]->display(str[i - 1]);
        }
    }

    void turnOff() const override
    {
        for (uint8_t i = 0; i < this->registeredDisplay; i++)
        {
            this->displays[i]->turnOff();
        }
    }
    void turnOn() const override
    {
        for (uint8_t i = 0; i < this->registeredDisplay; i++)
        {
            this->displays[i]->turnOn();
        }
    }
    void setLightIntensity(uint8_t intensity) const override
    {
        for (uint8_t i = 0; i < this->registeredDisplay; i++)
        {
            this->displays[i]->setLightIntensity(intensity);
        }
    }

private:
    size_t registeredDisplay;
    IDisplay<1> *displays[NbrDisplay];
};

#endif