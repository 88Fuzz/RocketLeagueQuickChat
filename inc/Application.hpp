#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "EventHandler.hpp"
#include "Context.hpp"
#include "State.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

/*
 * Main application that runs
 */
class Application
{
public:
    Application(int, int, int);
    virtual ~Application();
    void run();

private:
    static const sf::Time TIME_PER_FRAME;
    sf::RenderWindow window;
    sf::Font font;
    EventHandler buttonEventHandler;
    Context context;
    State* currentState;
    sf::Text statisticsText;
    sf::Time statisticsUpdateTime;
    int statisticsNumberOfFrames;
    int testing;

    void handleSFMLEvents();
    void handleButtonEvents(sf::Time);
    void updateStatistics(sf::Time);
    void update(sf::Time);
    void render();
};

#endif
