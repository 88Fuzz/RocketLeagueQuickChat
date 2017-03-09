#include "Application.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::CircleShape shape2(100.f);
    shape.setFillColor(sf::Color::Red);
    bool tarp = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if(tarp)
            window.draw(shape);
        else
            window.draw(shape2);

        tarp = !tarp;
        window.display();
    }*/

    Application application(800,600, sf::Style::Default);
    application.Run();

    return 0;
}
