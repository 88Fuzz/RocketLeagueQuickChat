#ifndef CATEGORY_ENTITY_HPP
#define CATEGORY_ENTITY_HPP

#include "TextEntity.hpp"
#include "ChatCategory.hpp"

#include <SFML/Graphics/Font.hpp>
#include <memory>

class ChatCategoryEntity : public TextEntity
{
public:
    ChatCategoryEntity(sf::Font&, ChatCategory);
    virtual ~ChatCategoryEntity();

    ChatCategory getChatCategory() const;
protected:
    /*
     * Draw the current entity on the RenderTarget.
     */
    virtual void localDraw(sf::RenderTarget&, sf::RenderStates) const;
    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    virtual void localUpdate(sf::Time);
private:
    ChatCategory chatCategory;
};


typedef std::shared_ptr<ChatCategoryEntity> SharedChatCategoryEntity;

#endif
