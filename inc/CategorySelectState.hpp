#ifndef CATEGORY_SELECT_STATE_HPP
#define CATEGORY_SELECT_STATE_HPP

#include "ChatOption.hpp"
#include "ChatCategory.hpp"
#include "ChatCategoryEntity.hpp"
#include "ChatOptionEntity.hpp"
#include "SelectionHolder.hpp"
#include "VectorWrapper.hpp"
#include "State.hpp"

#include <SFML/Graphics/Color.hpp>
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
    static const SelectionHolder<int> SIZE_SELECT;
    static const SelectionHolder<sf::Color> COLOR_SELECT;
    static const sf::Color DESELECT_COLOR;
    static const sf::Time TRANSITION_TIME;

    std::map<ChatCategory, std::vector<SharedTextEntity>> categoryMap;
    std::unique_ptr<VectorWrapper<SharedTextEntity>> chatCategoryEntities;
    sf::Vector2u windowSize;
    int selectedItem;
    int previousSelectedItem;
    float verticalStart;
    float verticalMidpoint;
    float verticalOffset;

    std::vector<SharedTextEntity>& getOrCreateChatOptionList(ChatCategory);
    void initOffsets();
    void initSelections();
    void updatePositions(std::function<void(SharedTextEntity&, float, float)>);
    void updateSelectedItem();
};

#endif
