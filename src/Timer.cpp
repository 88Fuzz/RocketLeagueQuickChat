#include "Timer.hpp"
#include "MathUtils.hpp"

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
    float percent = (float) elapsedTime.asMilliseconds() / (float) timeLimit.asMilliseconds();

    return MathUtils::clamp(0, 100, percent);
}
