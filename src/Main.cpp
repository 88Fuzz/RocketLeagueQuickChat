#include "Application.hpp"
#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    std::vector<ChatOption> chatOptions;
    chatOptions.push_back(ChatOption("$#@%!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Close one!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Holy cow!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("No problem.", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("No way!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Noooo!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("OMG!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Okay.", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Savage!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Siiiick!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Thanks!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Whew.", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("Wow!", ChatCategory::REACTIONS));
    chatOptions.push_back(ChatOption("All yours.", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("Centering!", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("Defending...", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("Go for it!", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("I got it!", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("In position.", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("Incoming!", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("Need boost!", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("Take the shot!", ChatCategory::INFORMATION));
    chatOptions.push_back(ChatOption("Calculated.", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("Great clear!", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("Great Pass!", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("Nice block!", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("Nice one!", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("Nice shot!", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("What a play!", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("What a save!", ChatCategory::COMPLIMENTS));
    chatOptions.push_back(ChatOption("My bad...", ChatCategory::APOLOGIES));
    chatOptions.push_back(ChatOption("My fault.", ChatCategory::APOLOGIES));
    chatOptions.push_back(ChatOption("Oops!", ChatCategory::APOLOGIES));
    chatOptions.push_back(ChatOption("Sorry!", ChatCategory::APOLOGIES));
    chatOptions.push_back(ChatOption("Whoops...", ChatCategory::APOLOGIES));
    chatOptions.push_back(ChatOption("gg", ChatCategory::POST_GAME));
    chatOptions.push_back(ChatOption("Well played.", ChatCategory::POST_GAME));
    chatOptions.push_back(ChatOption("That was fun!", ChatCategory::POST_GAME));
    chatOptions.push_back(ChatOption("Rematch!", ChatCategory::POST_GAME));
    chatOptions.push_back(ChatOption("One. More. Game.", ChatCategory::POST_GAME));
    chatOptions.push_back(ChatOption("What a game!", ChatCategory::POST_GAME));
    chatOptions.push_back(ChatOption("Nice moves.", ChatCategory::POST_GAME));
    chatOptions.push_back(ChatOption("Everybody dance!", ChatCategory::POST_GAME));
    ChatOptionHelper::writeVectorToFile("ChatOptions.json", chatOptions);

    std::vector<ChatOption> otherChatOptions = ChatOptionHelper::readVectorFromFile("ChatOptions.json");

    for(const ChatOption newChatOption: otherChatOptions)
    {
        std::cout << "Reading in some shit " << newChatOption.getText() << " " << newChatOption.getCategory() << "\n";
    }


    //Application application(800,600, sf::Style::Default);
    //application.run();

    return 0;
}
