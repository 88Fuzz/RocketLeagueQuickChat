#include "TextEntity.hpp"
#include "MathUtils.hpp"

TextEntity::TextEntity(sf::Font& font, sf::Color color, std::string str): 
        previousTargetPositionTimerActive(false),
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
    previousTargetPositionTimerActive = true;
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
    else if(previousTargetPositionTimerActive)
    {
        previousTargetPositionTimerActive = false;
        setPosition(targetPosition);
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
