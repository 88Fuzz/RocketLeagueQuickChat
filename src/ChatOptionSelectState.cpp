#include "ChatOptionSelectState.hpp"

#include <iostream>

ChatOptionSelectState::ChatOptionSelectState(StateManager* stateManager,
        Context& context): EntityListState(stateManager, context)
{
}

ChatOptionSelectState::~ChatOptionSelectState()
{
}

void ChatOptionSelectState::registerChatOptions(std::vector<SharedTextEntity>* chatOptions)
{
    for(auto entity: *chatOptions)
        addEntity(entity);
}

void ChatOptionSelectState::initLeft()
{
    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerUpListener(ButtonEvent::LEFT, [this](ButtonEvent buttonEvent)
    {
        swapState(StateId::CATEGORY_SELECT, [this](State* state) { });
    });
}

void ChatOptionSelectState::initRight()
{
    registerSelection(ButtonEvent::RIGHT);
}

void ChatOptionSelectState::initSelect()
{
    registerSelection(ButtonEvent::SELECT);
}

void ChatOptionSelectState::registerSelection(ButtonEvent buttonEvent)
{
    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerUpListener(buttonEvent, [this](ButtonEvent buttonEvent)
    {
        std::cout << getSelectedItem()->getString() << "\n";
    });
}
