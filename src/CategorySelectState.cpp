#include "CategorySelectState.hpp"
#include "ChatOptionSelectState.hpp"
#include "SelectionConstants.hpp"

#include <set>
#include <iostream>

CategorySelectState::CategorySelectState(StateManager* stateManager, Context& context):
        State(stateManager, context),
        selectedItem(0), previousSelectedItem(0)
{
}

CategorySelectState::~CategorySelectState()
{
}

void CategorySelectState::init()
{
    initOffsets();
    initSelections();
}

void CategorySelectState::registerChatOptions(std::vector<ChatOption> chatOptions)
{
    std::vector<SharedChatCategoryEntity> categoryEntities;
    std::set<ChatCategory> categorySet;
    for(auto chatOption: chatOptions)
    {
        ChatCategory category = chatOption.getCategory();

        if(categorySet.count(category) == 0)
        {
            SharedChatCategoryEntity categoryEntity(new ChatCategoryEntity(context.getFont(), category));
            categoryEntities.push_back(categoryEntity);
            categorySet.insert(category);
        }

        SharedTextEntity optionEntity(new ChatOptionEntity(context.getFont(), chatOption));
        getOrCreateChatOptionList(category);
        categoryMap[category].push_back(optionEntity);
    }

    chatCategoryEntities = std::unique_ptr<VectorWrapper<SharedChatCategoryEntity>>(
            new VectorWrapper<SharedChatCategoryEntity>(categoryEntities));

    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerDownListener(ButtonEvent::DOWN, [this](ButtonEvent buttonEvent)
    {
        previousSelectedItem = selectedItem;
        selectedItem -=1;
        if(selectedItem < 0)
            selectedItem = chatCategoryEntities->size() - 1;

        std::cout << "UP max size " << chatCategoryEntities->size() << " selection " << selectedItem << "\n";
        updateSelectedItem();
    });
    eventHandler.registerDownListener(ButtonEvent::UP, [this](ButtonEvent buttonEvent)
    {
        previousSelectedItem = selectedItem;
        selectedItem +=1;
        if(selectedItem >= chatCategoryEntities->size())
            selectedItem = 0;

        std::cout << "DOWN max size " << chatCategoryEntities->size() << " selection " << selectedItem << "\n";
        updateSelectedItem();
    });
    eventHandler.registerUpListener(ButtonEvent::SELECT, [this](ButtonEvent buttonEvent)
    {
        swapState(StateId::CHAT_SELECT, [this](State* state)
        {
            auto chatEntities = getOrCreateChatOptionList(chatCategoryEntities->get(selectedItem)
                    ->getChatCategory());
            ChatOptionSelectState* selectState = dynamic_cast<ChatOptionSelectState*>(state);
            //Yay error checking!

            selectState->registerChatOptions(&chatEntities);
        });
    });
}

std::vector<SharedTextEntity>& CategorySelectState::getOrCreateChatOptionList(ChatCategory category)
{
    auto optionListItr = categoryMap.find(category);
    if(optionListItr == categoryMap.end())
        categoryMap.insert(std::pair<ChatCategory, std::vector<SharedTextEntity>>(category,
                    std::vector<SharedTextEntity>()));

    return categoryMap[category];
}

void CategorySelectState::draw(sf::RenderTarget& renderTarget,sf::RenderStates renderStates) const
{
    for(auto entity: chatCategoryEntities->getCollection())
    {
        entity->draw(renderTarget, renderStates);
    }
}

void CategorySelectState::update(sf::Time dt)
{
    for(auto entity: chatCategoryEntities->getCollection())
    {
        entity->update(dt);
    }
}

void CategorySelectState::initOffsets()
{
    verticalOffset = context.getWindow().getSize().y / SelectionConstants::ITEMS_TO_DISPLAY;
}

void CategorySelectState::initSelections()
{
    for(auto entity: chatCategoryEntities->getCollection())
    {
        entity->setColor(SelectionConstants::COLOR.deselected);
        entity->setSize(SelectionConstants::SIZE.deselected);
    }

    chatCategoryEntities->get(selectedItem)->setColor(SelectionConstants::COLOR.selected);
    chatCategoryEntities->get(selectedItem)->setSize(SelectionConstants::SIZE.selected);
    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->setPosition(x, y);
    });
}

void CategorySelectState::updateSelectedItem()
{
    chatCategoryEntities->get(selectedItem)->registerColorModifier(
            SelectionConstants::COLOR.selected, SelectionConstants::SELECTION_TRANSITION_TIME);
    chatCategoryEntities->get(previousSelectedItem)->registerColorModifier(
            SelectionConstants::COLOR.deselected, SelectionConstants::SELECTION_TRANSITION_TIME);

    chatCategoryEntities->get(selectedItem)->registerSizeModifier(
            SelectionConstants::SIZE.selected, SelectionConstants::SELECTION_TRANSITION_TIME);
    chatCategoryEntities->get(previousSelectedItem)->registerSizeModifier(
            SelectionConstants::SIZE.deselected, SelectionConstants::SELECTION_TRANSITION_TIME);

    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->registerPositionModifer(sf::Vector2f(x, y), SelectionConstants::SELECTION_TRANSITION_TIME);
    });
}

void CategorySelectState::updatePositions(std::function<void(SharedTextEntity&, float, float)> processor)
{
    sf::Vector2f offset = SelectionConstants::DISPLAY_OFFSET;
    SharedTextEntity entity = chatCategoryEntities->get(selectedItem);
    processor(entity, offset.x, offset.y);

    for(int i = 1; i < SelectionConstants::ITEMS_TO_DISPLAY; i++)
    {
        entity = chatCategoryEntities->get(selectedItem + i);
        processor(entity, offset.x, offset.y + verticalOffset * i);
    }
}
