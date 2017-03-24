#include "ChatOptionSelectState.hpp"

ChatOptionSelectState::ChatOptionSelectState(StateManager* stateManager,
        Context& context): State(stateManager, context), displayList()
{
}

ChatOptionSelectState::~ChatOptionSelectState()
{
}

void ChatOptionSelectState::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
    for(auto entity: displayList)
        entity->draw(renderTarget, renderStates);
}

void ChatOptionSelectState::update(sf::Time dt)
{
    for(auto entity: displayList)
        entity->update(dt);
}

void ChatOptionSelectState::init()
{
}

void ChatOptionSelectState::registerChatOptions(std::vector<SharedTextEntity>* fuckBall)
{
    displayList = std::vector<SharedTextEntity>(*fuckBall);
}
