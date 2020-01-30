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




