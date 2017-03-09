#include "Application.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

Application::Application(int width, int height, int windowStyle) :
                window(sf::VideoMode(width, height), "RocketLeagueQuickChat", windowStyle)
{
    window.setKeyRepeatEnabled(false);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while(timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            handleEvents();
            update(TIME_PER_FRAME);
        }

        render();
    }
}

void Application::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Application::update(sf::Time dt)
{
    std::cout << "Updating!! " << dt.asSeconds() << "\n";
}

void Application::render()
{
    window.clear();

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);

    window.display();
}
