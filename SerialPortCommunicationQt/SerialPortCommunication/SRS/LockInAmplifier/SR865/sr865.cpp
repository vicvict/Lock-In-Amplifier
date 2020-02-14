#include "sr865.h"

int SR865::getMinDualHarmonic() const {
    return this->minHarmDual;
}

int SR865::getMaxDualHarmonic() const {
    return this->maxHarmDual;
}

bool SR865::isValidDualHarmonic(const int &i) const {
    return (i >= this->minHarmDual &&
            i <= this->maxHarmDual);
}

bool SR865::setDualHarmonic(const int &i) const {
    std::string command = commands.HarmonicDual + separator + std::to_string(i);
    if (isValidHarmonic(i))
        return sendCommand(command);
    else
        return false;
}

std::string SR865::getDualHarmonic() const {
    std::string answer = ask(commands.HarmonicDual + query_suffix);
    return answer;
}

double SR865::getMinSineDCLevel() const {
    return this->minSineDCLevel;
}

double SR865::getMaxSineDCLevel() const {
    return this->maxSineDCLevel;
}

bool SR865::isValidSineDCLevel(const double &voltage) const {
    return (voltage >= this->minSineDCLevel &&
            voltage <= this->maxSineDCLevel);
}

bool SR865::setSineDCLevel(const double &voltage) const {
    std::string command = commands.SineDCLevel + separator + std::to_string(voltage);
    if (isValidSineDCLevel(voltage))
        return sendCommand(command);
    else
        return false;
}

std::string SR865::getSineDCLevel() const {
    std::string answer = ask(commands.SineDCLevel + query_suffix);
    return answer;
}

std::vector<std::string> SR865::getSynchronousFilterList() const {
    return this->synchronousFilter;
}

int SR865::synchronousFilterNumberFromString(const std::string &synchronousFilter_string) const {
    return numberFromString(this->synchronousFilter, synchronousFilter_string);
}

std::string SR865::synchronousFilterStringFromNumber(const int &synchronousFilter_number) const {
    return stringFromNumber(this->synchronousFilter, synchronousFilter_number);
}

bool SR865::setSynchronousFilter(const int &synchronousFilter) const {
    if (!isValidNumber(this->synchronousFilter, synchronousFilter))
        return false;

    std::string command = commands.SynchronousFilter + separator + std::to_string(synchronousFilter);
    return sendCommand(command);
}

bool SR865::setSynchronousFilter(const std::string &synchronousFilter) const {
    return setSynchronousFilter(synchronousFilterNumberFromString(synchronousFilter));
}

std::string SR865::getSynchronousFilter() const {
    return synchronousFilterStringFromNumber(std::stoi(ask(commands.SynchronousFilter + query_suffix)));
}
