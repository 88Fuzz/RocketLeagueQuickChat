#ifndef CHAT_OPTION_SELECTION_STATE_HPP
#define CHAT_OPTION_SELECTION_STATE_HPP

#include "State.hpp"
#include "TextEntity.hpp"
#include "VectorWrapper.hpp"

#include <memory>

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
    std::unique_ptr<VectorWrapper<SharedTextEntity>> chatOptions;
    int selectedItem;
    int previousSelectedItem;
    float verticalOffset;

    void initOffsets();
    void initSelections();
    void updatePositions(std::function<void(SharedTextEntity&, float, float)>);
    void updateSelectedItem();
};

#endif
