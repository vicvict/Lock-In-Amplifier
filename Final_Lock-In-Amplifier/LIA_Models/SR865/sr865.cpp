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

std::string SR865:: getInternalFrequency() const {
    std::string answer = ask(commands.Frequence + "INT" + query_suffix);
    return answer;
}

std::string SR865:: getExternalFrequency() const {
    std::string answer = ask(commands.Frequence + "EXT" + query_suffix);
    return answer;
}

std::string SR865:: getFrequencyDetect() const {
    std::string answer = ask(commands.FrequencyDetect + query_suffix);
    return answer;
}

std::vector<std::string> SR865::getRefTriggerModeList() const {
    return this->refTriggerMode;
}

int SR865::refTriggerModeNumberFromString(const std::string &refTriggerMode_string) const {
    return numberFromString(this->refTriggerMode, refTriggerMode_string);
}

std::string SR865::refTriggerModeStringFromNumber(const int &refTriggerMode_number) const {
    return stringFromNumber(this->refTriggerMode, refTriggerMode_number);
}

bool SR865::setRefTriggerMode(const int &refTriggerMode) const {
    if (!isValidNumber(this->refTriggerMode, refTriggerMode))
        return false;
    std::string command = commands.RefTriggerMode + separator + std::to_string(refTriggerMode);
    return sendCommand(command);
}

bool SR865::setRefTriggerMode(const std::string &refTriggerMode) const {
    return setRefTriggerMode(refTriggerModeNumberFromString(refTriggerMode));
}

std::string SR865::getRefTriggerMode() const {
    return refTriggerModeStringFromNumber(std::stoi(ask(commands.RefTriggerMode + query_suffix)));
}

std::vector<std::string> SR865::getInputSignalList() const {
    return this->inputSignal;
}

int SR865::inputSignalNumberFromString(const std::string &inputSignal_string) const {
    return numberFromString(this->inputSignal, inputSignal_string);
}

std::string SR865::inputSignalStringFromNumber(const int &inputSignal_number) const {
    return stringFromNumber(this->inputSignal, inputSignal_number);
}

bool SR865::setInputSignal(const int &inputSignal) const {
    if (!isValidNumber(this->inputSignal, inputSignal))
        return false;
    std::string command = commands.InputSignal + separator + std::to_string(inputSignal);
    return sendCommand(command);
}

bool SR865::setInputSignal(const std::string &inputSignal) const {
    return setInputSignal(inputSignalNumberFromString(inputSignal));
}

std::string SR865::getInputSignal() const {
    return inputSignalStringFromNumber(std::stoi(ask(commands.InputSignal + query_suffix)));
}


std::vector<std::string> SR865::getInputVoltageModeList() const {
    return this->inputVoltageMode;
}

int SR865::inputVoltageModeNumberFromString(const std::string &inputVoltageMode_string) const {
    return numberFromString(this->inputVoltageMode, inputVoltageMode_string);
}

std::string SR865::inputVoltageModeStringFromNumber(const int &inputVoltageMode_number) const {
    return stringFromNumber(this->inputVoltageMode, inputVoltageMode_number);
}

bool SR865::setInputVoltageMode(const int &inputVoltageMode) const {
    if (!isValidNumber(this->inputVoltageMode, inputVoltageMode))
        return false;
    std::string command = commands.InputVoltageMode + separator + std::to_string(inputVoltageMode);
    return sendCommand(command);
}

bool SR865::setInputVoltageMode(const std::string &inputVoltageMode) const {
    return setInputVoltageMode(inputVoltageModeNumberFromString(inputVoltageMode));
}

std::string SR865::getInputVoltageMode() const {
    return inputVoltageModeStringFromNumber(std::stoi(ask(commands.InputVoltageMode + query_suffix)));
}


std::vector<std::string> SR865::getInputVoltageCouplingList() const {
    return this->inputVoltageCoupling;
}

int SR865::inputVoltageCouplingNumberFromString(const std::string &inputVoltageCoupling_string) const {
    return numberFromString(this->inputVoltageCoupling, inputVoltageCoupling_string);
}

std::string SR865::inputVoltageCouplingStringFromNumber(const int &inputVoltageCoupling_number) const {
    return stringFromNumber(this->inputVoltageCoupling, inputVoltageCoupling_number);
}

bool SR865::setInputVoltageCoupling(const int &inputVoltageCoupling) const {
    if (!isValidNumber(this->inputVoltageCoupling, inputVoltageCoupling))
        return false;
    std::string command = commands.InputVoltageCoupling + separator + std::to_string(inputVoltageCoupling);
    return sendCommand(command);
}

bool SR865::setInputVoltageCoupling(const std::string &inputVoltageCoupling) const {
    return setInputVoltageCoupling(inputVoltageCouplingNumberFromString(inputVoltageCoupling));
}

