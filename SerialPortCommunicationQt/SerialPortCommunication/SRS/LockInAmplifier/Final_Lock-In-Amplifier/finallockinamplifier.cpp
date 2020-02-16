#include "finallockinamplifier.h"

finalLockInAmplifier::finalLockInAmplifier() {

}

finalLockInAmplifier::finalLockInAmplifier(const std::string new_model){
    setModel(new_model);
}

finalLockInAmplifier::~finalLockInAmplifier() {
    SR830->~SR830();
    SR844->~SR844();
    SR865->~SR865();
}

std::string finalLockInAmplifier::getModel() const {
    return this->lockInAmplifierModel;
}

void finalLockInAmplifier::setModel(const std::string new_model) {
    lockInAmplifierModel = new_model;
    return;
}
/*void SerialPortCommunicationQt::init() {
    init_subroutine(string_to_baud_rate   , baud_rate_to_string   , valid_baud_rate   );
    init_subroutine(string_to_data_bits   , data_bits_to_string   , valid_data_bits   );
    init_subroutine(string_to_flow_control, flow_control_to_string, valid_flow_control);
    init_subroutine(string_to_parity      , parity_to_string      , valid_parity      );
    init_subroutine(string_to_stop_bits   , stop_bits_to_string   , valid_stop_bits   );
    init_subroutine(string_to_direction   , direction_to_string   , valid_direction   );

    std::reverse(valid_baud_rate.begin()   , valid_baud_rate.end()   );
    std::sort   (valid_data_bits.begin()   , valid_data_bits.end()   );
    std::reverse(valid_data_bits.begin()   , valid_data_bits.end()   );
    std::reverse(valid_flow_control.begin(), valid_flow_control.end());
    std::reverse(valid_parity.begin()      , valid_parity.end()      );
    std::reverse(valid_stop_bits.begin()   , valid_stop_bits.end()   );
    std::reverse(valid_direction.begin()   , valid_direction.end()   );

    if (!serial) {
        serial = new QSerialPort();
    }

    if (!timer) {
        timer  = new Timer();
    }

    if (!TTS) {
        TTS = new double;
    }

    if (!TTR) {
        TTR = new double;
    }

    if (!throw_exceptions) {
        throw_exceptions = new bool;
    }

    *TTS = -1;
    *TTR = -1;

    *throw_exceptions = true;

    if (valid_baud_rate.size() == 1) {
        setBaudRate(valid_baud_rate[0]);
    }
    if (valid_data_bits.size() == 1) {
        setDataBits(valid_data_bits[0]);
    }
    if (valid_flow_control.size() == 1) {
        setFlowControl(valid_flow_control[0]);
    }
    if (valid_parity.size() == 1) {
        setParity(valid_parity[0]);
    }
    if (valid_stop_bits.size() == 1) {
        setStopBits(valid_stop_bits[0]);
    }

    return;
}

QString SerialPortCommunicationQt::serialNameFromString(const std::string &str) const {
    return to_QString(str);
}

std::string SerialPortCommunicationQt::serialNameToString() const {
    if (serial) {
        return to_StdString(serial->portName());
    } else {
        std::string error_msg = "Cannot get port name settings in serialNameToString() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

QSerialPort::BaudRate SerialPortCommunicationQt::serialBaudRateFromString(const std::string &str) const {
    if (string_to_baud_rate.count(str) > 0) {
        return string_to_baud_rate.at(str);
    } else {
        std::string error_msg = "Unknown baudrate " + str + " was passed into serialBaudRateFromString() function";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return QSerialPort::Baud9600; // Default value
        }
    }
}

std::string SerialPortCommunicationQt::serialBaudRateToString() const {
    if (serial) {
        return std::to_string(serial->baudRate());
    } else {
        std::string error_msg = "Cannot get port baudrate settings in serialBaudRateToString() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

QSerialPort::DataBits SerialPortCommunicationQt::serialDataBitsFromString(const std::string &str) const {
    if (string_to_data_bits.count(str) > 0) {
        return string_to_data_bits.at(str);
    } else {
        std::string error_msg = "Unknown data bits " + str + " was passed into serialDataBitsFromString() function";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return QSerialPort::Data8; // Default value
        }
    }
}

std::string SerialPortCommunicationQt::serialDataBitsToString() const {
    if (serial) {
        QSerialPort::DataBits data_bits = serial->dataBits();

        if (data_bits_to_string.count(data_bits) > 0) {
            return data_bits_to_string.at(data_bits);
        } else {
            std::string error_msg = "Cannot get port data bits settings in serialDataBitsToString() function as data bits setting is unknown";
            if (throw_exceptions) {
                throw error_msg;
            } else {
                return "";
            }
        }
    } else {
        std::string error_msg = "Cannot get port data bits settings in serialDataBitsToString() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

QSerialPort::FlowControl SerialPortCommunicationQt::serialFlowControlFromString(const std::string &str) const {
    if (string_to_flow_control.count(str) > 0) {
        return string_to_flow_control.at(str);
    } else {
        std::string error_msg = "Unknown flow control " + str + " was passed into serialFlowControlFromString() function";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return QSerialPort::NoFlowControl; // Default value
        }
    }
}

std::string SerialPortCommunicationQt::serialFlowControlToString() const {
    if (serial) {
        QSerialPort::FlowControl flow_control = serial->flowControl();

        if (flow_control_to_string.count(flow_control) > 0) {
            return flow_control_to_string.at(flow_control);
        } else {
            std::string error_msg = "Cannot get port flow control settings in serialFlowControlToString() function as flow control setting is unknown";
            if (throw_exceptions) {
                throw error_msg;
            } else {
                return "";
            }
        }
    } else {
        std::string error_msg = "Cannot get port flow control settings in serialFlowControlToString() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

QSerialPort::Parity SerialPortCommunicationQt::serialParityFromString(const std::string &str) const {
    if (string_to_parity.count(str) > 0) {
        return string_to_parity.at(str);
    } else {
        std::string error_msg = "Unknown parity " + str + " was passed into serialParityFromString() function";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return QSerialPort::NoParity; // Default value
        }
    }
}

std::string SerialPortCommunicationQt::serialParityToString() const {
    if (serial) {
        QSerialPort::Parity parity = serial->parity();

        if (parity_to_string.count(parity) > 0) {
            return parity_to_string.at(parity);
        } else {
            std::string error_msg = "Cannot get port parity settings in serialParityToString() function as parity setting is unknown";
            if (throw_exceptions) {
                throw error_msg;
            } else {
                return "";
            }
        }
    } else {
        std::string error_msg = "Cannot get port parity settings in serialParityToString() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

QSerialPort::StopBits SerialPortCommunicationQt::serialStopBitsFromString(const std::string &str) const {
    if (string_to_stop_bits.count(str) > 0) {
        return string_to_stop_bits.at(str);
    } else {
        std::string error_msg = "Unknown stop bits " + str + " was passed into serialStopBitsFromString() function";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return QSerialPort::OneStop; // Default value
        }
    }
}

std::string SerialPortCommunicationQt::serialStopBitsToString() const {
    if (serial) {
        QSerialPort::StopBits stop_bits = serial->stopBits();

        if (stop_bits_to_string.count(stop_bits) > 0) {
            return stop_bits_to_string.at(stop_bits);
        } else {
            std::string error_msg = "Cannot get port stop bits settings in serialStopBitsToString() function as stop bits setting is unknown";
            if (throw_exceptions) {
                throw error_msg;
            } else {
                return "";
            }
        }
    } else {
        std::string error_msg = "Cannot get port stop bits settings in serialStopBitsToString() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

QSerialPort::Direction SerialPortCommunicationQt::serialDirectionFromString(const std::string &str) const {
    if (string_to_direction.count(str) > 0) {
        return string_to_direction.at(str);
    } else {
        std::string error_msg = "Unknown directions " + str + " was passed into serialDirectionFromString() function";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return QSerialPort::AllDirections;
        }
    }
}

void SerialPortCommunicationQt::setSerial(QSerialPort* const new_serial) {
    if (serial) {
        delete serial;
    }

    external_serial_port = true;
    serial = new_serial;

    return;
}

QSerialPort* SerialPortCommunicationQt::getSerial() const {
    return serial;
}


std::vector < std::string > finalLockInAmplifier::getValidPortName() {

}

std::string SerialPortCommunicationQt::getPortName() const {
    if (serial) {
        return to_StdString(serial->portName());
    } else {
        std::string error_msg = "Cannot get port name settings in getPortName() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

void SerialPortCommunicationQt::setPortName(const std::string &new_port_name) const {
    if (serial) {
        serial->setPortName(to_QString(new_port_name));
    } else {
        std::string error_msg = "Cannot set port name settings " + new_port_name + " in setPortName() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            // do nothing
        }
    }

    return;
}

std::vector < std::string > SerialPortCommunicationQt::getValidBaudRate() const {
    return valid_baud_rate;
}

std::string SerialPortCommunicationQt::getBaudRate() const {
    if (serial) {
        return std::to_string(serial->baudRate());
    } else {
        std::string error_msg = "Cannot get port baud rate settings in getBaudRate() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

void SerialPortCommunicationQt::setBaudRate(const std::string &new_baud_rate) const {
    if (serial) {
        serial->setBaudRate(serialBaudRateFromString(new_baud_rate));
    } else {
        std::string error_msg = "Cannot set port baud rate settings " + new_baud_rate + " in setBaudRate() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            // do nothing
        }
    }

    return;
}

void SerialPortCommunicationQt::setBaudRate(const int &new_baud_rate) const {
    if (serial) {
        serial->setBaudRate(new_baud_rate);
    } else {
        std::string error_msg = "Cannot set port baud rate settings " + std::to_string(new_baud_rate) + " in setBaudRate() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            // do nothing
        }
    }

    return;
}

std::vector < std::string > SerialPortCommunicationQt::getValidDataBits() const {
    return valid_data_bits;
}

std::string SerialPortCommunicationQt::getDataBits() const {
    if (serial) {
        return serialDataBitsToString();
    } else {
        std::string error_msg = "Cannot get port data bits settings in getDataBits() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

void SerialPortCommunicationQt::setDataBits(const std::string &new_data_bits) const {
    if (serial) {
        serial->setDataBits(serialDataBitsFromString(new_data_bits));
    } else {
        std::string error_msg = "Cannot set port data bits settings " + new_data_bits + " in setDataBits() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            // do nothing
        }
    }

    return;
}

std::vector < std::string > SerialPortCommunicationQt::getValidFlowControl() const {
    return valid_flow_control;
}

std::string SerialPortCommunicationQt::getFlowControl() const {
    if (serial) {
        return serialFlowControlToString();
    } else {
        std::string error_msg = "Cannot get port flow control settings in getFlowControl() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

void SerialPortCommunicationQt::setFlowControl(const std::string &new_flow_control) const {
    if (serial) {
        serial->setFlowControl(serialFlowControlFromString(new_flow_control));
    } else {
        std::string error_msg = "Cannot set port flow control settings " + new_flow_control + " in setFlowControl() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            // do nothing
        }
    }

    return;
}

std::vector < std::string > SerialPortCommunicationQt::getValidParity() const {
    return valid_parity;
}

std::string SerialPortCommunicationQt::getParity() const {
    if (serial) {
        return serialParityToString();
    } else {
        std::string error_msg = "Cannot get port flow control settings in getParity() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

void SerialPortCommunicationQt::setParity(const std::string &new_parity) const {
    if (serial) {
        serial->setParity(serialParityFromString(new_parity));
    } else {
        std::string error_msg = "Cannot set port parity settings " + new_parity + " in setParity() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            // do nothing
        }
    }

    return;
}

std::vector < std::string > SerialPortCommunicationQt::getValidStopBits() const {
    return valid_stop_bits;
}

std::string SerialPortCommunicationQt::getStopBits() const {
    if (serial) {
        return serialStopBitsToString();
    } else {
        std::string error_msg = "Cannot get port stop bits settings in getStopBits() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            return "";
        }
    }
}

void SerialPortCommunicationQt::setStopBits(const std::string &new_stop_bits) const {
    if (serial) {
        serial->setStopBits(serialStopBitsFromString(new_stop_bits));
    } else {
        std::string error_msg = "Cannot set port parity settings " + new_stop_bits + " in setStopBits() function as serial is a null pointer";
        if (throw_exceptions) {
            throw error_msg;
        } else {
            // do nothing
        }
    }

    return;
}

void SerialPortCommunicationQt::setStringToBaudRate(const std::vector < std::string > &new_vector_to_baud_rate) {
    std::unordered_map < std::string , QSerialPort::BaudRate > new_string_to_baud_rate;
    for (const auto &str: new_vector_to_baud_rate) {
        if (string_to_baud_rate.count(str) > 0) {
            new_string_to_baud_rate[str] = string_to_baud_rate.at(str);
        }

    }
    string_to_baud_rate = new_string_to_baud_rate;

    init_subroutine(string_to_baud_rate, baud_rate_to_string, valid_baud_rate);
    std::reverse(valid_baud_rate.begin(), valid_baud_rate.end());

    return;
}

void SerialPortCommunicationQt::setStringToDataBits(const std::vector<std::string> &new_vector_to_data_bits) {
    std::unordered_map < std::string , QSerialPort::DataBits > new_string_to_data_bits;
    for (const auto &str: new_vector_to_data_bits) {
        if (string_to_data_bits.count(str) > 0) {
            new_string_to_data_bits[str] = string_to_data_bits.at(str);
        }

    }
    string_to_data_bits = new_string_to_data_bits;

    init_subroutine(string_to_data_bits, data_bits_to_string, valid_data_bits);
    std::reverse(valid_data_bits.begin(), valid_data_bits.end());

    return;
}

void SerialPortCommunicationQt::setStringToFlowControl(const std::vector<std::string> &new_vector_to_flow_control) {
    std::unordered_map < std::string , QSerialPort::FlowControl > new_string_to_flow_control;
    for (const auto &str: new_vector_to_flow_control) {
        if (string_to_flow_control.count(str) > 0) {
            new_string_to_flow_control[str] = string_to_flow_control.at(str);
        }

    }
    string_to_flow_control = new_string_to_flow_control;

    init_subroutine(string_to_flow_control, flow_control_to_string, valid_flow_control);
    std::reverse(valid_flow_control.begin(), valid_flow_control.end());

    return;
}

void SerialPortCommunicationQt::setStringToStopBits(const std::vector<std::string> &new_vector_to_stop_bits) {
    std::unordered_map < std::string , QSerialPort::StopBits > new_string_to_stop_bits;
    for (const auto &str: new_vector_to_stop_bits) {
        if (string_to_stop_bits.count(str) > 0) {
            new_string_to_stop_bits[str] = string_to_stop_bits.at(str);
        }

    }
    string_to_stop_bits = new_string_to_stop_bits;

    init_subroutine(string_to_stop_bits, stop_bits_to_string, valid_stop_bits);
    std::reverse(valid_stop_bits.begin(), valid_stop_bits.end());

    return;
}
void SerialPortCommunicationQt::setStringToDataBits(const std::unordered_map < std::string , QSerialPort::DataBits > &new_string_to_data_bits) {
    string_to_data_bits = new_string_to_data_bits;

    init_subroutine(string_to_data_bits, data_bits_to_string, valid_data_bits);
    std::sort   (valid_data_bits.begin(), valid_data_bits.end());
    std::reverse(valid_data_bits.begin(), valid_data_bits.end());

    return;
}

void SerialPortCommunicationQt::setStringToFlowControl(const std::unordered_map < std::string , QSerialPort::FlowControl > &new_string_to_flow_control) {
    string_to_flow_control = new_string_to_flow_control;

    init_subroutine(string_to_flow_control, flow_control_to_string, valid_flow_control);
    std::reverse(valid_flow_control.begin(), valid_flow_control.end());

    return;
}

void SerialPortCommunicationQt::setStringToParity(const std::vector < std::string > &new_vector_to_parity) {
    std::unordered_map < std::string , QSerialPort::Parity > new_string_to_parity;
    for (const auto &str: new_vector_to_parity) {
        if (string_to_parity.count(str) > 0) {
            new_string_to_parity[str] = string_to_parity.at(str);
        }

    }

    string_to_parity = new_string_to_parity;

    init_subroutine(string_to_parity, parity_to_string, valid_parity);
    std::reverse(valid_parity.begin(), valid_parity.end());

    return;
}

void SerialPortCommunicationQt::setStringToStopBits(const std::unordered_map < std::string , QSerialPort::StopBits > &new_string_to_stop_bits) {
    string_to_stop_bits = new_string_to_stop_bits;

    init_subroutine(string_to_stop_bits, stop_bits_to_string, valid_stop_bits);
    std::reverse(valid_stop_bits.begin(), valid_stop_bits.end());

    return;
}

bool SerialPortCommunicationQt::getThrowExceptions() const {
    return throw_exceptions;
}

void SerialPortCommunicationQt::setThrowExceptions(const bool &new_throw_exceptions) const {
    *throw_exceptions = new_throw_exceptions;

    return;
}*/

