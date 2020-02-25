#ifndef FINALLOCKINAMPLIFIER_H
#define FINALLOCKINAMPLIFIER_H

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

#include "LIA_Models/SR830/sr830.h"
#include "LIA_Models/SR844/sr844.h"
#include "LIA_Models/SR865/sr865.h"
#include "LIA_Models/LockInAmplifier/SRS/SRS.h"

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
    finalLockInAmplifier(const std::string new_model);

    std::string getModel() const;
    void setModel(const std::string new_model) ;

    int  getWriteTimeout   (                                ) const;
    void setWriteTimeout   (const int &new_write_timeout    )      ;
    int  getReadTimeout    (                                ) const;
    void setReadTimeout    (const int &new_read_timeout     )      ;
    int  getReadWaitTimeout(                                ) const;
    void setReadWaitTimeout(const int &new_read_wait_timeout)      ;

    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ,
                 const std::string &new_data_bits   ,
                 const std::string &new_stop_bits   ,
                 const std::string &new_parity      ,
                 const std::string &new_flow_control,
                 const std::string &new_model);
    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ,
                 const std::string &new_data_bits   ,
                 const std::string &new_stop_bits   ,
                 const std::string &new_parity      ,
                 const std::string &new_flow_control);
    bool connect(const std::string &new_port_name   ,
                 const std::string &new_baudrate    ) const;
    bool connect(const std::string &new_port_name   ) const;
    bool disconnect() const;

    bool recieve    (                            std::string &response                                                                    ) const;
    bool send       (const std::string &command, std::string &response, const bool &wait_for_response, const std::string &terminate = "\n") const;
    bool sendCommand(const std::string &command,                                                       const std::string &terminate = "\n") const;
    bool sendQuery  (const std::string &command, std::string &response,                                const std::string &terminate = "\n") const;
    std::string ask (const std::string &command,                                                       const std::string &terminate = "\n") const;

    double getTTS() const;
    double getTTR() const;


    std::vector < std::string > getSupportedList() const;

    int  getAttemptsToConnect(                                  ) const;
    void setAttemptsToConnect(const int &new_attempts_to_connect)      ;

    std::string getIDN  (bool* succeed = nullptr) const;
    std::string getModel(bool* succeed = nullptr) const;

    bool isActive() const;

    std::string detect(const std::string &port_name, bool* succeed = nullptr) const;

    std::map < std::string , std::vector < std::string > > scanAllPorts() const;



    bool workWithPhase() const;
    bool workWithAutoPhase() const;
    bool workWithFrequency() const;
    bool workWithHarmonic() const;
    bool workWithDualHarmonic() const;
    bool workWithSineAmplitude() const;
    bool workWithSineDCLevel() const;
    bool workWithRefSourse() const;
    bool workWithRefTriggerMode() const;
    bool workWithRefTriggerOutput() const;
    bool workWithInputSignal() const;
    bool workWithInputVoltageMode() const;
    bool workWithInputVoltageCoupling() const;
    bool workWithInputVoltageShields() const;
    bool workWithInputVoltageRange() const;
    bool workWithInputCurrentGain() const;
    bool workWithSignalStrength() const;
    bool workWithSensitivity() const;
    bool workWithTimeConstant() const;
    bool workWithFilterSlope() const;
    bool workWithSynchronousFilter() const;
    bool workWithAdvanceFilter() const;
    bool workWithAutoScale() const;
    bool workWithAutoRange() const;
    bool workWithOutData() const;
    bool workWithOutDataCouple() const;
    bool workWithAutoWideReverse() const;
    bool workWithAutoReserve() const;
    bool workWithInputSignalZ() const;
    bool workWithCloseReserveMode() const;
    bool workWithSetOutDataChannel1() const;
    bool workWithSetOutDataChannel2() const;
    bool workWithBuffer() const;
    bool workWithBufferMode() const;


    double getMinPhase() const;
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
    bool testPhase(const double &interval, const double &epsilon ) const;

    double getMinInternalFrequency() const;
    double getMaxInternalFrequency() const;

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
    bool testSineAmplitude(const double &interval, const double &epsilon) const;

    double getMinSineDCLevel() const;
    double getMaxSineDCLevel() const;
    bool setSineDCLevel(const double &voltage) const;
    std::string getSineDCLevel() const;
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
    bool testRefSource() const;

    std::vector<std::string> getRefTriggerModeList() const;
    bool setRefTriggerMode(const int &refTriggerMode) const;
    bool setRefTriggerMode(const std::string &refTriggerMode) const;
    std::string getRefTriggerMode() const;
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
    bool testRefTriggerOutput() const;

    std::vector<std::string> getInputSignalList() const;
    bool setInputSignal(const int &inputSignal) const;
    bool setInputSignal(const std::string &inputSignal) const;
    std::string getInputSignal() const;
    bool testInputSignal() const;

    std::vector<std::string> getInputVoltageModeList() const;
    bool setInputVoltageMode(const int &inputVoltageMode) const;
    bool setInputVoltageMode(const std::string &inputVoltageMode) const;
    std::string getInputVoltageMode() const;
    bool testInputVoltageMode() const;


    std::vector<std::string> getInputVoltageCouplingList() const;
    bool setInputVoltageCoupling(const int &inputVoltageCoupling) const;
    bool setInputVoltageCoupling(const std::string &inputVoltageCoupling) const;
    std::string getInputVoltageCoupling() const;
    bool testInputVoltageCoupling() const;

    std::vector<std::string> getInputVoltageShieldsList() const;
    bool setInputVoltageShields(const int &inputVoltageShields) const;
    bool setInputVoltageShields(const std::string &inputVoltageShields) const;
    std::string getInputVoltageShields() const;
    bool testInputVoltageShields() const;

    std::vector<std::string> getInputVoltageRangeList() const;
    bool setInputVoltageRange(const int &inputVoltageRange) const;
    bool setInputVoltageRange(const std::string &inputVoltageRange) const;
    std::string getInputVoltageRange() const;
    bool testInputVoltageRange() const;

    std::vector<std::string> getInputCurrentGainList() const;
    bool setInputCurrentGain(const int &inputCurrentGain) const;
    bool setInputCurrentGain(const std::string &inputCurrentGain) const;
    std::string getInputCurrentGain() const;
    bool testInputCurrentGain() const;

    std::string getSignalStrength() const;

    std::vector<std::string> getSensitivityList() const;
    bool setSensitivity(const int &sensitivity) const;
    bool setSensitivity(const std::string &sensitivity) const;
    std::string getSensitivity() const;
    bool testSensitivity() const;

    std::vector<std::string> getFilterSlopeList() const;
    bool setFilterSlope(const int &filterSlope) const;
    bool setFilterSlope(const std::string &filterSlope) const;
    std::string getFilterSlope() const;
    bool testFilterSlope() const;

    std::vector<std::string> getSynchronousFilterList() const;
    bool setSynchronousFilter(const int &synchronousFilter) const;
    bool setSynchronousFilter(const std::string &synchronousFilter) const;
    std::string getSynchronousFilter() const;
    bool testSynchronousFilter() const;

    std::vector<std::string> getAdvanceFilterList() const;
    bool setAdvanceFilter(const int &advanceFilter) const;
    bool setAdvanceFilter(const std::string &advanceFilter) const;
    std::string getAdvanceFilter() const;
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
    bool testInputSignalZ() const;

    std::vector<std::string> getCloseReserveModeList() const;
    bool setCloseReserveMode(const int &closeReserveMode) const;
    bool setCloseReserveMode(const std::string &icloseReserveMode) const;
    std::string getCloseReserveMode() const;
    bool testCloseReserveMode() const;

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
    bool testBufferMode() const;

    bool startBuffer() const;
    bool pauseBuffer() const;
    bool stopBuffer() const;

    std::string allTest() const;
};

#endif // FINALLOCKINAMPLIFIER_H