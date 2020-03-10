#include "sr830.h"


std::vector<std::string> SR830::getCloseReserveModeList() const {
    return this->closeReserveMode;
}

int SR830::closeReserveModeNumberFromString(const std::string &closeReserveMode_string) const {
    return numberFromString(this->closeReserveMode, closeReserveMode_string);
}

std::string SR830::closeReserveModeStringFromNumber(const int &closeReserveMode_number) const {
    return stringFromNumber(this->closeReserveMode, closeReserveMode_number);
}

bool SR830::setCloseReserveMode(const int &closeReserveMode) const {
    if (!isValidNumber(this->closeReserveMode, closeReserveMode))
        return false;

    std::string command = commands.CloseReserveMode + separator + std::to_string(closeReserveMode);
    return sendCommand(command);
}

bool SR830::setCloseReserveMode(const std::string &closeReserveMode) const {
    return setCloseReserveMode(closeReserveModeNumberFromString(closeReserveMode));
}

std::string SR830::getCloseReserveMode() const {
    return closeReserveModeStringFromNumber(std::stoi(ask(commands.CloseReserveMode + query_suffix)));
}

bool SR830::getOutDataABCD(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue) const {
    if ((!isValidNumber(this->outDataCouple, A)) && (!isValidNumber(this->outDataCouple, B)) && (!isValidNumber(this->outDataCouple, C)) && (!isValidNumber(this->outDataCouple, D)))
        return false;
    std::string command = commands.CoupleOfData + query_suffix + separator + std::to_string(A) + comma + std::to_string(B)+comma + std::to_string(C) + comma + std::to_string(D);
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
    CValue = result.at(2);
    DValue = result.at(3);
    return true;
}

bool SR830::getOutDataABCDE(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue) const {
    if ((!isValidNumber(this->outDataCouple, A)) && (!isValidNumber(this->outDataCouple, B)) && (!isValidNumber(this->outDataCouple, C)) && (!isValidNumber(this->outDataCouple, D)) && (!isValidNumber(this->outDataCouple, E)))
        return false;
    std::string command = commands.CoupleOfData + query_suffix + separator + std::to_string(A) + comma + std::to_string(B) + comma + std::to_string(C) + comma + std::to_string(D) + comma + std::to_string(E);
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
    DValue = result.at(3);
    EValue = result.at(4);
    return true;
}

bool SR830::getOutDataABCDEF(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue, const int &F, std::string &FValue) const {
    if ((!isValidNumber(this->outDataCouple, A)) && (!isValidNumber(this->outDataCouple, B)) && (!isValidNumber(this->outDataCouple, C)) && (!isValidNumber(this->outDataCouple, D)) && (!isValidNumber(this->outDataCouple, E)) && (!isValidNumber(this->outDataCouple, F)))
        return false;
    std::string command = commands.CoupleOfData + query_suffix + separator + std::to_string(A) + comma + std::to_string(B) + comma + std::to_string(C) + comma + std::to_string(D) + comma + std::to_string(E) + comma + std::to_string(F);
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
    DValue = result.at(3);
    EValue = result.at(4);
    FValue = result.at(5);
    return true;
}

bool SR830::getOutDataABCD(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue) const {
    return getOutDataABCD(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue, outDataCoupleNumberFromString(C), CValue, outDataCoupleNumberFromString(D), DValue);
}

bool SR830::getOutDataABCDE(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue) const {
    return getOutDataABCDE(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue, outDataCoupleNumberFromString(C), CValue, outDataCoupleNumberFromString(D), DValue, outDataCoupleNumberFromString(E), EValue);
}

bool SR830::getOutDataABCDEF(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue, const std::string &F, std::string &FValue) const {
    return getOutDataABCDEF(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue, outDataCoupleNumberFromString(C), CValue, outDataCoupleNumberFromString(D), DValue, outDataCoupleNumberFromString(E), EValue, outDataCoupleNumberFromString(F), FValue);
}

std::vector<std::string> SR830::getOutDataChannel1List() const {
    return this->outDataChannel1;
}

int SR830::outDataChannel1NumberFromString(const std::string &outDataChannel1_string) const {
    return numberFromString(this->outDataChannel1, outDataChannel1_string);
}

std::string SR830::outDataChannel1StringFromNumber(const int &outDataChannel1_number) const {
    return stringFromNumber(this->outDataChannel1, outDataChannel1_number);
}


bool SR830::setOutDataChannel1(const int& outDataChannel1) const {
    if (!isValidNumber(this->outDataChannel1, outDataChannel1))
        return false;
    return sendCommand(commands.SetOutData + separator + "1" + comma + std::to_string(outDataChannel1));
}

bool SR830::setOutDataChannel1(const std::string &outDataChannel1) const{
    return setOutDataChannel1(outDataChannel1NumberFromString(outDataChannel1));
}

std::vector<std::string> SR830::getOutDataChannel2List() const {
    return this->outDataChannel2;
}

