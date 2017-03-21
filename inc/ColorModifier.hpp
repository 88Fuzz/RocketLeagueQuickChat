#ifndef COLOR_MODIFIER_HPP
#define COLOR_MODIFIER_HPP

#include "TextEntityModifier.hpp"

#include <SFML/Graphics/Color.hpp>

class ColorModifier: public TextEntityModifier
{
public:
    ColorModifier(TextEntity*, sf::Time, sf::Color, sf::Color);
    ~ColorModifier();
protected:
    virtual void doModify(float);
private:
    sf::Color startColor;
    sf::Color endColor;
};

#endif
