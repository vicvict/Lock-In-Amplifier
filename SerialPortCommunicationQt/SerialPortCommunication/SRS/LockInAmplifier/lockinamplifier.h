#ifndef LOCKINAMPLIFAER_H
#define LOCKINAMPLIFAER_H



#include "../SRS.h"

#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

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

    struct LockInAmplifierCommands
    {
        std::string Frequence = "FREQ";
        std::string FrequencyDetect = "FRAQ";
        std::string Harmonic  = "HARM";
        std::string HarmonicDual;
        std::string Phase     = "PHAS";
        std::string SineAmplitude = "SLVL";
        std::string SineDCLevel ;
        std::string TimeConstant = "OFLT";
        std::string RefSource = "FMOD";
        std::string RefTriggerMode;
        std::string RefTriggerOutput = "REFZ";
        std::string InputSignal;
        std::string InputVoltageMode = "ISRC";
        std::string InputVoltageCoupling = "ICPL";
        std::string InputVoltageShields = "IGND";
        std::string InputVoltageRange = "IRNG";
        std::string InputCurrentGain = "ICUR";
        std::string SignalStrength = "ILVL";
        std::string Sensitivity = "SENS";
        std::string FilterSlope = "OFSL";
        std::string SynchronousFilter = "SYNC";
        std::string AdvanceFilter = "ADVFILT";
        std::string InputSignalZ;
        std::string CloseReserveMode;

        std::string OutData = "OUTP";
        std::string CoupleOfData = "SNAP";

        std::string AutoPhase = "APHS";
        std::string AutoRange = "ARNG";
        std::string AutoScale = "ASCL";
        std::string AutoWideReverse;
        std::string AutoReserve;
    };

