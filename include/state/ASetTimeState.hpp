/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASetTimeState.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:00:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 13:04:42 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASETTIMESTATE_HPP
#define ASETTIMESTATE_HPP

#include <stdint.h>

#include "AState.hpp"

class ASetTimeState : public AState {
   public:
    ASetTimeState(Clock &clock);

    virtual void onSetTime()  = 0;
    virtual void onSetAlarm() = 0;

    void onIncrement() override final;
    void onDecrement() override final;
    void loop() override final;

   protected:
    enum Unit { HOURS, MINUTES };

    Unit selectedUnit;
};

#endif