#include "State.hpp"

State::State(StateManager* stateManager, Context& context):
    context(context), stateManager(stateManager)
{
}

State::~State()
{
}

void State::swapState(StateId id, std::function<void(State*)> stateConfig)
{
    stateManager->registerPendingState(id, stateConfig);
}
