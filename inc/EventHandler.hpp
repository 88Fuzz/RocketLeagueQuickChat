#ifndef EVENT_HANDLER_HPP 
#define EVENT_HANDLER_HPP 

#include "ButtonEvent.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <set>
#include <functional>

class EventHandler
{
public:
    EventHandler();
    /*
     * Register a function to be called whenever a ButtenEven is pressed.
     */
    void registerDownListener(ButtonEvent, std::function<void(ButtonEvent)>);

    /*
     * Register a function to be called whenever a ButtenEven is released.
     */
    void registerUpListener(ButtonEvent, std::function<void(ButtonEvent)>);

    /*
     * Check for ButtonEvent actions (pressed or released).
     */
    void handleEvents(sf::Time);

private:
    std::map<ButtonEvent, std::function<void(ButtonEvent)>> buttonDownListener;
    std::map<ButtonEvent, std::function<void(ButtonEvent)>> buttonUpListener;
    std::map<ButtonEvent, sf::Keyboard::Key> buttonEventKey;
    std::set<ButtonEvent> activeButtonEvents;

    bool checkButtonStatus(sf::Keyboard::Key);
};

#endif
