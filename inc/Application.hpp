#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "EventHandler.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/*
 * Main application that runs
 */
class Application
{
public:
    Application(int, int, int);
    void run();

private:
    static const sf::Time TIME_PER_FRAME;
    sf::RenderWindow window;
    EventHandler buttonEventHandler;
    int testing;

    void handleSFMLEvents();
    void handleButtonEvents(sf::Time);
    void update(sf::Time);
    void render();
};

#endif
