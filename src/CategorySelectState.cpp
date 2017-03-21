#include "CategorySelectState.hpp"
#include "ChatOptionHelper.hpp"

#include <set>
#include <iostream>

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


    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerDownListener(ButtonEvent::DOWN, [this](ButtonEvent buttonEvent)
    {
        selectedItem -=1;
        if(selectedItem < 0)
            selectedItem = chatCategoryEntities->size() - 1;

        std::cout << "UP max size " << chatCategoryEntities->size() << " selection " << selectedItem << "\n";
        updateSelectedItem();
    });
    eventHandler.registerDownListener(ButtonEvent::UP, [this](ButtonEvent buttonEvent)
    {
        selectedItem +=1;
        if(selectedItem >= chatCategoryEntities->size())
            selectedItem = 0;

        std::cout << "DOWN max size " << chatCategoryEntities->size() << " selection " << selectedItem << "\n";
        updateSelectedItem();
    });
    eventHandler.registerUpListener(ButtonEvent::SELECT, [this](ButtonEvent buttonEvent)
    {
        std::cout << "Selected item is " << chatCategoryEntities->get(selectedItem)->getString() << "\n";
    });
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
    for(auto entity: chatCategoryEntities->getCollection())
    {
        entity->draw(renderTarget, renderStates);
    }
}

void CategorySelectState::update(sf::Time dt)
{
    for(auto entity: chatCategoryEntities->getCollection())
    {
        entity->update(dt);
    }
}

void CategorySelectState::initOffsets()
{
    verticalStart = 40;
    verticalMidpoint = windowSize.y / 2;
    verticalOffset = windowSize.y / ITEMS_TO_DISPLAY;
}

void CategorySelectState::initPositions()
{
    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->setPosition(x, y);
    });
}

void CategorySelectState::updateSelectedItem()
{
    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->registerPositionModifer(sf::Vector2f(x, y), sf::seconds(.7f));
    });
}

void CategorySelectState::updatePositions(std::function<void(SharedTextEntity&, float, float)> processor)
{
    float x = verticalStart;
    SharedTextEntity entity = chatCategoryEntities->get(selectedItem);
    processor(entity, x, verticalStart);

    for(int i = 1; i < ITEMS_TO_DISPLAY; i++)
    {
        entity = chatCategoryEntities->get(selectedItem + i);
        processor(entity, x, verticalStart + verticalOffset * i);
    }

    /*processor(entity, x, verticalMidpoint);

    for(int i = 1; i <= ITEMS_TO_DISPLAY/2; i++)
    {
        entity = chatCategoryEntities->get(selectedItem + i);
        processor(entity, x, verticalMidpoint + verticalOffset * i);
    }

    for(int i = 1; i <= ITEMS_TO_DISPLAY/2; i++)
    {
        entity = chatCategoryEntities->get(selectedItem - i);
        processor(entity, x, verticalMidpoint - verticalOffset * i);
    }*/
}
