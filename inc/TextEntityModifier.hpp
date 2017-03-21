#ifndef TEXT_ENTITY_MODIFIER_HPP
#define TEXT_ENTITY_MODIFIER_HPP

#include "Timer.hpp"

#include <SFML/System/Time.hpp>

class TextEntity;

class TextEntityModifier
{
public:
    TextEntityModifier(TextEntity*, sf::Time);
    ~TextEntityModifier();
    /*
     * Modifies the saved textEntity. Returns true if the modifications are finished.
     */
    bool modify();
protected:
    /*
     * Modify the textEntity however necessary. Input is the percent the timer has completed.
     * The method will always be called with 100 once the time has expired.
     */
    virtual void doModify(float) = 0;
    TextEntity* textEntity;
private:
    Timer timer;
};

#endif
