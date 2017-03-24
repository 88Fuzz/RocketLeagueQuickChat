#include "ChatOptionSelectState.hpp"
#include "SelectionConstants.hpp"

ChatOptionSelectState::ChatOptionSelectState(StateManager* stateManager,
        Context& context): State(stateManager, context), chatOptions(),
        selectedItem(0), previousSelectedItem(0), verticalOffset(0)
{
}

ChatOptionSelectState::~ChatOptionSelectState()
{
}

void ChatOptionSelectState::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
    for(auto entity: chatOptions->getCollection())
        entity->draw(renderTarget, renderStates);
}

void ChatOptionSelectState::update(sf::Time dt)
{
    for(auto entity: chatOptions->getCollection())
        entity->update(dt);
}

void ChatOptionSelectState::init()
{
    initOffsets();
    initSelections();
}

void ChatOptionSelectState::registerChatOptions(std::vector<SharedTextEntity>* fuckBall)
{
    chatOptions = std::unique_ptr<VectorWrapper<SharedTextEntity>>(new VectorWrapper<SharedTextEntity>(std::vector<SharedTextEntity>(*fuckBall)));
}

void ChatOptionSelectState::initOffsets()
{
    verticalOffset = context.getWindow().getSize().y / SelectionConstants::ITEMS_TO_DISPLAY;
}

void ChatOptionSelectState::initSelections()
{
    for(auto entity: chatOptions->getCollection())
    {
        entity->setColor(SelectionConstants::COLOR.deselected);
        entity->setSize(SelectionConstants::SIZE.deselected);
    }

    chatOptions->get(selectedItem)->setColor(SelectionConstants::COLOR.selected);
    chatOptions->get(selectedItem)->setSize(SelectionConstants::SIZE.selected);
    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->setPosition(x, y);
    });
}

void ChatOptionSelectState::updateSelectedItem()
{
    chatOptions->get(selectedItem)->registerColorModifier(
            SelectionConstants::COLOR.selected, SelectionConstants::SELECTION_TRANSITION_TIME);
    chatOptions->get(previousSelectedItem)->registerColorModifier(
            SelectionConstants::COLOR.deselected, SelectionConstants::SELECTION_TRANSITION_TIME);

    chatOptions->get(selectedItem)->registerSizeModifier(
            SelectionConstants::SIZE.selected, SelectionConstants::SELECTION_TRANSITION_TIME);
    chatOptions->get(previousSelectedItem)->registerSizeModifier(
            SelectionConstants::SIZE.deselected, SelectionConstants::SELECTION_TRANSITION_TIME);

    updatePositions([](SharedTextEntity entity, float x, float y)
    {
        entity->registerPositionModifer(sf::Vector2f(x, y), SelectionConstants::SELECTION_TRANSITION_TIME);
    });
}

void ChatOptionSelectState::updatePositions(std::function<void(SharedTextEntity&, float, float)> processor)
{
    sf::Vector2f offset = SelectionConstants::DISPLAY_OFFSET;
    SharedTextEntity entity = chatOptions->get(selectedItem);
    processor(entity, offset.x, offset.y);

    for(int i = 1; i < chatOptions->size(); i++)
    {
        entity = chatOptions->get(selectedItem + i);
        processor(entity, offset.x, offset.y + verticalOffset * i);
    }
}
