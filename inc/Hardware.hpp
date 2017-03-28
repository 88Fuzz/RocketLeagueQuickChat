#ifndef HARDWARE_HPP
#define HARDWARE_HPP

class Hardware
{
public:
    enum Button
    {
        UP = 0,
        DOWN = 1,
        LEFT,
        RIGHT,
        SELECT,
        BUTTON_END
    };

    Hardware();
    bool isButtonPressed(Button);
};

#endif
