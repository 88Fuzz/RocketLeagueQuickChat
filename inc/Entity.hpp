#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

/*
 * Entity is the bast class that should be drawn on the screen.
 */
class Entity : public sf::Transformable, public sf:: Drawable
{
    /*
     * Draw the current entity on the RenderTarget.
     */
    virtual void Draw(RenderTarget &, RenderStates) const = 0;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    virtual void Update(sf::Time dt) = 0;
}
