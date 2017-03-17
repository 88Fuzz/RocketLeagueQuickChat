#include "ChatCategoryEntity.hpp"
#include "ChatOptionHelper.hpp"

ChatCategoryEntity::ChatCategoryEntity(sf::Font& font, ChatCategory chatCategory): TextEntity(font, sf::Color::Yellow, ""), chatCategory(chatCategory)
{
    auto optionalString = ChatOptionHelper::toSerializeString(chatCategory);
    if(optionalString)
        setString(*optionalString);
}

ChatCategoryEntity::~ChatCategoryEntity()
{
}

void ChatCategoryEntity::localDraw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const
{
}

void ChatCategoryEntity::localUpdate(sf::Time dt)
{
}

ChatCategory ChatCategoryEntity::getChatCategory() const
{
    return chatCategory;
}
