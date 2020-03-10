/**
 * @file
 * @brief
 * @details The file contains a description of the Lock-in Amplifier class
*/

/**
 * @brief Common class for SRS Lock-in Amplifiers
 * @details The class contains a description of the methods common to all Lock-in Amplifiers
 */

#ifndef LOCKINAMPLIFAER_H
#define LOCKINAMPLIFAER_H



#include "LIA_Models/LockInAmplifier/SRS/SRS.h"

#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

class LockInAmplifier : public SRS
{
protected:
    /// The worst values of all the models
    struct LockInAmplifierRanges
    {
        double minInternalFrequency = 1E-3;
        double maxInternalFrequency = 102E3;

        int minHarmonic = 1;
        int maxHarmonic = 99;

        double minPhase = -180.0;
        double maxPhase = +180.0;

        double minSineAmplitude = 4E-3;
        double maxSineAmplitude = 2.0;

        //only for SR865
        const int minHarmDual = 1;
        const int maxHarmDual = 99;

        const double minSineDCLevel = -5.00;
        const double maxSineDCLevel = +5.00;
    };

    //Как использовать этот state?
    struct LockInAmplifierState
    {
        double InternalFrequency;
        int Harmonic;
        double Phase;

        double SineAmplitude;
    };

    /**
     * @brief Commands that are available on at least one Lock-in Amplifier
     * @details The structure contains commands that are available on at least one Lock-in Amplifier.
     * If necessary, in the successor constructors, commands are reinitialized
     */
    struct LockInAmplifierCommands
    {
        std::string Frequence = "FREQ";
        std::string FrequencyDetect = "FRAQ";
        std::string Harmonic  = "HARM";
        std::string HarmonicDual;   ///< For 865A: harmonic search in dual ref mode
        std::string Phase     = "PHAS";
        std::string SineAmplitude = "SLVL";
        std::string SineDCLevel ;
        std::string TimeConstant = "OFLT";
        std::string RefSource = "FMOD";
        std::string RefTriggerMode;
        std::string RefTriggerOutput = "REFZ";
        std::string InputSignal;
        std::string InputVoltageMode;
        std::string InputVoltageCoupling = "ICPL";
        std::string InputVoltageShields = "IGND";
        std::string InputVoltageRange = "IRNG";
        std::string InputCurrentGain = "ICUR";
        std::string SignalStrength = "ILVL";
        std::string Sensitivity = "SENS";
        std::string FilterSlope = "OFSL";
        std::string SynchronousFilter = "SYNC";
        std::string AdvanceFilter;
        std::string InputSignalZ;
        std::string CloseReserveMode;
        std::string WideReserveMode;

        std::string OutData = "OUTP";
        std::string CoupleOfData = "SNAP";
        std::string SetOutData = "DDEF";

        std::string AutoPhase = "APHS";
        std::string AutoRange;
        std::string AutoScale = "AGAN"; //не факт что в 830 она делает то что надо. Надо проверить
        std::string AutoWideReverse;
        std::string AutoReserve;
        std::string AutoZero;

        //buffer commands exists only in SR844 and SR830
        std::string BufferMode = "SEND";
        std::string DataSampleRate = "SRAT";
        std::string StartBuffer = "STRT";
        std::string PauseBuffer = "PAUS";
        std::string StopBuffer =  "REST";
        std::string BufferSize =  "SPTS";
        std::string GetPointFromBuffer = "TRCA";
    };

public:
    LockInAmplifier();
    ~LockInAmplifier();

    /**
     * @brief Returns the error value
     */
    double getEpsilon() const;

    /**
     * @brief Returns the number of the source string value in the detector specification
     * @param[in] vector The set of aviable values
     * @param[in] string Source string
     * @return The number of source string in the aviable strings list
     */
    int numberFromString(const std::vector< std::string> &vector, const std::string &string) const;

    /**
     * @brief Returns the dest string from the list available by its number
     * @param[in] vector The set of aviable values
     * @param[in] number Source number
     * @return The dest string from the list available by its number
     */
    std::string stringFromNumber(const std::vector< std::string> &vector, const int &number) const;

