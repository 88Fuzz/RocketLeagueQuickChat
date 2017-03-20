#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "EventHandler.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class Context
{
public:
    Context(sf::RenderWindow&, EventHandler&, sf::Font&);

    sf::RenderWindow& getWindow() const;
    EventHandler& getEventHandler() const;
    sf::Font& getFont() const;
private:
    sf::RenderWindow& window;
    EventHandler& eventHandler;
    sf::Font& font;
};

#endif
