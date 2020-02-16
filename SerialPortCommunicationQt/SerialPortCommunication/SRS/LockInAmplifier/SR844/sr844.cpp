#include "sr844.h"

std::string SR844:: getFrequencyDetect() const {
    std::string answer = ask(commands.FrequencyDetect + query_suffix);
    return answer;
}

bool SR844:: autoReserve() const {
    return sendCommand(commands.AutoReserve);
}

std::vector<std::string> SR844::getInputSignalZList() const {
    return this->inputSignalZ;
}

int SR844::inputSignalZNumberFromString(const std::string &inputSignalZ_string) const {
    return numberFromString(this->inputSignalZ, inputSignalZ_string);
}

std::string SR844::inputSignalZStringFromNumber(const int &inputSignalZ_number) const {
    return stringFromNumber(this->inputSignalZ, inputSignalZ_number);
}

bool SR844::setInputSignalZ(const int &inputSignalZ) const {
    if (!isValidNumber(this->inputSignalZ, inputSignalZ))
        return false;

    std::string command = commands.InputSignalZ + separator + std::to_string(inputSignalZ);
    return sendCommand(command);
}

bool SR844::setInputSignalZ(const std::string &inputSignalZ) const {
    return setInputSignalZ(inputSignalZNumberFromString(inputSignalZ));
}

std::string SR844::getInputSignalZ() const {
    return inputSignalZStringFromNumber(std::stoi(ask(commands.InputSignalZ + query_suffix)));
}




bool SR844::outDataAutoZeroChannel1(const int &outDataChannel1) const {
    if (!isValidNumber(this->outDataChannel1, outDataChannel1))
        return false;
    sendCommand(commands.AutoZero + separator + "1" + comma + std::to_string(outDataChannel1));
    return true;
}

bool SR844::outDataAutoZeroChannel2(const int &outDataChannel2) const {
    if (!isValidNumber(this->outDataChannel1, outDataChannel2))
        return false;
    sendCommand(commands.AutoZero + separator + "2" + comma + std::to_string(outDataChannel2));
    return true;
}

bool SR844::outDataAutoZeroChannel1(const std::string &outDataChannel1) const {
    return outDataAutoZeroChannel1(outDataChannel1NumberFromString(outDataChannel1));
}

bool SR844::outDataAutoZeroChannel2(const std::string &outDataChannel2) const {
    return outDataAutoZeroChannel2(outDataChannel2NumberFromString(outDataChannel2));
}

std::string SR844::getPointFromBufferChannel1(const int &number) const {
    return ask(commands.GetPointFromBuffer + query_suffix + separator + "1," + std::to_string(number) + ",1");
}

std::string SR844::getPointFromBufferChannel2(const int &number) const {
    return ask(commands.GetPointFromBuffer + query_suffix + separator + "2," + std::to_string(number) + ",1");
}

std::vector <std::string> SR844::getChannel1FromBuffer() const {
    std::vector < std::string > ans;

        int size = getBufferSize();
        for (int i = 0;i < size;i++) {
            ans.push_back(getPointFromBufferChannel1(i));
        }

        return ans;
}

std::vector <std::string> SR844::getChannel2FromBuffer() const {
    std::vector < std::string > ans;

        int size = getBufferSize();
        for (int i = 0;i < size;i++) {
            ans.push_back(getPointFromBufferChannel2(i));
        }

        return ans;
}


std::vector<std::string> SR844::getCloseReserveModeList() const {
    return this->closeReserveMode;
}

int SR844::closeReserveModeNumberFromString(const std::string &closeReserveMode_string) const {
    return numberFromString(this->closeReserveMode, closeReserveMode_string);
}

std::string SR844::closeReserveModeStringFromNumber(const int &closeReserveMode_number) const {
    return stringFromNumber(this->closeReserveMode, closeReserveMode_number);
}

bool SR844::setCloseReserveMode(const int &closeReserveMode) const {
    if (!isValidNumber(this->closeReserveMode, closeReserveMode))
        return false;

    std::string command = commands.CloseReserveMode + separator + std::to_string(closeReserveMode);
    return sendCommand(command);
}

bool SR844::setCloseReserveMode(const std::string &closeReserveMode) const {
    return setCloseReserveMode(closeReserveModeNumberFromString(closeReserveMode));
}

std::string SR844::getCloseReserveMode() const {
    return closeReserveModeStringFromNumber(std::stoi(ask(commands.CloseReserveMode + query_suffix)));
}

