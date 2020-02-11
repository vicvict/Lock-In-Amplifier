#include "lockinamplifier.h"
//В процессе замены settings на ranges
LockInAmplifier::LockInAmplifier() {
    //setStringToBaudRate(lockinAmplifier_string_to_baud_rate);
    setStringToStopBits(lockinAmplifier_string_to_stop_bits);
    setStringToFlowControl(lockinAmplifier_string_to_flow_control);

    init();
}

LockInAmplifier::~LockInAmplifier() {

}

double LockInAmplifier::getEpsilon() const{
    return this->epsilon;
}

int LockInAmplifier::numberFromString(const std::vector < std::string > &vector, const std::string &string) const {
    for(size_t i = 0 ; i < vector.size(); ++i) {
        if (vector[i] == string)
            return static_cast<int>(i);
    }
    return -1;
}

std::string LockInAmplifier::stringFromNumber(const std::vector < std::string > &vector, const int &number) const{
    if (isValidNumber(vector, number))
        return vector.at(static_cast<size_t>(number));
    return "";
}

bool LockInAmplifier::isValidString(const std::vector< std::string> &vector, const std::string &string) const {
    return(numberFromString(vector, string) != -1);
}

bool LockInAmplifier::isValidNumber(const std::vector< std::string> &vector, const int &number) const {
    return (number >= 0 && number < static_cast<int>(vector.size()));
}

double LockInAmplifier::getMinPhase() const {
    return this->ranges.minPhase;
}

double LockInAmplifier::getMaxPhase() const {
    return this->ranges.maxPhase;
}

bool LockInAmplifier::isValidPhase(const double &Phase) const {
    return (Phase >= ranges.minPhase &&
            Phase < ranges.maxPhase);
}

bool LockInAmplifier::setInternalPhase(const double &Phase) const {
    std::string command = commands.Phase + separator + std::to_string(Phase);
    if (isValidPhase(Phase))
        return sendCommand(command);
    else
        return false;
}

std::string LockInAmplifier::getPhase() const {
    std::string answer = ask(commands.Phase + query_suffix);
    return answer;
}

double LockInAmplifier::getMinInternalFrequency() const {
    return this->ranges.minInternalFrequency;
}

double LockInAmplifier::getMaxInternalFrequency() const {
    return this->ranges.maxInternalFrequency;
}

bool LockInAmplifier::isValidInternalFrequency(const double &frequency) const {
    return (frequency >= this->ranges.minInternalFrequency &&
            frequency <= this->ranges.maxInternalFrequency);
}

bool LockInAmplifier::setInternalFrequency(const double &frequency) const {
    std:: string command = commands.Frequence + separator + std:: to_string(frequency);
    if (isValidInternalFrequency(frequency))
        return sendCommand(command);
    else
        return false;
}

std::string LockInAmplifier:: getInternalFrequency() const {
    std::string answer = ask(commands.Frequence + "INT" + query_suffix);
    return answer;
}

std::string LockInAmplifier:: getExternalFrequency() const {
    std::string answer = ask(commands.Frequence + "EXT" + query_suffix);
    return answer;
}

std::string LockInAmplifier:: getFrequencyDetect() const {
    std::string answer = ask(commands.FrequencyDetect + query_suffix);
    return answer;
}


std::string LockInAmplifier::getFrequency() const {
    std::string answer = ask(commands.Frequence + query_suffix);
    return answer;
}

int LockInAmplifier::getMinHarmonic() const {
    return this->ranges.minHarmonic;
}

int LockInAmplifier::getMaxHarmonic() const {
    return this->ranges.maxHarmonic;
}

bool LockInAmplifier::isValidHarmonic(const int &i) const {
    return (i >= this->ranges.minHarmonic &&
            i <= this->ranges.maxHarmonic);
}

bool LockInAmplifier::setHarmonic(const int &i) const {
    std::string command = commands.Harmonic + separator + std::to_string(i);
    if (isValidHarmonic(i))
        return sendCommand(command);
    else
        return false;
}

