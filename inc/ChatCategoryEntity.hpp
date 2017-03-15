#ifndef CATEGORY_ENTITY_HPP
#define CATEGORY_ENTITY_HPP

#include "Entity.hpp"
#include "ChatCategory.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

class ChatCategoryEntity : public Entity
{
public:
    ChatCategoryEntity(sf::Font&, const ChatCategory);
    /*
     * Draw the current entity on the RenderTarget.
     */
    void draw(sf::RenderTarget&, sf::RenderStates) const;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    void update(sf::Time dt);

    /*
     * Set the color of the text
     */
    void setColor(sf::Color);

    const ChatCategory getChatCategory() const;
private:
    sf::Text text;
    const ChatCategory chatCategory;
};

typedef std::shared_ptr<ChatCategoryEntity> SharedChatCategoryEntity;

#endif
