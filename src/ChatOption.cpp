#include "ChatOption.hpp"

const std::string ChatOption::TEXT = "text";
const std::string ChatOption::CATEGORY = "category";

nlohmann::json ChatOption::toJson() const
{
    nlohmann::json json;
    json[TEXT] = text;
    json[CATEGORY] = category;

    return json;
}
