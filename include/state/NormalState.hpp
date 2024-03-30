/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NormalState.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:34:48 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 12:57:12 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOWTIMESTATE_HPP
#define SHOWTIMESTATE_HPP

#include "AState.hpp"

class NormalState : public AState {
   public:
    void onIncrement() override final;
    void onDecrement() override final;
    void onSetAlarm() override final;
    void onSetTime() override final;
    void loop() override final;
};

#endif