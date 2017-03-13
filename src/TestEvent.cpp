#include "TestEvent.hpp"

#include <iostream>

void TestEvent::buttonDown(ButtonEvent buttonEvent)
{
    std::cout << buttonEvent << " was pressed down.\n";
}

void TestEvent::buttonUp(ButtonEvent buttonEvent)
{
    std::cout << buttonEvent << " was released.\n";
}
