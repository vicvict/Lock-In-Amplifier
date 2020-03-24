/**
 * @file
 * @brief
 * @details The file contains a description of the SR865 class
*/

/**
 * @brief SR865 class
 * @details The class contains a description of specialized for SR865 methods
 */

#ifndef SR865_H
#define SR865_H

#include "LIA_Models/LockInAmplifier/lockinamplifier.h"

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

        outDataCouple = outData;   /*{
                                "X",        "Y",    "R",    "THETa",
                                "IN1",      "IN2",  "IN3",  "IN4",
                                "OUT1",     "OUT2",
                                "XNOise",   "YNOise",
                                "PHAse",    "SAMp",  "LEVel",
                                "FINT",     "FEXT"
                            };*/
    }
    /**
     * @brief Auto Range function
     * @details The command performs the Auto Range function.
     * This command is the same as pressing the [Auto Range]
     * @return @b True is case of successful quering
     */
    bool autoRange() const;

    /**
     * @brief Returns the value of internal frequency
     * @return The value of internal frequency in Hz
     */
    std::string getInternalFrequency() const;

    /**
     * @brief Returns the value of external reference frequency
     * @return The value of external reference frequency in Hz
     */
    std::string getExternalFrequency() const;

    /**
     * @brief  Returns the actual detection frequency
     * @details This is helpful in dual reference mode or harmonic detection.
     * Otherwise, the detection frequency is either the internal
     * or external reference frequency.
     * @return The actual detection frequency in Hz
     */
    std::string getFrequencyDetect() const;

    /**
     * @brief Returns the minimum dual harmonic available in this Lock-in Amplifier
     */
    int getMinDualHarmonic() const;

    /**
     * @brief Returns the maximum dual harmonic available in this Lock-in Amplifier
     */
    int getMaxDualHarmonic() const;

    /**
     * @brief Determines if src dual harmonic is valid
     * @param[in] i The number of src dual harmonic
     * @return  @b True if dual harmonic is valid
     */
    bool isValidDualHarmonic(const int &i) const;

    /**
     * @brief Set harmonic for dual reference mode to i
     * @details Sets the lock-in to detect at the ith harmonic of the
     * external frequency in dual reference mode. The value of i is
     * limited to 1 ≤ i ≤ 99. The actual detection frequency,
     * when operating in dual reference mode, is
     * ![](harmDualSR865.png)
     * @param[in] i
     * @return @b True if query is valid and sending is correct
     */
    bool setDualHarmonic(const int &i) const;

    /**
     * @brief Returns the dual external harmonic
     */
    std::string getDualHarmonic() const;

    /**
     * @brief Returns the minimum sine out DC level available in this Lock-in Amplifier
     */
    double getMinSineDCLevel() const;

    /**
     * @brief Returns the maximum sine out DC level available in this Lock-in Amplifier
     */
    double getMaxSineDCLevel() const;

    /**
     * @brief Determines if src sine out DC level is valid
     * @param[in] voltage The value of src sine out DC level
     * @return  @b True if sine out DC level is valid
     */
    bool isValidSineDCLevel(const double &voltage) const;

    /**
     * @brief Sets the sine out dc level to voltage.
     * @param[in] voltage
     * @return  @b True if query is valid and sending is correct
     */
    bool setSineDCLevel(const double &voltage) const;

    /**
     * @brief Returns the sine out dc level in Volts
     */
    std::string getSineDCLevel() const;

    /**
     * @brief Returns a list of reference trigger mode
     */
    std::vector<std::string> getRefTriggerModeList() const;

    /**
     * @brief Converts the value of ref trigger mode to its index
     * @param[in] refTriggerMode_string reference trigger mode e.g. @a ZERO
     * @return Index of considered reference trigger mode
     */
    int refTriggerModeNumberFromString(const std::string  &refTriggerMode_string) const;

    /**
     * @brief Converts the index of Reference Trigger Mode to its value
     * @param[in] refTriggerMode_number the index of Reference Trigger Mode e.g. @a 1
     * @return The value of Reference Trigger Mode
     */
    std::string refTriggerModeStringFromNumber(const int &refTriggerMode_number) const;

    /**
     * @brief Sets or queries the reference trigger mode by index.
     * @details Sets or queries the reference trigger mode.
     * The parameter i selects @b sine (i=0) , @b positive (i=1) or @b negative (i=2).
     * @param[in] refTriggerMode
     * @return @b True if Reference Trigger Mode is valid and sending is correct.
     */
    bool setRefTriggerMode(const int &refTriggerMode) const;

    /**
     * @brief Sets Reference Trigger Mode to parameter refTriggerMode by its value (see @ref setRefTriggerMode "setRefTriggerMode" by indices)
     */
    bool setRefTriggerMode(const std::string &refTriggerMode) const;

    /**
      * @brief Gets the actual Reference Trigger Mode
      * @return Actual Reference Trigger Mode
      */
    std::string getRefTriggerMode() const;

    /**
     * @brief Returns an Input Signal list
     */
    std::vector<std::string> getInputSignalList() const;

    /**
     * @brief Converts the value of Input Signal to its index
     * @param[in] inputSignal_string Input Signal value e.g. @a VOLTage
     * @return Index of considered Input Signal
     */
    int inputSignalNumberFromString(const std::string  &inputSignal_string) const;

    /**
     * @brief Converts the index of Input Signal to its value
     * @param[in] inputSignal_number the index of Input Signal e.g. @a 1
     * @return The value of Input Signal
     */
    std::string inputSignalStringFromNumber(const int &inputSignal_number) const;

    /**
     * @brief Sets the signal input to @b voltage (i=0) or @b current (i=1) by index.
     * @param[in] inputSignal
     * @return @b True if query is valid and sending is correct
     */
    bool setInputSignal(const int &inputSignal) const;

    /**
     * @brief Sets Input Signal to parameter inputSignal by its value (see @ref setInputSignal "setInputSignal" by indices)
     */
    bool setInputSignal(const std::string &inputSignal) const;

    /**
     * @brief Returns the signal input
     */
    std::string getInputSignal() const;

    /**
     * @brief Returns an Input Voltage Mode list
     */
    std::vector<std::string> getInputVoltageModeList() const;

    /**
     * @brief Converts the value of Input Voltage Mode to its index
     * @param[in] inputVoltageMode_string Input Voltage Mode value e.g. @a A
     * @return Index of considered Input Voltage Mode
     */
    int inputVoltageModeNumberFromString(const std::string  &inputVoltageMode_string) const;

    /**
     * @brief Converts the index of Input Voltage Mode to its value
     * @param[in] inputVoltageMode_number the index of Input Voltage Mode e.g. @a 1
     * @return The value of Input Voltage Mode
     */
    std::string inputVoltageModeStringFromNumber(const int &inputVoltageMode_number) const;

    /**
     * @brief Sets the voltage input mode to @b A (i=0) or @b A−B (i=1) by index.
     * @param[in] inputVoltageMode
     * @return @b True if query is valid and sending is correct
     */
    bool setInputVoltageMode(const int &inputVoltageMode) const;

    /**
     * @brief Sets Input Voltage Mode to parameter inputVoltageMode by its value (see @ref setInputVoltageMode "setInputVoltageMode" by indices)
     */
    bool setInputVoltageMode(const std::string &inputVoltageMode) const;

    /**
     * @brief Returns the voltage input mode
     */
    std::string getInputVoltageMode() const;

    /**
     * @brief Returns a list of Input Voltage Coupling
     */
    std::vector<std::string> getInputVoltageCouplingList() const;

    /**
     * @brief Converts the value of Input Voltage Coupling to its index
     * @param[in] inputVoltageCoupling_string Input Voltage Coupling e.g. @a AC
     * @return Index of considered Input Voltage Coupling
     */
    int inputVoltageCouplingNumberFromString(const std::string  &inputVoltageCoupling_string) const;

    /**
     * @brief Converts the index of Input Voltage Coupling to its value
     * @param[in] inputVoltageCoupling_number the index of Input Voltage Coupling e.g. @a 1
     * @return The value of Input Voltage Coupling
     */
    std::string inputVoltageCouplingStringFromNumber(const int &inputVoltageCoupling_number) const;

    /**
     * @brief  Sets the Input Voltage Coupling by index.
     * @details Sets the Input Voltage Coupling.
     * The parameter i selects @b AC (i=0) or @b DC (i=1).
     * @param[in] inputVoltageCoupling
     * @return @b True if Input Voltage Coupling is valid and sending is correct.
     */
    bool setInputVoltageCoupling(const int &inputVoltageCoupling) const;

    /**
     * @brief Sets Input Voltage Coupling to parameter inputVoltageCoupling by its value (see @ref setInputVoltageCoupling "setInputVoltageCoupling" by indices)
     */
    bool setInputVoltageCoupling(const std::string &inputVoltageCoupling) const;

    /**
      * @brief Gets the actual Input Voltage Coupling
      * @return Actual Input Voltage Coupling
      */
    std::string getInputVoltageCoupling() const;

    /**
     * @brief Returns a list of Input Voltage Shields
     */
    std::vector<std::string> getInputVoltageShieldsList() const;

    /**
     * @brief Converts the value of Input Voltage Shields to its index
     * @param[in] inputVoltageShields_string Input Voltage Shields e.g. @a Float
     * @return Index of considered Input Voltage Shields
     */
    int inputVoltageShieldsNumberFromString(const std::string  &inputVoltageShields_string) const;

    /**
     * @brief Converts the index of Input Voltage Shields to its value
     * @param[in] inputVoltageShields_number the index of Input Voltage Shields e.g. @a 1
     * @return The value of Input Voltage Shields
     */
    std::string inputVoltageShieldsStringFromNumber(const int &inputVoltageShields_number) const;

    /**
     * @brief  Sets the input shield grounding by index.
     * @details Sets or queries the input shield grounding.
     * The parameter i selects @b Float (i=0) or @b Ground (i=1).
     * @param[in] inputVoltageShields
     * @return @b True if Input Voltage Shields is valid and sending is correct.
     */
    bool setInputVoltageShields(const int &inputVoltageShields) const;

    /**
     * @brief Sets Input Voltage Shields to parameter inputVoltageShields by its value (see @ref setInputVoltageShields "setInputVoltageShields" by indices)
     */
    bool setInputVoltageShields(const std::string &inputVoltageShields) const;

    /**
      * @brief Gets the actual Input Voltage Shields
      * @return Actual Input Voltage Shields
      */
    std::string getInputVoltageShields() const;

    /**
     * @brief Returns a list of Input Voltage Ranges
     */
    std::vector<std::string> getInputVoltageRangeList() const;

    /**
     * @brief Converts the value of Input Voltage Ranges to its index
     * @param[in] inputVoltageRange_string Input Voltage Ranges e.g. @a 1 @a V
     * @return Index of considered Input Voltage Ranges
     */
    int inputVoltageRangeNumberFromString(const std::string  &inputVoltageRange_string) const;

    /**
     * @brief Converts the index of Input Voltage Ranges to its value
     * @param[in] inputVoltageRange_number the index of Input Voltage Ranges e.g. @a 1
     * @return The value of Input Voltage Ranges
     */
    std::string inputVoltageRangeStringFromNumber(const int &inputVoltageRange_number) const;

    /**
     * @brief  Sets the voltage input range by index.
     * @details Sets the voltage input range by index.
     * The parameter i selects @b 1 @b V (i=0), @b 300 @b mV (i=1),
     * @b 100 @b mV (i=2), @b 30 @b mV (i=3) or @b 10 @b mV (i=4).
     * @param[in] inputVoltageRange
     * @return @b True if Input Voltage Ranges is valid and sending is correct.
     */
    bool setInputVoltageRange(const int &inputVoltageRange) const;

    /**
     * @brief Sets Input Voltage Ranges to parameter inputVoltageRange by its value (see @ref setInputVoltageRange "setInputVoltageRange" by indices)
     */
    bool setInputVoltageRange(const std::string &inputVoltageRange) const;

    /**
      * @brief Gets the actual Input Voltage Ranges
      * @return Actual Input Voltage Ranges
      */
    std::string getInputVoltageRange() const;

    /**
     * @brief Returns a list of Input Current Gain
     */
    std::vector<std::string> getInputCurrentGainList() const;

    /**
     * @brief Converts the value of Input Current Gain  to its index
     * @param[in] inputCurrentGain_string Input Current Gain e.g. @a 1 @a MΩ
     * @return Index of considered Input Current Gain
     */
    int inputCurrentGainNumberFromString(const std::string  &inputCurrentGain_string) const;

    /**
     * @brief Converts the index of Input Current Gain to its value
     * @param[in] inputCurrentGain_number the index of Input Current Gain e.g. @a 1
     * @return The value of Input Current Gain
     */
    std::string inputCurrentGainStringFromNumber(const int &inputCurrentGain_number) const;

    /**
     * @brief  Sets the current input gain by index.
     * @details Sets the current input gain by index.
     * The parameter i selects @b 1 @b MΩ (i=0) or @b 100 @b MΩ (i=1),
     * @param[in] inputCurrentGain
     * @return @b True if Input Current Gain is valid and sending is correct.
     */
    bool setInputCurrentGain(const int &inputCurrentGain) const;

    /**
     * @brief Sets Input Current Gain to parameter inputCurrentGain by its value (see @ref setInputCurrentGain "setInputCurrentGain" by indices)
     */
    bool setInputCurrentGain(const std::string &inputCurrentGain) const;

    /**
      * @brief  Returns the current input gain
      */
    std::string getInputCurrentGain() const;

    /**
     * @brief Returns the signal strength indicator from lowest (0) to overload (4).
     */
    std::string getSignalStrength() const;

    /**
     * @brief Returns a list of Synchronous Filter
     */
    std::vector<std::string> getSynchronousFilterList() const;

    /**
     * @brief Converts the value of synchronous filter to its index
     * @param[in] inputSynchronousFilter_string synchronous filter e.g. @a Off
     * @return Index of considered Synchronous Filter
     */
    int synchronousFilterNumberFromString(const std::string  &synchronousFilter_string) const;

    /**
     * @brief Converts the index of synchronous filter to its value
     * @param[in] inputSynchronousFilter_number the index of synchronous filter e.g. @a 1
     * @return The value of synchronous filter
     */
    std::string synchronousFilterStringFromNumber(const int &synchronousFilter_number) const;

    /**
     * @brief  Sets the current synchronous filter by index.
     * @details Sets the current synchronous filter by index.
     * The parameter i selects @b Off (i=0) or @b On (i=1),
     * @param[in] synchronousFilter
     * @return @b True if Synchronous Filter is valid and sending is correct.
     */
    bool setSynchronousFilter(const int &synchronousFilter) const;

    /**
     * @brief Sets synchronous filter to parameter synchronousFilter by its value (see @ref setSynchronousFilter "setSynchronousFilter" by indices)
     */
    bool setSynchronousFilter(const std::string &synchronousFilter) const;

    /**
      * @brief Gets the actual synchronous filter
      * @return Actual synchronous filter
      */
    std::string getSynchronousFilter() const;

    /**
     * @brief Returns a list of Advance Filter
     */
    std::vector<std::string> getAdvanceFilterList() const;

    /**
     * @brief Converts the value of advance filter to its index
     * @param[in] advanceFilter_string advance filter e.g. @a Off
     * @return Index of considered advance filter
     */
    int advanceFilterNumberFromString(const std::string  &advanceFilter_string) const;

    /**
     * @brief Converts the index of advance filter to its value
     * @param[in] advanceFilter_number the index of advance filter e.g. @a 1
     * @return The value of advance filter
     */
    std::string advanceFilterStringFromNumber(const int &advanceFilter_number) const;

    /**
     * @brief  Sets the current advance filter by index.
     * @details Sets the current advance filter by index.
     * The parameter i selects @b Off (i=0) or @b On (i=1),
     * @param[in] advanceFilter
     * @return @b True if Advance Filter is valid and sending is correct.
     */
    bool setAdvanceFilter(const int &advanceFilter) const;

    /**
     * @brief Sets advance filter to parameter advanceFilter by its value (see @ref setAdvanceFilter "setAdvanceFilter" by indices)
     */
    bool setAdvanceFilter(const std::string &advanceFilter) const;

    /**
      * @brief Gets the actual advance filter
      * @return Actual advance filter
      */
    std::string getAdvanceFilter() const;

protected:

    double SineDCLevel;

private:

};

#endif // SR865_H