    /**
     * @brief Checks the existance of string in src list
     * @param[in] vector src list
     * @param[in] string
     * @return @b True if string exists in src list
     */
    bool isValidString(const std::vector< std::string> &vector, const std::string &string) const;

    /**
     * @brief Checks the existance of string with given @b number in src @b string

     * @param[in] vector src list
     * @param[in] number
     * @return @b True if string with given @b number exists in src list
     */
    bool isValidNumber(const std::vector< std::string> &vector, const int &number) const;

    /**
     * @brief Returns the minimum phase available in this Lock-in Amplifier
     * @return The minimum phase available in this Lock-in Amplifier
     */
    double getMinPhase() const;

    /**
     * @brief Returns the maximum phase available in this Lock-in Amplifier
     * @return The maximum phase available in this Lock-in Amplifier
     */
    double getMaxPhase() const;

    /**
     * @brief Checks if given @phase is valid
     * @param[in] phase
     * @return @b True if given @phase is valid
     */
    bool isValidPhase(const double &phase) const;

    /**
     * @brief Set the reference phase shift to 'phase' degrees
     * @param[in] phase The value of phase in degrees is limited: \f$ -180 \leq phase < 180 \f$
     * @return @b True if phase is valid and sending is correct
     */
    bool setInternalPhase(const double &phase) const;

    /**
     * @brief Get the reference phase
     * @return The reference phase in degrees
     */
    std::string getPhase() const;

    /**
     * @brief Returns the minimum internal frequency available in this Lock-in Amplifier
     * @return The minimum internal frequency available in this Lock-in Amplifier
     */
    double getMinInternalFrequency() const;

    /**
     * @brief Returns the maximum internal frequency available in this Lock-in Amplifier
     * @return The maximum internal frequency available in this Lock-in Amplifier
     */
    double getMaxInternalFrequency() const;

    /**
     * @brief Checks if given internal @frequency is valid
     * @param[in] frequency
     * @return @b True if internal @frequency is valid
     */
    bool isValidInternalFrequency(const double &frequency) const;

    /**
     * @brief Sets the internal frequency to \f$ f \f$
     * @param[in] frequency the value of frequency in Hz
     * @return @b True if frequency is valid and sending is correct
     */
    bool setFrequency(const double &frequency) const;

    /**
     * @brief Returns the internal or external frequency
     * @details Returns the internal reference frequency whenever the reference
     * mode is either Internal, Dual, or Chop. The query returns the external
     * frequency when operating in External mode. This behavior mirrors
     * the value displayed in the info bar at the top of the display
     * @return The internal or external frequency in Hz
     */
    std::string getFrequency() const;

    /**
     * @brief Returns the minimum harmonic available in this Lock-in Amplifier
     * @return The minimum harmonic available in this Lock-in Amplifier
     */
    int getMinHarmonic() const;

    /**
     * @brief Returns the maximum harmonic available in this Lock-in Amplifier
     * @return The maximum harmonic available in this Lock-in Amplifier
     */
    int getMaxHarmonic() const;

    /**
     * @brief Checks if given harmonic @i is valid
     * @param[in] phase
     * @return @b True if harmonic is valid
     */
    bool isValidHarmonic(const int &i) const;

    /**
     * @brief Sets the lock-in to detect at the i-th harmonic of the reference frequency
     * @param[in] i The number of harmonic i is limited: \f$ 0 \leq i \geq 99 \f$
     * @return @b True if the harmonic number is valid and sending is correct
     */
    bool setHarmonic(const int &i) const;

    /**
     * @brief Returns the value of actual harmonic
     * @return The value of external reference frequency in Hz
     */
    std::string getHarmonic() const;

    /**
     * @brief Returns the minimum sine amplitude available in this Lock-in Amplifier
     * @return The minimum sine amplitude available in this Lock-in Amplifier
     */
    double getMinSineAmplitude() const;

    /**
     * @brief Returns the maximum sine amplitude available in this Lock-in Amplifier
     * @return The maximum sine amplitude available in this Lock-in Amplifier
     */
    double getMaxSineAmplitude() const;

