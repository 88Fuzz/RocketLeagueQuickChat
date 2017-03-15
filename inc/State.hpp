#ifndef STATE_HPP
#define STATE_HPP

#include "Context.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>

class State : public sf::Drawable
{
public:
    State(const Context&);

    /*
     * Draw anything on the RenderTarget.
     */
    virtual void draw(sf::RenderTarget&,const sf::RenderStates) const = 0;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    virtual void update(const sf::Time dt) = 0;
protected:
    const Context& context;
};

#endif