std::string LockInAmplifier::getHarmonic() const {
    std::string answer = ask(commands.Harmonic + query_suffix);
    return answer;
}

double LockInAmplifier::getMinSineAmplitude() const {
    return this->ranges.minSineAmplitude;
}

double LockInAmplifier::getMaxSineAmplitude() const {
    return this->ranges.maxSineAmplitude;
}

bool LockInAmplifier::isValidSineAmplitude(const double &voltage) const {
    return (voltage >= this->ranges.minSineAmplitude &&
            voltage <= this->ranges.maxSineAmplitude);
}

bool LockInAmplifier::setSineAmplitude(const double &voltage) const {
    std::string command = commands.SineAmplitude + separator + std::to_string(voltage);
    if (isValidSineAmplitude(voltage))
        return sendCommand(command);
    else
        return false;
}

std::string LockInAmplifier::getSineAmplitude() const {
    std::string answer = ask(commands.SineAmplitude + query_suffix);
    return answer;
}

std::vector<std::string> LockInAmplifier::getTimeConstantList() const {
    return this->timeConstant;
}

int LockInAmplifier::timeConstantNumberFromString(const std::string &timeConstant_string) const {
    return numberFromString(this->timeConstant, timeConstant_string);
}

std::string LockInAmplifier::timeConstantStringFromNumber(const int &timeConstant_number) const {
    return stringFromNumber(this->timeConstant, timeConstant_number);
}

bool LockInAmplifier::setTimeConstant(const int &timeConstant) const {
    if (!isValidNumber(this->timeConstant, timeConstant))
        return false;

    std::string command = commands.TimeConstant + separator + std::to_string(timeConstant);
    return sendCommand(command);
}

bool LockInAmplifier::setTimeConstant(const std::string &timeConstant) const {
    return setTimeConstant(timeConstantNumberFromString(timeConstant));
}

std::string LockInAmplifier::getTimeConstant() const {
    return timeConstantStringFromNumber(std::stoi(ask(commands.TimeConstant + query_suffix)));
}

std::vector<std::string> LockInAmplifier::getRefSourceList() const {
    return this->refSource;
}

int LockInAmplifier::refSourceNumberFromString(const std::string &refSource_string) const {

    return numberFromString(this->refSource, refSource_string);

}

std::string LockInAmplifier::refSourceStringFromNumber(const int &refSource_number) const {

    return stringFromNumber(this->refSource, refSource_number);

}

bool LockInAmplifier::setRefSource(const int &refSource) const {

    if (!isValidNumber(this->refSource, refSource)) {
        return false;
    }
    std::string command = commands.RefSource + separator + std::to_string(refSource);
    return sendCommand(command);
}



bool LockInAmplifier::setRefSource(const std::string &refSource) const {
    return setRefSource(refSourceNumberFromString(refSource));
}



std::string LockInAmplifier::getRefSource() const {
    return refSourceStringFromNumber(std::stoi(ask(commands.RefSource + query_suffix)));
}


std::vector<std::string> LockInAmplifier::getRefTriggerModeList() const {
    return this->refTriggerMode;
}

int LockInAmplifier::refTriggerModeNumberFromString(const std::string &refTriggerMode_string) const {
    return numberFromString(this->refTriggerMode, refTriggerMode_string);
}

std::string LockInAmplifier::refTriggerModeStringFromNumber(const int &refTriggerMode_number) const {
    return stringFromNumber(this->refTriggerMode, refTriggerMode_number);
}

bool LockInAmplifier::setRefTriggerMode(const int &refTriggerMode) const {
    if (!isValidNumber(this->refTriggerMode, refTriggerMode))
        return false;
    std::string command = commands.RefTriggerMode + separator + std::to_string(refTriggerMode);
    return sendCommand(command);
}

bool LockInAmplifier::setRefTriggerMode(const std::string &refTriggerMode) const {
    return setRefTriggerMode(refTriggerModeNumberFromString(refTriggerMode));
}

std::string LockInAmplifier::getRefTriggerMode() const {
    return refTriggerModeStringFromNumber(std::stoi(ask(commands.RefTriggerMode + query_suffix)));
}


