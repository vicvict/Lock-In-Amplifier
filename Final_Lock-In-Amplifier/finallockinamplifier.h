/**
 * @file
 * @brief
 * @details The file contains a description of the Final Lock-in Amplifier class
*/

/**
 * @brief Common class for all the LIA's functions
 * @details This class is a "wrapper" for classes that describe the functions
 * of each specific Lock-in Amplifier. It determines whether this model works with
 * this function, and, in case of positive responce, a method of the corresponding class is called.
 * Also, it contains test dunctions
 */

#ifndef FINALLOCKINAMPLIFIER_H
#define FINALLOCKINAMPLIFIER_H

#include "LIA_Models/SR830/sr830.h"
#include "LIA_Models/SR844/sr844.h"
#include "LIA_Models/SR865/sr865.h"
#include "LIA_Models/LockInAmplifier/SRS/SRS.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
#include "windows.h"

#include <QTest>

class finalLockInAmplifier
{
private:
    SRS *srs;

    SR830 *sr830;
    SR844 *sr844;
    SR865 *sr865;

    std::string lockInAmplifierModel;
public:
    finalLockInAmplifier();
    ~finalLockInAmplifier();

    /// Creates a new object with particular model name
    finalLockInAmplifier(const std::string new_model);

    /// Returns a particular model name
    std::string getModel() const;

    /// Sets a particular model name
    void setModel(const std::string new_model) ;

    /// Wrapped function from SerialPortCommunication.h class
    int  getWriteTimeout   (                                ) const;

    /// Wrapped function from SerialPortCommunication.h class
    void setWriteTimeout   (const int &new_write_timeout    )      ;

    /// Wrapped function from SerialPortCommunication.h class
    int  getReadTimeout    (                                ) const;

    /// Wrapped function from SerialPortCommunication.h class
    void setReadTimeout    (const int &new_read_timeout     )      ;

    /// Wrapped function from SerialPortCommunication.h class
    int  getReadWaitTimeout(                                ) const;

    /// Wrapped function from SerialPortCommunication.h class
    void setReadWaitTimeout(const int &new_read_wait_timeout)      ;

