#include "Application.hpp"
#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    Application application(800,600, sf::Style::Default);
    application.run();

    return 0;
}
