/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:41:42 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 11:45:59 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <stddef.h>
#include <stdint.h>

template <size_t DisplayableCharacter>
class IDisplay {
   public:
    virtual void display(const char str[DisplayableCharacter]) const = 0;
};

template <>
class IDisplay<0> {
   public:
    virtual void display() const = 0;
};

template <>
class IDisplay<1> {
   public:
    virtual void display(char c) const = 0;
};

template <size_t DisplayableCharacter>
class IControllableIntensityDisplay : public IDisplay<DisplayableCharacter> {
   public:
    virtual void turnOff() const                  = 0;
    virtual void turnOn() const                   = 0;
    virtual void setLightIntensity(uint8_t) const = 0;
};

#endif