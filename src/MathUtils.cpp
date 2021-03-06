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
    return sf::Vector2f(lerp(a.x, b.x, placement),
            lerp(a.y, b.y, placement));
}

sf::Color MathUtils::lerp(sf::Color a, sf::Color b, float placement)
{
    placement = clamp(0, 1, placement);
    return sf::Color(lerp(a.r, b.r, placement),
            lerp(a.g, b.g, placement),
            lerp(a.b, b.b, placement),
            lerp(a.a, b.a, placement));
}

float MathUtils::clamp(float min, float max, float value)
{
    if(value < min)
        return min;
    else if(value > max)
        return max;
    return value;
}


