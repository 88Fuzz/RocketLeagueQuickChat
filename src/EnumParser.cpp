#include "EnumParser.hpp"
#include "ChatCategory.hpp"

template <typename T> std::experimental::optional<T> EnumParser<T>::fromSerializeString(const std::string str)
{
    typename std::map<std::string, T>::const_iterator itr = enumMap.find(str);

    if(itr == enumMap.end())
        return {};

    return itr.second;
}

template <typename T> std::experimental::optional<std::string> EnumParser<T>::toSerializeString(const T enumVal)
{
    //TODO implement later!!
    return {};
}

template<> EnumParser<ChatCategory>::EnumParser()
{
    enumMap["INFORMATION"] = INFORMATION;
    enumMap["COMPLIMENTS"] = COMPLIMENTS;
    enumMap["REACTIONS"] = REACTIONS;
    enumMap["APOLOGIES"] = APOLOGIES;
    enumMap["POST_GAME"] = POST_GAME;
    enumMap["END_ENUM"] = END_ENUM;
}
