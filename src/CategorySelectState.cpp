#include "CategorySelectState.hpp"
#include "ChatOptionSelectState.hpp"
#include "SelectionConstants.hpp"

#include <set>
#include <iostream>

CategorySelectState::CategorySelectState(StateManager* stateManager, Context& context):
        EntityListState(stateManager, context)
{
}

CategorySelectState::~CategorySelectState()
{
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
            addEntity(categoryEntity);
            categorySet.insert(category);
        }

        SharedTextEntity optionEntity(new ChatOptionEntity(context.getFont(), chatOption));
        getOrCreateChatOptionList(category);
        categoryMap[category].push_back(optionEntity);
    }
}

void CategorySelectState::initSelect()
{
    registerSelection(ButtonEvent::SELECT);
}

void CategorySelectState::initRight()
{
    registerSelection(ButtonEvent::RIGHT);
}

void CategorySelectState::registerSelection(ButtonEvent buttonEvent)
{
    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerDownListener(buttonEvent, [this](ButtonEvent buttonEvent)
    {
        transitionOut([this]()
        {
            swapState(StateId::CHAT_SELECT, [this](State* state)
            {
                auto chatEntities = getOrCreateChatOptionList(getSelectedItem()->getChatCategory());
                ChatOptionSelectState* selectState = dynamic_cast<ChatOptionSelectState*>(state);
                //Yay error checking!

                selectState->registerChatOptions(&chatEntities);
            });
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
