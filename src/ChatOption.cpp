#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

const std::string ChatOption::TEXT = "text";
const std::string ChatOption::CATEGORY = "category";

ChatOption::ChatOption(std::string text, ChatCategory category)
{
    init(text, category);
}

ChatOption::ChatOption(std::string text, std::string category)
{ 
    init(text, category);
}

ChatOption::ChatOption(nlohmann::json json)
{ 
    std::string text = json[TEXT];
    std::string category = json[CATEGORY];

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

std::string ChatOption::getText() const
{
    return text;
}

ChatCategory ChatOption::getCategory() const
{
    return category;
}

void ChatOption::init(std::string text, std::string category)
{
    auto optionalCategory = ChatOptionHelper::fromSerializeString(category);
    if(optionalCategory)
        init(text, *optionalCategory);
}

void ChatOption::init(std::string text, ChatCategory category)
{
    this->text = text;
    this->category = category;
}
