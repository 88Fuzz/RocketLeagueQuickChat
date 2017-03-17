#include "MathUtils.hpp"

float MathUtils::lerp(float a, float b, float placement)
{
    placement = clamp(0, 1, placement);
    float offset = (b - a) * placement;
    return a + offset;
}

sf::Vector2f MathUtils::lerp(sf::Vector2f a, sf::Vector2f b, float placement)
{
    placement = clamp(0, 1, placement);
    return sf::Vector2f(lerp(a.x, a.y, placement),
            lerp(b.x, b.y, placement));
}

float MathUtils::clamp(float min, float max, float value)
{
    if(value < min)
        return min;
    else if(value > max)
        return max;
    return value;
}


