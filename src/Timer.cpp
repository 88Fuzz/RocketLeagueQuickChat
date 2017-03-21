#include "Timer.hpp"

Timer::Timer(sf::Time timeLimit, bool active): timeLimit(timeLimit), active(active)
{
}

bool Timer::timeExpired()
{
    if(!active)
        return true;
    else if(clock.getElapsedTime() > timeLimit)
        active = false;

    return !active;
}

float Timer::getPercentElapsed()
{
    if(!active)
        return 100;
    sf::Time elapsedTime = clock.getElapsedTime();

    return (float) elapsedTime.asMilliseconds() / (float) timeLimit.asMilliseconds();
}