void finalLockInAmplifier::setWriteTimeout(const int &new_write_timeout) {
    if(this->lockInAmplifierModel == "SR830"){
        this->SR830->setWriteTimeout(new_write_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR844") {
        this->SR844->setWriteTimeout(new_write_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR865") {
        this->SR865->setWriteTimeout(new_write_timeout);
        return;
    }
}

int finalLockInAmplifier::getWriteTimeout() const {
    if(this->lockInAmplifierModel == "SR830")
        return  this->SR830->getWriteTimeout();
    if(this->lockInAmplifierModel == "SR844")
        return  this->SR844->getWriteTimeout();
    if(this->lockInAmplifierModel == "SR865")
        return  this->SR865->getWriteTimeout();
    return -1;
}

void finalLockInAmplifier::setReadTimeout(const int &new_read_timeout) {
    if(this->lockInAmplifierModel == "SR830"){
        this->SR830->setReadTimeout(new_read_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR844") {
        this->SR844->setReadTimeout(new_read_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR865") {
        this->SR865->setReadTimeout(new_read_timeout);
        return;
    }
}

int finalLockInAmplifier::getReadTimeout() const {
    if(this->lockInAmplifierModel == "SR830")
        return  this->SR830->getReadTimeout();
    if(this->lockInAmplifierModel == "SR844")
        return  this->SR844->getReadTimeout();
    if(this->lockInAmplifierModel == "SR865")
        return  this->SR865->getReadTimeout();
    return -1;
}

void finalLockInAmplifier::setReadWaitTimeout(const int &new_read_wait_timeout) {
    if(this->lockInAmplifierModel == "SR830"){
        this->SR830->setReadWaitTimeout(new_read_wait_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR844") {
        this->SR844->setReadWaitTimeout(new_read_wait_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR865") {
        this->SR865->setReadWaitTimeout(new_read_wait_timeout);
        return;
    }
}

int finalLockInAmplifier::getReadWaitTimeout() const {
    if(this->lockInAmplifierModel == "SR830")
        return  this->SR830->getReadWaitTimeout();
    if(this->lockInAmplifierModel == "SR844")
        return  this->SR844->getReadWaitTimeout();
    if(this->lockInAmplifierModel == "SR865")
        return  this->SR865->getReadWaitTimeout();
    return -1;
}

bool finalLockInAmplifier::isOpen() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->isOpen();
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->isOpen();
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->isOpen();
    return false;
}

bool finalLockInAmplifier::openSerial() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->openSerial();
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->openSerial();
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->openSerial();
    return false;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name, const std::string &new_baudrate, const std::string &new_data_bits, const std::string &new_stop_bits, const std::string &new_parity, const std::string &new_flow_control, const std::string &new_model) {
    setModel(new_model);
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);
    return false;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name, const std::string &new_baudrate, const std::string &new_data_bits, const std::string &new_stop_bits, const std::string &new_parity, const std::string &new_flow_control) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);
    return false;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name, const std::string &new_baudrate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->connect(new_port_name, new_baudrate);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->connect(new_port_name, new_baudrate);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->connect(new_port_name, new_baudrate);
    return false;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->connect(new_port_name);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->connect(new_port_name);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->connect(new_port_name);
    return false;
}

bool finalLockInAmplifier::disconnect() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->disconnect();
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->disconnect();
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->disconnect();
    return false;
}

