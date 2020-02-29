#ifndef SR830_H
#define SR830_H


#include "LIA_Models/LockInAmplifier/lockinamplifier.h"

#include <vector>
#include <string>
#include <map>

///@bug outData = outDataCouple
class SR830: public LockInAmplifier
{
public:
    SR830() : LockInAmplifier() {
        ranges.minInternalFrequency = 0.001;
        ranges.maxInternalFrequency = 102000;
        ranges.minHarmonic = 1;
        ranges.maxHarmonic = 19999;
        ranges.minSineAmplitude = 0.004;
        ranges.maxSineAmplitude = 5.0;

        commands.RefTriggerMode = "RSLP";
        commands.InputVoltageMode = "ISRC";
        commands.AdvanceFilter = "ILIN";
        commands.CloseReserveMode = "RMOD";

        commands.AutoReserve = "ARSV";


        timeConstant = {
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

        sensitivity =   {
                                        "2 nV",     "5 nV",
                            "10 nV",    "20 nV",    "50 nV",
                            "100 nV",   "200 nV",   "500 nV",

                            "1 uV",     "2 uV",     "5 uV",
                            "10 uV",    "20 uV",    "50 uV",
                            "100 uV",   "200 uV",   "500 uV",

                            "1 mV",     "2 mV",     "5 mV",
                            "10 mV",    "20 mV",    "50 mV",
                            "100 mV",   "200 mV",   "500 mV",

                            "1 V"
                        };

        refSource = {
                        "EXT", "INT"
                    };

        refTriggerMode =    {
                                "Zero", "TTL rise", "TTL fail"
                            };

        inputVoltageMode =  {
                                "A", "A-B", "1 MOhm", "10 MOhm"
                            };

        inputVoltageShields =   {
                                    "Float", "Ground"
                                };

        inputVoltageCoupling =  {
                                    "AC", "DC"
                                };

        advanceFilter = {
                            "No", "Line notch", "2xLine notch", "Both notch"
                        };

        closeReserveMode =  {
                                "High", "Normal", "Low"
                            };

        filterSlope =   {
                            "6 dB", "12 dB", "18 dB", "24 dB"
                        };

        synchronousFilter = {
                                "Off", "On"
                            };

        outDataChannel1   = {
                                 "X",                    "R",

                                 "X noise",              "AUX IN1",

                                 "AUX IN2"
                            };

        outDataChannel2   = {
                                 "Y",                    "Theta",

                                 "Y noise",              "AUX IN3",

                                 "AUX IN4"
                            };

        bufferMode =    {
                            "Shot", "Loop"
                        };

        outData =   {
                        " ", "X", "Y", "R", "Theta"
                    };

        outDataCouple = {
                            "X",                    "Y",        "R",        "Theta",
                            "Aux In1",              "Aux In2",  "Aux In3",  "Aux In4",
                            "Reference Frequency",
                            "CH1 display",          "CH2 display"
                        };
    }

    bool autoReserve() const;// не уверен что это функция одинаковая в 830 и 844

    std::vector<std::string> getCloseReserveModeList() const;
    int closeReserveModeNumberFromString(const std::string  &closeReserveMode_string) const;
    std::string closeReserveModeStringFromNumber(const int &icloseReserveMode_number) const;
    bool setCloseReserveMode(const int &closeReserveMode) const;
    bool setCloseReserveMode(const std::string &icloseReserveMode) const;
    std::string getCloseReserveMode() const;

    bool getOutDataABCD(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue) const;
    bool getOutDataABCDE(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue) const;
    bool getOutDataABCDEF(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue, const int &F, std::string &FValue) const;
    bool getOutDataABCD(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue) const;
    bool getOutDataABCDE(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue) const;
    bool getOutDataABCDEF(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue, const std::string &F, std::string &FValue) const;

    std::vector<std::string> getOutDataChannel1List() const;
    int outDataChannel1NumberFromString(const std::string  &outDataChannel1_string) const;
    std::string outDataChannel1StringFromNumber(const int &outDataChannel1_number) const;
    bool setOutDataChannel1(const int &outDataChannel1) const;
    bool setOutDataChannel1(const std::string &outDataChannel1) const;

    std::vector<std::string> getOutDataChannel2List() const;
    int outDataChannel2NumberFromString(const std::string  &outDataChannel2_string) const;
    std::string outDataChannel2StringFromNumber(const int &outDataChannel2_number) const;
    bool setOutDataChannel2(const int &outDataChannel2) const;
    bool setOutDataChannel2(const std::string &outDataChannel2) const;

    std::vector<std::string> getBufferModeList() const;
    int bufferModeNumberFromString(const std::string  &bufferMode_string) const;
    std::string bufferModeStringFromNumber(const int &bufferMode_number) const;
    bool setBufferMode(const int &bufferMode) const;
    bool setBufferMode(const std::string &bufferMode) const;
    std::string getBufferMode() const;

    bool startBuffer() const;
    bool pauseBuffer() const;
    bool stopBuffer() const;
    int getBufferSize() const;

    std::string getPointFromBufferChannel1(const int &number) const;
    std::string getPointFromBufferChannel2(const int &number) const;
    std::vector <std::string> getChannel1FromBuffer() const;
    std::vector <std::string> getChannel2FromBuffer() const;

    std::vector<std::string> getRefTriggerModeList() const;
    int refTriggerModeNumberFromString(const std::string  &refTriggerMode_string) const;
    std::string refTriggerModeStringFromNumber(const int &refTriggerMode_number) const;
    bool setRefTriggerMode(const int &refTriggerMode) const;
    bool setRefTriggerMode(const std::string &refTriggerMode) const;
    std::string getRefTriggerMode() const;

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

    std::vector<std::string> getSynchronousFilterList() const;
    int synchronousFilterNumberFromString(const std::string  &synchronousFilter_string) const;
    std::string synchronousFilterStringFromNumber(const int &synchronousFilter_number) const;
    bool setSynchronousFilter(const int &synchronousFilter) const;
    bool setSynchronousFilter(const std::string &synchronousFilter) const;
    std::string getSynchronousFilter() const;
protected:


};

#endif // SR830_H









