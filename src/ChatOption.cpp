#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

const std::string ChatOption::TEXT = "text";
const std::string ChatOption::CATEGORY = "category";

ChatOption::ChatOption(const std::string text, const ChatCategory category)
{
    init(text, category);
}

ChatOption::ChatOption(const std::string text, const std::string category)
{ 
    init(text, category);
}

ChatOption::ChatOption(const nlohmann::json json)
{ 
    const std::string text = json[TEXT];
    const std::string category = json[CATEGORY];

    init(text, category);
}

nlohmann::json ChatOption::toJson() const
{
    nlohmann::json json;
    json[TEXT] = text;
    auto optionalCategory = ChatOptionHelper::toSerializeString(category);
    if(optionalCategory)
        json[CATEGORY] = *optionalCategory;

    return json;
}

const std::string ChatOption::getText() const
{
    return text;
}

const ChatCategory ChatOption::getCategory() const
{
    return category;
}

void ChatOption::init(const std::string text, const std::string category)
{
    auto optionalCategory = ChatOptionHelper::fromSerializeString(category);
    if(optionalCategory)
        init(text, *optionalCategory);
}

void ChatOption::init(const std::string text, const ChatCategory category)
{
    this->text = text;
    this->category = category;
}
