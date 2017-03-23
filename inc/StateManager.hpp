#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include "StateId.hpp"
#include "Context.hpp"

#include <map>
#include <functional>
#include <memory>

class State;

/*
 * Helper class to change the currently active state.
 */
class StateManager
{
public:
    StateManager(Context&);
    bool hasPendingState();
    std::shared_ptr<State> getPendingState();
    void registerPendingState(StateId, std::function<void(State*)>);
private:
    std::shared_ptr<State> pendingState;
    std::map<StateId, std::shared_ptr<State>> stateMap;
    Context& context;

    template<typename T> void createState(StateId);
};

template<typename T> void StateManager::createState(StateId id)
{
    std::shared_ptr<State> state = std::shared_ptr<State>(new T(this, context));
    stateMap[id] = state;
}

#endif
