#include "Application.hpp"
#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    ChatOption chatOption("fuck", "INFORMATION");

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
    ChatOptionHelper::writeVectorToFile("ChatOptions.json", chatOptions);

    std::vector<ChatOption> otherChatOptions = ChatOptionHelper::readVectorFromFile("ChatOptions.json");

    for(const ChatOption newChatOption: otherChatOptions)
    {
        std::cout << newChatOption.getText() << " " << newChatOption.getCategory() << "\n";
    }


    //Application application(800,600, sf::Style::Default);
    //application.run();

    return 0;
}
