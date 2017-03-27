#include "SingleChatOptionState.hpp"
#include "ChatOptionSelectState.hpp"
#include "SelectionConstants.hpp"

SingleChatOptionState::SingleChatOptionState(StateManager* stateManager, Context& context): 
    State(stateManager, context),verticalOffset(0)
{
    verticalOffset = context.getWindow().getSize().y / 2;
}

SingleChatOptionState::~SingleChatOptionState()
{
}

void SingleChatOptionState::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
    entity->draw(renderTarget, renderStates);
}

void SingleChatOptionState::update(sf::Time dt)
{
    entity->update(dt);
}

void SingleChatOptionState::init()
{
    context.getEventHandler().clearAllListeners();
    initBack(ButtonEvent::LEFT);
    initBack(ButtonEvent::SELECT);
    entity->setPositionAndCancelModifiers(SelectionConstants::DISPLAY_OFFSET.x, verticalOffset);
    entity->setSize(SelectionConstants::SIZE.selected);
    entity->setColor(SelectionConstants::COLOR.selected);

}

void SingleChatOptionState::initBack(ButtonEvent buttonEvent)
{
    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerDownListener(buttonEvent, [this](ButtonEvent buttonEvent)
    {
        swapState(StateId::CHAT_SELECT, [this](State* state) { });
    });
}


void SingleChatOptionState::registerChatOption(SharedTextEntity textEntity, std::vector<SharedTextEntity>* chatOptions)
{
    entity = textEntity;
    previousChatOptions = chatOptions;
}
