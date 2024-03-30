#include "Settings.hpp"

#include <EEPROM.h>

Settings::Settings() {
    EEPROM.get(EEPROMAddress, this->currentSettings);
}

void
Settings::save() {
    EEPROM.put(EEPROMAddress, this->currentSettings);
}

Settings&
Settings::setAlarmTime(uint8_t hours, uint8_t minutes) {
    this->currentSettings.alarmHours   = hours;
    this->currentSettings.alarmMinutes = minutes;

    return *this;
}

Settings&
Settings::setDisplayBrightness(uint8_t intensity) {
    this->currentSettings.displayBrightness = intensity;

    return *this;
}

uint16_t
Settings::getAlarmTime() const {
    return (this->currentSettings.alarmHours << 8) | this->currentSettings.alarmMinutes;
}

uint8_t
Settings::getDisplayBrightness() const {
    return this->currentSettings.displayBrightness;
}