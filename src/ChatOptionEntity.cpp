#include "ChatOptionEntity.hpp"

ChatOptionEntity::ChatOptionEntity(sf::Font& font, ChatOption chatOption):chatOption(chatOption)
{
    text.setFont(font);

    text.setString(chatOption.getText());
    text.setColor(sf::Color::Red);
}

void ChatOptionEntity::draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const
{
    renderTarget.draw(text);
}

void ChatOptionEntity::update(sf::Time dt)
{
    text.setPosition(getPosition());
}

void ChatOptionEntity::setColor(sf::Color color)
{
    text.setColor(color);
}

const ChatOption ChatOptionEntity::getChatOption() const
{
    return chatOption;
}
