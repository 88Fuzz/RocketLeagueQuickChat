#ifndef CHAT_OPTION_HPP 
#define CHAT_OPTION_HPP

#include "JsonSerializeable.hpp"
#include "ChatCategory.hpp"

#include <string>

class ChatOption: public JsonSerializeable
{
public:
    ChatOption(std::string, ChatCategory);
    ChatOption(std::string, std::string);
    ChatOption(nlohmann::json);

    /*
     * Converts the object to json.
     */
    nlohmann::json toJson() const;

    std::string getText() const;
    ChatCategory getCategory() const;

private:
    static const std::string TEXT;
    static const std::string CATEGORY;

    std::string text;
    ChatCategory category;

    /*
     * Helper method to set the text and category for each constructor.
     */
    void init(std::string, std::string);
    /*
     * Helper method to set the text and category for each constructor.
     */
    void init(std::string, ChatCategory);
};

#endif
