#ifndef SR844_H
#define SR844_H


#include "../lockinamplifier.h"

#include <vector>
#include <string>
#include <map>

class SR844 : public LockInAmplifier
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
    SR844() : LockInAmplifier() {
        //something about ranges

        //something about commands

        timeConstant = {
                            "100 us",   "300 us",

                            "1 ms",     "3 ms",
                            "10 ms",    "30 ms",
                            "100 ms",   "300 ms",

                            "1 s",     "3 s",
                            "10 s",    "30 s",
                            "100 s",   "300 s",

                            "1 ks",     "3 ks",
                            "10 ks",    "30 ks",
                            "100 ks",   "300 ks",
                       };

        sensitivity =   {
                            "100 nVrms",   "300 nVrms",

                            "1 uVrms",     "3 uVrms",
                            "10 uVrms",    "30 uVrms",
                            "100 uVrms",   "300 uVrms",

                            "1 mVrms",     "3 mVrms",
                            "10 mVrms",    "30 mVrms",
                            "100 mVrms",   "300 mVrms",

                            "1 Vrms"
                        };

        outData =   {
                        "X",                    "Y",
                        "R [V]",                "R [dBm]",      "Theta",
                        "AUX IN1",              "AUX IN2",
                        "OUT1",                 "OUT2",
                        "Reference Frequency",
                        "CH1 display",          "CH2 display"
                    };
    }

    bool setConnection(const QString &portName, const int &new_baudrate);
    bool setInternalFrequency(const double &new_frequency) const;
    double getFrequency() const;
};

#endif // SR844_H
