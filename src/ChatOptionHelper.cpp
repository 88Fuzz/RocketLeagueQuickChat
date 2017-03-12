#include "ChatOptionHelper.hpp"

#include "json/json.hpp"

#include <iostream>
#include <fstream>

const std::string INFORMATION_STRING = "INFORMATION";
const std::string COMPLIMENTS_STRING = "COMPLIMENTS";
const std::string REACTIONS_STRING = "REACTIONS";
const std::string APOLOGIES_STRING = "APOLOGIES";
const std::string POST_GAME_STRING = "POST_GAME";
const std::string END_ENUM_STRING = "END_ENUM";

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

std::experimental::optional<ChatCategory> ChatOptionHelper::fromSerializeString(const std::string str)
{
    typename std::map<std::string, ChatCategory>::const_iterator itr = stringToEnumMap.find(str);

    if(itr == stringToEnumMap.end())
        return {};

    return itr->second;
}

std::experimental::optional<std::string> ChatOptionHelper::toSerializeString(const ChatCategory enumVal)
{
    typename std::map<ChatCategory, std::string>::const_iterator itr = enumToStringMap.find(enumVal);

    if(itr == enumToStringMap.end())
        return {};

    return itr->second;
}

std::map<std::string, ChatCategory> ChatOptionHelper::stringToEnumMap =
{
    {INFORMATION_STRING, INFORMATION},
    {COMPLIMENTS_STRING, COMPLIMENTS},
    {REACTIONS_STRING, REACTIONS},
    {APOLOGIES_STRING, APOLOGIES},
    {POST_GAME_STRING, POST_GAME},
    {END_ENUM_STRING, END_ENUM},
};

std::map<ChatCategory, std::string> ChatOptionHelper::enumToStringMap =
{
    {INFORMATION, INFORMATION_STRING},
    {COMPLIMENTS, COMPLIMENTS_STRING},
    {REACTIONS, REACTIONS_STRING},
    {APOLOGIES, APOLOGIES_STRING},
    {POST_GAME, POST_GAME_STRING},
    {END_ENUM, END_ENUM_STRING}
};
