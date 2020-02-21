/**
 * @file
 * @brief
 * @details The file contains a description of the Lock-in Amplifier class.
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

        std::string OutData = "OUTP";
        std::string CoupleOfData = "SNAP";
        std::string SetOutData = "DDEF";

        std::string AutoPhase = "APHS";
        std::string AutoRange;
        std::string AutoScale = "AGAN"; //не факт что в 830 она делает то что надо. Надо проверить
        std::string AutoWideReverse;
        std::string AutoReserve;
        std::string AutoZero;
        ///buffer commands exist only 844 830
        std::string BufferMode = "SEND";
        std::string StartBuffer = "STRT";
        std::string PauseBuffer = "PAUS";
        std::string StopBuffer =  "REST";
        std::string BufferSize =  "SPTS";
        std::string GetPointFromBuffer = "TRCA";
    };

public:
    LockInAmplifier();
    ~LockInAmplifier();

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

    std::vector<std::string> getTimeConstantList() const;
    int timeConstantNumberFromString(const std::string  &timeConstant_string) const;
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

    std::vector<std::string> getRefSourceList() const;
    int refSourceNumberFromString(const std::string  &refSource_string) const;
    std::string refSourceStringFromNumber(const int &refSource_number) const;

    /**
     * @brief Sets the reference source to internal (i=0), external (i=1) (all the Lock-In Amplifiers),
     * dual (i=2) or chop (i=3). (SR865 only)
     * @param refSource
     * @return @b True if the reference source is valid and sending is correct
     */
    bool setRefSource(const int &refSource) const;
    bool setRefSource(const std::string &refSource) const;

    /**
     * @brief Gets the actual reference source
     * @return Actual reference source
     */
    std::string getRefSource() const;


    std::vector<std::string> getRefTriggerOutputList() const;
    int refTriggerOutputNumberFromString(const std::string  &refTriggerOutput_string) const;
    std::string refTriggerOutputStringFromNumber(const int &refTriggerOutput_number) const;

    /**
     * @brief Set the Reference Input impedance
     * @details Set the Reference Input impedance to:
     * @arg 50 Ω (0) or 10 kΩ (1) (in SR844);
     * @arg 50 Ω (0) or 1 MΩ (1) (in SR865A).
     * The reference Input impedance in SR830 is unchangeble and equals to 10 MΩ
     * @param refTriggerOutput
     * @return @b True if the reference Input impedance is valid and sending is correct
     */
    bool setRefTriggerOutput(const int &refTriggerOutput) const;
    bool setRefTriggerOutput(const std::string &refTriggerOutput) const;
    std::string getRefTriggerOutput() const;




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





    //auto functions
    bool autoPhase() const;
    bool autoScale() const;


    //output data functions
    std::vector<std::string> getOutDataList() const;
    int outDataNumberFromString(const std::string  &outData_string) const;
    std::string outDataStringFromNumber(const int &outData_number) const;
    std::string getOutData(const int &outData) const;
    std::string getOutData(const std::string &outData) const;

    std::vector<std::string> getOutDataCoupleList() const;
    int outDataCoupleNumberFromString(const std::string  &outDataCouple_string) const;
    std::string outDataCoupleStringFromNumber(const int &outDataCouple_number) const;
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
    std::vector <std::string> inputSignalZ;
    std::vector <std::string> closeReserveMode;

    std::vector <std::string> bufferMode;


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
