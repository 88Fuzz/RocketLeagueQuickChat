#include "ChatOptionSelectState.hpp"
#include "SingleChatOptionState.hpp"

ChatOptionSelectState::ChatOptionSelectState(StateManager* stateManager,
        Context& context): EntityListState(stateManager, context)
{
}

ChatOptionSelectState::~ChatOptionSelectState()
{
}

void ChatOptionSelectState::registerChatOptions(std::vector<SharedTextEntity>* chatOptions)
{
    resetState();
    for(auto entity: *chatOptions)
        addEntity(entity);
}

void ChatOptionSelectState::initLeft()
{
    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerDownListener(ButtonEvent::LEFT, [this](ButtonEvent buttonEvent)
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
    eventHandler.registerDownListener(buttonEvent, [this](ButtonEvent buttonEvent)
    {
        transitionOut([this]()
        {
            swapState(StateId::SINGLE_CHAT, [this](State* state)
            {
                SingleChatOptionState* singleState = dynamic_cast<SingleChatOptionState*>(state);
                //YAY error checking!
                singleState->registerChatOption(getSelectedItem(), &getCollection());
            });
        });
    });
}