bool finalLockInAmplifier::recieve(std::string &response) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->recieve(response);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->recieve(response);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->recieve(response);
    return false;
}

bool finalLockInAmplifier::send(const std::string &command, std::string &response, const bool &wait_for_response, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->send(command, response, wait_for_response, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->send(command, response, wait_for_response, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->send(command, response, wait_for_response, terminate);
    return false;
}

bool finalLockInAmplifier::sendCommand(const std::string &command, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->sendCommand(command, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->sendCommand(command, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->sendCommand(command, terminate);
    return false;
}

bool finalLockInAmplifier::sendQuery(const std::string &command, std::string &response, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->sendQuery(command, response, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->sendQuery(command, response, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->sendQuery(command, response, terminate);
    return false;
}

std::string finalLockInAmplifier::ask(const std::string &command, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->ask(command, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->ask(command, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->ask(command, terminate);
    return "wrong model";
}

double finalLockInAmplifier::getTTS() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->getTTS();
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->getTTS();
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->getTTS();;
}

double finalLockInAmplifier::getTTR() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->getTTR();
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->getTTR();
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->getTTR();;
}

std::vector < std::string > finalLockInAmplifier::getSupportedList() const {
    return this->SR830->getSupportedList();
}

int finalLockInAmplifier::getAttemptsToConnect() const {
    return this->SR830->getAttemptsToConnect();
}

void finalLockInAmplifier::setAttemptsToConnect(const int &new_attempts_to_connect) {
    this->SR830->setAttemptsToConnect(new_attempts_to_connect);
    this->SR844->setAttemptsToConnect(new_attempts_to_connect);
    this->SR865->setAttemptsToConnect(new_attempts_to_connect);

    return;
}

std::string finalLockInAmplifier::getIDN(bool* succeed) const {
    return this->SR844->getIDN(succeed);
}

std::string finalLockInAmplifier::getModel(bool* succeed) const {
    return this->SR865->getModel(succeed);
}

bool finalLockInAmplifier::isActive() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->SR830->isActive();
    if(this->lockInAmplifierModel == "SR844")
        return this->SR844->isActive();
    if(this->lockInAmplifierModel == "SR865")
        return this->SR865->isActive();;
    return false;
}

/*std::string SRS::detect(const std::string &port_name, bool *succeed) const {
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
}*/

/*std::map < std::string , std::vector < std::string > > SRS::scanAllPorts() const {
    std::map < std::string , std::vector < std::string > > result;

    for (const auto &current_port: getValidPortName()) {
        result[detect(current_port)].push_back(current_port);
    }

    return result;
}*/


bool finalLockInAmplifier::workWithPhas() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

bool finalLockInAmplifier::workWithAutoPhas() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinPhase() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMinPhase();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMinPhase();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMinPhase();
}

double finalLockInAmplifier::getMaxPhase() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMaxPhase();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMaxPhase();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMaxPhase();
}


bool finalLockInAmplifier::setInternalPhase(const double &phase) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setInternalPhase(phase);
    if (lockInAmplifierModel == "SR844")
        return SR844->setInternalPhase(phase);
    if (lockInAmplifierModel == "SR865")
        return SR865->setInternalPhase(phase);
    return false;
}

std::string finalLockInAmplifier::getPhase() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getPhase();
    if (lockInAmplifierModel == "SR844")
        return SR844->getPhase();
    if (lockInAmplifierModel == "SR865")
        return SR865->getPhase();
    return  "No ths model";
}

bool finalLockInAmplifier::autoPhase() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->autoPhase();
    if (lockInAmplifierModel == "SR844")
        return SR844->autoPhase();
    if (lockInAmplifierModel == "SR865")
        return SR865->autoPhase();
    return false;
}

