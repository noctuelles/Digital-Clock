/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AState.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:00:05 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 13:03:56 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTATE_HPP
#define ASTATE_HPP

#include <stdint.h>

class Clock;

class AState {
   public:
    AState() = delete;
    AState(Clock &clock);
    virtual ~AState() = default;

    virtual void onSetTime()   = 0;
    virtual void onSetAlarm()  = 0;
    virtual void onIncrement() = 0;
    virtual void onDecrement() = 0;
    virtual void loop()        = 0;

   protected:
    uint8_t hours;
    uint8_t minutes;

    Clock &clockContext;
};

#endif