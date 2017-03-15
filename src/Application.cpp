#include "Application.hpp"
#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

Application::Application(int width, int height, int windowStyle) :
                window(sf::VideoMode(width, height), "RocketLeagueQuickChat", windowStyle),
                context(buttonEventHandler, font), testing(0)
{
    window.setKeyRepeatEnabled(false);
    font.loadFromFile("fonts/Pacifico.ttf");

    std::cout << "fuck?\n";
    currentState = new CategorySelectState(context, ChatOptionHelper::readVectorFromFile("ChatOptions.json"));
    std::cout <<"about to register\n";
    buttonEventHandler.registerDownListener(ButtonEvent::UP, [this](ButtonEvent buttonEvent) 
    {
        std::cout << buttonEvent << " Go fuck yourself! " << ++testing << "\n";
    });
    buttonEventHandler.registerUpListener(ButtonEvent::UP, [this](ButtonEvent buttonEvent) 
    {
        std::cout << buttonEvent << " Go unfuck yourself! " << --testing << "\n";
    });
    std::cout <<"Done registering\n";
}

Application::~Application()
{
    std::cout << "Deleting this shit\n";
    delete currentState;
    std::cout << "Done deleting\n";
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
    currentState->update(dt);
}

void Application::render()
{
    window.clear();

    window.draw(*currentState);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    //window.draw(shape);

    window.display();
}
