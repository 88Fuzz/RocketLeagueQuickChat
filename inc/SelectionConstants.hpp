#ifndef SELECTION_CONSTANTS_HPP
#define SELECTION_CONSTANTS_HPP

#include "SelectionHolder.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

struct SelectionConstants
{
    static const sf::Vector2f DISPLAY_OFFSET;
    static const unsigned int ITEMS_TO_DISPLAY;
    static const SelectionHolder<int> SIZE;
    static const SelectionHolder<sf::Color> COLOR;
    static const sf::Time SELECTION_TRANSITION_TIME;
};

#endif
