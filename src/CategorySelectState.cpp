#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"

#include <iostream>
#include <set>

CategorySelectState::CategorySelectState(Context& context,std::vector<ChatOption> chatOptions): State(context)
{
    int i = 0;
    std::set<ChatCategory> categorySet;
    for(auto chatOption: chatOptions)
    {
        ChatCategory category = chatOption.getCategory();

        if(categorySet.count(category) == 0)
        {
            SharedEntity categoryEntity(new ChatCategoryEntity(context.getFont(), category));
            categoryEntity.get()->move(10,60*i++);
            chatCategoryEntities.push_back(categoryEntity);
            categorySet.insert(category);
        }

        SharedEntity optionEntity(new ChatOptionEntity(context.getFont(), chatOption));
        auto chatOptionList = getOrCreateChatOptionList(category);
        chatOptionList.push_back(optionEntity);
    }
}

CategorySelectState::~CategorySelectState()
{
}

std::vector<SharedEntity>& CategorySelectState::getOrCreateChatOptionList(ChatCategory category)
{
        auto optionListItr = categoryMap.find(category);
        if(optionListItr == categoryMap.end())
        {
            auto optionList = std::vector<SharedEntity>();
            categoryMap[category] = optionList;
        }

        return categoryMap[category];
}

void CategorySelectState::draw(sf::RenderTarget& renderTarget,sf::RenderStates renderStates) const
{
    for(auto entity: chatCategoryEntities)
    {
        entity.get()->draw(renderTarget, renderStates);
    }
}

void CategorySelectState::update(sf::Time dt)
{
    for(auto entity: chatCategoryEntities)
    {
        entity.get()->update(dt);
    }
}