std::vector<std::string> LockInAmplifier::getRefTriggerOutputList() const {
    return this->refTriggerOutput;
}

int LockInAmplifier::refTriggerOutputNumberFromString(const std::string &refTriggerOutput_string) const {
    return numberFromString(this->refTriggerOutput, refTriggerOutput_string);
}

std::string LockInAmplifier::refTriggerOutputStringFromNumber(const int &refTriggerOutput_number) const {
    return stringFromNumber(this->refTriggerOutput, refTriggerOutput_number);
}

bool LockInAmplifier::setRefTriggerOutput(const int &refTriggerOutput) const {
    if (!isValidNumber(this->refTriggerOutput, refTriggerOutput))
        return false;
    std::string command = commands.RefTriggerOutput + separator + std::to_string(refTriggerOutput);
    return sendCommand(command);
}

bool LockInAmplifier::setRefTriggerOutput(const std::string &refTriggerOutput) const {
    return setRefTriggerOutput(refTriggerOutputNumberFromString(refTriggerOutput));
}

std::string LockInAmplifier::getRefTriggerOutput() const {
    return refTriggerOutputStringFromNumber(std::stoi(ask(commands.RefTriggerOutput + query_suffix)));
}

std::vector<std::string> LockInAmplifier::getInputSignalList() const {
    return this->inputSignal;
}

int LockInAmplifier::inputSignalNumberFromString(const std::string &inputSignal_string) const {
    return numberFromString(this->inputSignal, inputSignal_string);
}

std::string LockInAmplifier::inputSignalStringFromNumber(const int &inputSignal_number) const {
    return stringFromNumber(this->inputSignal, inputSignal_number);
}

bool LockInAmplifier::setInputSignal(const int &inputSignal) const {
    if (!isValidNumber(this->inputSignal, inputSignal))
        return false;
    std::string command = commands.InputSignal + separator + std::to_string(inputSignal);
    return sendCommand(command);
}

bool LockInAmplifier::setInputSignal(const std::string &inputSignal) const {
    return setInputSignal(inputSignalNumberFromString(inputSignal));
}

std::string LockInAmplifier::getInputSignal() const {
    return inputSignalStringFromNumber(std::stoi(ask(commands.InputSignal + query_suffix)));
}


std::vector<std::string> LockInAmplifier::getInputVoltageModeList() const {
    return this->inputVoltageMode;
}

int LockInAmplifier::inputVoltageModeNumberFromString(const std::string &inputVoltageMode_string) const {
    return numberFromString(this->inputVoltageMode, inputVoltageMode_string);
}

std::string LockInAmplifier::inputVoltageModeStringFromNumber(const int &inputVoltageMode_number) const {
    return stringFromNumber(this->inputVoltageMode, inputVoltageMode_number);
}

bool LockInAmplifier::setInputVoltageMode(const int &inputVoltageMode) const {
    if (!isValidNumber(this->inputVoltageMode, inputVoltageMode))
        return false;
    std::string command = commands.InputVoltageMode + separator + std::to_string(inputVoltageMode);
    return sendCommand(command);
}

bool LockInAmplifier::setInputVoltageMode(const std::string &inputVoltageMode) const {
    return setInputVoltageMode(inputVoltageModeNumberFromString(inputVoltageMode));
}

std::string LockInAmplifier::getInputVoltageMode() const {
    return inputVoltageModeStringFromNumber(std::stoi(ask(commands.InputVoltageMode + query_suffix)));
}

std::vector<std::string> LockInAmplifier::getInputVoltageCouplingList() const {
    return this->inputVoltageCoupling;
}

int LockInAmplifier::inputVoltageCouplingNumberFromString(const std::string &inputVoltageCoupling_string) const {
    return numberFromString(this->inputVoltageCoupling, inputVoltageCoupling_string);
}

std::string LockInAmplifier::inputVoltageCouplingStringFromNumber(const int &inputVoltageCoupling_number) const {
    return stringFromNumber(this->inputVoltageCoupling, inputVoltageCoupling_number);
}

