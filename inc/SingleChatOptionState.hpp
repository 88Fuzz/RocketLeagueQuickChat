#ifndef SINGLE_CHAT_OPTION_STATE_HPP
#define SINGLE_CHAT_OPTION_STATE_HPP

#include "State.hpp"
#include "TextEntity.hpp"
#include "ButtonEvent.hpp"

#include <vector>

class SingleChatOptionState: public State
{
public:
    SingleChatOptionState(StateManager*, Context&);
    virtual ~SingleChatOptionState();

    void draw(sf::RenderTarget&,sf::RenderStates) const;
    void update(sf::Time dt);
    void init();
    void registerChatOption(SharedTextEntity, std::vector<SharedTextEntity>*);

private:
    float verticalOffset;
    SharedTextEntity entity;
    std::vector<SharedTextEntity>* previousChatOptions;

    void initBack(ButtonEvent);
};

#endif