    /// Connect by @b new_model name
    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ,
                 const std::string &new_data_bits   ,
                 const std::string &new_stop_bits   ,
                 const std::string &new_parity      ,
                 const std::string &new_flow_control,
                 const std::string &new_model);

    /**
     * @brief 'Auto' connect
     * @details It connects to device to learn its name, disconnects and connetcs by name.
     * @param[in] new_port_name
     * @param[in] new_baudrate
     * @param[in] new_data_bits
     * @param[in] new_stop_bits
     * @param[in] new_parity
     * @param[in] new_flow_control
     * @return @b True in case of success
     */
    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ,
                 const std::string &new_data_bits   ,
                 const std::string &new_stop_bits   ,
                 const std::string &new_parity      ,
                 const std::string &new_flow_control);

    /// Wrapped function from SerialPortCommunication.h class
    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ) const;

    /// Wrapped function from SerialPortCommunication.h class
    bool connect(const std::string &new_port_name   ) const;

    /// Wrapped function from SerialPortCommunication.h class
    bool disconnect() const;

    /// Wrapped function from SerialPortCommunication.h class
    bool recieve    (                            std::string &response                                                                    ) const;

    /// Wrapped function from SerialPortCommunication.h class
    bool send       (const std::string &command, std::string &response, const bool &wait_for_response, const std::string &terminate = "\n") const;

    /// Wrapped function from SerialPortCommunication.h class
    bool sendCommand(const std::string &command,                                                       const std::string &terminate = "\n") const;

    /// Wrapped function from SerialPortCommunication.h class
    bool sendQuery  (const std::string &command, std::string &response,                                const std::string &terminate = "\n") const;

    /// Wrapped function from SerialPortCommunication.h class
    std::string ask (const std::string &command,                                                       const std::string &terminate = "\n") const;

    /// Wrapped function from SerialPortCommunication.h class; see \ref ref_getTTS
    double getTTS() const;

    /// Wrapped function from SerialPortCommunication.h class
    double getTTR() const;

    /// Returns a list of supported models
    std::vector < std::string > getSupportedList() const;

    /// Wrapped function from SerialPortCommunication.h class
    int  getAttemptsToConnect(                                  ) const;

    /// Wrapped function from SerialPortCommunication.h class
    void setAttemptsToConnect(const int &new_attempts_to_connect)      ;

    /// Wrapped function from SerialPortCommunication.h class
    std::string getIDN  (bool* succeed = nullptr) const;

    /// Wrapped function from SerialPortCommunication.h class
    std::string getModel(bool* succeed = nullptr) const;

    /// Wrapped function from SRS.h class
    bool isActive() const;

    /// Wrapped function from SRS.h class
    std::string detect(const std::string &port_name, bool* succeed = nullptr) const;

    std::map < std::string , std::vector < std::string > > scanAllPorts() const;

    /// @b True if src LIA supports working with phase
    bool workWithPhase() const;

    /// @b True if src LIA supports Auto Phase function
    bool workWithAutoPhase() const;

    /// @b True if src LIA supports working with frequency
    bool workWithFrequency() const;

    /// @b True if src LIA supports working with harmonics
    bool workWithHarmonic() const;

    /// @b True if src LIA supports working with dual harmonics
    bool workWithDualHarmonic() const;

    /// @b True if src LIA supports working with sine amplitude
    bool workWithSineAmplitude() const;

    /// @b True if src LIA supports working with sine DC level
    bool workWithSineDCLevel() const;

    /// @b True if src LIA supports working with reference source
    bool workWithRefSource() const;

    /// @b True if src LIA supports working with trigger mode
    bool workWithRefTriggerMode() const;

    /// @b True if src LIA supports working with trigger output
    bool workWithRefTriggerOutput() const;

    /// @b True if src LIA supports working with input signal
    bool workWithInputSignal() const;

    /// @b True if src LIA supports working with Voltage mode
    bool workWithInputVoltageMode() const;

    /// @b True if src LIA supports working with Voltage coupling
    bool workWithInputVoltageCoupling() const;

    /// @b True if src LIA supports working with Voltage shields
    bool workWithInputVoltageShields() const;

    /// @b True if src LIA supports working with Voltage range
    bool workWithInputVoltageRange() const;

    /// @b True if src LIA supports working with Current gain
    bool workWithInputCurrentGain() const;

    /// @b True if src LIA supports working with Signal strenght
    bool workWithSignalStrength() const;

    /// @b True if src LIA supports working with sensitivity
    bool workWithSensitivity() const;

    /// @b True if src LIA supports working with time constant
    bool workWithTimeConstant() const;

    /// @b True if src LIA supports working with filter slope
    bool workWithFilterSlope() const;

    /// @b True if src LIA supports working with Synchronous filter
    bool workWithSynchronousFilter() const;

    /// @b True if src LIA supports working with Advance filter
    bool workWithAdvanceFilter() const;

    /// @b True if src LIA supports working with Auto scale
    bool workWithAutoScale() const;

    /// @b True if src LIA supports working with Auto range
    bool workWithAutoRange() const;

    /// @b True if src LIA supports working with Out Data
    bool workWithOutData() const;

    /// @b True if src LIA supports working with Out Data couple
    bool workWithOutDataCouple() const;

    /// @b True if src LIA supports working with Auto wide reverse
    bool workWithAutoWideReverse() const;

    /// @b True if src LIA supports working with Auto reserve
    bool workWithAutoReserve() const;

    /// @b True if src LIA supports working with input signal Z
    bool workWithInputSignalZ() const;

    /// @b True if src LIA supports working with close reserve mode
    bool workWithCloseReserveMode() const;

    /// @b True if src LIA supports working with wide reserve mode
    bool workWithWideReserveMode() const;

    /// @b True if src LIA supports working with Out Data Channel 1
    bool workWithSetOutDataChannel1() const;

    /// @b True if src LIA supports working with Out Data Channel 2
    bool workWithSetOutDataChannel2() const;

    /// @b True if src LIA supports working with Buffer
    bool workWithBuffer() const;

    /// @b True if src LIA supports working with Buffer
    bool workWithBufferMode() const;

    /// @b True if src LIA supports working with Buffer
    bool workWithDataSampleRate() const;

    /// Returns the minimum phase avialible in this LIA
    double getMinPhase() const;

    /// Returns the maximum phase avialible in this LIA
    double getMaxPhase() const;

    /**
     * @brief Set the reference phase shift to 'phase' degrees
     * @param[in] phase The value of phase in degrees is limited: \f$ -180 \leq phase < 180 \f$
     * @return True if phase is valid and sending is correct
     */
    bool setInternalPhase(const double &phase) const;

    /**
     * @brief Get the reference phase
     * @return The reference phase in degrees
     */
    std::string getPhase() const;

    /**
     * @brief Tests phase with @p epsilon accuracy and @p interval step
     * @return @b True in success case
     */
    bool testPhase(const double &interval, const double &epsilon ) const;

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
     * @param[in] Frequency the value of frequency in Hz
     * @return True if frequency is valid and sending is correct
     */
    bool setFrequency(const double &frequency) const;

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
     * @brief Returns the internal or external frequency
     * @details Returns the internal reference frequency whenever the reference
     * mode is either Internal, Dual, or Chop. The query returns the external
     * frequency when operating in External mode. This behavior mirrors
     * the value displayed in the info bar at the top of the display
     * @return The internal or external frequency in Hz
     */
    std::string getFrequency() const;

    /**
     * @brief Tests frequency with @p epsilon accuracy and @p interval step
     * @return @b True in success case
     */
    bool testFrequency(const double &interval, const double &epsilon) const;


    int getMinHarmonic() const;
    int getMaxHarmonic() const;

    /**
     * @brief Sets the lock-in to detect at the i-th harmonic of the reference frequency
     * @param[in] i The number of harmonic i is limited: \f$ 0 \leq i \geq 99 \f$
     * @return True if the harmonic number is valid and sending is correct
     */
    bool setHarmonic(const int &i) const;

    /**
     * @brief Returns the value of actual harmonic
     * @return The value of external reference frequency in Hz
     */
    std::string getHarmonic() const;
   // std::string testHarmonic(const int &interval) const; понятия не имею как это реализовать не хочу пладить три ифа

    int getMinDualHarmonic() const;
    int getMaxDualHarmonic() const;
    bool setDualHarmonic(const int &i) const;
    std::string getDualHarmonic() const; //сложно написать тест надо думать

    double getMinSineAmplitude() const;
    double getMaxSineAmplitude() const;

    /**
     * @brief Sets the sine amplitude to voltage
     * @param[in] voltage The value is to be rounded to 3 digits
     * @return True if the voltage is valid and sending is correct
     */
    bool setSineAmplitude(const double &voltage) const;

    /**
     * @brief Returns the sine out amplitude
     * @return Returns the sine out amplitude in Volts
     */
    std::string getSineAmplitude() const;

    /**
     * @brief Tests sine amplitude with @p epsilon accuracy and @p interval step
     * @return @b True in success case
     */
    bool testSineAmplitude(const double &interval, const double &epsilon) const;

    double getMinSineDCLevel() const;
    double getMaxSineDCLevel() const;
    bool setSineDCLevel(const double &voltage) const;
    std::string getSineDCLevel() const;

    /**
     * @brief Tests sine DC level with @p epsilon accuracy and @p interval step
     * @return @b True in success case
     */
    bool testSineDCLevel(const double &interval, const double &epsilon) const;

    std::vector<std::string> getTimeConstantList() const;

    /**
     * @brief Sets the time constant according to the specification table
     * ![SR830](timeConstantTableSR830.png)
     *
     * ![SR844](timeConstantTableSR844.png)
     *
     * ![SR865A](timeConstantTableSR865A.png)
     * @param[in] timeConstant
     * @return True if the time constant is valid and sending is correct
     */
    bool setTimeConstant(const int &timeConstant) const;

    /**
     * @brief Sets the time constant by actual value
     * @param[in] timeConstant
     * @return True if the time constant is valid and sending is correct
     */
    bool setTimeConstant(const std::string &timeConstant) const;

    /**
     * @brief Gets the actual time constant
     * @return Actual time constant
     */
    std::string getTimeConstant() const;

    /**
     * @brief Tests time constant
     * @return @b True in success case
     */
    bool testTimeConstant() const;

    std::vector<std::string> getRefSourceList() const;

    /**
     * @brief Sets the reference source to internal (i=0), external (i=1) (all the Lock-In Amplifiers),
     * dual (i=2) or chop (i=3). (SR865 only)
     * @param refSource
     * @return True if the reference source is valid and sending is correct
     */
    bool setRefSource(const int &refSource) const;
    bool setRefSource(const std::string &refSource) const;

    /**
     * @brief Gets the actual reference source
     * @return Actual reference source
     */
    std::string getRefSource() const;

    /**
     * @brief Tests reference source
     * @return @b True in success case
     */
    bool testRefSource() const;

    std::vector<std::string> getRefTriggerModeList() const;
    bool setRefTriggerMode(const int &refTriggerMode) const;
    bool setRefTriggerMode(const std::string &refTriggerMode) const;
    std::string getRefTriggerMode() const;

    /**
     * @brief Tests reference trigger mode
     * @return @b True in success case
     */
    bool testRefTriggerMode() const;

    std::vector<std::string> getRefTriggerOutputList() const;

    /**
     * @brief Set the Reference Input impedance
     * @details Set the Reference Input impedance to:
     * @arg 50 Ω (0) or 10 kΩ (1) (in SR844);
     * @arg 50 Ω (0) or 1 MΩ (1) (in SR865A).
     * The reference Input impedance in SR830 is unchangeble and equals to 10 MΩ
     * @param refTriggerOutput
     * @return True if the reference Input impedance is valid and sending is correct
     */
    bool setRefTriggerOutput(const int &refTriggerOutput) const;
    bool setRefTriggerOutput(const std::string &refTriggerOutput) const;
    std::string getRefTriggerOutput() const;

    /**
     * @brief Tests reference trigger output
     * @return @b True in success case
     */
    bool testRefTriggerOutput() const;

    std::vector<std::string> getInputSignalList() const;
    bool setInputSignal(const int &inputSignal) const;
    bool setInputSignal(const std::string &inputSignal) const;
    std::string getInputSignal() const;

    /**
     * @brief Tests input signal
     * @return @b True in success case
     */
    bool testInputSignal() const;

    std::vector<std::string> getInputVoltageModeList() const;
    bool setInputVoltageMode(const int &inputVoltageMode) const;
    bool setInputVoltageMode(const std::string &inputVoltageMode) const;
    std::string getInputVoltageMode() const;

    /**
     * @brief Tests input voltage mode
     * @return @b True in success case
     */
    bool testInputVoltageMode() const;


    std::vector<std::string> getInputVoltageCouplingList() const;
    bool setInputVoltageCoupling(const int &inputVoltageCoupling) const;
    bool setInputVoltageCoupling(const std::string &inputVoltageCoupling) const;
    std::string getInputVoltageCoupling() const;

    /**
     * @brief Tests input voltage coupling
     * @return @b True in success case
     */
    bool testInputVoltageCoupling() const;

    std::vector<std::string> getInputVoltageShieldsList() const;
    bool setInputVoltageShields(const int &inputVoltageShields) const;
    bool setInputVoltageShields(const std::string &inputVoltageShields) const;
    std::string getInputVoltageShields() const;

    /**
     * @brief Tests input voltage shields
     * @return @b True in success case
     */
    bool testInputVoltageShields() const;

    std::vector<std::string> getInputVoltageRangeList() const;
    bool setInputVoltageRange(const int &inputVoltageRange) const;
    bool setInputVoltageRange(const std::string &inputVoltageRange) const;
    std::string getInputVoltageRange() const;

    /**
     * @brief Tests input voltage ranges
     * @return @b True in success case
     */
    bool testInputVoltageRange() const;

    std::vector<std::string> getInputCurrentGainList() const;
    bool setInputCurrentGain(const int &inputCurrentGain) const;
    bool setInputCurrentGain(const std::string &inputCurrentGain) const;
    std::string getInputCurrentGain() const;

    /**
     * @brief Tests input current gain
     * @return @b True in success case
     */
    bool testInputCurrentGain() const;

    std::string getSignalStrength() const;

    std::vector<std::string> getSensitivityList() const;
    bool setSensitivity(const int &sensitivity) const;
    bool setSensitivity(const std::string &sensitivity) const;
    std::string getSensitivity() const;

    /**
     * @brief Tests sensitivity
     * @return @b True in success case
     */
    bool testSensitivity() const;

    std::vector<std::string> getFilterSlopeList() const;
    bool setFilterSlope(const int &filterSlope) const;
    bool setFilterSlope(const std::string &filterSlope) const;
    std::string getFilterSlope() const;

    /**
     * @brief Tests filter slope
     * @return @b True in success case
     */
    bool testFilterSlope() const;

    std::vector<std::string> getSynchronousFilterList() const;
    bool setSynchronousFilter(const int &synchronousFilter) const;
    bool setSynchronousFilter(const std::string &synchronousFilter) const;
    std::string getSynchronousFilter() const;

    /**
     * @brief Tests synchronous filter
     * @return @b True in success case
     */
    bool testSynchronousFilter() const;

    std::vector<std::string> getAdvanceFilterList() const;
    bool setAdvanceFilter(const int &advanceFilter) const;
    bool setAdvanceFilter(const std::string &advanceFilter) const;
    std::string getAdvanceFilter() const;

    /**
     * @brief Tests advance filter
     * @return @b True in success case
     */
    bool testAdvanceFilter() const;


    //auto functions
    bool autoPhase() const;
    bool autoRange() const;
    bool autoScale() const;


    //output data functions
    std::vector<std::string> getOutDataList() const;
    std::string getOutData(const int &outData) const;
    std::string getOutData(const std::string &outData) const;

    std::vector<std::string> getOutDataCoupleList() const;
    bool getOutDataAB(const int &A, std::string &AValue, const int &B, std::string &BValue) const;
    bool getOutDataABC(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue) const;
    bool getOutDataAB(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue) const;
    bool getOutDataABC(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue) const;

    bool autoWideReverse() const;
    bool autoReserve() const;

    std::vector<std::string> getInputSignalZList() const;
    bool setInputSignalZ(const int &inputSignalZ) const;
    bool setInputSignalZ(const std::string &inputSignalZ) const;
    std::string getInputSignalZ() const;

    /**
     * @brief Tests input signal list
     * @return @b True in success case
     */
    bool testInputSignalZ() const;

    std::vector<std::string> getCloseReserveModeList() const;
    bool setCloseReserveMode(const int &closeReserveMode) const;
    bool setCloseReserveMode(const std::string &icloseReserveMode) const;
    std::string getCloseReserveMode() const;

    /**
     * @brief Tests close reserve mode
     * @return @b True in success case
     */
    bool testCloseReserveMode() const;

    std::vector<std::string> getWideReserveModeList() const;
    bool setWideReserveMode(const int &wideReserveMode) const;
    bool setWideReserveMode(const std::string &wideReserveMode) const;
    std::string getWideReserveMode() const;

    /**
     * @brief Tests wide reserve mode
     * @return @b True in success case
     */
    bool testWideReserveMode() const;

    /*bool outDataAutoZeroChannel1(const int &outDataChannel1) const;
    bool outDataAutoZeroChannel1(const std::string &outDataChannel1) const;
    bool outDataAutoZeroChannel2(const int &outDataChannel2) const;
    bool outDataAutoZeroChannel2(const std::string &outDataChannel2) const;
*/ // не понял как работает эта функция поэтому скорей всего удалю
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
    bool setOutDataChannel1(const int &outDataChannel1) const;
    bool setOutDataChannel1(const std::string &outDataChannel1) const;

    std::vector<std::string> getOutDataChannel2List() const;
    bool setOutDataChannel2(const int &outDataChannel2) const;
    bool setOutDataChannel2(const std::string &outDataChannel2) const;

    std::vector<std::string> getBufferModeList() const;
    bool setBufferMode(const int &bufferMode) const;
    bool setBufferMode(const std::string &bufferMode) const;
    std::string getBufferMode() const;

    /**
     * @brief Tests buffer mode
     * @return @b True in success case
     */
    bool testBufferMode() const;

    std::vector<std::string> getDataSampleRateList() const;
    bool setDataSampleRate(const int &dataSampleRate) const;
    bool setDataSampleRate(const std::string &dataSampleRate) const;
    std::string getDataSampleRate() const;

    /**
     * @brief Tests data sample rate
     * @return @b True in success case
     */
    bool testDataSampleRate() const;


    bool startBuffer() const;
    bool pauseBuffer() const;
    bool stopBuffer() const;


    /**
     * @brief Tests all possibilities of current LIA model
     * @return @b True in success case
     */
    std::string allTest() const;
};

#endif // FINALLOCKINAMPLIFIER_H
