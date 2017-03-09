#ifndef TEST_OBJECT_HPP
#define TEST_OBJECT_HPP

#include "JsonSerializeable.hpp"

#include <string>

class ChatOption: public JsonSerializeable
{
public:
    nlohmann::json toJson() const;
    std::string text;
    std::string category;

private:
    static const std::string TEXT;
    static const std::string CATEGORY;
};

#endif
