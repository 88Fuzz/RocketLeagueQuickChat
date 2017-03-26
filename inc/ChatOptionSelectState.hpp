#ifndef CHAT_OPTION_SELECTION_STATE_HPP
#define CHAT_OPTION_SELECTION_STATE_HPP

#include "EntityListState.hpp"
#include "TextEntity.hpp"
#include "VectorWrapper.hpp"

#include <memory>

class ChatOptionSelectState : public EntityListState<SharedTextEntity>
{
public:
    ChatOptionSelectState(StateManager*, Context&);
    virtual ~ChatOptionSelectState();

    void registerChatOptions(std::vector<SharedTextEntity>*);
protected:
    void initLeft();
    void initRight();
    void initSelect();
private:
    void registerSelection(ButtonEvent);
};

#endif
