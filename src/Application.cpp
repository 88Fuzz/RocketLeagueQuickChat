#include "Application.hpp"
#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 30.f);

Application::Application(int width, int height, int windowStyle) :
                window(sf::VideoMode(width, height), "RocketLeagueQuickChat", windowStyle),
                context(buttonEventHandler, font), statisticsText(),
                statisticsUpdateTime(), statisticsNumberOfFrames(0),
                testing(0)
{
    window.setKeyRepeatEnabled(false);
    font.loadFromFile("fonts/Pacifico.ttf");

    statisticsText.setFont(font);
    statisticsText.setFillColor(sf::Color::Green);
    statisticsText.setCharacterSize(15);

    currentState = new CategorySelectState(context, ChatOptionHelper::readVectorFromFile("ChatOptions.json"));
    buttonEventHandler.registerDownListener(ButtonEvent::UP, [this](ButtonEvent buttonEvent) 
    {
        std::cout << buttonEvent << " Go fuck yourself! " << ++testing << "\n";
    });
    buttonEventHandler.registerUpListener(ButtonEvent::UP, [this](ButtonEvent buttonEvent) 
    {
        std::cout << buttonEvent << " Go unfuck yourself! " << --testing << "\n";
    });
}

Application::~Application()
{
    delete currentState;
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

        updateStatistics(dt);
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

void Application::updateStatistics(sf::Time dt)
{
    statisticsUpdateTime += dt;
    statisticsNumberOfFrames += 1;

    if(statisticsUpdateTime >= sf::seconds(1.0f))
    {
        std::stringstream ss;
        ss << "FPS: " << statisticsNumberOfFrames;
        statisticsText.setString(ss.str());

        statisticsUpdateTime -= sf::seconds(1.0f);
        statisticsNumberOfFrames = 0;
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
    window.draw(statisticsText);

    window.display();
}
