#include "SelectionConstants.hpp"

const sf::Vector2f SelectionConstants::DISPLAY_OFFSET = sf::Vector2f(40,40);
const int SelectionConstants::ITEMS_TO_DISPLAY = 5;
const SelectionHolder<int> SelectionConstants::SIZE(55, 33);
const SelectionHolder<sf::Color> SelectionConstants::COLOR(sf::Color::Yellow, sf::Color(200,200,200));
const sf::Time SelectionConstants::SELECTION_TRANSITION_TIME = sf::seconds(.7f);
