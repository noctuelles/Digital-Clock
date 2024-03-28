/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:41:42 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 17:34:48 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <stdint.h>
#include <stddef.h>

template <size_t N>
class IDisplay
{
public:
    virtual void display(const char str[N + 1]) const = 0;
    virtual void turnOff() const = 0;
    virtual void turnOn() const = 0;
    virtual void setLightIntensity(uint8_t) const = 0;
};

template <>
class IDisplay<1>
{
public:
    virtual void display(char c) const = 0;
    virtual void turnOff() const = 0;
    virtual void turnOn() const = 0;
    virtual void setLightIntensity(uint8_t intensity) const = 0;
};

#endif