#include "StateManager.hpp"
#include "CategorySelectState.hpp"

StateManager::StateManager(Context& context):
    context(context)
{
    //createState<CategorySelectState>(StateId::CATEGORY_SELECT);
    createState<CategorySelectState>(StateId::CATEGORY_SELECT);
}

bool StateManager::hasPendingState()
{
    /*
     * So interestingly enough, std::shared_ptr has an override to
     * "convert" to a bool in an if statement to tell if the ptr
     * is has a null reference or not. Apparently this is not called
     * if returning a bool.
     */
    if(pendingState)
        return true;
    return false;
}

std::shared_ptr<State> StateManager::getPendingState()
{
    std::shared_ptr<State> tmpState = pendingState;
    pendingState = std::shared_ptr<State>(nullptr);

    return tmpState;
}

void StateManager::registerPendingState(StateId id, std::function<void(State*)> stateConfig)
{
    auto stateItr = stateMap.find(id);
    std::shared_ptr<State> state;
    if(stateItr == stateMap.end())
        //YAY silently failing!
        return;
    state = stateItr->second;

    stateConfig(&(*state));
    state->init();

    pendingState = state;
}
