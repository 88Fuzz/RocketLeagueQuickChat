#include "TextEntity.hpp"
#include "MathUtils.hpp"

TextEntity::TextEntity(sf::Font& font, sf::Color color, std::string str): 
        targetPositionTimer(Timer(sf::seconds(0), false))
{
    text.setFont(font);
    setColor(color);
    setString(str);
}

TextEntity::~TextEntity()
{
}

void TextEntity::setTargetPosition(sf::Vector2f position, sf::Time time)
{
    targetStartPosition = getPosition();
    targetPosition = position;
    targetPositionTimer = Timer(time, true);
}

void TextEntity::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
    renderTarget.draw(text);
    localDraw(renderTarget, renderStates);
}

void TextEntity::update(sf::Time dt)
{
    if(!targetPositionTimer.timeExpired())
    {
        sf::Vector2f position = MathUtils::lerp(targetStartPosition, targetPosition, targetPositionTimer.getPercentElapsed());
        setPosition(position);
    }
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