    /**
     * @brief Checks if given sine amplitude @voltage is valid
     * @param[in] voltage
     * @return @b True if sine amplitude is valid
     */
    bool isValidSineAmplitude(const double &voltage) const;

    /**
     * @brief Sets the sine amplitude to voltage
     * @param[in] voltage The value is to be rounded to 3 digits
     * @return @b True if the voltage is valid and sending is correct
     */
    bool setSineAmplitude(const double &voltage) const;

    /**
     * @brief Returns the sine out amplitude
     * @return Returns the sine out amplitude in Volts
     */
    std::string getSineAmplitude() const;

    /**
     * @brief Returns a list of time constants
     */
    std::vector<std::string> getTimeConstantList() const;

    /**
     * @brief Converts the value of time constant to its index
     * @param[in] timeConstant_string time constant e.g. @a INT
     * @return Index of considered time constant
     */
    int timeConstantNumberFromString(const std::string  &timeConstant_string) const;

    /**
     * @brief Converts the index of time constant to its value
     * @param[in] timeConstant_number the index of time constant e.g. @a 8
     * @return The value of time constant
     */
    std::string timeConstantStringFromNumber(const int &timeConstant_number) const;

    /**
     * @brief Sets the time constant according to the specification table
     * ![SR830](timeConstantTableSR830.png)
     *
     * ![SR844](timeConstantTableSR844.png)
     *
     * ![SR865A](timeConstantTableSR865A.png)
     * @param[in] timeConstant
     * @return @b True if the time constant is valid and sending is correct
     */
    bool setTimeConstant(const int &timeConstant) const;

    /**
     * @brief Sets the time constant by actual value
     * @param[in] timeConstant
     * @return @b True if the time constant is valid and sending is correct
     */
    bool setTimeConstant(const std::string &timeConstant) const;

    /**
     * @brief Gets the actual time constant
     * @return Actual time constant
     */
    std::string getTimeConstant() const;

    /**
     * @brief Returns a list of reference sources
     */
    std::vector<std::string> getRefSourceList() const;

    /**
     * @brief Converts the value of ref source to its index
     * @param[in] refSource_string ref source e.g. @a INT
     * @return Index of considered ref source
     */
    int refSourceNumberFromString(const std::string  &refSource_string) const;

    /**
     * @param[in] refSource_number the index of ref source e.g. @a 2
     * @return The value of ref source
     * @brief Converts the index of ref source to its value
     */
    std::string refSourceStringFromNumber(const int &refSource_number) const;

    /**
     * @brief Sets the reference source to internal (i=0), external (i=1) (all the Lock-In Amplifiers),
     * dual (i=2) or chop (i=3). @b (SR865 @b only)
     * @param[in] refSource
     * @return @b True if the reference source is valid and sending is correct
     *
     */
    bool setRefSource(const int &refSource) const;

    /**
     * @brief Sets the reference source by value (see @ref setRefSource "setRefSource" by index)
     */
    bool setRefSource(const std::string &refSource) const;

    /**
     * @brief Gets the actual reference source
     * @return Actual reference source
     */
    std::string getRefSource() const;


    /**
     * @brief Returns a list of external reference trigger input
     */
    std::vector<std::string> getRefTriggerOutputList() const;

    /**
     * @brief Converts the value of external reference trigger input to its index
     * @param[in] refTriggerOutput_string reference trigger input e.g. @a 50 @a Ω
     * @return Index of considered reference trigger input
     */
    int refTriggerOutputNumberFromString(const std::string  &refTriggerOutput_string) const;

    /**
     * @brief Converts the index of external reference trigger input to its value
     * @param[in] refTriggerOutput_number the index of external reference trigger input e.g. @a 0
     * @return The value of external reference trigger input
     */
    std::string refTriggerOutputStringFromNumber(const int &refTriggerOutput_number) const;

    /**
     * @brief Set the Reference Input impedance
     * @details Set the Reference Input impedance to:
     * @arg 50 Ω (0) or 10 kΩ (1) (in SR844);
     * @arg 50 Ω (0) or 1 MΩ (1) (in SR865A).
     * The reference Input impedance in SR830 is unchangeble and equals to 10 MΩ
     * @param[in] refTriggerOutput The index of external reference trigger input e.g. @a 0
     * @return @b True if the reference Input impedance is valid and sending is correct
     */
    bool setRefTriggerOutput(const int &refTriggerOutput) const;

