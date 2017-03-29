#include "Application.hpp"
#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

int main()
{
    sf::VideoMode videoMode = sf::VideoMode::getFullscreenModes()[0];
    sf::RenderWindow window(videoMode, "RocketLeagueQuickChat", sf::Style::Fullscreen);
    Application application(window);
    application.run();

    return 0;
}
