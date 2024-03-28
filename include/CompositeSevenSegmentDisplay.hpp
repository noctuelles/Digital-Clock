/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CompositeSevenSegmentDisplay.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:23 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 16:08:24 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPOSITESEVENSEGMENTDISPLAY_HPP
#define COMPOSITESEVENSEGMENTDISPLAY_HPP

#include "IDisplay.hpp"
#include <stddef.h>

template <size_t N>
class CompositeSevenSegmentDisplay : public IDisplay
{
public:
    CompositeSevenSegmentDisplay();
    ~CompositeSevenSegmentDisplay();

    void pushDisplay(IDisplay *display);
    void popDisplay();

    const IDisplay &getDisplay(size_t index) const;

    void display(char *str) const override;
    void turnOff() const override;
    void turnOn() const override;
    void setLightIntensity(LightIntensity intensity) const override;

private:
    CompositeSevenSegmentDisplay &operator=(const CompositeSevenSegmentDisplay &other) = delete;
    CompositeSevenSegmentDisplay(const CompositeSevenSegmentDisplay &other) = delete;

    size_t n;
    IDisplay *displays[N];
};

#endif