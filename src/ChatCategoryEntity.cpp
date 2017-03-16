#include "ChatCategoryEntity.hpp"
#include "ChatOptionHelper.hpp"

ChatCategoryEntity::ChatCategoryEntity(sf::Font& font, ChatCategory chatCategory): chatCategory(chatCategory)
{
    text.setFont(font);

    auto optionalString = ChatOptionHelper::toSerializeString(chatCategory);
    if(optionalString)
        text.setString(*optionalString);

    text.setColor(sf::Color::Red);
}

ChatCategoryEntity::~ChatCategoryEntity()
{
}

void ChatCategoryEntity::draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const
{
    renderTarget.draw(text);
}

void ChatCategoryEntity::update(sf::Time dt)
{
    text.setPosition(getPosition());
}

ChatCategory ChatCategoryEntity::getChatCategory() const
{
    return chatCategory;
}
