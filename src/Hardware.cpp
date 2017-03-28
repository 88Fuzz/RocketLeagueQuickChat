#include "Hardware.hpp"
#include <wiringPi.h>

Hardware::Hardware()
{
    wiringPiSetup();
    for(int i = Button::UP; i < BUTTON_END; i++)
        pinMode(i, INPUT);
}

bool Hardware::isButtonPressed(Button button)
{
    return digitalRead(button) != 0;
}
