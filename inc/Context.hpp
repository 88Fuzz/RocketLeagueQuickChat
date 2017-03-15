#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "EventHandler.hpp"

#include <SFML/Graphics/Font.hpp>

class Context
{
public:
    Context(EventHandler&, sf::Font&);

    EventHandler& getEventHandler() const;
    sf::Font& getFont() const;
private:
    EventHandler& eventHandler;
    sf::Font& font;
};

#endif
