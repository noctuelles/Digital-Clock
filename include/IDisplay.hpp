/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:41:42 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 16:07:33 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <stdint.h>

enum class LightIntensity : uint8_t
{
    LOW = 255,
    MEDIUM = 128,
    HIGH = 0
};

class IDisplay
{
public:
    virtual void display(char *str) const = 0;
    virtual void turnOff() const = 0;
    virtual void turnOn() const = 0;
    virtual void setLightIntensity(LightIntensity intensity) const = 0;
};

#endif