int SR830::outDataChannel2NumberFromString(const std::string &outDataChannel2_string) const {
    return numberFromString(this->outDataChannel2, outDataChannel2_string);
}

std::string SR830::outDataChannel2StringFromNumber(const int &outDataChannel2_number) const {
    return stringFromNumber(this->outDataChannel2, outDataChannel2_number);
}


bool SR830::setOutDataChannel2(const int& outDataChannel2) const {
    if (!isValidNumber(this->outDataChannel2, outDataChannel2))
        return false;
    return sendCommand(commands.SetOutData + separator + "2" + comma + std::to_string(outDataChannel2));
}

bool SR830::setOutDataChannel2(const std::string &outDataChannel2) const{
    return setOutDataChannel2(outDataChannel2NumberFromString(outDataChannel2));
}

bool SR830:: autoReserve() const {
    return sendCommand(commands.AutoReserve);
}

std::vector<std::string> SR830::getBufferModeList() const {
    return this->bufferMode;
}

int SR830::bufferModeNumberFromString(const std::string &bufferMode_string) const {
    return numberFromString(this->bufferMode, bufferMode_string);
}

std::string SR830::bufferModeStringFromNumber(const int &bufferMode_number) const {
    return stringFromNumber(this->bufferMode, bufferMode_number);
}

bool SR830::setBufferMode(const int &bufferMode) const {
    if (!isValidNumber(this->bufferMode, bufferMode))
        return false;
    std::string command = commands.BufferMode + separator + std::to_string(bufferMode);
    return sendCommand(command);
}

bool SR830::setBufferMode(const std::string &bufferMode) const {
    return setBufferMode(bufferModeNumberFromString(bufferMode));
}

std::string SR830::getBufferMode() const {
    return bufferModeStringFromNumber(std::stoi(ask(commands.BufferMode + query_suffix)));
}

std::vector<std::string> SR830::getDataSampleRateList() const {
    return this->dataSampleRate;
}

int SR830::dataSampleRateNumberFromString(const std::string &dataSampleRate_string) const {
    return numberFromString(this->dataSampleRate, dataSampleRate_string);
}

std::string SR830::dataSampleRateStringFromNumber(const int &dataSampleRate_number) const {
    return stringFromNumber(this->dataSampleRate, dataSampleRate_number);
}

bool SR830::setDataSampleRate(const int &dataSampleRate) const {
    if (!isValidNumber(this->dataSampleRate, dataSampleRate))
        return false;
    std::string command = commands.DataSampleRate + separator + std::to_string(dataSampleRate);
    return sendCommand(command);
}

bool SR830::setDataSampleRate(const std::string &dataSampleRate) const {
    return setDataSampleRate(dataSampleRateNumberFromString(dataSampleRate));
}

std::string SR830::getDataSampleRate() const {
    return dataSampleRateStringFromNumber(std::stoi(ask(commands.DataSampleRate + query_suffix)));
}

bool SR830::startBuffer() const {
    return sendCommand(commands.StartBuffer);
}

bool SR830::pauseBuffer() const {
    return sendCommand(commands.PauseBuffer);
}

bool SR830::stopBuffer() const {
    return sendCommand(commands.StopBuffer);
}

int SR830::getBufferSize() const{
    return std::stoi(ask(commands.BufferSize + query_suffix));
}

std::string SR830::getPointFromBufferChannel1(const int &number) const {
    return ask(commands.GetPointFromBuffer + query_suffix + separator + "1," + std::to_string(number) + ",1");
}

std::string SR830::getPointFromBufferChannel2(const int &number) const {
    return ask(commands.GetPointFromBuffer + query_suffix + separator + "2," + std::to_string(number) + ",1");
}

std::vector <std::string> SR830::getChannel1FromBuffer() const {
    std::vector < std::string > ans;

        int size = getBufferSize();
        for (int i = 0;i < size;i++) {
            ans.push_back(getPointFromBufferChannel1(i));
        }

        return ans;
}

std::vector <std::string> SR830::getChannel2FromBuffer() const {
    std::vector < std::string > ans;

        int size = getBufferSize();
        for (int i = 0;i < size;i++) {
            ans.push_back(getPointFromBufferChannel2(i));
        }

        return ans;
}

std::vector<std::string> SR830::getRefTriggerModeList() const {
    return this->refTriggerMode;
}

int SR830::refTriggerModeNumberFromString(const std::string &refTriggerMode_string) const {
    return numberFromString(this->refTriggerMode, refTriggerMode_string);
}

std::string SR830::refTriggerModeStringFromNumber(const int &refTriggerMode_number) const {
    return stringFromNumber(this->refTriggerMode, refTriggerMode_number);
}

bool SR830::setRefTriggerMode(const int &refTriggerMode) const {
    if (!isValidNumber(this->refTriggerMode, refTriggerMode))
        return false;
    std::string command = commands.RefTriggerMode + separator + std::to_string(refTriggerMode);
    return sendCommand(command);
}

