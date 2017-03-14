#include "EventHandler.hpp"

#include <iostream>

EventHandler::EventHandler()
{
    buttonEventKey[ButtonEvent::UP] = sf::Keyboard::Key::Up;
    buttonEventKey[ButtonEvent::DOWN] = sf::Keyboard::Key::Down;
    buttonEventKey[ButtonEvent::LEFT] = sf::Keyboard::Key::Left;
    buttonEventKey[ButtonEvent::RIGHT] = sf::Keyboard::Key::Right;
    buttonEventKey[ButtonEvent::SELECT] = sf::Keyboard::Key::Return;
}

bool EventHandler::checkButtonStatus(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
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
    for(auto const &itr : buttonEventKey)
    {
        const auto activeButton = activeButtonEvents.find(itr.first);
        const bool buttonDown = checkButtonStatus(itr.second);
        if(buttonDown && activeButton == activeButtonEvents.end())
        {
            activeButtonEvents.insert(itr.first);
            const auto action = buttonDownListener.find(itr.first);
            if(action != buttonDownListener.end())
                action->second(itr.first);
            else
                std::cout << "Button is pressed for the first time but nothing to do!\n";
        }
        else if(!buttonDown && activeButton != activeButtonEvents.end())
        {
            activeButtonEvents.erase(itr.first);
            const auto action = buttonUpListener.find(itr.first);
            if(action != buttonUpListener.end())
                action->second(itr.first);
            else
                std::cout << "Button is released for the first time but nothing to do!\n";
        }
    }
}
