#include "ChatOption.hpp"
#include "ChatOptionHelper.hpp"

const std::string ChatOption::TEXT = "text";
const std::string ChatOption::CATEGORY = "category";

ChatOption::ChatOption(const std::string text, const std::string category)
{ 
    this->text = text;
    auto optionalCategory = ChatOptionHelper::fromSerializeString(category);
    if(optionalCategory)
        this->category = *optionalCategory;
}

ChatOption::ChatOption(const nlohmann::json json):ChatOption(json[TEXT], json[CATEGORY])
{ }

nlohmann::json ChatOption::toJson() const
{
    nlohmann::json json;
    json[TEXT] = text;
    std::experimental::optional<std::string> optionalCategory = ChatOptionHelper::toSerializeString(category);
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
