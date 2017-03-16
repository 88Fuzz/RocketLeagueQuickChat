#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

/*
 * Entity is the bast class that should be drawn on the screen.
 */
class Entity : public sf::Transformable, public sf:: Drawable
{
public:
    virtual ~Entity();
    /*
     * Draw the current entity on the RenderTarget.
     */
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const = 0;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    virtual void update(sf::Time dt) = 0;
};

typedef std::shared_ptr<Entity> SharedEntity;

#endif
