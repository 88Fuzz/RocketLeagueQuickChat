#include "Application.hpp"
#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    ChatOption chatOption("fuck", "me");

    nlohmann::json json = chatOption.toJson();
    std::cout << json.dump() << "\n\n";

    for (nlohmann::json::iterator it = json.begin(); it != json.end(); it++) 
    {
        std::cout << *it << '\n';
    }

    std::cout << "\n";

    std::vector<ChatOption> chatOptions;
    chatOptions.push_back(chatOption);
    chatOptions.push_back(chatOption);
    chatOptions.push_back(chatOption);
    chatOptions.push_back(chatOption);
    ChatOptionHelper::writeVectorToFile("chatOptions.json", chatOptions);

    std::vector<ChatOption> otherChatOptions = ChatOptionHelper::readVectorFromFile("chatOptions.json");

    for(const ChatOption newChatOption: otherChatOptions)
    {
        std::cout << newChatOption.text << " " << newChatOption.category << "\n";
    }


    //Application application(800,600, sf::Style::Default);
    //application.run();

    return 0;
}