bool finalLockInAmplifier::workWithFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinInternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMinInternalFrequency();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMinInternalFrequency();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMinInternalFrequency();
    return -1;
}

double finalLockInAmplifier::getMaxInternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMaxInternalFrequency();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMaxInternalFrequency();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMaxInternalFrequency();
    return -1;
}

bool finalLockInAmplifier::setFrequency(const double &frequency) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setFrequency(frequency);
    if (lockInAmplifierModel == "SR844")
        return SR844->setFrequency(frequency);
    if (lockInAmplifierModel == "SR865")
        return SR865->setFrequency(frequency);
    return false;
}

std::string finalLockInAmplifier::getFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return SR844->getFrequency();
    if (lockInAmplifierModel == "SR865")
        return SR865->getFrequency();
    return  "No this model";
}

std::string finalLockInAmplifier::getInternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return SR844->getFrequency();
    if (this->lockInAmplifierModel == "SR865")
        return SR865->getInternalFrequency();
    return  "no this model";
}

std::string finalLockInAmplifier::getExternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return SR844->getFrequency();
    if (this->lockInAmplifierModel == "SR865")
        return SR865->getExternalFrequency();
    return  "no this model";
}

std::string finalLockInAmplifier::getFrequencyDetect() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return SR844->getFrequencyDetect();
    if (this->lockInAmplifierModel == "SR865")
        return SR865->getFrequencyDetect();
    return  "no this model";
}

