#ifndef CATEGORY_SELECT_STATE_HPP
#define CATEGORY_SELECT_STATE_HPP

#include "ChatOption.hpp"
#include "ChatCategory.hpp"
#include "ChatCategoryEntity.hpp"
#include "ChatOptionEntity.hpp"
#include "VectorWrapper.hpp"
#include "State.hpp"
#include "StateManager.hpp"

#include <SFML/Graphics/Color.hpp>
#include <vector>
#include <map>
#include <memory>
#include <functional>

class CategorySelectState : public State
{
public:
    CategorySelectState(StateManager*, Context&);
    ~CategorySelectState();

    /*
     * Draw anything on the RenderTarget.
     */
    void draw(sf::RenderTarget&, sf::RenderStates) const;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    void update(sf::Time dt);

    void registerChatOptions(std::vector<ChatOption>);
    void init();
private:
    std::map<ChatCategory, std::vector<SharedTextEntity>> categoryMap;
    std::unique_ptr<VectorWrapper<SharedChatCategoryEntity>> chatCategoryEntities;
    int selectedItem;
    int previousSelectedItem;
    float verticalOffset;

    std::vector<SharedTextEntity>& getOrCreateChatOptionList(ChatCategory);
    void initOffsets();
    void initSelections();
    void updatePositions(std::function<void(SharedTextEntity&, float, float)>);
    void updateSelectedItem();
};

#endif
