#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/*
 * Main application that runs
 */
class Application
{
public:
    Application(int, int, int);
    void Run();

private:
    static const sf::Time TIMEPERFRAME;
    sf::RenderWindow window;

    void HandleEvents();
    void Update(sf::Time);
    void Render();
};

#endif
