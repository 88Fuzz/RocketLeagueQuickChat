#ifndef CHAT_OPTION_HPP 
#define CHAT_OPTION_HPP

#include "JsonSerializeable.hpp"
#include "ChatCategory.hpp"

#include <string>

class ChatOption: public JsonSerializeable
{
public:
    ChatOption(const std::string, const std::string);
    ChatOption(const nlohmann::json);
    nlohmann::json toJson() const;

    const std::string getText() const;
    const ChatCategory getCategory() const;

private:
    static const std::string TEXT;
    static const std::string CATEGORY;

    std::string text;
    ChatCategory category;
};

#endif
