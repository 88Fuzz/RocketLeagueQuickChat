#include "PositionModifier.hpp"
#include "TextEntity.hpp"
#include "MathUtils.hpp"

PositionModifier::PositionModifier(TextEntity* textEntity, sf::Time time, sf::Vector2f startPosition, sf::Vector2f endPosition):
    TextEntityModifier(textEntity, time), startPosition(startPosition),
    endPosition(endPosition)
{
}

PositionModifier::~PositionModifier()
{
}

void PositionModifier::doModify(float percent)
{
    sf::Vector2f position = MathUtils::lerp(startPosition, endPosition, percent);
    textEntity->setPosition(position);
}
