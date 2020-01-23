// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "SRS.h"

SRS::SRS() {
    setStringToDataBits(SRS_string_to_data_bits);
    setStringToFlowControl(SRS_string_to_flow_control);
    setStringToParity(SRS_string_to_parity);
    setStringToStopBits(SRS_string_to_stop_bits);

    init();
}

SRS::~SRS() {

}

std::vector < std::string > SRS::getSupportedList() const {
    return supported_models;
}

int SRS::getAttemptsToConnect() const {
    return attempts_to_connect;
}

void SRS::setAttemptsToConnect(const int &new_attempts_to_connect) {
    attempts_to_connect = new_attempts_to_connect;

    return;
}

std::string SRS::getIDN(bool* succeed) const {
    if (succeed) {
        *succeed = false;
    }

    auto result = ask(IDN + query_suffix, command_terminator);

    if (succeed) {
        *succeed = !result.empty();
    }

    return result;
}

std::string SRS::getModel(bool* succeed) const {
    if (succeed) {
        *succeed = false;
    }

    auto idn = getIDN(succeed);

    for (const auto &model: supported_models) {
        if (idn.find(model) != std::string::npos) {
            if (succeed) {
                *succeed = true;
            }

            return model;
        }
    }
    if (succeed) {
        *succeed = false;
    }

    return "failed to get model";
}

bool SRS::isActive() const {
    try {
        return !getIDN().empty();
    } catch (...) {
        return false;
    }
}

std::string SRS::detect(const std::string &port_name, bool *succeed) const {
    if (succeed) {
        *succeed = false;
    }

    if (isOpen()) {
        disconnect();
    }

    setPortName(port_name);
    for (const auto &current_baud_rate: valid_baud_rate) {
        setBaudRate(current_baud_rate);
        for (const auto &current_data_bits: valid_data_bits) {
            setDataBits(current_data_bits);
            for (const auto &current_flow_control: valid_flow_control) {
                setFlowControl(current_flow_control);
                for (const auto &current_parity: valid_parity) {
                    setParity(current_parity);
                    for (const auto &current_stop_bits: valid_stop_bits) {
                        setStopBits(current_stop_bits);

                        try {
                            if (openSerial()) {
                                auto model = getModel(succeed);

                                disconnect();

                                if (!model.empty()) {
                                    if (succeed) {
                                        *succeed = true;
                                    }

                                    return model;
                                }
                            }
                        } catch (...) {
                            if (isOpen()) {
                                disconnect();
                            }
                        }
                    }
                }
            }
        }
    }

    if (succeed) {
        *succeed = false;
    }

    return "";
}

std::map < std::string , std::vector < std::string > > SRS::scanAllPorts() const {
    std::map < std::string , std::vector < std::string > > result;

    for (const auto &current_port: getValidPortName()) {
        result[detect(current_port)].push_back(current_port);
    }

    return result;
}