bool LockInAmplifier::setInputVoltageCoupling(const int &inputVoltageCoupling) const {
    if (!isValidNumber(this->inputVoltageCoupling, inputVoltageCoupling))
        return false;
    std::string command = commands.InputVoltageCoupling + separator + std::to_string(inputVoltageCoupling);
    return sendCommand(command);
}

bool LockInAmplifier::setInputVoltageCoupling(const std::string &inputVoltageCoupling) const {
    return setInputVoltageCoupling(inputVoltageCouplingNumberFromString(inputVoltageCoupling));
}

std::string LockInAmplifier::getInputVoltageCoupling() const {
    return inputVoltageCouplingStringFromNumber(std::stoi(ask(commands.InputVoltageCoupling + query_suffix)));
}


std::vector<std::string> LockInAmplifier::getInputVoltageShieldsList() const {
    return this->inputVoltageShields;
}

int LockInAmplifier::inputVoltageShieldsNumberFromString(const std::string &inputVoltageShields_string) const {
    return numberFromString(this->inputVoltageShields, inputVoltageShields_string);
}

std::string LockInAmplifier::inputVoltageShieldsStringFromNumber(const int &inputVoltageShields_number) const {
    return stringFromNumber(this->inputVoltageShields, inputVoltageShields_number);
}

bool LockInAmplifier::setInputVoltageShields(const int &inputVoltageShields) const {
    if (!isValidNumber(this->inputVoltageShields, inputVoltageShields))
        return false;
    std::string command = commands.InputVoltageShields + separator + std::to_string(inputVoltageShields);
    return sendCommand(command);
}

bool LockInAmplifier::setInputVoltageShields(const std::string &inputVoltageShields) const {
    return setInputVoltageShields(inputVoltageShieldsNumberFromString(inputVoltageShields));
}

std::string LockInAmplifier::getInputVoltageShields() const {
    return inputVoltageShieldsStringFromNumber(std::stoi(ask(commands.InputVoltageShields + query_suffix)));
}


std::vector<std::string> LockInAmplifier::getInputVoltageRangeList() const {
    return this->inputVoltageRange;
}

int LockInAmplifier::inputVoltageRangeNumberFromString(const std::string &inputVoltageRange_string) const {
    return numberFromString(this->inputVoltageRange, inputVoltageRange_string);
}

std::string LockInAmplifier::inputVoltageRangeStringFromNumber(const int &inputVoltageRange_number) const {
    return stringFromNumber(this->inputVoltageRange, inputVoltageRange_number);
}

bool LockInAmplifier::setInputVoltageRange(const int &inputVoltageRange) const {
    if (!isValidNumber(this->inputVoltageRange, inputVoltageRange))
        return false;
    std::string command = commands.InputVoltageRange + separator + std::to_string(inputVoltageRange);
    return sendCommand(command);
}

bool LockInAmplifier::setInputVoltageRange(const std::string &inputVoltageRange) const {
    return setInputVoltageRange(inputVoltageRangeNumberFromString(inputVoltageRange));
}

std::string LockInAmplifier::getInputVoltageRange() const {
    return inputVoltageRangeStringFromNumber(std::stoi(ask(commands.InputVoltageRange + query_suffix)));
}

std::vector<std::string> LockInAmplifier::getInputCurrentGainList() const {
    return this->inputCurrentGain;
}

int LockInAmplifier::inputCurrentGainNumberFromString(const std::string &inputCurrentGain_string) const {
    return numberFromString(this->inputCurrentGain, inputCurrentGain_string);
}

std::string LockInAmplifier::inputCurrentGainStringFromNumber(const int &inputCurrentGain_number) const {
    return stringFromNumber(this->inputCurrentGain, inputCurrentGain_number);
}

bool LockInAmplifier::setInputCurrentGain(const int &inputCurrentGain) const {
    if (!isValidNumber(this->inputCurrentGain, inputCurrentGain))
        return false;
    std::string command = commands.InputCurrentGain + separator + std::to_string(inputCurrentGain);
    return sendCommand(command);
}

