#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <SFML/System/Vector2.hpp>

class MathUtils
{
public:
    /*
     * Linearly interpolate between values a and b by placement amount.
     * If placement is 1, the return value is b if placement is 0,
     * the return value is a.
     */
    static float lerp(float a, float b, float placement);

    /*
     * Linearly interpolate between vector2f a and b by placement amount.
     * If placement is 1, the return value is b if placement is 0,
     * the return value is a.
     */
    static sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float placement);

    /*
     * returns min if value < min. Max if value is > max.
     * Value for anything else.
     */
    static float clamp(float min, float max, float value);
};

#endif
