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
    CategorySelectState(Context&, std::vector<ChatOption>);
    ~CategorySelectState();

    /*
     * Draw anything on the RenderTarget.
     */
    void draw(sf::RenderTarget&, sf::RenderStates) const;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    void update(sf::Time dt);
private:
    std::map<ChatCategory, std::vector<SharedEntity>> categoryMap;
    std::vector<SharedEntity> chatCategoryEntities;

    std::vector<SharedEntity>& getOrCreateChatOptionList(ChatCategory);
};


#endif