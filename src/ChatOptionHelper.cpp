#include "ChatOptionHelper.hpp"

#include "json/json.hpp"

#include <iostream>
#include <fstream>

void ChatOptionHelper::writeVectorToFile(const std::string fileName, const std::vector<ChatOption> chatOptions)
{
    std::ofstream file;
    file.open(fileName);

    int i = 0;
    nlohmann::json json;
    for(const ChatOption chatOption: chatOptions)
        json[i++] = chatOption.toJson();

    file << json.dump();
    file.close();
}

std::vector<ChatOption> ChatOptionHelper::readVectorFromFile(const std::string fileName)
{
    std::vector<ChatOption> chatOptions;
    const std::ifstream file(fileName);
    std::stringstream buffer;

    buffer << file.rdbuf();
    nlohmann::json json = nlohmann::json::parse(buffer.str()); 

    for(auto element : json) 
    {
        std::cout << element << '\n';
        chatOptions.push_back(ChatOption(element));
    }

    return chatOptions;
}