bool finalLockInAmplifier::workWithHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

int finalLockInAmplifier::getMinHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMinHarmonic();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMinHarmonic();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMinHarmonic();
    return -1;
}

int finalLockInAmplifier::getMaxHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMaxHarmonic();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMaxHarmonic();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMaxHarmonic();
    return -1;
}

bool finalLockInAmplifier::setHarmonic(const int &harmonic) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setHarmonic(harmonic);
    if (lockInAmplifierModel == "SR844")
        return SR844->setHarmonic(harmonic);
    if (lockInAmplifierModel == "SR865")
        return SR865->setHarmonic(harmonic);
    return false;
}

std::string finalLockInAmplifier::getHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getHarmonic();
    if (lockInAmplifierModel == "SR844")
        return SR844->getHarmonic();
    if (lockInAmplifierModel == "SR865")
        return SR865->getHarmonic();
    return  "No this model";
}

bool finalLockInAmplifier::workWithDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

int finalLockInAmplifier::getMinDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getMinDualHarmonic();
    return -1;
}

int finalLockInAmplifier::getMaxDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getMaxDualHarmonic();
    return -1;
}


bool finalLockInAmplifier::setDualHarmonic(const int &harmonic) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setDualHarmonic(harmonic);
    return false;
}

std::string finalLockInAmplifier::getDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getDualHarmonic();
    return  "No this model or this model can't work with dual harmonic";
}

