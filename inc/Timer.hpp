#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

/*
 * Class used to keep track of when a specific amount of time has passed (accuate to the milliseconds).
 */
class Timer
{
public:
    Timer(sf::Time);
    /*
     * Returns true if the time limit has expired.
     */
    bool timeExpired();

    /*
     * Return the percent of the total timer elapsed for the timer.
     */
    float getPercentElapsed();
private:
    sf::Clock clock;
    sf::Time timeLimit;
};

#endif
