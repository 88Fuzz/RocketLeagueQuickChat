#include "Application.hpp"
#include "ChatOption.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    ChatOption chatOption;
    chatOption.text = "fuck";
    chatOption.category = "me";

    std::cout << chatOption.toJsonString() << "\n";
    //Application application(800,600, sf::Style::Default);
    //application.run();

    return 0;
}
