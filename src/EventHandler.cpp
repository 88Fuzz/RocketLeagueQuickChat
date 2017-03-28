#include "EventHandler.hpp"

EventHandler::EventHandler(): hardware()
{
    buttonEventKey[ButtonEvent::UP] = Hardware::Button::UP;
    buttonEventKey[ButtonEvent::DOWN] = Hardware::Button::DOWN;
    buttonEventKey[ButtonEvent::LEFT] = Hardware::Button::LEFT;
    buttonEventKey[ButtonEvent::RIGHT] = Hardware::Button::RIGHT;
    buttonEventKey[ButtonEvent::SELECT] = Hardware::Button::SELECT;
}

void EventHandler::clearAllListeners()
{
    buttonDownListener.clear();
    buttonUpListener.clear();
}

bool EventHandler::checkButtonStatus(Hardware::Button button)
{
    return hardware.isButtonPressed(button);
}

void EventHandler::registerDownListener(ButtonEvent buttonEvent, std::function<void(ButtonEvent)> callback)
{
    buttonDownListener[buttonEvent] = callback;
}

void EventHandler::registerUpListener(ButtonEvent buttonEvent, std::function<void(ButtonEvent)> callback)
{
    buttonUpListener[buttonEvent] = callback;
}

void EventHandler::handleEvents(sf::Time dt)
{
    for(auto &itr : buttonEventKey)
    {
        auto activeButton = activeButtonEvents.find(itr.first);
        bool buttonDown = checkButtonStatus(itr.second);
        if(buttonDown && activeButton == activeButtonEvents.end())
        {
            activeButtonEvents.insert(itr.first);
            auto action = buttonDownListener.find(itr.first);
            if(action != buttonDownListener.end())
                action->second(itr.first);
        }
        else if(!buttonDown && activeButton != activeButtonEvents.end())
        {
            activeButtonEvents.erase(itr.first);
            auto action = buttonUpListener.find(itr.first);
            if(action != buttonUpListener.end())
                action->second(itr.first);
        }
    }
}
