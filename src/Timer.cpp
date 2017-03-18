#include "Timer.hpp"

Timer::Timer(sf::Time timeLimit, bool active): timeLimit(timeLimit), active(active)
{
}

bool Timer::timeExpired()
{
    return active && clock.getElapsedTime() > timeLimit;
}

float Timer::getPercentElapsed()
{
    if(!active)
        return 0;
    sf::Time elapsedTime = clock.getElapsedTime();

    return (float) elapsedTime.asMilliseconds() / (float) timeLimit.asMilliseconds();
}
