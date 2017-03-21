#ifndef TEXT_ENTITY_HPP
#define TEXT_ENTITY_HPP

#include "Entity.hpp"
#include "Timer.hpp"
#include "PositionModifier.hpp"
#include "ColorModifier.hpp"
#include "SizeModifier.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <memory>

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
     * Linearly change the size of the font over the specified time.
     */
    void registerSizeModifier(int, sf::Time);
    /*
     * Linearly change the color over the specified time.
     */
    void registerColorModifier(sf::Color, sf::Time);
    /*
     * Linearly move the text to position Vector2f on the screen over the time specified.
     */
    void registerPositionModifer(sf::Vector2f, sf::Time);
    void setSize(int);
    void setColor(sf::Color);
    void setString(std::string);
    std::string getString();
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
    std::unique_ptr<PositionModifier> positionModifier;
    std::unique_ptr<ColorModifier> colorModifier;
    std::unique_ptr<SizeModifier> sizeModifier;
};

typedef std::shared_ptr<TextEntity> SharedTextEntity;

#endif
