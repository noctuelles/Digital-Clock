/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SeparatorDisplay.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:04:22 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 12:46:37 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEPARATORDISPLAY_HPP
#define SEPARATORDISPLAY_HPP

#include "IDisplay.hpp"

class SeparatorDisplay : public IControllableIntensityDisplay<0> {
   public:
    SeparatorDisplay() = delete;
    SeparatorDisplay(uint8_t pin);
    ~SeparatorDisplay() = default;

    void display() const override;
    void turnOff() const override;
    void turnOn() const override;
    void setLightIntensity(uint8_t) const override;

   private:
    uint8_t pin;
};

#endif