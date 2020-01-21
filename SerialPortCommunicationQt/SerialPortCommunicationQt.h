#ifndef SERIALPORTCOMMUNICATIONQT_H
#define SERIALPORTCOMMUNICATIONQT_H

#include "QtSTLConvertion.h"
#include "Timer.h"

#include <unordered_map>
#include <algorithm>
#include <iostream>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>

class SerialPortCommunicationQt {
public:
    explicit SerialPortCommunicationQt();
    ~SerialPortCommunicationQt();

    QSerialPort* getSerial(                             ) const;
    void         setSerial(QSerialPort* const new_serial)      ;

    static std::vector < std::string > getValidPortName   (                                   )      ;
           std::string                 getPortName        (                                   ) const;
           void                        setPortName        (const std::string &new_port_name   ) const;
           std::vector < std::string > getValidBaudRate   (                                   ) const;
           std::string                 getBaudRate        (                                   ) const;
           void                        setBaudRate        (const std::string &new_baud_rate   ) const;
           void                        setBaudRate        (const int         &new_baud_rate   ) const;
           std::vector < std::string > getValidDataBits   (                                   ) const;
           std::string                 getDataBits        (                                   ) const;
           void                        setDataBits        (const std::string &new_data_bits   ) const;
           std::vector < std::string > getValidFlowControl(                                   ) const;
           std::string                 getFlowControl     (                                   ) const;
           void                        setFlowControl     (const std::string &new_flow_control) const;
           std::vector < std::string > getValidParity     (                                   ) const;
           std::string                 getParity          (                                   ) const;
           void                        setParity          (const std::string &new_parity      ) const;
           std::vector < std::string > getValidStopBits   (                                   ) const;
           std::string                 getStopBits        (                                   ) const;
           void                        setStopBits        (const std::string &new_stop_bits   ) const;

    bool getThrowExceptions(                                ) const;
    void setThrowExceptions(const bool &new_throw_exceptions) const;

    int  getWriteTimeout   (                                ) const;
    void setWriteTimeout   (const int &new_write_timeout    )      ;
    int  getReadTimeout    (                                ) const;
    void setReadTimeout    (const int &new_read_timeout     )      ;
    int  getReadWaitTimeout(                                ) const;
    void setReadWaitTimeout(const int &new_read_wait_timeout)      ;

    bool isOpen    () const;
    bool openSerial() const;

    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ,
                 const std::string &new_data_bits   ,
                 const std::string &new_stop_bits   ,
                 const std::string &new_parity      ,
                 const std::string &new_flow_control) const;
    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ) const;
    bool connect(const std::string &new_port_name   ) const;
    bool disconnect() const;

    bool recieve    (                            std::string &response                                                                    ) const;
    bool send       (const std::string &command, std::string &response, const bool &wait_for_response, const std::string &terminate = "\n") const;
    bool sendCommand(const std::string &command,                                                       const std::string &terminate = "\n") const;
    bool sendQuery  (const std::string &command, std::string &response,                                const std::string &terminate = "\n") const;
    std::string ask (const std::string &command,                                                       const std::string &terminate = "\n") const;

    double getTTS() const;
    double getTTR() const;

