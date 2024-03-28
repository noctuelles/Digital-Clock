/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CompositeSevenSegmentDisplay.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:45:29 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 15:55:02 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CompositeSevenSegmentDisplay.hpp"
#include <string.h>
#include <stdint.h>

template <size_t N>
CompositeSevenSegmentDisplay<N>::CompositeSevenSegmentDisplay() : n(0)
{
    for (size_t i = 0; i < N; i++)
    {
        this->displays[i] = NULL;
    }
}

template <size_t N>
CompositeSevenSegmentDisplay<N>::~CompositeSevenSegmentDisplay() {}

template <size_t N>
void CompositeSevenSegmentDisplay<N>::pushDisplay(IDisplay *display)
{
    if (this->n >= N)
    {
        return;
    }

    this->displays[this->n++] = display;
}

template <size_t N>
void CompositeSevenSegmentDisplay<N>::popDisplay()
{
    if (this->n == 0)
    {
        return;
    }

    this->displays[this->n--] = NULL;
}

template <size_t N>
void CompositeSevenSegmentDisplay<N>::display(char *str) const
{
    char nextCharacter = 0;

    for (uint8_t i = 0; i < this->n && i < strlen(str); i++)
    {
        nextCharacter = str[i + 1];
        str[i + 1] = '\0';
        this->displays[i]->display(&str[i]);
        str[i + 1] = nextCharacter;
    }
}