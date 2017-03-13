#ifndef EVENT_HANDLER_CALLBACK_HPP
#define EVENT_HANDLER_CALLBACK_HPP

#include "ButtonEvent.hpp"

class EventHandlerCallback
{
public:
    /*
     * Method called when ButtenEvent is pressed down.
     */
    virtual void buttonDown(ButtonEvent) = 0;
    /*
     * Method called when ButtenEvent is released.
     */
    virtual void buttonUp(ButtonEvent) = 0;
};

#endif
