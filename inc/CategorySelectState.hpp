#ifndef CATEGORY_SELECT_STATE_HPP
#define CATEGORY_SELECT_STATE_HPP

#include "ChatOption.hpp"
#include "ChatCategory.hpp"
#include "ChatCategoryEntity.hpp"
#include "ChatOptionEntity.hpp"
#include "VectorWrapper.hpp"
#include "EntityListState.hpp"

#include <SFML/Graphics/Color.hpp>
#include <vector>
#include <map>
#include <memory>
#include <functional>

class CategorySelectState : public EntityListState<SharedChatCategoryEntity>
{
public:
    CategorySelectState(StateManager*, Context&);
    ~CategorySelectState();

    void registerChatOptions(std::vector<ChatOption>);
protected:
    virtual void initSelect();
    virtual void initRight();
    void registerSelection(ButtonEvent);
private:
    std::map<ChatCategory, std::vector<SharedTextEntity>> categoryMap;

    std::vector<SharedTextEntity>& getOrCreateChatOptionList(ChatCategory);
};

#endif
