#ifndef ENUM_PARSER_HPP
#define ENUM_PARSER_HPP

#include <string>
#include <experimental/optional>
#include <map>

template <typename T> class EnumParser
{
public:
    EnumParser();
    std::experimental::optional<T> fromSerializeString(const std::string str);
    std::experimental::optional<std::string> toSerializeString(const T);

protected:
    std::map<std::string, T> enumMap;
};

#endif
