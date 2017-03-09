#include "Application.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Time Application::TIMEPERFRAME = sf::seconds(1.f / 60.f);

Application::Application(int width, int height, int windowStyle) :
                window(sf::VideoMode(width, height), "RocketLeagueQuickChat", windowStyle)
{
    window.setKeyRepeatEnabled(false);
}

void Application::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while(timeSinceLastUpdate > TIMEPERFRAME)
        {
            timeSinceLastUpdate -= TIMEPERFRAME;
            HandleEvents();
            Update(TIMEPERFRAME);
        }

        Render();
    }
}

void Application::HandleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Application::Update(sf::Time dt)
{
    std::cout << "Updating!! " << dt.asSeconds() << "\n";
}

void Application::Render()
{
    window.clear();

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);

    window.display();
}
