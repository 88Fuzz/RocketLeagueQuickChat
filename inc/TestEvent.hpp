#ifndef TEST_EVENT_HPP
#define TEST_EVENT_HPP

#include "EventHandlerCallback.hpp"

class TestEvent : public EventHandlerCallback
{
public:
    virtual void buttonDown(ButtonEvent);
    virtual void buttonUp(ButtonEvent);
};

#endif
