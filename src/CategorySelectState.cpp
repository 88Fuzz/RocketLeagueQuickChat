#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"

#include <iostream>

CategorySelectState::CategorySelectState(const Context& context,const std::vector<ChatOption> chatOptions): State(context)
{
    int i = 0;
    for(const auto chatOption: chatOptions)
    {
        ChatCategory category = chatOption.getCategory();

        SharedChatCategoryEntity categoryEntity(new ChatCategoryEntity(context.getFont(), category));
        categoryEntity.get()->move(10,60*i++);
        chatCategoryEntities.push_back(categoryEntity);


        ChatOptionEntity* optionEntity = new ChatOptionEntity(context.getFont(), chatOption);
        auto chatOptionList = getOrCreateChatOptionList(category);
        chatOptionList.push_back(optionEntity);

        //SharedChatOptionEntity optionEntity(new ChatOptionEntity(context.getFont(), chatOption));
        //auto chatOptionList = getOrCreateChatOptionList(category);
        //chatOptionList.push_back(optionEntity);
    }
}

//std::vector<SharedChatOptionEntity>& CategorySelectState::getOrCreateChatOptionList(const ChatCategory category)
std::vector<ChatOptionEntity*>& CategorySelectState::getOrCreateChatOptionList(const ChatCategory category)
{
        const auto optionListItr = categoryMap.find(category);
        if(optionListItr == categoryMap.end())
        {
            const auto optionList = std::vector<ChatOptionEntity*>();
            categoryMap[category] = optionList;
        }

        return categoryMap[category];
}

void CategorySelectState::draw(sf::RenderTarget& renderTarget,const sf::RenderStates renderStates) const
{
    for(const auto entity: chatCategoryEntities)
    {
        entity.get()->draw(renderTarget, renderStates);
    }
}

void CategorySelectState::update(const sf::Time dt)
{
    for(const auto entity: chatCategoryEntities)
    {
        entity.get()->update(dt);
    }
}
