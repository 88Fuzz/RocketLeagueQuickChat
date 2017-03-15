#include "Context.hpp"

Context::Context(EventHandler& eventHandler,sf::Font& font): eventHandler(eventHandler), font(font)
{
}

EventHandler& Context::getEventHandler() const
{
    return eventHandler;
}

sf::Font& Context::getFont() const
{
    return font;
}
