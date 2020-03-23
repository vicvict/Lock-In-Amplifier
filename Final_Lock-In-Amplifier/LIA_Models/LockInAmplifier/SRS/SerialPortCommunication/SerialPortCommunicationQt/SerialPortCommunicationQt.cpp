// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "SerialPortCommunicationQt.h"

template < class T >
void init_subroutine (const std::unordered_map<std::string, T> &string_to_T, std::unordered_map<T, std::string> &T_to_string, std::vector < std::string > &valid_strings) {
    valid_strings.clear();
    T_to_string.clear();

    for (const auto &item : string_to_T) {
        T_to_string[item.second] = item.first;
        valid_strings.push_back(item.first);
    }

    return;
}

SerialPortCommunicationQt::SerialPortCommunicationQt() {
    init();
}

SerialPortCommunicationQt::~SerialPortCommunicationQt() {
    if (!external_serial_port) {
        delete serial;
    }
    
    delete timer;
    
    delete TTS;
    delete TTR;
}

void SerialPortCommunicationQt::init() {
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

std::vector < std::string > SerialPortCommunicationQt::getValidPortName() {
    std::vector < std::string > result;

    for(const QSerialPortInfo &info: QSerialPortInfo::availablePorts()) {
        result.push_back(to_StdString(info.portName()));
    }

    return result;
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
/*void SerialPortCommunicationQt::setStringToDataBits(const std::unordered_map < std::string , QSerialPort::DataBits > &new_string_to_data_bits) {
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
}*/

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

/*void SerialPortCommunicationQt::setStringToStopBits(const std::unordered_map < std::string , QSerialPort::StopBits > &new_string_to_stop_bits) {
    string_to_stop_bits = new_string_to_stop_bits;

    init_subroutine(string_to_stop_bits, stop_bits_to_string, valid_stop_bits);
    std::reverse(valid_stop_bits.begin(), valid_stop_bits.end());

    return;
}*/

bool SerialPortCommunicationQt::getThrowExceptions() const {
    return throw_exceptions;
}

void SerialPortCommunicationQt::setThrowExceptions(const bool &new_throw_exceptions) const {
    *throw_exceptions = new_throw_exceptions;

    return;
}

void SerialPortCommunicationQt::setWriteTimeout(const int &new_write_timeout) {
    write_timeout = new_write_timeout;

    return;
}

int SerialPortCommunicationQt::getWriteTimeout() const {
    return  write_timeout;
}

void SerialPortCommunicationQt::setReadTimeout(const int &new_read_timeout) {
    read_timeout = new_read_timeout;

    return;
}

int SerialPortCommunicationQt::getReadTimeout() const {
    return read_timeout;
}

void SerialPortCommunicationQt::setReadWaitTimeout(const int &new_read_wait_timeout) {
    read_wait_timeout = new_read_wait_timeout;

    return;
}

int SerialPortCommunicationQt::getReadWaitTimeout() const {
    return  read_wait_timeout;
}

bool SerialPortCommunicationQt::isOpen() const {
    if (serial) {
        return serial->isOpen();
    } else {
        return false;
    }
}

bool SerialPortCommunicationQt::openSerial() const {
    if (serial) {
        if (!serial->open(QIODevice::ReadWrite)) {
            QSerialPort::SerialPortError error = serial->error();

            std::string error_msg = "Cannot open port " + to_StdString(serial->portName());
            if (error == QSerialPort::DeviceNotFoundError) {
                error_msg += ", error: device not found";
            } else if (error == QSerialPort::PermissionError) {
                error_msg += ", error: permission error";
            } else if (error == QSerialPort::OpenError) {
                error_msg += ", error: open error";
            } else if (error == QSerialPort::NotOpenError) {
                error_msg += ", error: not open error";
            } else if (error == QSerialPort::WriteError) {
                error_msg += ", error: write error";
            } else if (error == QSerialPort::ReadError) {
                error_msg += ", error: read error";
            } else if (error == QSerialPort::ResourceError) {
                error_msg += ", error: resource error";
            } else if (error == QSerialPort::UnsupportedOperationError) {
                error_msg += ", error: unsupported operation";
            } else if (error == QSerialPort::TimeoutError) {
                error_msg += ", error: timeout error";
            } else {
                error_msg += ", error: unknown error";
            }

            if (throw_exceptions) {
                throw error_msg;
            }

            return false;
        } else {
            return true;
        }
    } else {
        std::string error_msg = "Cannot open port because serial is nullptr";
        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }
}

bool SerialPortCommunicationQt::connect(const std::string &new_port_name, const std::string &new_baudrate, const std::string &new_data_bits, const std::string &new_stop_bits, const std::string &new_parity, const std::string &new_flow_control) const {
    if (serial) {
        setBaudRate(new_baudrate);
        setDataBits(new_data_bits);
        setStopBits(new_stop_bits);
        setParity(new_parity);
        setFlowControl(new_flow_control);

        return connect(new_port_name);
    } else {
        std::string error_msg = "Cannot set serial connection as serial is a nullptr";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }
}

bool SerialPortCommunicationQt::connect(const std::string &new_port_name, const std::string &new_baudrate) const {
    if (serial) {
        setBaudRate(new_baudrate);

        return connect(new_port_name);
    } else {
        std::string error_msg = "Cannot set serial connection as serial is a nullptr";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }
}

bool SerialPortCommunicationQt::connect(const std::string &new_port_name) const {
    if (serial) {
        setPortName(new_port_name);

        return openSerial();
    } else {
        std::string error_msg = "Cannot set serial connection as serial is a nullptr";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }
}

bool SerialPortCommunicationQt::disconnect() const {
    if (serial) {
        if (serial->isOpen()) {
            serial->close();

            return true;
        } else {
            std::string error_msg = "Cannot disconnect serial as serial is not opened";

            if (throw_exceptions) {
                throw error_msg;
            }

            return false;
        }
    } else {
        std::string error_msg = "Cannot disconnect serial as serial is a nullptr";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }
}

bool SerialPortCommunicationQt::recieve(std::string &response) const {
    if (serial->waitForReadyRead(read_timeout)) {
        QByteArray response_data = serial->readAll();

        while (serial->waitForReadyRead(read_wait_timeout)) {
            response_data += serial->readAll();
        }

        response = to_StdString(QString(response_data));

        *TTR = 0.001 * timer->usecElapsedNow() - *TTS;

        return true;
    } else {
        std::string error_msg = "No data recieved via serial but expected to";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }
}

bool SerialPortCommunicationQt::send(const std::string &command, std::string &response, const bool &wait_for_response, const std::string &terminate) const {
    *TTS = *TTR = -1;

    timer->start();

    response.clear();

    if (!serial) {
        std::string error_msg = "Cannot send data via serial as serial is a nullptr";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }

    if (!serial->isOpen()) {
        std::string error_msg = "Cannot send data via serial as serial is not opened";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }

    std::string modified_command = command + terminate;

    if (serial->write(modified_command.c_str()) > 0) {
        *TTS = 0.001 * timer->usecElapsedNow();

        if (wait_for_response) {
            return recieve(response);
        } else {
            return true;
        }
    } else {
        std::string error_msg = "Cannot send data via serial as no bytes were sent";

        if (throw_exceptions) {
            throw error_msg;
        }

        return false;
    }
}

bool SerialPortCommunicationQt::sendCommand(const std::string &command, const std::string &terminate) const {
    std::string response = "";

    return send(command, response, false, terminate);
}

bool SerialPortCommunicationQt::sendQuery(const std::string &command, std::string &response, const std::string &terminate) const {
    return send(command, response, true, terminate);
}

std::string SerialPortCommunicationQt::ask(const std::string &command, const std::string &terminate) const {
    std::string response = "";

    sendQuery(command, response, terminate);

    return response;
}

/// @anchor ref_getTTS
double SerialPortCommunicationQt::getTTS() const {
    return *TTS;
}

double SerialPortCommunicationQt::getTTR() const {
    return *TTR;
}


