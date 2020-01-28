#ifndef LOCKINAMPLIFAER_H
#define LOCKINAMPLIFAER_H



#include "../SRS.h"

#include <vector>
#include <string>
#include <map>

class LockInAmplifier : public SRS
{
protected:
    struct LockInAmplifierRanges // LockInAmplifierSettings
    {
        //The worst values of all the models
        double minInternalFrequency = 1E-3;
        double maxInternalFrequency = 102E3;

        int minHarmonic = 1;
        int maxHarmonic = 99;

        double minPhase = -180.0;
        double maxPhase = +180.0;

        double minSineAmplitude = 4E-3;
        double maxSineAmplitude = 2.0;
    };

    //Как использовать этот state?
    struct LockInAmplifierState
    {
        double InternalFrequency;
        int Harmonic;
        double Phase;

        double SineAmplitude;
    };

    std::vector <std::string> timeConstant;
public:
    LockInAmplifier();
    ~LockInAmplifier();

    int numberFromString(const std::vector< std::string> &vector, const std::string &string) const;
    std::string stringFromNumber(const std::vector< std::string> &vector, const int &number) const;
    bool isValidString(const std::vector< std::string> &vector, const std::string &string) const;
    bool isValidNumber(const std::vector< std::string> &vector, const int &number) const;

    bool isValidPhase(const double &phase) const;
    bool setInternalPhase(const double &phase) const;
    bool autoPhase() const;
    std::string getPhase() const;

    double getMinInternalFrequency() const;
    double getMaxInternalFrequency() const;
    bool isValidInternalFrequency(const double &frequency) const;
    bool setInternalFrequency(const double &frequency) const;
    std::string getInternalFrequency() const;
    std::string getExternalFrequency() const;
    std::string getFrequencyDetect() const;
    std::string getFrequency() const;


    int getMinHarmonic() const;
    int getMaxHarmonic() const;
    bool isValidHarmonic(const int &i) const;
    bool setHarmonic(const int &i) const;
    std::string getHarmonic() const;

    double getMinSineAmplitude() const;
    double getMaxSineAmplitude() const;
    bool isValidSineAmplitude(const double &voltage) const;
    bool setSineAmplitude(const double &voltage) const;
    std::string getSineAmplitude() const;

    std::vector<std::string> getTimeConstantList() const;
    int timeConstantNumberFromString(const std::string  &timeConstant_string) const;
    std::string timeConstantStringFromNumber(const int &timeConstant_number) const;
    bool setTimeConstant(const int &timeConstant) const;
    bool setTimeConstant(const std::string &timeConstant) const;
    std::string getTimeConstant() const;




   /* double getMinSineOutAmplitude() const;
    double getMaxSineOutAmplitude() const;
    bool isValidSineOutAmplitude(const double &sineAmplitude) const;
    bool setSineOutAmplitude(const double &sineAmplitude) const;
    double getSineOutAmplitude() const;

    void initReferenceSourceList();
    QStringList getReferenceSourceList() const;
    int refSourceNumberFromString(const QString &ref_string) const;
    QString refSourceStringFromNumber(const int &ref_number) const;
    bool setReferenceSource(const int &source) const;
    bool setReferenceSource(const QString &source) const;
    QString getReferenceSource() const;

    void initReferenceTriggerModeList();
    QStringList getReferenceTriggerModeList() const;
    int refModeNumberFromString(const QString &mode_string) const;
    QString refModeStringFromNumber(const int &mode_number) const;
    bool setReferenceTriggerMode(const int &mode) const;
    bool setReferenceTriggerMode(const QString &mode) const;
    QString getReferenceTriggerMode() const;

    void initSignalInputList();
    QStringList getSignalInputList() const;
    int signalInputNumberFromString(const QString &signalInput_string) const;
    QString signalInputStringFromNumber(const int &signalInput_number) const;
    bool setSignalInput(const int &signalInput) const;
    bool setSignalInput(const QString &signalInput) const;
    QString getSignalInput() const;

    void initVoltageInputCouplingList();
    QStringList getVoltageInputCouplingList() const;
    int voltageInputCouplingNumberFromString(const QString &voltageInputCoupling_string) const;
    QString voltageInputCouplingStringFromNumber(const int &voltageInputCoupling_number) const;
    bool setVoltageInputCoupling(const int &voltageInputCoupling) const;
    bool setVoltageInputCoupling(const QString &voltageInputCoupling) const;
    QString getVoltageInputCoupling() const;

    void initVoltageInputShieldsList();
    QStringList getVoltageInputShieldsList() const;
    int voltageInputShieldsNumberFromString(const QString &voltageInputShields_string) const;
    QString voltageInputShieldsStringFromNumber(const int &voltageInputShields_number) const;
    bool setVoltageInputShields(const int &voltageInputShields) const;
    bool setVoltageInputShields(const QString &voltageInputShields) const;
    QString getVoltageInputShields() const;

    void initInputLineNotchFilterList();
    QStringList getInputLineNotchFilterList() const;
    int inputLineNotchFilterNumberFromString(const QString &inputLineNotchFilter_string) const;
    QString inputLineNotchFilterStringFromNumber(const int &inputLineNotchFilter_number) const;
    bool setInputLineNotchFilter(const int &inputLineNotchFilter) const;
    bool setInputLineNotchFilter(const QString &inputLineNotchFilter) const;
    QString getInputLineNotchFilter() const;

    void initSensivityList();
    QStringList getSensivityList() const;
    int sensivityNumberFromString(const QString &sensivity_string) const;
    QString sensivityStringFromNumber(const int &sensivity_number) const;
    bool setSensivity(const int &sensivity) const;
    bool setSensivity(const QString &sensivity) const;
    QString getSensivity() const;

    void initReserveModeList();
    QStringList getReserveModeList() const;
    int reserveModeNumberFromString(const QString &reserveMode_string) const;
    QString reserveModeStringFromNumber(const int &reserveMode_number) const;
    bool setReserveMode(const int &reserveMode) const;
    bool setReserveMode(const QString &reserveMode) const;
    QString getReserveMode() const;*/

