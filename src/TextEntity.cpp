#include "TextEntity.hpp"

TextEntity::TextEntity(sf::Font& font, sf::Color color, std::string str)
{
    text.setFont(font);
    setColor(color);
    setString(str);
}

TextEntity::~TextEntity()
{

}

void TextEntity::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
    renderTarget.draw(text);
    localDraw(renderTarget, renderStates);
}

void TextEntity::update(sf::Time dt)
{
    text.setPosition(getPosition());
    localUpdate(dt);
}

void TextEntity::setColor(sf::Color color)
{
    text.setFillColor(color);
    text.setOutlineColor(color);
}

void TextEntity::setString(std::string str)
{
    text.setString(str);
}
