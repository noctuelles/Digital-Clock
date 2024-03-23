#include <stdint.h>

/**
 * @brief
 *
 */
class SevenSegmentDisplay
{
public:
    static constexpr size_t nbrAvailableNumbers = 10;

    SevenSegmentDisplay(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin);
    ~SevenSegmentDisplay();

    void display(char toDisplay);

private:
    SevenSegmentDisplay() = delete;
    SevenSegmentDisplay(const SevenSegmentDisplay &other) = delete;
    SevenSegmentDisplay operator=(const SevenSegmentDisplay &other) = delete;

    static const uint8_t bitsMapping[nbrAvailableNumbers];

    uint8_t latchPin;
    uint8_t clockPin;
    uint8_t dataPin;
};