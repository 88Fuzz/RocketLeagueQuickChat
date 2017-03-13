#ifndef EVENT_HANDLER_HPP 
#define EVENT_HANDLER_HPP 

#include "ButtonEvent.hpp"
#include "EventHandlerCallback.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <set>

class EventHandler
{
public:
    EventHandler();
    /*
     * Register a function to be called whenever a ButtenEven is pressed.
     */
    void registerDownListener(ButtonEvent, EventHandlerCallback*);

    /*
     * Register a function to be called whenever a ButtenEven is released.
     */
    void registerUpListener(ButtonEvent, EventHandlerCallback*);

    /*
     * Check for ButtonEvent actions (pressed or released).
     */
    void handleEvents(sf::Time);

private:
    std::map<ButtonEvent, EventHandlerCallback*> buttonDownListener;
    std::map<ButtonEvent, EventHandlerCallback*> buttonUpListener;
    std::map<ButtonEvent, sf::Keyboard::Key> buttonEventKey;
    std::set<ButtonEvent> activeButtonEvents;

    bool checkButtonStatus(sf::Keyboard::Key);
};

#endif
