#ifndef TEXT_ENTITY_HPP
#define TEXT_ENTITY_HPP

#include "Entity.hpp"
#include "Timer.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

/*
 * Class used to draw text on screen.
 */
class TextEntity : public Entity
{
public:
    TextEntity(sf::Font&, sf::Color, std::string);
    virtual ~TextEntity();

    /*
     * Draws the text on the screen.
     */
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    /*
     * Updates the Text information every tick.
     */
    virtual void update(sf::Time);

    /*
     * Linearly move the text to position Vector2f on the screen over the time specified.
     */
    void setTargetPosition(sf::Vector2f, sf::Time);
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
    sf::Vector2f targetStartPosition;
    sf::Vector2f targetPosition;
    Timer targetPositionTimer;
};

typedef std::shared_ptr<TextEntity> SharedTextEntity;

#endif