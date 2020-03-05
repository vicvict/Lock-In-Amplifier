#ifndef SR844_H
#define SR844_H

#include "LIA_Models/LockInAmplifier/lockinamplifier.h"
#include <vector>
#include <string>
#include <map>

class SR844 : public LockInAmplifier{
protected:

public:
    SR844() : LockInAmplifier() {
        //something about ranges
        ranges.minHarmonic = 0;
        ranges.maxHarmonic = 1;
        ranges.minInternalFrequency = 2.5E4;
        ranges.maxInternalFrequency = 2E7;

        //something about commands
        commands.FrequencyDetect = "FRAQ";
        commands.WideReserveMode = "WRSV";
        commands.AutoWideReverse = "AWRS";
        commands.InputSignalZ = "INPZ";
        commands.CloseReserveMode = "CRSV";
        commands.AutoReserve = "ACRS";
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

                            "10 ks",    "30 ks"
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

        outData  = {
                        " ", "X", "Y", "R [V]", "R [dBm]", "Theta"
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

        outDataCouple = {
                            "X", "Y", "R [V]", "R [dBm]", "Theta",
                            "AUX IN1", "AUX IN2", "Ref Frequency",
                            "CH1", "CH2"
                        };

        refSource = {
                        "EXT", "INT"
                    };

        refTriggerOutput =  {
                                "50 Ohm", "10 kOhm"
                            };

        filterSlope =   {
                            "No", "6 dB", "12 dB", "18 dB", "24 dB"
                        };

        bufferMode  =   {
                            "Shot", "Loop"
                        };

        inputSignalZ =    {
                               "50 Ohm", "1 MOhm"
                          };
        closeReserveMode =    {
                                    "High", "Normal", "Low"
                              };

        wideReserveMode =     {
                                    "High", "Normal", "Low"
                              };


    }

    std::string getFrequencyDetect() const;

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

    std::vector<std::string> getWideReserveModeList() const;
    int wideReserveModeNumberFromString(const std::string  &wideReserveMode_string) const;
    std::string wideReserveModeStringFromNumber(const int &wideReserveMode_number) const;
    bool setWideReserveMode(const int &wideReserveMode) const;
    bool setWideReserveMode(const std::string &wideReserveMode) const;
    std::string getWideReserveMode() const;

    bool outDataAutoZeroChannel1(const int &outDataChannel1) const;
    bool outDataAutoZeroChannel1(const std::string &outDataChannel1) const;
    bool outDataAutoZeroChannel2(const int &outDataChannel2) const;
    bool outDataAutoZeroChannel2(const std::string &outDataChannel2) const;

    std::string getPointFromBufferChannel1(const int &number) const;
    std::string getPointFromBufferChannel2(const int &number) const;
    std::vector <std::string> getChannel1FromBuffer() const;
    std::vector <std::string> getChannel2FromBuffer() const;

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
};



#endif // SR844_H