bool SR844::getOutDataABCD(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue) const {
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

bool SR844::getOutDataABCDE(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue) const {
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

bool SR844::getOutDataABCDEF(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue, const int &F, std::string &FValue) const {
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

bool SR844::getOutDataABCD(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue) const {
    return getOutDataABCD(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue, outDataCoupleNumberFromString(C), CValue, outDataCoupleNumberFromString(D), DValue);
}

bool SR844::getOutDataABCDE(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue) const {
    return getOutDataABCDE(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue, outDataCoupleNumberFromString(C), CValue, outDataCoupleNumberFromString(D), DValue, outDataCoupleNumberFromString(E), EValue);
}

bool SR844::getOutDataABCDEF(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue, const std::string &F, std::string &FValue) const {
    return getOutDataABCDEF(outDataCoupleNumberFromString(A), AValue, outDataCoupleNumberFromString(B), BValue, outDataCoupleNumberFromString(C), CValue, outDataCoupleNumberFromString(D), DValue, outDataCoupleNumberFromString(E), EValue, outDataCoupleNumberFromString(F), FValue);
}

std::vector<std::string> SR844::getOutDataChannel1List() const {
    return this->outDataChannel1;
}

int SR844::outDataChannel1NumberFromString(const std::string &outDataChannel1_string) const {
    return numberFromString(this->outDataChannel1, outDataChannel1_string);
}

std::string SR844::outDataChannel1StringFromNumber(const int &outDataChannel1_number) const {
    return stringFromNumber(this->outDataChannel1, outDataChannel1_number);
}


bool SR844::setOutDataChannel1(const int& outDataChannel1) const {
    if (!isValidNumber(this->outDataChannel1, outDataChannel1))
        return false;
    return sendCommand(commands.SetOutData + separator + "1" + comma + std::to_string(outDataChannel1));
}

bool SR844::setOutDataChannel1(const std::string &outDataChannel1) const{
    return setOutDataChannel1(outDataChannel1NumberFromString(outDataChannel1));
}

std::vector<std::string> SR844::getOutDataChannel2List() const {
    return this->outDataChannel2;
}

int SR844::outDataChannel2NumberFromString(const std::string &outDataChannel2_string) const {
    return numberFromString(this->outDataChannel2, outDataChannel2_string);
}

std::string SR844::outDataChannel2StringFromNumber(const int &outDataChannel2_number) const {
    return stringFromNumber(this->outDataChannel2, outDataChannel2_number);
}


bool SR844::setOutDataChannel2(const int& outDataChannel2) const {
    if (!isValidNumber(this->outDataChannel2, outDataChannel2))
        return false;
    return sendCommand(commands.SetOutData + separator + "2" + comma + std::to_string(outDataChannel2));
}

bool SR844::setOutDataChannel2(const std::string &outDataChannel2) const{
    return setOutDataChannel2(outDataChannel2NumberFromString(outDataChannel2));
}

bool SR844:: autoWideReverse() const {
    return sendCommand(commands.AutoWideReverse);
}

std::vector<std::string> SR844::getBufferModeList() const {
    return this->bufferMode;
}

int SR844::bufferModeNumberFromString(const std::string &bufferMode_string) const {
    return numberFromString(this->bufferMode, bufferMode_string);
}

std::string SR844::bufferModeStringFromNumber(const int &bufferMode_number) const {
    return stringFromNumber(this->bufferMode, bufferMode_number);
}

bool SR844::setBufferMode(const int &bufferMode) const {
    if (!isValidNumber(this->bufferMode, bufferMode))
        return false;
    std::string command = commands.BufferMode + separator + std::to_string(bufferMode);
    return sendCommand(command);
}

bool SR844::setBufferMode(const std::string &bufferMode) const {
    return setBufferMode(bufferModeNumberFromString(bufferMode));
}

std::string SR844::getBufferMode() const {
    return bufferModeStringFromNumber(std::stoi(ask(commands.BufferMode + query_suffix)));
}

bool SR844::startBuffer() const {
    return sendCommand(commands.StartBuffer);
}

bool SR844::pauseBuffer() const {
    return sendCommand(commands.PauseBuffer);
}

bool SR844::stopBuffer() const {
    return sendCommand(commands.StopBuffer);
}

int SR844::getBufferSize() const{
    return std::stoi(ask(commands.BufferSize + query_suffix));
}
