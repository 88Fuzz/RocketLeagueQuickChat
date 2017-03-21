#include "TextEntity.hpp"
#include "MathUtils.hpp"

TextEntity::TextEntity(sf::Font& font, sf::Color color, std::string str)
{
    text.setFont(font);
    setColor(color);
    setString(str);
}

TextEntity::~TextEntity()
{
}

void TextEntity::registerPositionModifer(sf::Vector2f position, sf::Time time)
{
    positionModifier = std::unique_ptr<PositionModifier>(new PositionModifier(this, time, getPosition(), position));
}

void TextEntity::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
    renderTarget.draw(text);
    localDraw(renderTarget, renderStates);
}

void TextEntity::update(sf::Time dt)
{
    if(positionModifier)
    {
        if(positionModifier->modify())
            positionModifier = std::unique_ptr<PositionModifier>(nullptr);
    }

    text.setPosition(getPosition());
    localUpdate(dt);
}

void TextEntity::setColor(sf::Color color)
{
    text.setFillColor(color);
    text.setOutlineColor(color);
}

std::string TextEntity::getString()
{
    return text.getString();
}

void TextEntity::setString(std::string str)
{
    text.setString(str);
}
