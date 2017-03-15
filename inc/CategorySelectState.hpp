#ifndef CATEGORY_SELECT_STATE_HPP
#define CATEGORY_SELECT_STATE_HPP

#include "ChatOption.hpp"
#include "ChatCategory.hpp"
#include "ChatCategoryEntity.hpp"
#include "ChatOptionEntity.hpp"
#include "State.hpp"

#include <vector>
#include <map>

class CategorySelectState : public State
{
public:
    CategorySelectState(const Context&, const std::vector<ChatOption>);

    /*
     * Draw anything on the RenderTarget.
     */
    void draw(sf::RenderTarget&, const sf::RenderStates) const;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    void update(const sf::Time dt);
private:
    std::map<ChatCategory, std::vector<ChatOptionEntity *>> categoryMap;
    std::vector<SharedChatCategoryEntity> chatCategoryEntities;

    std::vector<ChatOptionEntity *>& getOrCreateChatOptionList(const ChatCategory);
};


#endif
