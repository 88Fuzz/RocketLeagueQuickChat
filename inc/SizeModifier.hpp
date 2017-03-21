#ifndef SIZE_MODIFIER_HPP
#define SIZE_MODIFIER_HPP

#include "TextEntityModifier.hpp"

class SizeModifier: public TextEntityModifier
{
public:
    SizeModifier(TextEntity*, sf::Time, int, int);
    ~SizeModifier();
protected:
    virtual void doModify(float);
private:
    int startSize;
    int endSize;
};

#endif
