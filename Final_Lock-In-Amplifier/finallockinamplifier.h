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

    /**
     * @brief Returns the minimum dual harmonic available in this Lock-in Amplifier
     */
    int getMinDualHarmonic() const;

    /**
     * @brief Returns the maximum dual harmonic available in this Lock-in Amplifier
     */
    int getMaxDualHarmonic() const;

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
    std::string getDualHarmonic() const; //сложно написать тест надо думать

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

    /**
     * @brief Returns the minimum sine out DC level available in this Lock-in Amplifier
     */
    double getMinSineDCLevel() const;

    /**
     * @brief Returns the maximum sine out DC level available in this Lock-in Amplifier
     */
    double getMaxSineDCLevel() const;

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
     * @brief Tests sine DC level with @p epsilon accuracy and @p interval step
     * @return @b True in success case
     */
    bool testSineDCLevel(const double &interval, const double &epsilon) const;

    /**
     * @brief Returns a list of time constants
     */
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

    /**
     * @brief Returns a list of reference sources
     */
    std::vector<std::string> getRefSourceList() const;

    /**
     * @brief Sets the reference source to internal (i=0), external (i=1) (all the Lock-In Amplifiers),
     * dual (i=2) or chop (i=3). (SR865 only)
     * @param refSource
     * @return True if the reference source is valid and sending is correct
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
     * @brief Tests reference source
     * @return @b True in success case
     */
    bool testRefSource() const;

    /**
     * @brief Returns a list of reference trigger mode
     */
    std::vector<std::string> getRefTriggerModeList() const;

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
     * @brief Tests reference trigger mode
     * @return @b True in success case
     */
    bool testRefTriggerMode() const;

    /**
     * @brief Returns a list of external reference trigger input
     */
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
     * @brief Tests reference trigger output
     * @return @b True in success case
     */
    bool testRefTriggerOutput() const;

    /**
     * @brief Returns an Input Signal list
     */
    std::vector<std::string> getInputSignalList() const;

    /**
     * @brief Sets the signal input to @b voltage (i=0) or @b current (i=1) by index.
     * @param[in] inputSignal
     * @return @b True if query is valid and sending is correct
     */
    bool setInputSignal(const int &inputSignal) const;
    \
    /**
     * @brief Sets Input Signal to parameter inputSignal by its value (see @ref setInputSignal "setInputSignal" by indices)
     */
    bool setInputSignal(const std::string &inputSignal) const;

    /**
     * @brief Returns the signal input
     */
    std::string getInputSignal() const;

    /**
     * @brief Tests input signal
     * @return @b True in success case
     */
    bool testInputSignal() const;

    /**
     * @brief Returns an Input Voltage Mode list
     */
    std::vector<std::string> getInputVoltageModeList() const;

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
     * @brief Tests input voltage mode
     * @return @b True in success case
     */
    bool testInputVoltageMode() const;

    /**
     * @brief Returns a list of Input Voltage Coupling
     */
    std::vector<std::string> getInputVoltageCouplingList() const;

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
     * @brief Tests input voltage coupling
     * @return @b True in success case
     */
    bool testInputVoltageCoupling() const;

    /**
     * @brief Returns a list of Input Voltage Shields
     */
    std::vector<std::string> getInputVoltageShieldsList() const;

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
     * @brief Tests input voltage shields
     * @return @b True in success case
     */
    bool testInputVoltageShields() const;

    /**
     * @brief Returns a list of Input Voltage Ranges
     */
    std::vector<std::string> getInputVoltageRangeList() const;

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
     * @brief Tests input voltage ranges
     * @return @b True in success case
     */
    bool testInputVoltageRange() const;

    /**
     * @brief Returns a list of Input Current Gain
     */
    std::vector<std::string> getInputCurrentGainList() const;

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
     * @brief Tests input current gain
     * @return @b True in success case
     */
    bool testInputCurrentGain() const;

    /**
     * @brief Returns the signal strength indicator from lowest (0) to overload (4).
     */
    std::string getSignalStrength() const;

    /**
     * @brief Returns a sensitivity list
     */
    std::vector<std::string> getSensitivityList() const;

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
     * @brief Tests sensitivity
     * @return @b True in success case
     */
    bool testSensitivity() const;

    /**
     * @brief Returns a list of filer slope values
     */
    std::vector<std::string> getFilterSlopeList() const;

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
     * @brief Tests filter slope
     * @return @b True in success case
     */
    bool testFilterSlope() const;

    /**
     * @brief Returns a list of Synchronous Filter
     */
    std::vector<std::string> getSynchronousFilterList() const;

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
     * @brief Tests synchronous filter
     * @return @b True in success case
     */
    bool testSynchronousFilter() const;

    /**
     * @brief Returns a list of Advance Filter
     */
    std::vector<std::string> getAdvanceFilterList() const;

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

    /**
     * @brief Tests advance filter
     * @return @b True in success case
     */
    bool testAdvanceFilter() const;


    //auto functions
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
     * @brief Auto Range function
     * @details The command performs the Auto Range function.
     * This command is the same as pressing the [Auto Range]
     * @return @b True is case of successful quering
     */
    bool autoRange() const;

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


    //output data functions
    /**
     * @brief Returns a list of out data positions
     */
    std::vector<std::string> getOutDataList() const;

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

    /**
     * @brief Automatically sets the Wide Reserve Mode of the instrument to the minimum reserve without overload.
     */
    bool autoWideReverse() const;

    /**
     * @brief Automatically sets the Reserve Mode of the instrument to the minimum reserve without overload.
     */
    bool autoReserve() const;

    /**
     * @brief Returns a Input Signal list
     */
    std::vector<std::string> getInputSignalZList() const;

    /**
     * @brief Sets the input signal to 50 Ohm (i=0) or 1 MOhm (i=1)
     * @param[in] inputSignalZ
     * @return
     */
    bool setInputSignalZ(const int &inputSignalZ) const;

    /**
     * @brief Sets the input signal by value (see @ref setInputSignalZ "setInputSignalZ" by index)
     */
    bool setInputSignalZ(const std::string &inputSignalZ) const;

    /**
     * @brief Gets the actual input signal
     * @return Actual input signal
     */
    std::string getInputSignalZ() const;

    /**
     * @brief Tests input signal list
     * @return @b True in success case
     */
    bool testInputSignalZ() const;

    /**
     * @brief Returns a Close Reserve Mode list
     */
    std::vector<std::string> getCloseReserveModeList() const;

    /**
     * @brief Sets the reserve mode to high (i=0), normal (i=1) or low (i=2)
     * @param[in] closeReserveMode
     * @return
     */
    bool setCloseReserveMode(const int &closeReserveMode) const;

    /**
     * @brief Sets the reserve mode by value (see @ref setCloseReserveMode "setCloseReserveMode" by index)
     */
    bool setCloseReserveMode(const std::string &icloseReserveMode) const;

    /**
     * @brief Gets the actual reserve mode
     * @return Actual reserve mode
     */
    std::string getCloseReserveMode() const;

    /**
     * @brief Tests close reserve mode
     * @return @b True in success case
     */
    bool testCloseReserveMode() const;

    /**
     * @brief Returns a Wide Reserve Mode list
     */
    std::vector<std::string> getWideReserveModeList() const;

    /**
     * @brief Sets the wide reserve mode to high (i=0), normal (i=1) or low (i=2)
     * @param[in] wideReserveMode
     * @return
     */
    bool setWideReserveMode(const int &wideReserveMode) const;

    /**
     * @brief Sets the wide reserve mode by value (see @ref setWideReserveMode "setWideReserveMode" by index)
     */
    bool setWideReserveMode(const std::string &wideReserveMode) const;

    /**
     * @brief Gets the actual wide reserve mode
     * @return Actual wide reserve mode
     */
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

    /**
     * @brief Return the point @b number stored in the Channel 1 buffer.
     * @param number
     */
    std::string getPointFromBufferChannel1(const int &number) const;

    /**
     * @brief Return the point @b number stored in the Channel 2 buffer.
     * @param number
     */
    std::string getPointFromBufferChannel2(const int &number) const;

    /**
     * @brief Return all point stored in Channel 1 buffer
     */
    std::vector <std::string> getChannel1FromBuffer() const;

    /**
     * @brief Return all point stored in Channel 2 buffer
     */
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
     * @brief Sets the end of buffer mode by index
     * @details Sets the end of buffer mode.
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
     * @brief Tests buffer mode
     * @return @b True in success case
     */
    bool testBufferMode() const;

    /**
     * @brief Returns a Data Sample Rate list
     */
    std::vector<std::string> getDataSampleRateList() const;

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

    /**
     * @brief Tests data sample rate
     * @return @b True in success case
     */
    bool testDataSampleRate() const;

    /**
     * @brief Starts data storage.
     */
    bool startBuffer() const;

    /**
     * @brief Pause data storage
     */
    bool pauseBuffer() const;

    /**
     * @brief Reset the data buffers.
     * This command will erase the data buffer
     */
    bool stopBuffer() const;


    /**
     * @brief Tests all possibilities of current LIA model
     * @return @b True in success case
     */
    std::string allTest() const;
};

#endif // FINALLOCKINAMPLIFIER_H
