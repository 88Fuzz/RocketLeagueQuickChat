#ifndef CHAT_OPTION_SELECTION_STATE_HPP
#define CHAT_OPTION_SELECTION_STATE_HPP

#include "State.hpp"
#include "TextEntity.hpp"

class ChatOptionSelectState : public State
{
public:
    ChatOptionSelectState(StateManager*, Context&);
    virtual ~ChatOptionSelectState();

    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void update(sf::Time);
    void init();
    void registerChatOptions(std::vector<SharedTextEntity>*);
private:
    std::vector<SharedTextEntity> displayList;
};

#endif