std::string SR865::getInputVoltageCoupling() const {
    return inputVoltageCouplingStringFromNumber(std::stoi(ask(commands.InputVoltageCoupling + query_suffix)));
}

std::vector<std::string> SR865::getInputVoltageShieldsList() const {
    return this->inputVoltageShields;
}

int SR865::inputVoltageShieldsNumberFromString(const std::string &inputVoltageShields_string) const {
    return numberFromString(this->inputVoltageShields, inputVoltageShields_string);
}

std::string SR865::inputVoltageShieldsStringFromNumber(const int &inputVoltageShields_number) const {
    return stringFromNumber(this->inputVoltageShields, inputVoltageShields_number);
}

bool SR865::setInputVoltageShields(const int &inputVoltageShields) const {
    if (!isValidNumber(this->inputVoltageShields, inputVoltageShields))
        return false;
    std::string command = commands.InputVoltageShields + separator + std::to_string(inputVoltageShields);
    return sendCommand(command);
}

bool SR865::setInputVoltageShields(const std::string &inputVoltageShields) const {
    return setInputVoltageShields(inputVoltageShieldsNumberFromString(inputVoltageShields));
}

std::string SR865::getInputVoltageShields() const {
    return inputVoltageShieldsStringFromNumber(std::stoi(ask(commands.InputVoltageShields + query_suffix)));
}

std::vector<std::string> SR865::getInputVoltageRangeList() const {
    return this->inputVoltageRange;
}

int SR865::inputVoltageRangeNumberFromString(const std::string &inputVoltageRange_string) const {
    return numberFromString(this->inputVoltageRange, inputVoltageRange_string);
}

std::string SR865::inputVoltageRangeStringFromNumber(const int &inputVoltageRange_number) const {
    return stringFromNumber(this->inputVoltageRange, inputVoltageRange_number);
}

bool SR865::setInputVoltageRange(const int &inputVoltageRange) const {
    if (!isValidNumber(this->inputVoltageRange, inputVoltageRange))
        return false;
    std::string command = commands.InputVoltageRange + separator + std::to_string(inputVoltageRange);
    return sendCommand(command);
}

bool SR865::setInputVoltageRange(const std::string &inputVoltageRange) const {
    return setInputVoltageRange(inputVoltageRangeNumberFromString(inputVoltageRange));
}

std::string SR865::getInputVoltageRange() const {
    return inputVoltageRangeStringFromNumber(std::stoi(ask(commands.InputVoltageRange + query_suffix)));
}

std::vector<std::string> SR865::getInputCurrentGainList() const {
    return this->inputCurrentGain;
}

int SR865::inputCurrentGainNumberFromString(const std::string &inputCurrentGain_string) const {
    return numberFromString(this->inputCurrentGain, inputCurrentGain_string);
}

std::string SR865::inputCurrentGainStringFromNumber(const int &inputCurrentGain_number) const {
    return stringFromNumber(this->inputCurrentGain, inputCurrentGain_number);
}

bool SR865::setInputCurrentGain(const int &inputCurrentGain) const {
    if (!isValidNumber(this->inputCurrentGain, inputCurrentGain))
        return false;
    std::string command = commands.InputCurrentGain + separator + std::to_string(inputCurrentGain);
    return sendCommand(command);
}

bool SR865::setInputCurrentGain(const std::string &inputCurrentGain) const {
    return setInputCurrentGain(inputCurrentGainNumberFromString(inputCurrentGain));
}

std::string SR865::getInputCurrentGain() const {
    return inputCurrentGainStringFromNumber(std::stoi(ask(commands.InputCurrentGain + query_suffix)));
}

std::string SR865::getSignalStrength() const {
    std::string answer = ask(commands.SignalStrength + query_suffix);
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


std::vector<std::string> SR865::getAdvanceFilterList() const {
    return this->advanceFilter;
}

int SR865::advanceFilterNumberFromString(const std::string &advanceFilter_string) const {
    return numberFromString(this->advanceFilter, advanceFilter_string);
}

std::string SR865::advanceFilterStringFromNumber(const int &advanceFilter_number) const {
    return stringFromNumber(this->advanceFilter, advanceFilter_number);
}

bool SR865::setAdvanceFilter(const int &advanceFilter) const {
    if (!isValidNumber(this->advanceFilter, advanceFilter))
        return false;

    std::string command = commands.AdvanceFilter + separator + std::to_string(advanceFilter);
    return sendCommand(command);
}

bool SR865::setAdvanceFilter(const std::string &advanceFilter) const {
    return setAdvanceFilter(advanceFilterNumberFromString(advanceFilter));
}

std::string SR865::getAdvanceFilter() const {
    return advanceFilterStringFromNumber(std::stoi(ask(commands.AdvanceFilter + query_suffix)));
}

bool SR865::autoRange() const {
    return sendCommand(commands.AutoRange);
}