bool SR830::setRefTriggerMode(const std::string &refTriggerMode) const {
    return setRefTriggerMode(refTriggerModeNumberFromString(refTriggerMode));
}

std::string SR830::getRefTriggerMode() const {
    return refTriggerModeStringFromNumber(std::stoi(ask(commands.RefTriggerMode + query_suffix)));
}


std::vector<std::string> SR830::getInputVoltageModeList() const {
    return this->inputVoltageMode;
}

int SR830::inputVoltageModeNumberFromString(const std::string &inputVoltageMode_string) const {
    return numberFromString(this->inputVoltageMode, inputVoltageMode_string);
}

std::string SR830::inputVoltageModeStringFromNumber(const int &inputVoltageMode_number) const {
    return stringFromNumber(this->inputVoltageMode, inputVoltageMode_number);
}

bool SR830::setInputVoltageMode(const int &inputVoltageMode) const {
    if (!isValidNumber(this->inputVoltageMode, inputVoltageMode))
        return false;
    std::string command = commands.InputVoltageMode + separator + std::to_string(inputVoltageMode);
    return sendCommand(command);
}

bool SR830::setInputVoltageMode(const std::string &inputVoltageMode) const {
    return setInputVoltageMode(inputVoltageModeNumberFromString(inputVoltageMode));
}

std::string SR830::getInputVoltageMode() const {
    return inputVoltageModeStringFromNumber(std::stoi(ask(commands.InputVoltageMode + query_suffix)));
}


std::vector<std::string> SR830::getInputVoltageCouplingList() const {
    return this->inputVoltageCoupling;
}

int SR830::inputVoltageCouplingNumberFromString(const std::string &inputVoltageCoupling_string) const {
    return numberFromString(this->inputVoltageCoupling, inputVoltageCoupling_string);
}

std::string SR830::inputVoltageCouplingStringFromNumber(const int &inputVoltageCoupling_number) const {
    return stringFromNumber(this->inputVoltageCoupling, inputVoltageCoupling_number);
}

bool SR830::setInputVoltageCoupling(const int &inputVoltageCoupling) const {
    if (!isValidNumber(this->inputVoltageCoupling, inputVoltageCoupling))
        return false;
    std::string command = commands.InputVoltageCoupling + separator + std::to_string(inputVoltageCoupling);
    return sendCommand(command);
}

bool SR830::setInputVoltageCoupling(const std::string &inputVoltageCoupling) const {
    return setInputVoltageCoupling(inputVoltageCouplingNumberFromString(inputVoltageCoupling));
}

std::string SR830::getInputVoltageCoupling() const {
    return inputVoltageCouplingStringFromNumber(std::stoi(ask(commands.InputVoltageCoupling + query_suffix)));
}

std::vector<std::string> SR830::getInputVoltageShieldsList() const {
    return this->inputVoltageShields;
}

int SR830::inputVoltageShieldsNumberFromString(const std::string &inputVoltageShields_string) const {
    return numberFromString(this->inputVoltageShields, inputVoltageShields_string);
}

std::string SR830::inputVoltageShieldsStringFromNumber(const int &inputVoltageShields_number) const {
    return stringFromNumber(this->inputVoltageShields, inputVoltageShields_number);
}

bool SR830::setInputVoltageShields(const int &inputVoltageShields) const {
    if (!isValidNumber(this->inputVoltageShields, inputVoltageShields))
        return false;
    std::string command = commands.InputVoltageShields + separator + std::to_string(inputVoltageShields);
    return sendCommand(command);
}

bool SR830::setInputVoltageShields(const std::string &inputVoltageShields) const {
    return setInputVoltageShields(inputVoltageShieldsNumberFromString(inputVoltageShields));
}

std::string SR830::getInputVoltageShields() const {
    return inputVoltageShieldsStringFromNumber(std::stoi(ask(commands.InputVoltageShields + query_suffix)));
}

std::vector<std::string> SR830::getSynchronousFilterList() const {
    return this->synchronousFilter;
}

int SR830::synchronousFilterNumberFromString(const std::string &synchronousFilter_string) const {
    return numberFromString(this->synchronousFilter, synchronousFilter_string);
}

std::string SR830::synchronousFilterStringFromNumber(const int &synchronousFilter_number) const {
    return stringFromNumber(this->synchronousFilter, synchronousFilter_number);
}

bool SR830::setSynchronousFilter(const int &synchronousFilter) const {
    if (!isValidNumber(this->synchronousFilter, synchronousFilter))
        return false;

    std::string command = commands.SynchronousFilter + separator + std::to_string(synchronousFilter);
    return sendCommand(command);
}

bool SR830::setSynchronousFilter(const std::string &synchronousFilter) const {
    return setSynchronousFilter(synchronousFilterNumberFromString(synchronousFilter));
}

std::string SR830::getSynchronousFilter() const {
    return synchronousFilterStringFromNumber(std::stoi(ask(commands.SynchronousFilter + query_suffix)));
}
