/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetAlarmTimeState.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:36:14 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 12:40:27 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETALARMTIMESTATE_HPP
#define SETALARMTIMESTATE_HPP

#include "ASetTimeState.hpp"

class SetAlarmTimeState : public ASetTimeState {
   public:
    SetAlarmTimeState(Clock &clockContext);
    ~SetAlarmTimeState() = default;

    void onSetTime() override final;
    void onSetAlarm() override final;
};

#endif