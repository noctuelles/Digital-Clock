/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:41:42 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/28 15:52:03 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

class IDisplay
{
public:
    virtual void display(char *str) const = 0;
};

#endif