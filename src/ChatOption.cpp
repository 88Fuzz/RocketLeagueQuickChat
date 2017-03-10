#include "ChatOption.hpp"

const std::string ChatOption::TEXT = "text";
const std::string ChatOption::CATEGORY = "category";

ChatOption::ChatOption(const std::string text, const std::string category): text(text), category(category)
{ }

ChatOption::ChatOption(const nlohmann::json json):ChatOption(json[TEXT], json[CATEGORY])
{ }

nlohmann::json ChatOption::toJson() const
{
    nlohmann::json json;
    json[TEXT] = text;
    json[CATEGORY] = category;

    return json;
}
