#include "Context.hpp"

Context::Context(sf::RenderWindow& window, EventHandler& eventHandler,sf::Font& font): window(window), eventHandler(eventHandler), font(font)
{
}

sf::RenderWindow& Context::getWindow() const
{
    return window;
}

EventHandler& Context::getEventHandler() const
{
    return eventHandler;
}

sf::Font& Context::getFont() const
{
    return font;
}
