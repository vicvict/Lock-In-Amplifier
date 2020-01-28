#include "sr865.h"

int SR865::getMinDualHarmonic() const
{
    return this->minHarmDual;
}

int SR865::getMaxDualHarmonic() const
{
    return this->maxHarmDual;
}

bool SR865::isValidDualHarmonic(const int &i) const
{
    return (i >= this->minHarmDual &&
            i <= this->maxHarmDual);
}

bool SR865::setDualHarmonic(const int &i) const
{
    std::string command = commands.HarmonicDual + " " + std::to_string(i);
    if (isValidHarmonic(i))
        return sendCommand(command);
    else
        return false;
}

std::string SR865::getDualHarmonic() const
{
    std::string answer = ask(commands.HarmonicDual + "?");
    return answer;
}

double SR865::getMinSineDCLevel() const
{
    return this->minSineDCLevel;
}

double SR865::getMaxSineDCLevel() const
{
    return this->maxSineDCLevel;
}

bool SR865::isValidSineDCLevel(const double &voltage) const
{
    return (voltage >= this->minSineDCLevel &&
            voltage <= this->maxSineDCLevel);
}

bool SR865::setSineDCLevel(const double &voltage) const
{
    std::string command = commands.SineDCLevel + " " + std::to_string(voltage);
    if (isValidSineDCLevel(voltage))
        return sendCommand(command);
    else
        return false;
}

std::string SR865::getSineDCLevel() const
{
    std::string answer = ask(commands.SineDCLevel + "?");
    return answer;
}


