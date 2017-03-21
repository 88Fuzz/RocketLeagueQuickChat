#ifndef CATEGORY_SELECT_STATE_HPP
#define CATEGORY_SELECT_STATE_HPP

#include "ChatOption.hpp"
#include "ChatCategory.hpp"
#include "ChatCategoryEntity.hpp"
#include "ChatOptionEntity.hpp"
#include "VectorWrapper.hpp"
#include "State.hpp"

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <map>
#include <memory>
#include <functional>

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
    static const int ITEMS_TO_DISPLAY;

    std::map<ChatCategory, std::vector<SharedTextEntity>> categoryMap;
    std::unique_ptr<VectorWrapper<SharedTextEntity>> chatCategoryEntities;
    sf::Vector2u windowSize;
    int selectedItem;
    float verticalStart;
    float verticalMidpoint;
    float verticalOffset;

    std::vector<SharedTextEntity>& getOrCreateChatOptionList(ChatCategory);
    void initOffsets();
    void initPositions();
    void updatePositions(std::function<void(SharedTextEntity&, float, float)>);
    void updateSelectedItem();
};

#endif