bool finalLockInAmplifier::workWithSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMinSineAmplitude();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMinSineAmplitude();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMinSineAmplitude();
    //return -1;
}

double finalLockInAmplifier::getMaxSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getMaxSineAmplitude();
    if (lockInAmplifierModel == "SR844")
        return SR844->getMaxSineAmplitude();
    if (lockInAmplifierModel == "SR865")
        return SR865->getMaxSineAmplitude();
    //return -1;
}

bool finalLockInAmplifier::setSineAmplitude(const double &sineAmplitude) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setSineAmplitude(sineAmplitude);
    if (lockInAmplifierModel == "SR844")
        return SR844->setSineAmplitude(sineAmplitude);
    if (lockInAmplifierModel == "SR865")
        return SR865->setSineAmplitude(sineAmplitude);
    return false;
}

std::string finalLockInAmplifier::getSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getSineAmplitude();
    if (lockInAmplifierModel == "SR844")
        return SR844->getSineAmplitude();
    if (lockInAmplifierModel == "SR865")
        return SR865->getSineAmplitude();
    return  "No this model";
}


bool finalLockInAmplifier::workWithSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getMinSineDCLevel();
    return -1;
}

double finalLockInAmplifier::getMaxSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getMaxSineDCLevel();
    return -1;
}

bool finalLockInAmplifier::setSineDCLevel(const double &voltage) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setSineDCLevel(voltage);
    return false;
}

std::string finalLockInAmplifier::getSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getSineDCLevel();
    return  "No this model or this model can't work with dual harmonic";
}

bool finalLockInAmplifier::workWithRefSourse() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getRefSourceList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getRefSourceList();
    if (lockInAmplifierModel == "SR844")
        return SR844->getRefSourceList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getRefSourceList();
}

bool finalLockInAmplifier::setRefSource(const int &refSource) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setRefSource(refSource);
    if (lockInAmplifierModel == "SR844")
        return SR844->setRefSource(refSource);
    if (lockInAmplifierModel == "SR865")
        return SR865->setRefSource(refSource);
    return false;
}

bool finalLockInAmplifier::setRefSource(const std::string &refSource) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setRefSource(refSource);
    if (lockInAmplifierModel == "SR844")
        return SR844->setRefSource(refSource);
    if (lockInAmplifierModel == "SR865")
        return SR865->setRefSource(refSource);
    return false;
}

std::string finalLockInAmplifier::getRefSource() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getRefSource();
    if (lockInAmplifierModel == "SR844")
        return SR844->getRefSource();
    if (lockInAmplifierModel == "SR865")
        return SR865->getRefSource();
    return "No this model";
}

bool finalLockInAmplifier::workWithRefTriggerMode() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getRefTriggerModeList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getRefSourceList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getRefSourceList();
}

bool finalLockInAmplifier::setRefTriggerMode(const int &refTriggerMode) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setRefTriggerMode(refTriggerMode);
    if (lockInAmplifierModel == "SR865")
        return SR865->setRefTriggerMode(refTriggerMode);
    return false;
}

bool finalLockInAmplifier::setRefTriggerMode(const std::string &refTriggerMode) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setRefTriggerMode(refTriggerMode);
    if (lockInAmplifierModel == "SR865")
        return SR865->setRefTriggerMode(refTriggerMode);
    return false;
}