    /**
     * @brief Sets the external reference trigger input by its value (see @ref setRefTriggerOutput "setRefTriggerOutput" by index)
     */
    bool setRefTriggerOutput(const std::string &refTriggerOutput) const;

    /**
     * @brief Gets the actual external reference trigger input
     * @return Actual external reference trigger input
     */
    std::string getRefTriggerOutput() const;

    /**
     * @brief Returns a sensitivity list
     */
    std::vector<std::string> getSensitivityList() const;

    /**
     * @brief Converts the value of sensitivity to its index
     * @param[in] sensitivity_string the value of sensitivity e.g. @a 10 @a mV
     * @return Index of considered value of sensitivity
     */
    int sensitivityNumberFromString(const std::string  &sensitivity_string) const;

    /**
     * @brief Converts the index of sensitivity to its value
     * @param[in] sensitivity_number the index of sensitivity e.g. @a 7
     * @return The value of sensitivity
     */
    std::string sensitivityStringFromNumber(const int &sensitivity_number) const;

    /**
     * @brief Sets the value of sensitivity by index according to the specification tables
     * ![SR830](sensitivityTableSR830.png)
     *
     * ![SR844](sensitivityTableSR844.png)
     *
     * ![SR865A](sensitivityTableSR865A.png)
     * @param[in] sensitivity
     * @return @b True if sensitivity is valid and sending is correct
     */
    bool setSensitivity(const int &sensitivity) const;

    /**
     * @brief Sets the value of sensitivity by its value (see @ref setSensitivity "setSensitivity" by index)
     */
    bool setSensitivity(const std::string &sensitivity) const;

    /**
     * @brief Gets the actual value of sensitivity
     * @return Actual value of sensitivity
     */
    std::string getSensitivity() const;

    /**
     * @brief Returns a list of filer slope values
     */
    std::vector<std::string> getFilterSlopeList() const;

    /**
     * @brief Converts the value of filer slope to its index
     * @param[in] filterSlope_string the value of filer slope e.g. @a 6 @a dB/oct
     * @return Index of considered value of filer slope
     */
    int filterSlopeNumberFromString(const std::string  &filterSlope_string) const;

    /**
     * @brief Converts the index of filer slope to its value
     * @param[in] filterSlope_number the index of filer slope e.g. @a 2
     * @return The value of filer slope
     */
    std::string filterSlopeStringFromNumber(const int &filterSlope_number) const;

    /**
     * @brief Sets the value of filter slope by index according to the specification table
     * ![Filter slope values](filterSlopeTable.png)
     * @param[in] filterSlope
     * @return @b True if filter slope is valid and sending is correct
     */
    bool setFilterSlope(const int &filterSlope) const;

    /**
     * @brief Sets the value of filter slope by its value (see @ref setFilterSlope "setFilterSlope" by index)
     */
    bool setFilterSlope(const std::string &filterSlope) const;

    /**
     * @brief Gets the actual value of filter slope
     * @return Actual value of filter slope
     */
    std::string getFilterSlope() const;

    /**
     * @brief Performs the Auto Phase function
     * @details This commandis the same as pressing the [Auto Phase] key.
     * This command adjusts the reference phase so that the current
     * measurement has a Y value of zero and an X value equal to the
     * signal magnitude, R.
     * The outputs will take many time constants to reach their new values.
     * Do not send the APHS command again without waiting the appropriate
     * amount of time. If the phase is unstable, then APHS will do nothing.
     * Query the new value of the phase shift to see if APHS changed the phase shift.
     * @return @b True if quering is correct
     */
    bool autoPhase() const;

    /**
     * @brief Performs the Auto Scale (Auto Gain) function
     * @details This command is the same as pressing the [Auto Scale]
     * (in SR865) or [Auto Gain] (in SR8830 and SR844) key.
     * This automatically sets the sensitivity. Measurements with
     * the synchronous filter on or measurements of Xnoise or
     * Ynoise may take many time constants to return to their steady
     * state values.
     * @return True if quering is correct
     */
    bool autoScale() const;

