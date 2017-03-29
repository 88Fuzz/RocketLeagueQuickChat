#include "Application.hpp"
#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"
#include "StateId.hpp"

#include <SFML/Graphics.hpp>
#include <sstream>

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 30.f);

Application::Application(sf::RenderWindow& window) :
                window(window),
                context(window, buttonEventHandler, font),
                stateManager(context),
                statisticsText(),
                statisticsUpdateTime(), statisticsNumberOfFrames(0),
                testing(0)
{
    window.setKeyRepeatEnabled(false);
    font.loadFromFile("fonts/GoGoPosterPunch.otf");

    statisticsText.setFont(font);
    statisticsText.setFillColor(sf::Color::Green);
    statisticsText.setCharacterSize(15);

    stateManager.registerPendingState(StateId::CATEGORY_SELECT, [](State* state)
    {
        CategorySelectState* selectState = dynamic_cast<CategorySelectState*>(state);
        selectState->registerChatOptions(ChatOptionHelper::readVectorFromFile("ChatOptions.json"));
    });
}

Application::~Application()
{
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    currentState = stateManager.getPendingState();

    while(window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while(timeSinceLastUpdate > TIME_PER_FRAME)
        {
            if(stateManager.hasPendingState())
                currentState = stateManager.getPendingState();

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
    window.clear(sf::Color(0, 35, 91));

    window.draw(*currentState);
    window.draw(statisticsText);

    window.display();
}
