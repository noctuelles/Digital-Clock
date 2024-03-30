/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetCurrentTimeState.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:35:31 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 12:42:43 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETCURRENTTIMESTATE_HPP
#define SETCURRENTTIMESTATE_HPP

#include "ASetTimeState.hpp"

class SetCurrentTimeMode : public ASetTimeState {
   public:
    void onSetAlarm() override final;
    void onSetTime() override final;
};

#endif