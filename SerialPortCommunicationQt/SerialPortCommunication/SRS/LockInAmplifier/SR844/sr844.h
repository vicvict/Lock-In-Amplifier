#ifndef SR844_H
#define SR844_H


#include "../../SRS.h"

#include <vector>
#include <string>
#include <map>

class SR844 : public SRS
{
protected:
    double frequency;
    std::unordered_map < std::string , QSerialPort::BaudRate    > SRS844_string_to_baud_rate    = {
                                                                                                {"9600", QSerialPort::Baud9600 }
                                                                                               };

    std::unordered_map < std::string , QSerialPort::DataBits    > SRS844_string_to_data_bits    = {
                                                                                                {"8", QSerialPort::Data8}
                                                                                               };
    std::unordered_map < std::string , QSerialPort::FlowControl > SRS844_string_to_flow_control = {
                                                                                                {  "NO", QSerialPort::NoFlowControl  }
                                                                                               };
    std::unordered_map < std::string , QSerialPort::Parity      > SRS844_string_to_parity       = {
                                                                                                {   "NO", QSerialPort::NoParity   }
                                                                                               };
    std::unordered_map < std::string , QSerialPort::StopBits    > SRS844_string_to_stop_bits    = {
                                                                                                {  "1",  QSerialPort::OneStop       }
                                                                                               };
public:
    SR844();

    bool setConnection(const QString &portName, const int &new_baudrate);
    bool setInternalFrequency(const double &new_frequency) const;
    double getFrequency() const;
};

#endif // SR844_H
