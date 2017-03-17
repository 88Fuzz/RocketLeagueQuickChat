#include "ChatOptionEntity.hpp"

ChatOptionEntity::ChatOptionEntity(sf::Font& font, ChatOption chatOption):TextEntity(font, sf::Color::Yellow, chatOption.getText()), chatOption(chatOption)
{
}
ChatOptionEntity::~ChatOptionEntity()
{
}

void ChatOptionEntity::localDraw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const
{
}

void ChatOptionEntity::localUpdate(sf::Time dt)
{
}

ChatOption ChatOptionEntity::getChatOption() const
{
    return chatOption;
}
