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
    std::string command = "HARMDUAL " + std::to_string(i);
    if (isValidHarmonic(i))
        return sendCommand(command);
    else
        return false;
}

std::string SR865::getDualHarmonic() const
{
    std::string answer = ask("HARMDUAL?");
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
    std::string command = "SOFF " + std::to_string(voltage);
    if (isValidSineDCLevel(voltage))
        return sendCommand(command);
    else
        return false;
}

std::string SR865::getSineDCLevel() const
{
    std::string answer = ask("SOFF?");
    return answer;
}

std::vector<std::string> SR865::getRefSourceList() const
{
    return this->refSource;
}

int SR865::refSourceNumberFromString(const std::string &refSource_string) const
{
    return numberFromString(this->refSource, refSource_string);
}

std::string SR865::refSourceStringFromNumber(const int &refSource_number) const
{
    return stringFromNumber(this->refSource, refSource_number);
}

bool SR865::setRefSource(const int &refSource) const
{
    if (!isValidNumber(this->refSource, refSource))
        return false;

    std::string command = "RSRC " + std::to_string(refSource);
    return sendCommand(command);
}

bool SR865::setRefSource(const std::string &refSource) const
{
    return setRefSource(refSourceNumberFromString(refSource));
}

std::string SR865::getRefSource() const
{
    return refSourceStringFromNumber(std::stoi(ask("RSRC?")));
}
