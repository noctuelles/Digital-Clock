#include "state/ASetTimeState.hpp"

#include "Clock.hpp"
#include "state/AState.hpp"

ASetTimeState::ASetTimeState(Clock &clock) : AState(clock), selectedUnit(Unit::HOURS) {}

void
ASetTimeState::onIncrement() {
    if (selectedUnit == Unit::HOURS) {
        hours = (hours + 1) % 24;
    } else {
        minutes = (minutes + 1) % 60;
    }
}

void
ASetTimeState::onDecrement() {
    if (selectedUnit == Unit::HOURS) {
        hours = (hours - 1) % 24;
    } else {
        minutes = (minutes - 1) % 60;
    }
}

void
ASetTimeState::loop() {
    char hoursDisplayBuffer[3];
    char minutesDisplayBuffer[3];

    memcpy(hoursDisplayBuffer, "00", 3);
    memcpy(minutesDisplayBuffer, "00", 3);

    itoa(this->hours, hoursDisplayBuffer, 10);
    itoa(this->minutes, minutesDisplayBuffer, 10);

    if (selectedUnit == Unit::HOURS) {
        this->clockContext.getHoursDisplay().setLightIntensity(255);
        this->clockContext.getMinutesDisplay().setLightIntensity(50);
    } else {
        this->clockContext.getHoursDisplay().setLightIntensity(50);
        this->clockContext.getMinutesDisplay().setLightIntensity(255);
    }

    this->clockContext.getHoursDisplay().display(hoursDisplayBuffer);
    this->clockContext.getMinutesDisplay().display(minutesDisplayBuffer);
}
