#ifndef APPLICATION_HPP
#define APPLICATION_HPP

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
    static const sf::Time TIMEPERFRAME;
    sf::RenderWindow window;

    void handleEvents();
    void update(sf::Time);
    void render();
};

#endif
