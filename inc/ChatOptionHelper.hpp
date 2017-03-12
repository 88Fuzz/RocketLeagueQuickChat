#ifndef CHAT_OPTION_HELPER_HPP
#define CHAT_OPTION_HELPER_HPP

#include "ChatOption.hpp"

#include <string>
#include <experimental/optional>
#include <vector>

class ChatOptionHelper
{
public:
    /*
     * Serialize the list of ChatOptions to a file
     */
    static void writeVectorToFile(const std::string,const std::vector<ChatOption>);

    /*
     * Read the file and convert it to a list of ChatOptions
     */
    static std::vector<ChatOption> readVectorFromFile(const std::string);

    /*
     * Return the ChatCategory that corresponds to the string.
     * Returns empty optional if the string does not translate to a category.
     */
    static std::experimental::optional<ChatCategory> fromSerializeString(const std::string);

    /*
     * Converts the ChatCategory to a string
     */
    static std::experimental::optional<std::string> toSerializeString(const ChatCategory);

private:
    static std::map<std::string, ChatCategory> stringToEnumMap;
    static std::map<ChatCategory, std::string> enumToStringMap;
};

#endif
