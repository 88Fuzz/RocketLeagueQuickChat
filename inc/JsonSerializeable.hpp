#ifndef JSON_SERIALIZEABLE_HPP
#define JSON_SERIALIZEABLE_HPP

#include "json/json.hpp"

#include <string>

/*
 * Any data that needs to be serialized to json should implement this class.
 */
class JsonSerializeable
{
public:
    /*
     * Method called to convert the class into a json object.
     */
    virtual nlohmann::json toJson() const = 0;

    /*
     * Method called to convert the class into a json string.
     */
    std::string toJsonString() const;
};

#endif