bool LockInAmplifier::setInputCurrentGain(const std::string &inputCurrentGain) const {
    return setInputCurrentGain(inputCurrentGainNumberFromString(inputCurrentGain));
}

std::string LockInAmplifier::getInputCurrentGain() const {
    return inputCurrentGainStringFromNumber(std::stoi(ask(commands.InputCurrentGain + query_suffix)));
}

std::string LockInAmplifier::getSignalStrength() const {
    std::string answer = ask(commands.SignalStrength + query_suffix);
    return answer;
}

std::vector<std::string> LockInAmplifier::getSensitivityList() const {
    return this->sensitivity;
}

int LockInAmplifier::sensitivityNumberFromString(const std::string &sensitivity_string) const {
    return numberFromString(this->sensitivity, sensitivity_string);
}

std::string LockInAmplifier::sensitivityStringFromNumber(const int &sensitivity_number) const {
    return stringFromNumber(this->sensitivity, sensitivity_number);
}

bool LockInAmplifier::setSensitivity(const int &sensitivity) const {
    if (!isValidNumber(this->sensitivity, sensitivity))
        return false;

    std::string command = commands.Sensitivity + separator + std::to_string(sensitivity);
    return sendCommand(command);
}

bool LockInAmplifier::setSensitivity(const std::string &sensitivity) const {
    return setSensitivity(sensitivityNumberFromString(sensitivity));
}

std::string LockInAmplifier::getSensitivity() const {
    return sensitivityStringFromNumber(std::stoi(ask(commands.Sensitivity + query_suffix)));
}


std::vector<std::string> LockInAmplifier::getFilterSlopeList() const {
    return this->filterSlope;
}

int LockInAmplifier::filterSlopeNumberFromString(const std::string &filterSlope_string) const {
    return numberFromString(this->filterSlope, filterSlope_string);
}

std::string LockInAmplifier::filterSlopeStringFromNumber(const int &filterSlope_number) const {
    return stringFromNumber(this->filterSlope, filterSlope_number);
}

bool LockInAmplifier::setFilterSlope(const int &filterSlope) const {
    if (!isValidNumber(this->filterSlope, filterSlope))
        return false;

    std::string command = commands.FilterSlope + separator + std::to_string(filterSlope);
    return sendCommand(command);
}

bool LockInAmplifier::setFilterSlope(const std::string &filterSlope) const {
    return setFilterSlope(filterSlopeNumberFromString(filterSlope));
}

std::string LockInAmplifier::getFilterSlope() const {
    return filterSlopeStringFromNumber(std::stoi(ask(commands.FilterSlope + query_suffix)));
}


std::vector<std::string> LockInAmplifier::getSynchronousFilterList() const {
    return this->synchronousFilter;
}

int LockInAmplifier::synchronousFilterNumberFromString(const std::string &synchronousFilter_string) const {
    return numberFromString(this->synchronousFilter, synchronousFilter_string);
}

std::string LockInAmplifier::synchronousFilterStringFromNumber(const int &synchronousFilter_number) const {
    return stringFromNumber(this->synchronousFilter, synchronousFilter_number);
}

bool LockInAmplifier::setSynchronousFilter(const int &synchronousFilter) const {
    if (!isValidNumber(this->synchronousFilter, synchronousFilter))
        return false;

    std::string command = commands.SynchronousFilter + separator + std::to_string(synchronousFilter);
    return sendCommand(command);
}

bool LockInAmplifier::setSynchronousFilter(const std::string &synchronousFilter) const {
    return setSynchronousFilter(synchronousFilterNumberFromString(synchronousFilter));
}

std::string LockInAmplifier::getSynchronousFilter() const {
    return synchronousFilterStringFromNumber(std::stoi(ask(commands.SynchronousFilter + query_suffix)));
}

std::vector<std::string> LockInAmplifier::getOutDataList() const {
    return this->outData;
}

int LockInAmplifier::outDataNumberFromString(const std::string &outData_string) const {
    return numberFromString(this->outData, outData_string);
}

