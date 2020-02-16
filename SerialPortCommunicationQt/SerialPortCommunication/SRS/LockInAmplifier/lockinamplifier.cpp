#include "lockinamplifier.h"
//В процессе замены settings на ranges
LockInAmplifier::LockInAmplifier() {
    //setStringToBaudRate(lockinAmplifier_string_to_baud_rate);
    //setStringToStopBits(lockinAmplifier_string_to_stop_bits);
    //setStringToFlowControl(lockinAmplifier_string_to_flow_control);

    //init();

    supported_models =  {
                            "SR830", "SR844", "SR865"
                        };
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

bool LockInAmplifier::setFrequency(const double &frequency) const {
    std:: string command = commands.Frequence + separator + std:: to_string(frequency);
    if (isValidInternalFrequency(frequency))
        return sendCommand(command);
    else
        return false;
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


std::vector<std::string> LockInAmplifier::getOutDataCoupleList() const {
    return this->outDataCouple;
}

int LockInAmplifier::outDataCoupleNumberFromString(const std::string &outDataCouple_string) const {
    return numberFromString(this->outDataCouple, outDataCouple_string);
}

std::string LockInAmplifier::outDataCoupleStringFromNumber(const int &outDataCouple_number) const {
    return stringFromNumber(this->outDataCouple, outDataCouple_number);
}

bool LockInAmplifier::getOutDataAB(const int &A, std::string &AValue, const int &B, std::string &BValue) const {
    if ((!isValidNumber(this->outDataCouple, A)) && (!isValidNumber(this->outDataCouple, B)))
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
    if ((!isValidNumber(this->outDataCouple, A)) && (!isValidNumber(this->outDataCouple, B)))
        return false;
    std::string command = commands.CoupleOfData + query_suffix + separator + std::to_string(A) + comma + std::to_string(B) + comma + std::to_string(C);
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
    return getOutDataAB(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue);
}

bool LockInAmplifier::getOutDataABC(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue) const {
    return getOutDataABC(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue, outDataCoupleNumberFromString(C), CValue);
}



bool LockInAmplifier:: autoPhase() const {
    return sendCommand(commands.AutoPhase);
}


bool LockInAmplifier::autoScale() const {
    return sendCommand(commands.AutoScale);
}


