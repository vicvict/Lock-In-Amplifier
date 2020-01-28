#ifndef SR830_H
#define SR830_H


#include "../lockinamplifier.h"

#include <vector>
#include <string>
#include <map>


class SR830: public LockInAmplifier
{
public:
    SR830() : LockInAmplifier() {
        ranges.maxInternalFrequency = 4E6;
        ranges.minSineAmplitude = 1E-9;
        ranges.maxSineAmplitude = 2.0;


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
    }


protected:


};

#endif // SR830_H









//Это только пример (как и реализация библиотеки!)
/*#ifndef SR830_H
#define SR830_H


#include "../lockinamplifier.h"

#include <vector>
#include <string>
#include <map>

struct LockInAmplifier_State
{
    QStringList referenceSourceList;
    QStringList referenceTriggerModeList;
    QStringList signalInputList;
    QStringList voltageInputCouplingList;
    QStringList voltageInputShieldsList;
    QStringList notchFilterList;
    QStringList sensivityList;
    QStringList reserveModeList;
    QStringList timeConstantList;
    QStringList filterList;
    QStringList sampleRateList;
    QStringList bufferModeList;
    QStringList outputNumberList;
};

class SR830 : public LockInAmplifier
{
protected:
    const double minInternalFrequency = 1e-3;
    const double maxInternalFrequency = 1.02e5;

    const double minSineOutputAmplitude = 0.004;
    const double maxSineOutputAmplitude = 5;

    const int minHarmonic = 1;
    const int maxHarmonic = 19999;

    LockInAmplifier_State State;

public:
    explicit SR830();
    ~SR830();

    int numberFromString(const QStringList &list, const QString &string) const;
    QString stringFromNumber(const QStringList &list, const int &number) const;
    bool isValidString(const QStringList &list, const QString &string) const;
    bool isValidNumber(const QStringList &list, const int &number) const;

    bool isValidPhase(const double &Phase) const;
    bool setInternalPhase(const double &phase) const;
    double getPhase() const;

    double getMinInternalFrequency() const;
    double getMaxInternalFrequency() const;
    bool isValidInternalFrequency(const double &frequency) const;
    bool setInternalFrequency(const double &frequency) const;
    double getFrequency() const;

    int getMinHarmonic() const;
    int getMaxHarmonic() const;
    bool isValidHarmonic(const int &i) const;
    bool setHarmonic(const int &i) const;
    int getHarmonic() const;

    double getMinSineOutAmplitude() const;
    double getMaxSineOutAmplitude() const;
    bool isValidSineOutAmplitude(const double &sineAmplitude) const;
    bool setSineOutAmplitude(const double &sineAmplitude) const;
    double getSineOutAmplitude() const;

    void initReferenceSourceList();
    QStringList getReferenceSourceList() const;
    int refSourceNumberFromString(const QString &ref_string) const;
    QString refSourceStringFromNumber(const int &ref_number) const;
    bool setReferenceSource(const int &source) const;
    bool setReferenceSource(const QString &source) const;
    QString getReferenceSource() const;

    void initReferenceTriggerModeList();
    QStringList getReferenceTriggerModeList() const;
    int refModeNumberFromString(const QString &mode_string) const;
    QString refModeStringFromNumber(const int &mode_number) const;
    bool setReferenceTriggerMode(const int &mode) const;
    bool setReferenceTriggerMode(const QString &mode) const;
    QString getReferenceTriggerMode() const;

    void initSignalInputList();
    QStringList getSignalInputList() const;
    int signalInputNumberFromString(const QString &signalInput_string) const;
    QString signalInputStringFromNumber(const int &signalInput_number) const;
    bool setSignalInput(const int &signalInput) const;
    bool setSignalInput(const QString &signalInput) const;
    QString getSignalInput() const;

    void initVoltageInputCouplingList();
    QStringList getVoltageInputCouplingList() const;
    int voltageInputCouplingNumberFromString(const QString &voltageInputCoupling_string) const;
    QString voltageInputCouplingStringFromNumber(const int &voltageInputCoupling_number) const;
    bool setVoltageInputCoupling(const int &voltageInputCoupling) const;
    bool setVoltageInputCoupling(const QString &voltageInputCoupling) const;
    QString getVoltageInputCoupling() const;

    void initVoltageInputShieldsList();
    QStringList getVoltageInputShieldsList() const;
    int voltageInputShieldsNumberFromString(const QString &voltageInputShields_string) const;
    QString voltageInputShieldsStringFromNumber(const int &voltageInputShields_number) const;
    bool setVoltageInputShields(const int &voltageInputShields) const;
    bool setVoltageInputShields(const QString &voltageInputShields) const;
    QString getVoltageInputShields() const;

    void initInputLineNotchFilterList();
    QStringList getInputLineNotchFilterList() const;
    int inputLineNotchFilterNumberFromString(const QString &inputLineNotchFilter_string) const;
    QString inputLineNotchFilterStringFromNumber(const int &inputLineNotchFilter_number) const;
    bool setInputLineNotchFilter(const int &inputLineNotchFilter) const;
    bool setInputLineNotchFilter(const QString &inputLineNotchFilter) const;
    QString getInputLineNotchFilter() const;

    void initSensivityList();
    QStringList getSensivityList() const;
    int sensivityNumberFromString(const QString &sensivity_string) const;
    QString sensivityStringFromNumber(const int &sensivity_number) const;
    bool setSensivity(const int &sensivity) const;
    bool setSensivity(const QString &sensivity) const;
    QString getSensivity() const;

    void initReserveModeList();
    QStringList getReserveModeList() const;
    int reserveModeNumberFromString(const QString &reserveMode_string) const;
    QString reserveModeStringFromNumber(const int &reserveMode_number) const;
    bool setReserveMode(const int &reserveMode) const;
    bool setReserveMode(const QString &reserveMode) const;
    QString getReserveMode() const;

    void initTimeConstantList();
    QStringList getTimeConstantList() const;
    int timeConstantNumberFromString(const QString &timeConstant_string) const;
    QString timeConstantStringFromNumber(const int &timeConstant_number) const;
    bool setTimeConstant(const int &timeConstant) const;
    bool setTimeConstant(const QString &timeConstant) const;
    QString getTimeConstant() const;

    void initFilterList();
    QStringList getFilterList() const;
    int filterNumberFromString(const QString &filter_string) const;
    QString filterStringFromNumber(const int &filter_number) const;
    bool setFilter(const int &filter) const;
    bool setFilter(const QString &filter) const;
    QString getFilter() const;

    bool enableSynchronousFilter(const bool &enable) const;
    bool getSynchronousFilterEnabled() const;

    bool enableRS232outputInterface() const;

    bool autoGain() const;

    bool autoReserve() const;

    bool autoPhase() const;

    bool autoOffset(const int &i) const;
    bool autoOffsetAll() const;

    void initSampleRateList();
    QStringList getSampleRateList() const;
    int sampleRateNumberFromString(const QString &sampleRate_string) const;
    QString sampleRateStringFromNumber(const int &sampleRate_number) const;
    bool setSampleRate(const int &sampleRate) const;
    bool setSampleRate(const QString &sampleRate) const;
    QString getSampleRate() const;

    void initBufferModeList();
    QStringList getBufferModeList() const;
    int bufferModeNumberFromString(const QString &bufferMode_string) const;
    QString bufferModeStringFromNumber(const int &bufferMode_number) const;
    bool setBufferMode(const int &bufferMode) const;
    bool setBufferMode(const QString &bufferMode) const;
    QString getBufferMode() const;

    bool startBuffer() const;
    bool pauseBuffer() const;
    bool stopBuffer() const;

    void initOutputNumberList();
    QStringList getOutputNumberList() const;
    int outpNumberFromString(const QString &outp_string) const;
    QString outpStringFromNumber(const int &outp_number) const;
    double getOUTP(const int &i) const;
    double getOUTP(const QString &i) const;
    double getX() const;
    double getY() const;
    double getR() const;
    double getTheta() const;
    bool getAB(const int &Apos, double &A, const int &Bpos, double &B) const;
    bool getABC(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C) const;
    bool getABCDE(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C, const int &Dpos, double &D, const int &Epos, double &E) const;
    bool getABCDEF(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C, const int &Dpos, double &D, const int &Epos, double &E, const int &Fpos, double &F) const;
    bool getXY(double &X, double &Y) const;
    bool getRTheta(double &R, double &Theta) const;
    bool getRThetaF(double &R, double &Theta, double &F) const;
    bool getXYRThetaF(double &X, double&Y, double &R, double &Theta, double &F) const;

    bool setDisplayData(const int &channel, const int &data) const;
    bool setOutputSourses(const int &channel, const int &quntity) const;
    bool setOffsetandExpand(const int &data, const int &offset, const int expand) const;
    bool setAvtoOffset(const int &data) const;
    int getBufferSize() const;

    double getPointFromBuffer(const int &channel, const int &number) const;
    std::vector < double > getChannelFromBuffer(const int &channel) const;
    int getBuffer(std::vector < double > &ch1, std::vector < double > &ch2) const;

public slots:
    void catchErrorSignal(const QString &s) const;
    void catchResponseSignal(const QString &s) const;
    void catchCommandSignal(const QString &s) const;
    void catchTimeoutSignal(const QString &s) const;

signals:
    void errorSignal(const QString &s) const;
    void responseSignal(const QString &s) const;
    void commandSignal(const QString &s) const;
    void timeoutSignal(const QString &s) const;
};

#endif // SR830_H
*/
