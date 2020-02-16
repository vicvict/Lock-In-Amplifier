#ifndef SR865_H
#define SR865_H


#include "../lockinamplifier.h"

#include <vector>
#include <string>
#include <map>


class SR865: public LockInAmplifier
{
public:
    SR865() : LockInAmplifier() {
        ranges.minInternalFrequency = 0.001;
        ranges.maxInternalFrequency = 2.5E6;
        ranges.minPhase = -180;
        ranges.maxPhase = 180;
        ranges.minHarmonic = 1;
        ranges.maxHarmonic = 99;
        ranges.minSineAmplitude = 1E-9;
        ranges.maxSineAmplitude = 2.0;

        commands.FrequencyDetect = "FREQDET";
        commands.RefSource = "RSRC";
        commands.HarmonicDual = "HARMDUAL";
        commands.SineDCLevel = "SOFF";
        commands.RefTriggerMode = "RTRG";
        commands.InputSignal = "IVMD";
        commands.Sensitivity = "SCAL";
        commands.InputVoltageMode = "ISRC";
        commands.AdvanceFilter = "ADVFILT";
        commands.AutoScale = "ASCL";
        commands.AutoRange = "ARNG";

        timeConstant = {
                            "1 us",     "3 us",
                            "10 us",    "30 us",
                            "100 us",   "300 us",

                            "1 ms",     "3 ms",
                            "10 ms",    "30 ms",
                            "100 ms",   "300 ms",

                            "1 s",      "3 s",
                            "10 s",     "30 s",
                            "100 s",    "300 s",

                            "1 ks",     "3 ks",
                            "10 ks",    "30 ks"
                       };


        refSource =    {
                          "INT", "EXT", "DUAL", "CHOP"
                       };

        refTriggerMode =    {
                                "SIN" , "POSTTL", "NEGTTL"
                            };

        refTriggerOutput =  {
                                "50 Ohm", "1 MOhm"
                            };

        inputSignal =       {
                                "VOLTage", "CURRent"
                            };

        inputVoltageMode = {
                                "A", "A-B"
                           };

        inputVoltageCoupling =  {
                                    "AC", "DC"
                                };

        inputVoltageShields =   {
                                    "Float", "Ground"
                                };

        inputVoltageRange =     {
                                    "1 V", "300 mV", "100 mV", "30 mV", "10 mV"
                                };

        inputCurrentGain =      {
                                    "1 uA", "10 nA"
                                };

        sensitivity =   {
                            "1 V",

                            "500 mV",   "200 mV",   "100 mV",
                            "50 mV",    "20 mV",    "10 mV",
                            "5 mV",     "2 mV",     "1 mV",

                            "500 uV",   "200 uV",   "100 uV",
                            "50 uV",    "20 uV",    "10 uV",
                            "5 uV",     "2 uV",     "1 uV",

                            "500 nV",   "200 nV",   "100 nV",
                            "50 nV",    "20 nV",    "10 nV",
                            "5 nV",     "2 nV",     "1 nV",
                        };

        filterSlope =   {
                            "6 dB", "12 dB", "18 dB", "24 dB"
                        };

        synchronousFilter =     {
                                    "Off", "On"
                                };

        advanceFilter = {
                            "Off", "On"
                        };

        outData =   {
                        "X",        "Y",    "R",    "THETa",
                        "IN1",      "IN2",  "IN3",  "IN4",
                        "OUT1",     "OUT2",
                        "XNOise",   "YNOise",
                        "PHAse",    "SAMp",  "LEVel",
                        "FINT",     "FEXT"
                    };

        outDataCouple =    {
                                "X",        "Y",    "R",    "THETa",
                                "IN1",      "IN2",  "IN3",  "IN4",
                                "OUT1",     "OUT2",
                                "XNOise",   "YNOise",
                                "PHAse",    "SAMp",  "LEVel",
                                "FINT",     "FEXT"
                            };
    }

    bool autoRange() const;

    std::string getInternalFrequency() const;
    std::string getExternalFrequency() const;
    std::string getFrequencyDetect() const;

    int getMinDualHarmonic() const;
    int getMaxDualHarmonic() const;
    bool isValidDualHarmonic(const int &i) const;
    bool setDualHarmonic(const int &i) const;
    std::string getDualHarmonic() const;

    double getMinSineDCLevel() const;
    double getMaxSineDCLevel() const;
    bool isValidSineDCLevel(const double &voltage) const;
    bool setSineDCLevel(const double &voltage) const;
    std::string getSineDCLevel() const;

    std::vector<std::string> getRefTriggerModeList() const;
    int refTriggerModeNumberFromString(const std::string  &refTriggerMode_string) const;
    std::string refTriggerModeStringFromNumber(const int &refTriggerMode_number) const;
    bool setRefTriggerMode(const int &refTriggerMode) const;
    bool setRefTriggerMode(const std::string &refTriggerMode) const;
    std::string getRefTriggerMode() const;

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

protected:
    const int minHarmDual = 1;
    const int maxHarmDual = 99;

    const double minSineDCLevel = -5.00;
    const double maxSineDCLevel = +5.00;

    double SineDCLevel;

private:

};

#endif // SR865_H
