#include "Application.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    Application application(800,600, sf::Style::Default);
    application.run();

    return 0;
}
