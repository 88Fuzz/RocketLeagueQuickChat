#include "TextEntityModifier.hpp"

TextEntityModifier::TextEntityModifier(TextEntity* textEntity, sf::Time time): textEntity(textEntity), timer(time)
{
}

TextEntityModifier::~TextEntityModifier()
{
}

bool TextEntityModifier::modify()
{
    if(!timer.timeExpired())
    {
        doModify(timer.getPercentElapsed());
        return false;
    }
    doModify(100);

    return true;
}
