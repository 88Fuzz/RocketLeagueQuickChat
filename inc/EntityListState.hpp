#ifndef ENTITY_LIST_STATE_HPP
#define ENTITY_LIST_STATE_HPP

#include "State.hpp"
#include "VectorWrapper.hpp"
#include "SelectionConstants.hpp"
#include "TextEntity.hpp"

template<typename T> class EntityListState: public State
{
public:
    EntityListState(StateManager*, Context& ); 
    virtual ~EntityListState();
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void update(sf::Time);
    void init();

protected:
    T getSelectedItem();
    void resetState();
    void addEntity(T entity);
    std::vector<T>& getCollection();

    void transitionOut(std::function<void()>);
    virtual void initUp();
    virtual void initDown();
    virtual void initLeft();
    virtual void initRight();
    virtual void initSelect();

private:
    int selectedItem;
    int previousSelectedItem;
    float verticalOffset;
    float verticalMidpoint;
    std::unique_ptr<VectorWrapper<T>> entities;
    std::function<void()> transitionFinisher;

    void initEvents();
    void initSelections();
    void updateSelectedItem();
    void updatePositions(std::function<void(SharedTextEntity&, float, float)>);
};

template<typename T> EntityListState<T>::EntityListState(StateManager* stateManager, Context& context): 
    State(stateManager, context), selectedItem(0), previousSelectedItem(0),
    verticalOffset(0), entities(new VectorWrapper<T>(std::vector<T>())), transitionFinisher(nullptr)
{
    verticalOffset = context.getWindow().getSize().y / SelectionConstants::ITEMS_TO_DISPLAY;
    verticalMidpoint = context.getWindow().getSize().y / 2;
}

template<typename T> EntityListState<T>::~EntityListState()
{
}

template<typename T> void EntityListState<T>::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
    for(auto entity: entities->getCollection())
        entity->draw(renderTarget, renderStates);
}

template<typename T> void EntityListState<T>::update(sf::Time dt)
{
    for(auto entity: entities->getCollection())
        entity->update(dt);

    if(transitionFinisher)
    {
        bool stateFinished = true;
        for(auto entity: entities->getCollection())
        {
            if(entity->hasActiveModifiers())
            {
                stateFinished = false;
                break;
            }
        }

        if(stateFinished)
            transitionFinisher();
    }
}

template<typename T> void EntityListState<T>::init()
{
    transitionFinisher = nullptr;
    initEvents();
    initSelections();
}

template<typename T> void EntityListState<T>::transitionOut(std::function<void()> transitionFinisher)
{
    for(auto entity: entities->getCollection())
    {
        entity->registerSizeModifier(0, SelectionConstants::SELECTION_TRANSITION_TIME);
        entity->registerPositionModifier(sf::Vector2f(-SelectionConstants::DISPLAY_OFFSET.x,verticalMidpoint),
                SelectionConstants::SELECTION_TRANSITION_TIME);
    }

    context.getEventHandler().clearAllListeners();
    this->transitionFinisher = transitionFinisher;
}

template<typename T> void EntityListState<T>::initEvents()
{
    context.getEventHandler().clearAllListeners();
    initUp();
    initDown();
    initLeft();
    initRight();
    initSelect();
}

template<typename T> void EntityListState<T>::initUp()
{
    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerDownListener(ButtonEvent::UP, [this](ButtonEvent buttonEvent)
    {
        previousSelectedItem = selectedItem;
        selectedItem +=1;
        if(selectedItem >= entities->size())
            selectedItem = 0;

        updateSelectedItem();
    });
}

template<typename T> void EntityListState<T>::initDown()
{
    EventHandler& eventHandler = context.getEventHandler();
    eventHandler.registerDownListener(ButtonEvent::DOWN, [this](ButtonEvent buttonEvent)
    {
        previousSelectedItem = selectedItem;
        selectedItem -=1;
        if(selectedItem < 0)
            selectedItem = entities->size() - 1;

        updateSelectedItem();
    });
}

template<typename T> void EntityListState<T>::initLeft()
{
}

template<typename T> void EntityListState<T>::initRight()
{
}

template<typename T> void EntityListState<T>::initSelect()
{
}

template<typename T> T EntityListState<T>::getSelectedItem()
{
    return entities->get(selectedItem);
}

template<typename T> void EntityListState<T>::resetState()
{
    entities->getCollection().clear();
    selectedItem = 0;
    previousSelectedItem = 0;
}

template<typename T> void EntityListState<T>::addEntity(T entity)
{
    entities->getCollection().push_back(entity);
}

template<typename T> std::vector<T>& EntityListState<T>::getCollection()
{
    return entities->getCollection();
}

template<typename T> void EntityListState<T>::initSelections()
{
    for(auto entity: entities->getCollection())
    {
        entity->setPositionAndCancelModifiers(0, verticalMidpoint);
        entity->setColor(SelectionConstants::COLOR.deselected);
        entity->setSize(0);
        entity->registerSizeModifier(SelectionConstants::SIZE.deselected,
                SelectionConstants::SELECTION_TRANSITION_TIME);
    }

    entities->get(selectedItem)->setColor(SelectionConstants::COLOR.selected);
    entities->get(selectedItem)->registerSizeModifier(SelectionConstants::SIZE.deselected,
            SelectionConstants::SELECTION_TRANSITION_TIME);
    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->registerPositionModifier(sf::Vector2f(x, y),
                SelectionConstants::SELECTION_TRANSITION_TIME);
    });
}

template<typename T> void EntityListState<T>::updateSelectedItem()
{
    entities->get(selectedItem)->registerColorModifier(
            SelectionConstants::COLOR.selected, SelectionConstants::SELECTION_TRANSITION_TIME);
    entities->get(previousSelectedItem)->registerColorModifier(
            SelectionConstants::COLOR.deselected, SelectionConstants::SELECTION_TRANSITION_TIME);

    entities->get(selectedItem)->registerSizeModifier(
            SelectionConstants::SIZE.selected, SelectionConstants::SELECTION_TRANSITION_TIME);
    entities->get(previousSelectedItem)->registerSizeModifier(
            SelectionConstants::SIZE.deselected, SelectionConstants::SELECTION_TRANSITION_TIME);

    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->registerPositionModifier(sf::Vector2f(x, y), SelectionConstants::SELECTION_TRANSITION_TIME);
    });
}


template<typename T> void EntityListState<T>::updatePositions(std::function<void(SharedTextEntity&, float, float)> processor)
{
    sf::Vector2f offset = SelectionConstants::DISPLAY_OFFSET;
    SharedTextEntity entity = entities->get(selectedItem);
    processor(entity, offset.x, offset.y);

    for(unsigned int i = 1; i < entities->getCollection().size(); i++)
    {
        float y = offset.y + verticalOffset * i;
        if(i >= SelectionConstants::ITEMS_TO_DISPLAY)
            y = context.getWindow().getSize().y + verticalOffset;
        entity = entities->get(selectedItem + i);
        processor(entity, offset.x, y);
    }
}

#endif
