/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:52:56 by plouvel           #+#    #+#             */
/*   Updated: 2024/03/30 12:53:10 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <stdint.h>

class Settings {
   public:
    Settings();
    Settings(const Settings& other)          = default;
    Settings& operator=(const Settings& rhs) = default;
    ~Settings()                              = default;

    Settings& setAlarmTime(uint8_t hours, uint8_t minutes);
    Settings& setDisplayBrightness(uint8_t intensity);

    void save();

    uint16_t getAlarmTime() const;
    uint8_t  getDisplayBrightness() const;

   private:
    struct EEPROMSettings {
        uint8_t alarmHours;
        uint8_t alarmMinutes;
        uint8_t displayBrightness;
    };

    static constexpr uint16_t EEPROMAddress = 0;
    EEPROMSettings            currentSettings;
};

#endif