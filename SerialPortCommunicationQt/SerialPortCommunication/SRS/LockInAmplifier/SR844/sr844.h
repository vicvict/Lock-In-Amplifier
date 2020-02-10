#ifndef SR844_H
#define SR844_H

#include "../lockinamplifier.h"
#include <vector>
#include <string>
#include <map>

class SR844 : public LockInAmplifier{
protected:
    std::vector <std::string> inputSignalZ =    {
                                                    "50 Ohm", "1 MOhm"
                                                };
    std::vector <std::string> closeReserveMode =    {
                                                        "High", "Normal", "Low"
                                                    };

public:
    SR844() : LockInAmplifier() {
        //something about ranges
        ranges.minHarmonic = 1;
        ranges.maxHarmonic = 2;
        ranges.minInternalFrequency = 2.5E4;
        ranges.maxInternalFrequency = 2E8;

        //something about commands
        commands.FrequencyDetect = "FRAQ";
        commands.AutoWideReverse = "AWRS";
        commands.InputSignalZ = "INPZ";
        commands.AutoScale = "AGAN";
        commands.CloseReserveMode = "CRSV";
        commands.AutoReserve = "ACRS";
        commands.OutData = "DDEF";
        commands.AutoZero = "AOFF";


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



        outDataChannel1 =   {
                        "X",                    "R [V]",

                        "R [dBm]",              "X noise",

                        "AUX IN1"

                        };

        outDataChannel2  = {
                                     "Y",

                                    "Theta",                 "Y noise [V]",

                                    "Y noise [dBm]",         "AUX IN2"
        };

        refSource = {
                        "Ext", "Int"
                    };

        refTriggerOutput =  {
                                "50 Ohm", "10 kOhm"
                            };

        filterSlope =   {
                            "No", "6 dB", "12 dB", "18 dB", "24 dB"
                        };

    }

    bool autoWideReverse() const;
    bool autoReserve() const;

    std::vector<std::string> getInputSignalZList() const;
    int inputSignalZNumberFromString(const std::string  &inputSignalZ_string) const;
    std::string inputSignalZStringFromNumber(const int &inputSignalZ_number) const;
    bool setInputSignalZ(const int &inputSignalZ) const;
    bool setInputSignalZ(const std::string &inputSignalZ) const;
    std::string getInputSignalZ() const;

    std::vector<std::string> getCloseReserveModeList() const;
    int closeReserveModeNumberFromString(const std::string  &closeReserveMode_string) const;
    std::string closeReserveModeStringFromNumber(const int &icloseReserveMode_number) const;
    bool setCloseReserveMode(const int &closeReserveMode) const;
    bool setCloseReserveMode(const std::string &icloseReserveMode) const;
    std::string getCloseReserveMode() const;

    std::vector<std::string> getOutDataChannel1List() const;
    int outDataChannel1NumberFromString(const std::string  &outDataChannel1_string) const;
    std::string outDataChannel1StringFromNumber(const int &outDataChannel1_number) const;
    std::string getOutDataChannel1(const int &outDataChannel1) const;
    std::string getOutDataChannel1(const std::string &outDataChannel1) const;

    std::vector<std::string> getOutDataChannel2List() const;
    int outDataChannel2NumberFromString(const std::string  &outDataChannel2_string) const;
    std::string outDataChannel2StringFromNumber(const int &outDataChannel2_number) const;
    std::string getOutDataChannel2(const int &outDataChannel2) const;
    std::string getOutDataChannel2(const std::string &outDataChannel2) const;

    bool outDataAutoZeroChannel1(const int &outDataChannel1) const;
    bool outDataAutoZeroChannel1(const std::string &outDataChannel1) const;
    bool outDataAutoZeroChannel2(const int &outDataChannel2) const;
    bool outDataAutoZeroChannel2(const std::string &outDataChannel2) const;
};



#endif // SR844_H