protected:
    int write_timeout     = 10;
    int read_timeout      = 100;
    int read_wait_timeout = 10;

    QSerialPort *serial = nullptr;
    bool external_serial_port = false;

    Timer *timer = nullptr;

    double *TTS = nullptr;
    double *TTR = nullptr;

    bool *throw_exceptions = nullptr;

    void setStringToBaudRate   (const std::unordered_map < std::string , QSerialPort::BaudRate    > &new_string_to_baud_rate   );
    void setStringToDataBits   (const std::unordered_map < std::string , QSerialPort::DataBits    > &new_string_to_data_bits   );
    void setStringToFlowControl(const std::unordered_map < std::string , QSerialPort::FlowControl > &new_string_to_flow_control);
    void setStringToParity     (const std::unordered_map < std::string , QSerialPort::Parity      > &new_string_to_parity      );
    void setStringToStopBits   (const std::unordered_map < std::string , QSerialPort::StopBits    > &new_string_to_stop_bits   );

    std::unordered_map < std::string , QSerialPort::BaudRate    > string_to_baud_rate    = {
                                                                                            {  "1200", QSerialPort::Baud1200  },
                                                                                            {  "2400", QSerialPort::Baud2400  },
                                                                                            {  "4800", QSerialPort::Baud4800  },
                                                                                            {  "9600", QSerialPort::Baud9600  },
                                                                                            { "19200", QSerialPort::Baud19200 },
                                                                                            { "38400", QSerialPort::Baud38400 },
                                                                                            { "57600", QSerialPort::Baud57600 },
                                                                                            {"115200", QSerialPort::Baud115200}
                                                                                           };
    std::unordered_map < QSerialPort::BaudRate , std::string    > baud_rate_to_string       ;
    std::vector        < std::string                            > valid_baud_rate           ;

    std::unordered_map < std::string , QSerialPort::DataBits    > string_to_data_bits    = {
                                                                                            {"5", QSerialPort::Data5},
                                                                                            {"6", QSerialPort::Data6},
                                                                                            {"7", QSerialPort::Data7},
                                                                                            {"8", QSerialPort::Data8}
                                                                                           };
    std::unordered_map < QSerialPort::DataBits , std::string    > data_bits_to_string       ;
    std::vector        < std::string                            > valid_data_bits           ;

    std::unordered_map < std::string , QSerialPort::FlowControl > string_to_flow_control = {
                                                                                            {  "NO", QSerialPort::NoFlowControl  },
                                                                                            {"HARD", QSerialPort::HardwareControl},
                                                                                            {"SOFT", QSerialPort::SoftwareControl}
                                                                                           };
    std::unordered_map < QSerialPort::FlowControl , std::string > flow_control_to_string    ;
    std::vector        < std::string                            > valid_flow_control        ;

    std::unordered_map < std::string , QSerialPort::Parity      > string_to_parity       = {
                                                                                            {   "NO", QSerialPort::NoParity   },
                                                                                            {  "ODD", QSerialPort::OddParity  },
                                                                                            { "EVEN", QSerialPort::EvenParity },
                                                                                            {"SPACE", QSerialPort::SpaceParity},
                                                                                            { "MARK", QSerialPort::MarkParity }
                                                                                           };
    std::unordered_map < QSerialPort::Parity , std::string      > parity_to_string          ;
    std::vector        < std::string                            > valid_parity              ;

    std::unordered_map < std::string , QSerialPort::StopBits    > string_to_stop_bits    = {
                                                                                            {  "1",  QSerialPort::OneStop       },
                                                                                            {"1.5",  QSerialPort::OneAndHalfStop},
                                                                                            {  "2",  QSerialPort::TwoStop       }
                                                                                           };
    std::unordered_map < QSerialPort::StopBits , std::string    > stop_bits_to_string       ;
    std::vector        < std::string                            > valid_stop_bits           ;

    std::unordered_map < std::string , QSerialPort::Direction   > string_to_direction    = {
                                                                                            { "INPUT",  QSerialPort::Input        },
                                                                                            {"OUTPUT",  QSerialPort::Output       },
                                                                                            {   "ALL",  QSerialPort::AllDirections}
                                                                                           };
    std::unordered_map < QSerialPort::Direction , std::string   > direction_to_string       ;
    std::vector        < std::string                            > valid_direction           ;

    void init();

    QString                  serialNameFromString       (const std::string &str) const;
    std::string              serialNameToString         (                      ) const;
    QSerialPort::BaudRate    serialBaudRateFromString   (const std::string &str) const;
    std::string              serialBaudRateToString     (                      ) const;
    QSerialPort::DataBits    serialDataBitsFromString   (const std::string &str) const;
    std::string              serialDataBitsToString     (                      ) const;
    QSerialPort::FlowControl serialFlowControlFromString(const std::string &str) const;
    std::string              serialFlowControlToString  (                      ) const;
    QSerialPort::Parity      serialParityFromString     (const std::string &str) const;
    std::string              serialParityToString       (                      ) const;
    QSerialPort::StopBits    serialStopBitsFromString   (const std::string &str) const;
    std::string              serialStopBitsToString     (                      ) const;
    QSerialPort::Direction   serialDirectionFromString  (const std::string &str) const;
};

template < class T >
void init_subroutine(const std::unordered_map < std::string , T > &string_to_T  ,
                           std::unordered_map < T , std::string > &T_to_string  ,
                           std::vector        < std::string     > &valid_strings);

#endif // SERIALPORTCOMMUNICATIONQT_H
