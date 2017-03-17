#include "Timer.hpp"

Timer::Timer(sf::Time timeLimit): timeLimit(timeLimit)
{
}

bool Timer::timeExpired()
{
    return clock.getElapsedTime() > timeLimit;
}

float Timer::getPercentElapsed()
{
    sf::Time elapsedTime = clock.getElapsedTime();

    return elapsedTime.asMilliseconds() / timeLimit.asMilliseconds();
}
