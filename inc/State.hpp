#ifndef STATE_HPP
#define STATE_HPP

#include "Context.hpp"
#include "StateId.hpp"
#include "StateManager.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <functional>

class State : public sf::Drawable
{
public:
    State(StateManager*, Context&);
    virtual ~State();

    /*
     * Draw anything on the RenderTarget.
     */
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const = 0;

    /*
     * Called once every tick to update the entity, with the time since the last update call.
     */
    virtual void update(sf::Time dt) = 0;

    /*
     * Called after construction but before any draw or update calls. Alsao called after the
     * state is brought to the top of the stack.
     */
    virtual void init() = 0;

protected:
    void swapState(StateId, std::function<void(State*)>);
    Context& context;
private:
    StateManager* stateManager;
};

#endif