std::string finalLockInAmplifier::getRefTriggerMode() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getRefTriggerMode();
    if (lockInAmplifierModel == "SR865")
        return SR865->getRefTriggerMode();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::workWithRefTriggerOutput() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getRefTriggerOutputList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getRefTriggerOutputList();
    if (lockInAmplifierModel == "SR844")
        return SR844->getRefTriggerOutputList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getRefTriggerOutputList();
}

bool finalLockInAmplifier::setRefTriggerOutput(const int &refTriggerOutput) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR844")
        return SR844->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR865")
        return SR865->setRefTriggerOutput(refTriggerOutput);
    return false;
}

bool finalLockInAmplifier::setRefTriggerOutput(const std::string &refTriggerOutput) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR844")
        return SR844->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR865")
        return SR865->setRefTriggerOutput(refTriggerOutput);
    return false;
}

std::string finalLockInAmplifier::getRefTriggerOutput() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getRefTriggerOutput();
    if (lockInAmplifierModel == "SR844")
        return SR844->getRefTriggerOutput();
    if (lockInAmplifierModel == "SR865")
        return SR865->getRefTriggerOutput();
    return "No this model";
}


bool finalLockInAmplifier::workWithInputSignal() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputSignalList() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputSignalList();
}

bool finalLockInAmplifier::setInputSignal(const int &inputSignal) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputSignal(inputSignal);
    return false;
}

bool finalLockInAmplifier::setInputSignal(const std::string &inputSignal) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputSignal(inputSignal);
    return false;
}

std::string finalLockInAmplifier::getInputSignal() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputSignal();
    return "No this model or this model can't work with reference trigger mode";
}


bool finalLockInAmplifier::workWithInputVoltageMode() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageModeList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getInputVoltageModeList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageModeList();
}

bool finalLockInAmplifier::setInputVoltageMode(const int &inputVoltageMode) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setInputVoltageMode(inputVoltageMode);
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageMode(inputVoltageMode);
    return false;
}

bool finalLockInAmplifier::setInputVoltageMode(const std::string &inputVoltageMode) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setInputVoltageMode(inputVoltageMode);
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageMode(inputVoltageMode);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageMode() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getInputVoltageMode();
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageMode();
    return "No this model or this model can't work with reference trigger mode";
}


bool finalLockInAmplifier::workWithInputVoltageCoupling() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageCouplingList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getInputVoltageCouplingList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageCouplingList();
}

bool finalLockInAmplifier::setInputVoltageCoupling(const int &inputVoltageCoupling) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setInputVoltageCoupling(inputVoltageCoupling);
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageCoupling(inputVoltageCoupling);
    return false;
}

bool finalLockInAmplifier::setInputVoltageCoupling(const std::string &inputVoltageCoupling) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setInputVoltageCoupling(inputVoltageCoupling);
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageCoupling(inputVoltageCoupling);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageCoupling() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getInputVoltageCoupling();
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageCoupling();
    return "No this model or this model can't work with reference trigger mode";
}


bool finalLockInAmplifier::workWithInputVoltageShields() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageShieldsList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getInputVoltageShieldsList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageShieldsList();
}

bool finalLockInAmplifier::setInputVoltageShields(const int &inputVoltageShields) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setInputVoltageShields(inputVoltageShields);
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageShields(inputVoltageShields);
    return false;
}

bool finalLockInAmplifier::setInputVoltageShields(const std::string &inputVoltageShields) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setInputVoltageShields(inputVoltageShields);
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageShields(inputVoltageShields);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageShields() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getInputVoltageShields();
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageShields();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::workWithInputVoltageRange() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageRangeList() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageRangeList();
}

bool finalLockInAmplifier::setInputVoltageRange(const int &inputVoltageRange) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageRange(inputVoltageRange);
    return false;
}

bool finalLockInAmplifier::setInputVoltageRange(const std::string &inputVoltageRange) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputVoltageRange(inputVoltageRange);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageRange() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputVoltageRange();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::workWithInputCurrentGain() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputCurrentGainList() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputCurrentGainList();
}

bool finalLockInAmplifier::setInputCurrentGain(const int &inputCurrentGain) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputCurrentGain(inputCurrentGain);
    return false;
}

bool finalLockInAmplifier::setInputCurrentGain(const std::string &inputCurrentGain) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setInputCurrentGain(inputCurrentGain);
    return false;
}

std::string finalLockInAmplifier::getInputCurrentGain() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getInputCurrentGain();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::workWithSignalStrength() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

std::string finalLockInAmplifier::getSignalStrength() const {
    if (lockInAmplifierModel == "SR865")
        return  SR865->getSignalStrength();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::workWithSensitivity() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getSensitivityList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getSensitivityList();
    if (lockInAmplifierModel == "SR844")
        return SR844->getSensitivityList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getSensitivityList();
}

bool finalLockInAmplifier::setSensitivity(const int &sensitivity) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR844")
        return SR844->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR865")
        return SR865->setSensitivity(sensitivity);
    return false;
}

bool finalLockInAmplifier::setSensitivity(const std::string &sensitivity) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR844")
        return SR844->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR865")
        return SR865->setSensitivity(sensitivity);
    return false;
}

