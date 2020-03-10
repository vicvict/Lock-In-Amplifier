/**
 * @file
 * @brief
 * @details The file contains a description of the SR830 class
*/

/**
 * @brief SR830 class
 * @details The class contains a description of specialized for SR830 methods
 */

#ifndef SR830_H
#define SR830_H


#include "LIA_Models/LockInAmplifier/lockinamplifier.h"

#include <vector>
#include <string>
#include <map>

class SR830: public LockInAmplifier
{
public:
    SR830() : LockInAmplifier() {
        //Overloading of ranges values
        ranges.minInternalFrequency = 0.001;
        ranges.maxInternalFrequency = 102000;
        ranges.minHarmonic = 1;
        ranges.maxHarmonic = 19999;
        ranges.minSineAmplitude = 0.004;
        ranges.maxSineAmplitude = 5.0;

        ///Overloading of commands
        commands.RefTriggerMode = "RSLP";
        commands.InputVoltageMode = "ISRC";
        commands.AdvanceFilter = "ILIN";
        ///'Close' equals to 'dynamic' in this case
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

        dataSampleRate =    {
                                "62.5 mHz", "125 mHz",  "250 mHz",  "500 mHz,"
                                "1 Hz",     "2 Hz",     "4 Hz",     "8 Hz",
                                "16 Hz",    "32 Hz",    "64 Hz",    "128 Hz",
                                "256 Hz",   "512 Hz",   "Trigger"
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

    /**
     * @brief Performs the Auto Scale (Auto Gain) function
     * @details The ARSV command performs the Auto Reserve function.
     * This command is the same as pressing the [Auto Reserve] key.
     * Auto Reserve may take some time. Check the command execution
     * in progress bit in the Serial Poll Status Byte (bit 1) to determine
     * when the function is finished.
     * @return True if quering is correct
     */
    bool autoReserve() const;// не уверен что это функция одинаковая в 830 и 844

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

    /**
     * @brief Returns values of 4 parameters at a single instant by their indices
     * according to specification tables
     * ![SR830](outDataCoupleTableSR830.png)
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
     * ![SR830](outDataCoupleTableSR830.png)
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
     * ![SR830](outDataCoupleTableSR830.png)
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
     * ![Out Data Channel 1](outDataChannel1TableSR830.png)
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
     * ![Out Data Channel 2](outDataChannel2TableSR830.png)
     * @param[in] outDataChannel2
     * @return @b True if Out Data Channel 2 is valid and sending is correct. Records data to appropriate strings
     */
    bool setOutDataChannel2(const int &outDataChannel2) const;

    /**
     * @brief Sets display 2 to parameter outDataChannel2 by its value (see @ref setOutDataChannel2 "setOutDataChannel2" by indices)
     */
    bool setOutDataChannel2(const std::string &outDataChannel2) const;
    /*std::vector<std::string> getOutDataChannel2List() const;
    int outDataChannel2NumberFromString(const std::string  &outDataChannel2_string) const;
    std::string outDataChannel2StringFromNumber(const int &outDataChannel2_number) const;
    bool setOutDataChannel2(const int &outDataChannel2) const;
    bool setOutDataChannel2(const std::string &outDataChannel2) const;*/

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

    std::vector<std::string> getDataSampleRateList() const;
    int dataSampleRateNumberFromString(const std::string  &dataSampleRate_string) const;
    std::string dataSampleRateStringFromNumber(const int &dataSampleRate_number) const;
    bool setDataSampleRate(const int &dataSampleRate) const;
    bool setDataSampleRate(const std::string &dataSampleRate) const;
    std::string getDataSampleRate() const;

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









