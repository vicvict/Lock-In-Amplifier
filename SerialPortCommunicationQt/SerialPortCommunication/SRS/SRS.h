#ifndef SRS_H
#define SRS_H

#include "../../Timer.h"
#include "../../QtSTLConvertion.h"

#include "../SerialPortCommunication.h"

#include <vector>
#include <string>
#include <map>
#include <algorithm>

class SRS : public SerialPortCommunication {
public:
    explicit SRS();
    ~SRS();

    std::vector < std::string > getSupportedList() const;

    int  getAttemptsToConnect(                                  ) const;
    void setAttemptsToConnect(const int &new_attempts_to_connect)      ;

    std::string getIDN  (bool* succeed = nullptr) const;
    std::string getModel(bool* succeed = nullptr) const;

    bool isActive() const;

    std::string detect(const std::string &port_name, bool* succeed = nullptr) const;

    std::map < std::string , std::vector < std::string > > scanAllPorts() const;

protected:
    std::vector < std::string > supported_models = {
                                                    "DS335", "DS345",
                                                    "SR830", "SR844", "SR865", "SR865A",
                                                    "PTC10"
                                                   };

    int attempts_to_connect = 5;
    //А как же LF = "\r"?
    inline static const std::string command_terminator = "\n";

    inline static const std::string query_suffix = "?";
    inline static const std::string separator    = " ";
    inline static const std::string comma        = ",";

    inline static const std::string IDN = "*IDN";

    std:: vector < std::string > SRS_vector_to_baud_rate  = {
                                                                "1200", "2400",
                                                                "4800", "9600",
                                                                "19200", "38400",
                                                                "57600", "115200"
                                                            };

    std:: vector < std::string > SRS_vector_to_data_bits  = {
                                                                "8"
                                                            };

    std:: vector < std::string > SRS_vector_to_flow_control  = {
                                                                   "NO",
                                                                   "HARD"
                                                               };


    /*std::unordered_map < std::string , QSerialPort::DataBits    > SRS_string_to_data_bits    = {
                                                                                                {"8", QSerialPort::Data8}
                                                                                               };
    std::unordered_map < std::string , QSerialPort::FlowControl > SRS_string_to_flow_control = {
                                                                                                {  "NO", QSerialPort::NoFlowControl  },
                                                                                                {"HARD", QSerialPort::HardwareControl}
                                                                                               };*/
    std::vector < std::string > SRS_vector_to_parity       = {
                                                                "NO",
                                                                "EVEN",
                                                                "ODD"
                                                             };
   /* std::unordered_map < std::string , QSerialPort::Parity      > SRS_string_to_parity       = {
                                                                                                {   "NO", QSerialPort::NoParity   },
                                                                                                {  "ODD", QSerialPort::OddParity  },
                                                                                                { "EVEN", QSerialPort::EvenParity }
                                                                                               };*/
    /*std::unordered_map < std::string , QSerialPort::StopBits    > SRS_string_to_stop_bits    = {
                                                                                                {  "1",  QSerialPort::OneStop       },
                                                                                                {  "2",  QSerialPort::TwoStop       }
                                                                                               };*/
    std::vector < std::string > SRS_vector_to_stop_bits       = {
                                                                    "1",
                                                                    "2"
                                                                };
};

#endif // SRS_H
