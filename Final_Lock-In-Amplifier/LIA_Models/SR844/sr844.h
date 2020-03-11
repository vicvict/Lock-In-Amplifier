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

        dataSampleRate =    {
                                "62.5 mHz", "125 mHz",  "250 mHz",  "500 mHz,"
                                "1 Hz",     "2 Hz",     "4 Hz",     "8 Hz",
                                "16 Hz",    "32 Hz",    "64 Hz",    "128 Hz",
                                "256 Hz",   "512 Hz",   "Trigger"
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

    /**
     * @brief Returns a Close Reserve Mode list
     */
    std::vector<std::string> getCloseReserveModeList() const;

    /**
     * @brief Converts the value of close reserve mode to its index
     * @param[in] closeReserveMode_string close reserve mode e.g. @a High
     * @return Index of considered reference trigger input
     */
    int closeReserveModeNumberFromString(const std::string  &closeReserveMode_string) const;

    /**
     * @brief Converts the index of close reserve mode to its value
     * @param[in] closeReserveMode_number the index of close reserve mode e.g. @a 1
     * @return The value of close reserve mode
     */
    std::string closeReserveModeStringFromNumber(const int &closeReserveMode_number) const;

    /**
     * @brief Sets the reserve mode to high (i=0), normal (i=1) or low (i=2)
     * @param[in] closeReserveMode
     * @return
     */
    bool setCloseReserveMode(const int &closeReserveMode) const;

    /**
     * @brief Sets the reserve mode by value (see @ref setCloseReserveMode "setRefSource" by index)
     */
    bool setCloseReserveMode(const std::string &icloseReserveMode) const;

    /**
     * @brief Gets the actual reserve mode
     * @return Actual reserve mode
     */
    std::string getCloseReserveMode() const;

    std::vector<std::string> getWideReserveModeList() const;
    int wideReserveModeNumberFromString(const std::string  &wideReserveMode_string) const;
    std::string wideReserveModeStringFromNumber(const int &wideReserveMode_number) const;
    bool setWideReserveMode(const int &wideReserveMode) const;
    bool setWideReserveMode(const std::string &wideReserveMode) const;
    std::string getWideReserveMode() const;

    /*bool outDataAutoZeroChannel1(const int &outDataChannel1) const;
    bool outDataAutoZeroChannel1(const std::string &outDataChannel1) const;
    bool outDataAutoZeroChannel2(const int &outDataChannel2) const;
    bool outDataAutoZeroChannel2(const std::string &outDataChannel2) const;
*/ // не знаю зачем нужна эта функция

    std::string getPointFromBufferChannel1(const int &number) const;
    std::string getPointFromBufferChannel2(const int &number) const;
    std::vector <std::string> getChannel1FromBuffer() const;
    std::vector <std::string> getChannel2FromBuffer() const;

    /**
     * @brief Returns values of 4 parameters at a single instant by their indices
     * according to specification tables
     * ![SR830](outDataCoupleTableSR844.png)
     * @param[in] A
     * @param[out] AValue
     * @param[in] B
     * @param[out] BValue
     * @param[in] C
     * @param[out] CValue
     * @param[in] D
     * @param[out] DValue
     * @return @b True if out data is valid and sending is correct. Records data to appropriate strings
     */
    bool getOutDataABCD(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue) const;

    /**
     * @brief Gets the value of out data by its value (see @ref getOutDataABCD "getOutDataABCD" by indices)
     */
    bool getOutDataABCD(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue) const;

    /**
     * @brief Returns values of 5 parameters at a single instant by their indices
     * according to specification tables
     * ![SR830](outDataCoupleTableSR844.png)
     * @param[in] A
     * @param[out] AValue
     * @param[in] B
     * @param[out] BValue
     * @param[in] C
     * @param[out] CValue
     * @param[in] D
     * @param[out] DValue
     * @param[in] E
     * @param[out] EValue
     * @return @b True if out data is valid and sending is correct. Records data to appropriate strings
     */
    bool getOutDataABCDE(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue) const;

    /**
     * @brief Gets the value of out data by its value (see @ref getOutDataABCDE "getOutDataABCDE" by indices)
     */
    bool getOutDataABCDE(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue) const;


    /**
     * @brief Returns values of 6 parameters at a single instant by their indices
     * according to specification tables
     * ![SR830](outDataCoupleTableSR844.png)
     * @param[in] A
     * @param[out] AValue
     * @param[in] B
     * @param[out] BValue
     * @param[in] C
     * @param[out] CValue
     * @param[in] D
     * @param[out] DValue
     * @param[in] E
     * @param[out] EValue
     * @param[in] F
     * @param[out] FValue
     * @return @b True if out data is valid and sending is correct. Records data to appropriate strings
     */
    bool getOutDataABCDEF(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue, const int &F, std::string &FValue) const;

    /**
     * @brief Gets the value of out data by its value (see @ref getOutDataABCDEF "getOutDataABCDEF" by indices)
     */
    bool getOutDataABCDEF(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue, const std::string &F, std::string &FValue) const;


    /**
     * @brief Returns an Out Data Channel 1 list
     */
    std::vector<std::string> getOutDataChannel1List() const;

    /**
     * @brief Converts the value of Out Data Channel 1 to its index
     * @param[in] outDataChannel1_string Out Data Channel 1 e.g. @a R
     * @return Index of considered Out Data Channel 1
     */
    int outDataChannel1NumberFromString(const std::string  &outDataChannel1_string) const;

    /**
     * @brief Converts the index of Out Data Channel 1 to its value
     * @param[in] outDataChannel1_number the index of Out Data Channel 1 e.g. @a 1
     * @return The value of Out Data Channel 1
     */
    std::string outDataChannel1StringFromNumber(const int &outDataChannel1_number) const;

    /**
     * @brief Sets display 1 to parameter outDataChannel1 by index
     * according to specification tables
     * ![Out Data Channel 1](outDataChannel1TableSR844.png)
     * @param[in] outDataChannel1
     * @return @b True if Out Data Channel 1 is valid and sending is correct. Records data to appropriate strings
     */
    bool setOutDataChannel1(const int &outDataChannel1) const;

    /**
     * @brief Sets display 1 to parameter outDataChannel1 by its value (see @ref setOutDataChannel1 "setOutDataChannel1" by indices)
     */
    bool setOutDataChannel1(const std::string &outDataChannel1) const;


    /**
     * @brief Returns an Out Data Channel 2 list
     */
    std::vector<std::string> getOutDataChannel2List() const;

    /**
     * @brief Converts the value of Out Data Channel 2 to its index
     * @param[in] outDataChannel2_string Out Data Channel 2 e.g. @a R
     * @return Index of considered Out Data Channel 2
     */
    int outDataChannel2NumberFromString(const std::string  &outDataChannel2_string) const;

    /**
     * @brief Converts the index of Out Data Channel 2 to its value
     * @param[in] outDataChannel2_number the index of Out Data Channel 2 e.g. @a 2
     * @return The value of Out Data Channel 2
     */
    std::string outDataChannel2StringFromNumber(const int &outDataChannel2_number) const;

    /**
     * @brief Sets display 2 to parameter outDataChannel2 by index
     * according to specification tables
     * ![Out Data Channel 2](outDataChannel2TableSR844.png)
     * @param[in] outDataChannel2
     * @return @b True if Out Data Channel 2 is valid and sending is correct. Records data to appropriate strings
     */
    bool setOutDataChannel2(const int &outDataChannel2) const;

    /**
     * @brief Sets display 2 to parameter outDataChannel2 by its value (see @ref setOutDataChannel2 "setOutDataChannel2" by indices)
     */
    bool setOutDataChannel2(const std::string &outDataChannel2) const;

    /**
     * @brief Returns a Buffer Mode list
     */
    std::vector<std::string> getBufferModeList() const;

    /**
     * @brief Converts the value of Buffer Mode to its index
     * @param[in] bufferMode_string Buffer Mode e.g. @a LOOP
     * @return Index of considered Buffer Mode
     */
    int bufferModeNumberFromString(const std::string  &bufferMode_string) const;

    /**
     * @brief Converts the index of Buffer Mode to its value
     * @param[in] bufferMode_number the index of Buffer Mode e.g. @a 1
     * @return The value of Buffer Mode
     */
    std::string bufferModeStringFromNumber(const int &bufferMode_number) const;

    /**
     * @brief Sets or queries the end of buffer mode by index
     * @details Sets or queries the end of buffer mode.
     * The parameter i selects @b Shot (i=0) or @b Loop (i=1).
     * If @b Loop mode is used, make sure to pause data storage
     * before reading the data to avoid confusion about which point
     * is the most recent.
     * @param[in] bufferMode
     * @return @b True if Buffer Mode is valid and sending is correct.
     */
    bool setBufferMode(const int &bufferMode) const;

    /**
     * @brief Sets Buffer Mode by its value (see @ref setBufferMode "setBufferMode" by index)
     */
    bool setBufferMode(const std::string &bufferMode) const;

    /**
     * @brief Gets the actual Buffer Mode
     * @return Actual Buffer Mode
     */
    std::string getBufferMode() const;

    /**
     * @brief Returns a Data Sample Rate list
     */
    std::vector<std::string> getDataSampleRateList() const;

    /**
     * @brief Converts the value of Data Sample Rate to its index
     * @param[in] dataSampleRate_string Data Sample Rate e.g. @a 1 HZ
     * @return Index of considered Data Sample Rate
     */
    int dataSampleRateNumberFromString(const std::string  &dataSampleRate_string) const;

    /**
     * @brief Converts the index of Data Sample Rate to its value
     * @param[in] dataSampleRate_number the index of Data Sample Rate e.g. @a 1
     * @return The value of Data Sample Rate
     */
    std::string dataSampleRateStringFromNumber(const int &dataSampleRate_number) const;

    /**
     * @brief Sets Data Sample Rate to parameter dataSampleRate by index
     * according to specification tables
     * ![Data Sample Rate](dataSampleRateTableSR844.png)
     * @param[in] dataSampleRate
     * @return @b True if Data Sample Rate is valid and sending is correct.
     */
    bool setDataSampleRate(const int &dataSampleRate) const;

    /**
     * @brief Sets Data Sample Rate to parameter dataSampleRate by its value (see @ref setDataSampleRate "setDataSampleRate" by indices)
     */
    bool setDataSampleRate(const std::string &dataSampleRate) const;

    /**
      * @brief Gets the actual Data Sample Rate
      * @return Actual Data Sample Rate
      */
    std::string getDataSampleRate() const;

    bool startBuffer() const;
    bool pauseBuffer() const;
    bool stopBuffer() const;
    int getBufferSize() const;
};



#endif // SR844_H