    /**
     * @brief Returns a list of out data positions
     */
    std::vector<std::string> getOutDataList() const;

    /**
     * @brief Converts the value of out data to its index
     * @param[in] outData_string the value of out data e.g. @a X
     * @return Index of considered value of out data
     */
    int outDataNumberFromString(const std::string  &outData_string) const;

    /**
     * @brief Converts the index of out data to its value
     * @param[in] outData_number the index of out data e.g. @a 2
     * @return The value of out data
     */
    std::string outDataStringFromNumber(const int &outData_number) const;

    /**
     * @brief Gets the value of out data by index according to the specification table
     * ![Out data values (for SR830 & SR844)](outDataTable.png)
     *
     * ![Out data values (for SR865)](outDataTableSR865.png)
     * @param[in] outData
     * @return @b True if out data is valid and sending is correct
     */
    std::string getOutData(const int &outData) const;

    /**
     * @brief Gets the value of out data by its value (see @ref getOutData "getOutData" by index)
     */
    std::string getOutData(const std::string &outData) const;

    /**
     * @brief Returns a list of out data could be obtained by multiple values simultaneously
     */
    std::vector<std::string> getOutDataCoupleList() const;

    /**
     * @brief Converts the value of out data to its index
     * @param[in] outData_string the value of out data e.g. @a X
     * @return Index of considered value of out data
     */
    int outDataCoupleNumberFromString(const std::string  &outDataCouple_string) const;

    /**
     * @brief Converts the index of out data to its value
     * @param[in] outData_number the index of out data e.g. @a 2
     * @return The value of out data
     */
    std::string outDataCoupleStringFromNumber(const int &outDataCouple_number) const;

    /**
     * @brief Returns the values of 2 parameters at a single instant by their indices
     * according to specification tables
     * ![SR830](outDataCoupleTableSR830.png)
     * ![SR844](outDataCoupleTableSR844.png)
     * ![SR865](outDataTableSR865.png)
     * @param[in] A
     * @param[out] AValue
     * @param[in] B
     * @param[out] BValue
     * @return @b True if out data is valid and sending is correct. Records data to appropriate strings
     */
    bool getOutDataAB(const int &A, std::string &AValue, const int &B, std::string &BValue) const;

    /**
     * @brief Returns the values of 3 parameters at a single instant by their indices
     * according to specification tables
     * ![SR830](outDataCoupleTableSR830.png)
     * ![SR844](outDataCoupleTableSR844.png)
     * ![SR865](outDataTableSR865.png)
     * @param[in] A
     * @param[out] AValue
     * @param[in] B
     * @param[out] BValue
     * @return @b True if out data is valid and sending is correct. Records data to appropriate strings
     */
    bool getOutDataABC(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue) const;

    /**
     * @brief Gets the value of out data by its value (see @ref getOutDataAB "getOutDataAB" by indices)
     */
    bool getOutDataAB(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue) const;

    /**
     * @brief Gets the value of out data by its value (see @ref getOutDataABC "getOutDataABC" by indices)
     */
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
    std::vector <std::string> inputSignalZ;
    std::vector <std::string> closeReserveMode;
    std::vector <std::string> wideReserveMode;

    std::vector <std::string> bufferMode;
    std::vector <std::string> dataSampleRate;


    ///output data such as X, Y, R, Theta
    std::vector <std::string> outData;
    std::vector <std::string> outDataCouple;
    std::vector <std::string> outDataChannel1;
    std::vector <std::string> outDataChannel2;


    //void SetRanges(const LockInAmplifierRanges &new_ranges);

    //void SetTimeConstantList( const std::vector<std::string> &new_time_constantlist);


    /*std::unordered_map < std::string , QSerialPort::BaudRate    > lockinAmplifier_string_to_baud_rate    = {
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
                                                                                               };*/
    std::string invalidData = "-1";

    double epsilon = 0.01;
};

#endif // LOCKINAMPLIFAER_H
