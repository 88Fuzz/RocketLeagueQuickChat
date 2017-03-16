#ifndef CHAT_OPTION_ENTITY_HPP
#define CHAT_OPTION_ENTITY_HPP

#include "ChatOption.hpp"
#include "Entity.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

class ChatOptionEntity : public Entity
{
public:
    ChatOptionEntity(sf::Font&, ChatOption);
    ~ChatOptionEntity();
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

    ChatOption getChatOption() const;
private:
    sf::Text text;
    ChatOption chatOption;
};

#endif
