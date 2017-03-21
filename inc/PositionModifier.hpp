#ifndef POSITION_MODIFIER_HPP
#define POSITION_MODIFIER_HPP

#include "TextEntityModifier.hpp"
#include "MathUtils.hpp"

#include <SFML/System/Vector2.hpp>

class PositionModifier: public TextEntityModifier
{
public:
    PositionModifier(TextEntity*, sf::Time, sf::Vector2f, sf::Vector2f);
    virtual ~PositionModifier();
protected:
    virtual void doModify(float);
private:
    sf::Vector2f startPosition;
    sf::Vector2f endPosition;
};

#endif
