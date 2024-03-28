/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pins.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:18:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 21:01:41 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PINS_HPP
#define PINS_HPP

#include <stdint.h>

struct DisplayPins
{
    static const uint8_t LATCH = 23;
    static const uint8_t CLOCK = 24;
    static const uint8_t DATA = 22;
    static const uint8_t HOURS_OUTPUT_ENABLE_1 = 3;
    static const uint8_t HOURS_OUTPUT_ENABLE_2 = 5;
    static const uint8_t MINUTES_OUTPUT_ENABLE_1 = 9;
    static const uint8_t MINUTES_OUTPUT_ENABLE_2 = 10;
};

enum class RTCPins : uint8_t
{
    SDA = 0,
    SCL = 1
};

enum class ButtonPins : uint8_t
{
    SET_TIME,
    SET_ALARM,
    ENABLE_ALARM,
    INCREMENT,
    DECREMENT,
};

enum class StatusLedPins : uint8_t
{
    SET_ALARM,
    SET_TIME
};

#endif