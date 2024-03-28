/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pins.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:18:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 16:20:45 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PINS_HPP
#define PINS_HPP

#include <stdint.h>

enum class DisplayPins : uint8_t
{
    LATCH = 0,
    CLOCK = 1,
    DATA = 2,
    MINUTES_OUTPUT_ENABLE_1 = 3,
    MINUTES_OUTPUT_ENABLE_2 = 4,
    HOURS_OUTPUT_ENABLE_1 = 5,
    HOURS_OUTPUT_ENABLE_2 = 6
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