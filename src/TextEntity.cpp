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

void TextEntity::registerSizeModifier(int size, sf::Time time)
{
    sizeModifier = std::unique_ptr<SizeModifier>(new SizeModifier(this, time, text.getCharacterSize(), size));
}

void TextEntity::registerColorModifier(sf::Color color, sf::Time time)
{
    colorModifier = std::unique_ptr<ColorModifier>(new ColorModifier(this, time, text.getFillColor(), color));
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
    if(colorModifier)
    {
        if(colorModifier->modify())
            colorModifier = std::unique_ptr<ColorModifier>(nullptr);
    }
    if(sizeModifier)
    {
        if(sizeModifier->modify())
            sizeModifier = std::unique_ptr<SizeModifier>(nullptr);
    }

    text.setPosition(getPosition());
    localUpdate(dt);
}

void TextEntity::setSize(int size)
{
    text.setCharacterSize(size);
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
