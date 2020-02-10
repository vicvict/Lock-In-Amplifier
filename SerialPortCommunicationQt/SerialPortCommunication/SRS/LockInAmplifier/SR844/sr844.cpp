#include "sr844.h"

bool SR844:: autoWideReverse() const {
    return sendCommand(commands.AutoWideReverse);
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

std::vector<std::string> SR844::getOutDataChannel1List() const {
    return this->outDataChannel1;
}

int SR844::outDataChannel1NumberFromString(const std::string &outDataChannel1_string) const {
    return numberFromString(this->outDataChannel1, outDataChannel1_string);
}

std::string SR844::outDataChannel1StringFromNumber(const int &outDataChannel1_number) const {
    return stringFromNumber(this->outDataChannel1, outDataChannel1_number);
}


std::string SR844::getOutDataChannel1(const int& outDataChannel1) const {
    if (!isValidNumber(this->outDataChannel1, outDataChannel1))
        return invalidData;
    return ask(commands.OutData + query_suffix + separator + "1" + separator + std::to_string(outDataChannel1));
}

std::string SR844::getOutDataChannel1(const std::string &outDataChannel1) const{
    return getOutDataChannel1(outDataChannel1NumberFromString(outDataChannel1));
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


std::string SR844::getOutDataChannel2(const int& outDataChannel2) const {
    if (!isValidNumber(this->outDataChannel2, outDataChannel2))
        return invalidData;
    return ask(commands.OutData + query_suffix + separator + "2" + separator + std::to_string(outDataChannel2));
}

std::string SR844::getOutDataChannel2(const std::string &outDataChannel2) const{
    return getOutDataChannel2(outDataChannel2NumberFromString(outDataChannel2));
}

bool SR844::outDataAutoZeroChannel1(const int &outDataChannel1) const {
    if (!isValidNumber(this->outDataChannel1, outDataChannel1))
        return false;
    sendCommand(commands.AutoZero + separator + "1" + separator + std::to_string(outDataChannel1));
    return true;
}

bool SR844::outDataAutoZeroChannel2(const int &outDataChannel2) const {
    if (!isValidNumber(this->outDataChannel1, outDataChannel2))
        return false;
    sendCommand(commands.AutoZero + separator + "1" + separator + std::to_string(outDataChannel2));
    return true;
}

bool SR844::outDataAutoZeroChannel1(const std::string &outDataChannel1) const {
    return outDataAutoZeroChannel1(outDataChannel1NumberFromString(outDataChannel1));
}

bool SR844::outDataAutoZeroChannel2(const std::string &outDataChannel2) const {
    return outDataAutoZeroChannel2(outDataChannel2NumberFromString(outDataChannel2));
}
