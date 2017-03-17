#ifndef TEXT_ENTITY_HPP
#define TEXT_ENTITY_HPP

#include "Entity.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

/*
 * Class used to draw text on screen.
 */
class TextEntity : public Entity
{
public:
    TextEntity(sf::Font&, sf::Color, std::string);
    virtual ~TextEntity();
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    virtual void update(sf::Time);

    void setColor(sf::Color);
    void setString(std::string);
protected:
    /*
     * Draw the current entity on the RenderTarget.
     */
    virtual void localDraw(sf::RenderTarget&, sf::RenderStates) const = 0;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    virtual void localUpdate(sf::Time) = 0;
private:
    sf::Text text;
};

#endif
