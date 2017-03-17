#ifndef CHAT_OPTION_ENTITY_HPP
#define CHAT_OPTION_ENTITY_HPP

#include "ChatOption.hpp"
#include "TextEntity.hpp"

#include <SFML/Graphics/Font.hpp>
#include <memory>

class ChatOptionEntity : public TextEntity
{
public:
    ChatOptionEntity(sf::Font&, ChatOption);
    ~ChatOptionEntity();

    ChatOption getChatOption() const;

protected:
    /*
     * Draw the current entity on the RenderTarget.
     */
    void localDraw(sf::RenderTarget&, sf::RenderStates) const;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    void localUpdate(sf::Time dt);

private:
    ChatOption chatOption;
};

#endif
