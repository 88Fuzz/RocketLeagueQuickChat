#include "ColorModifier.hpp"
#include "MathUtils.hpp"
#include "TextEntity.hpp"

ColorModifier::ColorModifier(TextEntity* textEntity, sf::Time time, sf::Color startColor, sf::Color endColor):
    TextEntityModifier(textEntity, time), startColor(startColor), endColor(endColor)
{
}

ColorModifier::~ColorModifier()
{
}

void ColorModifier::doModify(float percent)
{
    sf::Color color = MathUtils::lerp(startColor, endColor, percent);
    textEntity->setColor(color);
}
