#include "JsonSerializeable.hpp"

std::string JsonSerializeable::toJsonString() const
{
    return toJson().dump();
}
