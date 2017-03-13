#include "Application.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

Application::Application(int width, int height, int windowStyle) :
                window(sf::VideoMode(width, height), "RocketLeagueQuickChat", windowStyle)
{
    window.setKeyRepeatEnabled(false);
    buttonEventHandler.registerDownListener(ButtonEvent::UP, &yourMom);
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
            handleButtonEvents(TIME_PER_FRAME);
            handleSFMLEvents();
            update(TIME_PER_FRAME);
        }

        render();
    }
}

void Application::handleButtonEvents(sf::Time dt)
{
    buttonEventHandler.handleEvents(dt);
}

void Application::handleSFMLEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window.close();
    }
}

void Application::update(sf::Time dt)
{
}

void Application::render()
{
    window.clear();

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);

    window.display();
}