public:
    LockInAmplifier();
    ~LockInAmplifier();

    double getEpsilon() const;

    int numberFromString(const std::vector< std::string> &vector, const std::string &string) const;
    std::string stringFromNumber(const std::vector< std::string> &vector, const int &number) const;
    bool isValidString(const std::vector< std::string> &vector, const std::string &string) const;
    bool isValidNumber(const std::vector< std::string> &vector, const int &number) const;

    double getMinPhase() const;
    double getMaxPhase() const;
    bool isValidPhase(const double &phase) const;
    bool setInternalPhase(const double &phase) const;
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

    std::vector<std::string> getRefSourceList() const;
    int refSourceNumberFromString(const std::string  &refSource_string) const;
    std::string refSourceStringFromNumber(const int &refSource_number) const;
    bool setRefSource(const int &refSource) const;
    bool setRefSource(const std::string &refSource) const;
    std::string getRefSource() const;

    std::vector<std::string> getRefTriggerModeList() const;
    int refTriggerModeNumberFromString(const std::string  &refTriggerMode_string) const;
    std::string refTriggerModeStringFromNumber(const int &refTriggerMode_number) const;
    bool setRefTriggerMode(const int &refTriggerMode) const;
    bool setRefTriggerMode(const std::string &refTriggerMode) const;
    std::string getRefTriggerMode() const;

    std::vector<std::string> getRefTriggerOutputList() const;
    int refTriggerOutputNumberFromString(const std::string  &refTriggerOutput_string) const;
    std::string refTriggerOutputStringFromNumber(const int &refTriggerOutput_number) const;
    bool setRefTriggerOutput(const int &refTriggerOutput) const;
    bool setRefTriggerOutput(const std::string &refTriggerOutput) const;
    std::string getRefTriggerOutput() const;

    std::vector<std::string> getInputSignalList() const;
    int inputSignalNumberFromString(const std::string  &inputSignal_string) const;
    std::string inputSignalStringFromNumber(const int &inputSignal_number) const;
    bool setInputSignal(const int &inputSignal) const;
    bool setInputSignal(const std::string &inputSignal) const;
    std::string getInputSignal() const;

    std::vector<std::string> getInputVoltageModeList() const;
    int inputVoltageModeNumberFromString(const std::string  &inputVoltageMode_string) const;
    std::string inputVoltageModeStringFromNumber(const int &inputVoltageMode_number) const;
    bool setInputVoltageMode(const int &inputVoltageMode) const;
    bool setInputVoltageMode(const std::string &inputVoltageMode) const;
    std::string getInputVoltageMode() const;


    std::vector<std::string> getInputVoltageCouplingList() const;
    int inputVoltageCouplingNumberFromString(const std::string  &inputVoltageCoupling_string) const;
    std::string inputVoltageCouplingStringFromNumber(const int &inputVoltageCoupling_number) const;
    bool setInputVoltageCoupling(const int &inputVoltageCoupling) const;
    bool setInputVoltageCoupling(const std::string &inputVoltageCoupling) const;
    std::string getInputVoltageCoupling() const;

    std::vector<std::string> getInputVoltageShieldsList() const;
    int inputVoltageShieldsNumberFromString(const std::string  &inputVoltageShields_string) const;
    std::string inputVoltageShieldsStringFromNumber(const int &inputVoltageShields_number) const;
    bool setInputVoltageShields(const int &inputVoltageShields) const;
    bool setInputVoltageShields(const std::string &inputVoltageShields) const;
    std::string getInputVoltageShields() const;

    std::vector<std::string> getInputVoltageRangeList() const;
    int inputVoltageRangeNumberFromString(const std::string  &inputVoltageRange_string) const;
    std::string inputVoltageRangeStringFromNumber(const int &inputVoltageRange_number) const;
    bool setInputVoltageRange(const int &inputVoltageRange) const;
    bool setInputVoltageRange(const std::string &inputVoltageRange) const;
    std::string getInputVoltageRange() const;

    std::vector<std::string> getInputCurrentGainList() const;
    int inputCurrentGainNumberFromString(const std::string  &inputCurrentGain_string) const;
    std::string inputCurrentGainStringFromNumber(const int &inputCurrentGain_number) const;
    bool setInputCurrentGain(const int &inputCurrentGain) const;
    bool setInputCurrentGain(const std::string &inputCurrentGain) const;
    std::string getInputCurrentGain() const;

    std::string getSignalStrength() const;

    std::vector<std::string> getSensitivityList() const;
    int sensitivityNumberFromString(const std::string  &sensitivity_string) const;
    std::string sensitivityStringFromNumber(const int &sensitivity_number) const;
    bool setSensitivity(const int &sensitivity) const;
    bool setSensitivity(const std::string &sensitivity) const;
    std::string getSensitivity() const;

    std::vector<std::string> getFilterSlopeList() const;
    int filterSlopeNumberFromString(const std::string  &filterSlope_string) const;
    std::string filterSlopeStringFromNumber(const int &filterSlope_number) const;
    bool setFilterSlope(const int &filterSlope) const;
    bool setFilterSlope(const std::string &filterSlope) const;
    std::string getFilterSlope() const;

    std::vector<std::string> getSynchronousFilterList() const;
    int synchronousFilterNumberFromString(const std::string  &synchronousFilter_string) const;
    std::string synchronousFilterStringFromNumber(const int &synchronousFilter_number) const;
    bool setSynchronousFilter(const int &synchronousFilter) const;
    bool setSynchronousFilter(const std::string &synchronousFilter) const;
    std::string getSynchronousFilter() const;

    std::vector<std::string> getAdvanceFilterList() const;
    int advanceFilterNumberFromString(const std::string  &advanceFilter_string) const;
    std::string advanceFilterStringFromNumber(const int &advanceFilter_number) const;
    bool setAdvanceFilter(const int &advanceFilter) const;
    bool setAdvanceFilter(const std::string &advanceFilter) const;
    std::string getAdvanceFilter() const;

    //auto functions
    bool autoPhase() const;
    bool autoRange() const;
    bool autoScale() const;

    //output data functions
    std::vector<std::string> getOutDataList() const;
    int outDataNumberFromString(const std::string  &outData_string) const;
    std::string outDataStringFromNumber(const int &outData_number) const;
    std::string getOutData(const int &outData) const;
    std::string getOutData(const std::string &outData) const;
    bool getOutDataAB(const int &A, std::string &AValue, const int &B, std::string &BValue) const;
    bool getOutDataABC(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue) const;
    bool getOutDataAB(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue) const;
    bool getOutDataABC(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue) const;

protected:

    LockInAmplifierRanges ranges;
    LockInAmplifierState state;
    LockInAmplifierCommands commands;

    std::vector <std::string> timeConstant;
    std::vector <std::string> refSource;
    std::vector <std::string> refTriggerMode;
    std::vector <std::string> refTriggerOutput;
    std::vector <std::string> inputSignal;
    std::vector <std::string> inputVoltageMode;
    std::vector <std::string> inputVoltageCoupling;
    std::vector <std::string> inputVoltageShields;
    std::vector <std::string> inputVoltageRange;
    std::vector <std::string> inputCurrentGain;
    std::vector <std::string> sensitivity;
    std::vector <std::string> filterSlope;
    std::vector <std::string> synchronousFilter;
    std::vector <std::string> advanceFilter;

    //output data such as X, Y, R, Theta
    std::vector <std::string> outData;

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
    std::string invalidData = "-1";

    double epsilont = 0.01;
};

#endif // LOCKINAMPLIFAER_H
