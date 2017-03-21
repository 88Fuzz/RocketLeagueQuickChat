#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"

#include <set>

const int CategorySelectState::ITEMS_TO_DISPLAY = 5;

CategorySelectState::CategorySelectState(Context& context,std::vector<ChatOption> chatOptions):
        State(context), windowSize(context.getWindow().getSize()),
        selectedItem(0)
{
    std::vector<SharedTextEntity> categoryEntities;
    std::set<ChatCategory> categorySet;
    for(auto chatOption: chatOptions)
    {
        ChatCategory category = chatOption.getCategory();

        if(categorySet.count(category) == 0)
        {
            SharedTextEntity categoryEntity(new ChatCategoryEntity(context.getFont(), category));
            categoryEntities.push_back(categoryEntity);
            categorySet.insert(category);
        }

        SharedTextEntity optionEntity(new ChatOptionEntity(context.getFont(), chatOption));
        auto chatOptionList = getOrCreateChatOptionList(category);
        chatOptionList.push_back(optionEntity);
    }

    chatCategoryEntities = std::unique_ptr<VectorWrapper<SharedTextEntity>>(new VectorWrapper<SharedTextEntity>(categoryEntities));
    initOffsets();
    initPositions();
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
    for(auto entity: chatCategoryEntities.get()->getCollection())
    {
        entity.get()->draw(renderTarget, renderStates);
    }
}

void CategorySelectState::update(sf::Time dt)
{
    for(auto entity: chatCategoryEntities.get()->getCollection())
    {
        entity.get()->update(dt);
    }
}

void CategorySelectState::initOffsets()
{
    verticalMidpoint = windowSize.y / 2;
    verticalOffset = windowSize.y / ITEMS_TO_DISPLAY;
}

void CategorySelectState::initPositions()
{
    int x = 60;
    SharedTextEntity entity = chatCategoryEntities.get()->get(selectedItem);
    entity.get()->setPosition(x, verticalMidpoint);

    for(int i = 1; i <= ITEMS_TO_DISPLAY/2; i++)
    {
        entity = chatCategoryEntities.get()->get(selectedItem + i);
        entity.get()->setPosition(x, verticalMidpoint + verticalOffset * i);
    }

    for(int i = 1; i <= ITEMS_TO_DISPLAY/2; i++)
    {
        entity = chatCategoryEntities.get()->get(selectedItem - i);
        entity.get()->setPosition(x, verticalMidpoint - verticalOffset * i);
    }
}