    //void initTimeConstantList();


    /*void initFilterList();
    QStringList getFilterList() const;
    int filterNumberFromString(const QString &filter_string) const;
    QString filterStringFromNumber(const int &filter_number) const;
    bool setFilter(const int &filter) const;
    bool setFilter(const QString &filter) const;
    QString getFilter() const;

    bool enableSynchronousFilter(const bool &enable) const;
    bool getSynchronousFilterEnabled() const;

    bool enableRS232outputInterface() const;

    bool autoGain() const;

    bool autoReserve() const;

    bool autoPhase() const;

    bool autoOffset(const int &i) const;
    bool autoOffsetAll() const;

    void initSampleRateList();
    QStringList getSampleRateList() const;
    int sampleRateNumberFromString(const QString &sampleRate_string) const;
    QString sampleRateStringFromNumber(const int &sampleRate_number) const;
    bool setSampleRate(const int &sampleRate) const;
    bool setSampleRate(const QString &sampleRate) const;
    QString getSampleRate() const;

    void initBufferModeList();
    QStringList getBufferModeList() const;
    int bufferModeNumberFromString(const QString &bufferMode_string) const;
    QString bufferModeStringFromNumber(const int &bufferMode_number) const;
    bool setBufferMode(const int &bufferMode) const;
    bool setBufferMode(const QString &bufferMode) const;
    QString getBufferMode() const;

    bool startBuffer() const;
    bool pauseBuffer() const;
    bool stopBuffer() const;

    void initOutputNumberList();
    QStringList getOutputNumberList() const;
    int outpNumberFromString(const QString &outp_string) const;
    QString outpStringFromNumber(const int &outp_number) const;
    double getOUTP(const int &i) const;
    double getOUTP(const QString &i) const;
    double getX() const;
    double getY() const;
    double getR() const;
    double getTheta() const;
    bool getAB(const int &Apos, double &A, const int &Bpos, double &B) const;
    bool getABC(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C) const;
    bool getABCDE(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C, const int &Dpos, double &D, const int &Epos, double &E) const;
    bool getABCDEF(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C, const int &Dpos, double &D, const int &Epos, double &E, const int &Fpos, double &F) const;
    bool getXY(double &X, double &Y) const;
    bool getRTheta(double &R, double &Theta) const;
    bool getRThetaF(double &R, double &Theta, double &F) const;
    bool getXYRThetaF(double &X, double&Y, double &R, double &Theta, double &F) const;

    bool setDisplayData(const int &channel, const int &data) const;
    int getBufferSize() const;

    double getPointFromBuffer(const int &channel, const int &number) const;
    std::vector < double > getChannelFromBuffer(const int &channel) const;
    int getBuffer(std::vector < double > &ch1, std::vector < double > &ch2) const;
*/
protected:

    LockInAmplifierRanges ranges;
    LockInAmplifierState state;

    void SetRanges(const LockInAmplifierRanges &new_ranges);

    void SetTimeConstantList( const std::vector<std::string> &new_time_constantlist);


    std::unordered_map < std::string , QSerialPort::BaudRate    > lockinAmplifier_string_to_baud_rate    = {
                                                                                           // {  "1200", QSerialPort::Baud1200  },
                                                                                           // {  "2400", QSerialPort::Baud2400  },
                                                                                            //{  "4800", QSerialPort::Baud4800  },
                                                                                            {  "9600", QSerialPort::Baud9600  },
                                                                                            { "19200", QSerialPort::Baud19200 },
                                                                                            //{ "57600", QSerialPort::Baud57600 },
                                                                                            //{"115200", QSerialPort::Baud115200}
                                                                                           };
    std::unordered_map < std::string , QSerialPort::StopBits    > lockinAmplifier_string_to_stop_bits    = {
                                                                                                {  "1",  QSerialPort::OneStop       }
                                                                                               };

    std::unordered_map < std::string , QSerialPort::FlowControl > lockinAmplifier_string_to_flow_control = {
                                                                                                {  "NO", QSerialPort::NoFlowControl  }
                                                                                               };

    const double sensivityReserve = 1.5;
    const double inputRangeReserve = 3;

    const double Err = 1E-11;
};

#endif // LOCKINAMPLIFAER_H
