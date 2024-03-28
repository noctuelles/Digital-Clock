/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CompositeSevenSegmentDisplay.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 17:36:44 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPOSITESEVENSEGMENTDISPLAY_HPP
#define COMPOSITESEVENSEGMENTDISPLAY_HPP

#include "IDisplay.hpp"
#include <stddef.h>
#include <stdint.h>
#include <string.h>

template <size_t N>
class CompositeSevenSegmentDisplay : public IDisplay<N>
{
public:
    CompositeSevenSegmentDisplay() : n(0)
    {
        for (size_t i = 0; i < N; i++)
        {
            this->displays[i] = NULL;
        }
    }
    ~CompositeSevenSegmentDisplay()
    {
    }

    void push(IDisplay<1> *display)
    {
        if (this->n >= N)
        {
            return;
        }

        this->displays[this->n++] = display;
    }

    void pop()
    {
        if (this->n == 0)
        {
            return;
        }

        this->displays[this->n--] = NULL;
    }

    const IDisplay<1> &getDisplay(size_t index) const
    {
        if (index >= this->n)
        {
            return NULL;
        }

        return this->displays[index];
    }

    void display(const char str[N + 1]) const override
    {
        for (size_t i = N; i > 0; i--)
        {
            this->displays[i - 1]->display(str[i - 1]);
        }
    }

    void turnOff() const override
    {
        for (uint8_t i = 0; i < this->n; i++)
        {
            this->displays[i]->turnOff();
        }
    }
    void turnOn() const override
    {
        for (uint8_t i = 0; i < this->n; i++)
        {
            this->displays[i]->turnOn();
        }
    }
    void setLightIntensity(uint8_t intensity) const override
    {
        for (uint8_t i = 0; i < this->n; i++)
        {
            this->displays[i]->setLightIntensity(intensity);
        }
    }

private:
    CompositeSevenSegmentDisplay &operator=(const CompositeSevenSegmentDisplay &other) = delete;
    CompositeSevenSegmentDisplay(const CompositeSevenSegmentDisplay &other) = delete;

    size_t n;
    IDisplay<1> *displays[N];
};

#endif