#include "SizeModifier.hpp"
#include "MathUtils.hpp"
#include "TextEntity.hpp"

SizeModifier::SizeModifier(TextEntity* textEntity, sf::Time time, int startSize, int endSize): TextEntityModifier(textEntity, time),
    startSize(startSize), endSize(endSize)
{
}

SizeModifier::~SizeModifier()
{
}

void SizeModifier::doModify(float percent)
{
    int size = MathUtils::lerp(startSize, endSize, percent);
    textEntity->setSize(size);
}