std::string finalLockInAmplifier::getSensitivity() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getSensitivity();
    if (lockInAmplifierModel == "SR844")
        return SR844->getSensitivity();
    if (lockInAmplifierModel == "SR865")
        return SR865->getSensitivity();
    return "No this model";
}


bool finalLockInAmplifier::workWithTimeConstant() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getTimeConstantList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getTimeConstantList();
    if (lockInAmplifierModel == "SR844")
        return SR844->getTimeConstantList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getTimeConstantList();
}

bool finalLockInAmplifier::setTimeConstant(const int &timeConstant) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR844")
        return SR844->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR865")
        return SR865->setTimeConstant(timeConstant);
    return false;
}

bool finalLockInAmplifier::setTimeConstant(const std::string &timeConstant) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR844")
        return SR844->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR865")
        return SR865->setTimeConstant(timeConstant);
    return false;
}

std::string finalLockInAmplifier::getTimeConstant() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getTimeConstant();
    if (lockInAmplifierModel == "SR844")
        return SR844->getTimeConstant();
    if (lockInAmplifierModel == "SR865")
        return SR865->getTimeConstant();
    return "No this model";
}


bool finalLockInAmplifier::workWithFilterSlope() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getFilterSlopeList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getFilterSlopeList();
    if (lockInAmplifierModel == "SR844")
        return SR844->getFilterSlopeList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getFilterSlopeList();
}

bool finalLockInAmplifier::setFilterSlope(const int &filterSlope) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR844")
        return SR844->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR865")
        return SR865->setFilterSlope(filterSlope);
    return false;
}

bool finalLockInAmplifier::setFilterSlope(const std::string &filterSlope) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR844")
        return SR844->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR865")
        return SR865->setFilterSlope(filterSlope);
    return false;
}

std::string finalLockInAmplifier::getFilterSlope() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getFilterSlope();
    if (lockInAmplifierModel == "SR844")
        return SR844->getFilterSlope();
    if (lockInAmplifierModel == "SR865")
        return SR865->getFilterSlope();
    return "No this model";
}


bool finalLockInAmplifier::workWithSynchronousFilter() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getSynchronousFilterList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getSynchronousFilterList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getSynchronousFilterList();
}

bool finalLockInAmplifier::setSynchronousFilter(const int &synchronousFilter) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setSynchronousFilter(synchronousFilter);
    if (lockInAmplifierModel == "SR865")
        return SR865->setSynchronousFilter(synchronousFilter);
    return false;
}

bool finalLockInAmplifier::setSynchronousFilter(const std::string &synchronousFilter) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->setSynchronousFilter(synchronousFilter);
    if (lockInAmplifierModel == "SR865")
        return SR865->setSynchronousFilter(synchronousFilter);
    return false;
}

std::string finalLockInAmplifier::getSynchronousFilter() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getSynchronousFilter();
    if (lockInAmplifierModel == "SR865")
        return SR865->getSynchronousFilter();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::workWithAdvanceFilter() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getAdvanceFilterList() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getAdvanceFilterList();
}

bool finalLockInAmplifier::setAdvanceFilter(const int &advanceFilter) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setAdvanceFilter(advanceFilter);
    return false;
}

bool finalLockInAmplifier::setAdvanceFilter(const std::string &advanceFilter) const {
    if (lockInAmplifierModel == "SR865")
        return SR865->setAdvanceFilter(advanceFilter);
    return false;
}

std::string finalLockInAmplifier::getAdvanceFilter() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->getAdvanceFilter();
    return "No this model or this model can't work with reference trigger mode";
}


bool finalLockInAmplifier::workWithAutoRange() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

bool finalLockInAmplifier::autoRange() const {
    if (lockInAmplifierModel == "SR865")
        return SR865->autoRange();
    return false;
}

bool finalLockInAmplifier::workWithAutoScale() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

bool finalLockInAmplifier::autoScale() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->autoScale();
    if (lockInAmplifierModel == "SR844")
        return SR844->autoScale();
    if (lockInAmplifierModel == "SR865")
        return SR865->autoRange();
    return false;
}

bool finalLockInAmplifier::workWithOutData() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

std::vector<std::string> finalLockInAmplifier::getOutDataList() const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getOutDataList();
    if (lockInAmplifierModel == "SR844")
        return SR844->getOutDataList();
    if (lockInAmplifierModel == "SR865")
        return SR865->getOutDataList();
}

std::string finalLockInAmplifier::getOutData(const int &outData) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getOutData(outData);
    if (lockInAmplifierModel == "SR844")
        return SR844->getOutData(outData);
    if (lockInAmplifierModel == "SR865")
        return SR865->getOutData(outData);
    return "No this model";
}

std::string finalLockInAmplifier::getOutData(const std::string &outData) const {
    if (lockInAmplifierModel == "SR830")
        return SR830->getOutData(outData);
    if (lockInAmplifierModel == "SR844")
        return SR844->getOutData(outData);
    if (lockInAmplifierModel == "SR865")
        return SR865->getOutData(outData);
    return "No this model";
}