std::string LockInAmplifier::outDataStringFromNumber(const int &outData_number) const {
    return stringFromNumber(this->outData, outData_number);
}


std::string LockInAmplifier::getOutData(const int& outData) const {
    if (!isValidNumber(this->outData, outData))
        return invalidData;
    return ask(commands.OutData + query_suffix + separator + std::to_string(outData));
}

std::string LockInAmplifier::getOutData(const std::string &outData) const{
    return getOutData(outDataNumberFromString(outData));
}

bool LockInAmplifier::getOutDataAB(const int &A, std::string &AValue, const int &B, std::string &BValue) const {
    if ((!isValidNumber(this->outData, A)) && (!isValidNumber(this->outData, B)))
        return false;
    std::string command = commands.CoupleOfData + query_suffix + separator + std::to_string(A) + comma + std::to_string(B);
    std::string response;
    sendQuery(command, response);
    std::istringstream ss(response);
    std::string str;
    char splitSymbol = ',';
    std::vector < std::string > result;
    while (std::getline(ss, str, splitSymbol)) {
        result.push_back(str);
    }

    AValue = result.at(0);
    BValue = result.at(1);
    return true;
}

bool LockInAmplifier::getOutDataABC(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue) const {
    if ((!isValidNumber(this->outData, A)) && (!isValidNumber(this->outData, B)))
        return false;
    std::string command = commands.CoupleOfData + query_suffix + separator + std::to_string(A) + comma + std::to_string(B) + comma =std::to_string(C);
    std::string response;
    sendQuery(command, response);
    std::stringstream ss(response);
    std::string str;
    char splitSymbol = ',';
    std::vector < std::string > result;
    while (std::getline(ss, str, splitSymbol)) {
        result.push_back(str);
    }

    AValue = result.at(0);
    BValue = result.at(1);
    CValue = result.at(2);
    return true;
}

bool LockInAmplifier::getOutDataAB(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue) const {
    return getOutDataAB(outDataNumberFromString(A), AValue, outDataNumberFromString(B), BValue);
}

bool LockInAmplifier::getOutDataABC(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue) const {
    return getOutDataABC(outDataNumberFromString(A), AValue, outDataNumberFromString(B), BValue, outDataNumberFromString(C), CValue);
}


std::vector<std::string> LockInAmplifier::getAdvanceFilterList() const {
    return this->advanceFilter;
}

int LockInAmplifier::advanceFilterNumberFromString(const std::string &advanceFilter_string) const {
    return numberFromString(this->advanceFilter, advanceFilter_string);
}

std::string LockInAmplifier::advanceFilterStringFromNumber(const int &advanceFilter_number) const {
    return stringFromNumber(this->advanceFilter, advanceFilter_number);
}

bool LockInAmplifier::setAdvanceFilter(const int &advanceFilter) const {
    if (!isValidNumber(this->advanceFilter, advanceFilter))
        return false;

    std::string command = commands.AdvanceFilter + separator + std::to_string(advanceFilter);
    return sendCommand(command);
}

bool LockInAmplifier::setAdvanceFilter(const std::string &advanceFilter) const {
    return setAdvanceFilter(advanceFilterNumberFromString(advanceFilter));
}

std::string LockInAmplifier::getAdvanceFilter() const {
    return advanceFilterStringFromNumber(std::stoi(ask(commands.AdvanceFilter + query_suffix)));
}


bool LockInAmplifier:: autoPhase() const {
    return sendCommand(commands.AutoPhase);
}

bool LockInAmplifier::autoRange() const {
    return sendCommand(commands.AutoRange);
}

bool LockInAmplifier::autoScale() const {
    return sendCommand(commands.AutoScale);
}





void LockInAmplifier::SetRanges(const LockInAmplifierRanges &new_ranges) {
    ranges = new_ranges;
    return;
}

void LockInAmplifier::SetTimeConstantList(const std::vector<std::string> &new_time_constantlist) {
    timeConstant = new_time_constantlist;
    return;
}
