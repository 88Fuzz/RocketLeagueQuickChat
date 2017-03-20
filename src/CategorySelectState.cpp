#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <set>

CategorySelectState::CategorySelectState(Context& context,std::vector<ChatOption> chatOptions): State(context)
{
    sf::Vector2u windowSize = context.getWindow().getSize();
    int i = 0;
    std::set<ChatCategory> categorySet;
    for(auto chatOption: chatOptions)
    {
        ChatCategory category = chatOption.getCategory();

        if(categorySet.count(category) == 0)
        {
            int y = 60 * ++i;
            SharedTextEntity categoryEntity(new ChatCategoryEntity(context.getFont(), category));
            categoryEntity.get()->move(10,y);
            categoryEntity.get()->setTargetPosition(sf::Vector2f(500, 60), sf::seconds(i * 10));
            chatCategoryEntities.push_back(categoryEntity);
            categorySet.insert(category);
        }

        SharedTextEntity optionEntity(new ChatOptionEntity(context.getFont(), chatOption));
        auto chatOptionList = getOrCreateChatOptionList(category);
        chatOptionList.push_back(optionEntity);
    }
}

CategorySelectState::~CategorySelectState()
{
}

std::vector<SharedTextEntity>& CategorySelectState::getOrCreateChatOptionList(ChatCategory category)
{
        auto optionListItr = categoryMap.find(category);
        if(optionListItr == categoryMap.end())
        {
            auto optionList = std::vector<SharedTextEntity>();
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
