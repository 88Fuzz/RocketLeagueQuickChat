#ifndef SELECTION_CONSTANTS_HPP
#define SELECTION_CONSTANTS_HPP

#include "SelectionHolder.hpp"

#include <SFML/System/Vector2.hpp>

struct SelectionConstants
{
    static const sf::Vector2f DISPLAY_OFFSET;
    static const int ITEMS_TO_DISPLAY;
    static const SelectionHolder<int> SIZE_SELECT;
    static const SelectionHolder<sf::Color> COLOR_SELECT;
    static const sf::Time SELECTION_TRANSITION_TIME;
};

const sf::Vector2f SelectionConstants::DISPLAY_OFFSET = sf::Vector2f(40,40);
const int SelectionConstants::ITEMS_TO_DISPLAY = 5;
const SelectionHolder<int> SelectionConstants::SIZE_SELECT(55, 33);
const SelectionHolder<sf::Color> SelectionConstants::COLOR_SELECT(sf::Color::Yellow, sf::Color(200,200,200));
const sf::Time SelectionConstants::SELECTION_TRANSITION_TIME = sf::seconds(.7f);

#endif
