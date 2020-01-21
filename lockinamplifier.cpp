#include "lockinamplifier.h"

LockInAmplifier::LockInAmplifier()
{
    init();
}

LockInAmplifier::~LockInAmplifier()
{

}

int LockInAmplifier::numberFromString(const QStringList &list, const QString &string) const
{
    return list.indexOf(string);
}

QString LockInAmplifier::stringFromNumber(const QStringList &list, const int &number) const
{
    if (isValidNumber(list, number))
        return list.at(number);
    return "";
}

bool LockInAmplifier::isValidString(const QStringList &list, const QString &string) const
{
    return(numberFromString(list, string) != -1);
}

bool LockInAmplifier::isValidNumber(const QStringList &list, const int &number) const
{
    return (number >= 0 && number < list.size());
}

bool LockInAmplifier::isValidPhase(const double &Phase) const
{
    return (Phase >= -180 &&
            Phase <= 180);
}

bool LockInAmplifier::setInternalPhase(const double &Phase) const
{
    QString command = "PHAS " + QString::number(Phase);
    if (isValidInternalFrequency(Phase))
        return sendCommand(to_StdString(command));
    else
        return false;
}

double LockInAmplifier::getPhase() const
{
    std::string answer = ask("PHAS?");
    QString answer_q = to_QString(answer);
    return answer_q.toDouble();
}

double LockInAmplifier::getMinInternalFrequency() const
{
    return this->State.minInternalFrequency;
}

double LockInAmplifier::getMaxInternalFrequency() const
{
    return this->State.maxInternalFrequency;
}

bool LockInAmplifier::isValidInternalFrequency(const double &frequency) const
{
    return (frequency >= this->State.minInternalFrequency &&
            frequency <= this->State.maxInternalFrequency);
}

bool LockInAmplifier::setInternalFrequency(const double &frequency) const
{
    QString command = "FREQ " + QString::number(frequency);
    std::string command_s = to_StdString(command);
    if (isValidInternalFrequency(frequency))
        return sendCommand(command_s);
    else
        return false;
}

double LockInAmplifier::getFrequency() const
{
    std::string answer = ask("FREQ?");
    QString answer_q = to_QString(answer);
    return answer_q.toDouble();
}

int LockInAmplifier::getMinHarmonic() const
{
    return this->State.minHarmonic;
}

int LockInAmplifier::getMaxHarmonic() const
{
    return this->State.maxHarmonic;
}

bool LockInAmplifier::isValidHarmonic(const int &i) const
{
    return (i >= this->State.minHarmonic &&
            i <= this->State.maxHarmonic);
}

bool LockInAmplifier::setHarmonic(const int &i) const
{
    QString command = "HARM " + QString::number(i);
    std::string command_s = to_StdString(command);
    if (isValidHarmonic(i))
        return sendCommand(command_s);
    else
        return false;
}

int LockInAmplifier::getHarmonic() const
{
    std::string answer = ask("HARM?");
    QString answer_q = to_QString(answer);
    return answer_q.toInt();
}

double LockInAmplifier::getMinSineOutAmplitude() const
{
    return this->State.minSineOutputAmplitude;
}

double LockInAmplifier::getMaxSineOutAmplitude() const
{
    return this->State.maxSineOutputAmplitude;
}

bool LockInAmplifier::isValidSineOutAmplitude(const double &sineAmplitude) const
{
    return (sineAmplitude >= this->State.minSineOutputAmplitude &&
            sineAmplitude <= this->State.maxSineOutputAmplitude);
}

bool LockInAmplifier::setSineOutAmplitude(const double &sineAmplitude) const
{
    QString command = "SLVL " + QString::number(sineAmplitude);
    std::string command_s = to_StdString(command);
    if (isValidSineOutAmplitude(sineAmplitude))
        return sendCommand(command_s);
    else
        return false;
}

double LockInAmplifier::getSineOutAmplitude() const
{
    std::string answer = ask("SLVL?");
    QString answer_q = to_QString(answer);
    return answer_q.toDouble();
}

void LockInAmplifier::initReferenceSourceList()
{
    this->State.referenceSourceList.clear();

    this->State.referenceSourceList.push_back("EXT");
    this->State.referenceSourceList.push_back("INT");

    return;
}

QStringList LockInAmplifier::getReferenceSourceList() const
{
    return this->State.referenceSourceList;
}

int LockInAmplifier::refSourceNumberFromString(const QString &ref_string) const
{
    return numberFromString(this->State.referenceSourceList, ref_string);
}

QString LockInAmplifier::refSourceStringFromNumber(const int &ref_number) const
{
    return stringFromNumber(this->State.referenceSourceList, ref_number);
}

bool LockInAmplifier::setReferenceSource(const int &source) const
{
    if (!isValidNumber(this->State.referenceSourceList, source))
        return false;

    QString command = "FMOD " + QString::number(source);
    std::string command_s = to_StdString(command);
    return sendCommand(command_s);
}

bool LockInAmplifier::setReferenceSource(const QString &source) const
{
    return setReferenceSource(refSourceNumberFromString(source));
}

QString LockInAmplifier::getReferenceSource() const
{
    std::string answer = ask("FMOD?");
    QString answer_q = to_QString(answer);
    return refSourceStringFromNumber(answer_q.toInt());
}

void LockInAmplifier::initReferenceTriggerModeList()
{
    this->State.referenceTriggerModeList.clear();

    this->State.referenceTriggerModeList.push_back("SIN");
    this->State.referenceTriggerModeList.push_back("TTL Rising");
    this->State.referenceTriggerModeList.push_back("TTL Falling");

    return;
}

QStringList LockInAmplifier::getReferenceTriggerModeList() const
{
    return this->State.referenceTriggerModeList;
}

int LockInAmplifier::refModeNumberFromString(const QString &mode_string) const
{
    return numberFromString(this->State.referenceTriggerModeList, mode_string);
}

QString LockInAmplifier::refModeStringFromNumber(const int &mode_number) const
{
    return stringFromNumber(this->State.referenceTriggerModeList, mode_number);
}

bool LockInAmplifier::setReferenceTriggerMode(const int &mode) const
{
    if (!isValidNumber(this->State.referenceTriggerModeList, mode))
        return false;

    QString command = "RSLP " + QString::number(mode);
    std::string command_s = to_StdString(command);
    return sendCommand(command_s);
}

bool LockInAmplifier::setReferenceTriggerMode(const QString &mode) const
{
    return setReferenceTriggerMode(refModeNumberFromString(mode));
}

QString LockInAmplifier::getReferenceTriggerMode() const
{
    std::string answer = ask("RSLP?");
    QString answer_q = to_QString(answer);
    return refModeStringFromNumber(answer_q.toInt());
}

void LockInAmplifier::initSignalInputList()
{
    this->State.signalInputList.clear();

    this->State.signalInputList.push_back("Vol A");
    this->State.signalInputList.push_back("Vol A-B");
    this->State.signalInputList.push_back("Cur 1MOhm");
    this->State.signalInputList.push_back("Cur 100MOhm");

    return;
}

QStringList LockInAmplifier::getSignalInputList() const
{
    return this->State.signalInputList;
}

int LockInAmplifier::signalInputNumberFromString(const QString &signalInput_string) const
{
    return numberFromString(this->State.signalInputList, signalInput_string);
}

QString LockInAmplifier::signalInputStringFromNumber(const int &signalInput_number) const
{
    return stringFromNumber(this->State.signalInputList, signalInput_number);
}

bool LockInAmplifier::setSignalInput(const int &signalInput) const
{
    if (!isValidNumber(this->State.signalInputList, signalInput))
        return false;

    QString command = "ISRC " + QString::number(signalInput);
    std::string command_s = to_StdString(command);
    return sendCommand(command_s);
}

bool LockInAmplifier::setSignalInput(const QString &signalInput) const
{
    return setSignalInput(signalInputNumberFromString(signalInput));
}

QString LockInAmplifier::getSignalInput() const
{
    return signalInputStringFromNumber(to_QString(ask("ISRC?")).toInt());
}

void LockInAmplifier::initVoltageInputCouplingList()
{
    this->State.voltageInputCouplingList.clear();

    this->State.voltageInputCouplingList.push_back("AC");
    this->State.voltageInputCouplingList.push_back("DC");

    return;
}

QStringList LockInAmplifier::getVoltageInputCouplingList() const
{
    return this->State.voltageInputCouplingList;
}

int LockInAmplifier::voltageInputCouplingNumberFromString(const QString &voltageInputCoupling_string) const
{
    return numberFromString(this->State.voltageInputCouplingList, voltageInputCoupling_string);
}

QString LockInAmplifier::voltageInputCouplingStringFromNumber(const int &voltageInputCoupling_number) const
{
    return stringFromNumber(this->State.voltageInputCouplingList, voltageInputCoupling_number);
}

bool LockInAmplifier::setVoltageInputCoupling(const int &voltageInputCoupling) const
{
    if (!isValidNumber(this->State.voltageInputCouplingList, voltageInputCoupling))
        return false;

    QString command = "ICPL " + QString::number(voltageInputCoupling);

    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setVoltageInputCoupling(const QString &voltageInputCoupling) const
{
    return setVoltageInputCoupling(voltageInputCouplingNumberFromString(voltageInputCoupling));
}

QString LockInAmplifier::getVoltageInputCoupling() const
{
    return voltageInputCouplingStringFromNumber(to_QString(ask("ICPL?")).toInt());
}

void LockInAmplifier::initVoltageInputShieldsList()
{
    this->State.voltageInputShieldsList.clear();

    this->State.voltageInputShieldsList.push_back("FLOAT");
    this->State.voltageInputShieldsList.push_back("GROUND");

    return;
}

QStringList LockInAmplifier::getVoltageInputShieldsList() const
{
    return this->State.voltageInputShieldsList;
}

int LockInAmplifier::voltageInputShieldsNumberFromString(const QString &voltageInputShields_string) const
{
    return numberFromString(this->State.voltageInputShieldsList, voltageInputShields_string);
}

QString LockInAmplifier::voltageInputShieldsStringFromNumber(const int &voltageInputShields_number) const
{
    return stringFromNumber(this->State.voltageInputShieldsList, voltageInputShields_number);
}

bool LockInAmplifier::setVoltageInputShields(const int &voltageInputShields) const
{
    if (!isValidNumber(this->State.voltageInputShieldsList, voltageInputShields))
        return false;

    QString command = "IGND " + QString::number(voltageInputShields);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setVoltageInputShields(const QString &voltageInputShields) const
{
    return setVoltageInputShields(voltageInputShieldsNumberFromString(voltageInputShields));
}

QString LockInAmplifier::getVoltageInputShields() const
{
    return voltageInputShieldsStringFromNumber(to_QString(ask("IGND?")).toInt());
}

void LockInAmplifier::initInputLineNotchFilterList()
{
    this->State.notchFilterList.clear();

    this->State.notchFilterList.push_back("No filter");
    this->State.notchFilterList.push_back("Line notch");
    this->State.notchFilterList.push_back("2xLine notch");
    this->State.notchFilterList.push_back("Both notch");

    return;
}

QStringList LockInAmplifier::getInputLineNotchFilterList() const
{
    return this->State.notchFilterList;
}

int LockInAmplifier::inputLineNotchFilterNumberFromString(const QString &inputLineNotchFilter_string) const
{
    return numberFromString(this->State.notchFilterList, inputLineNotchFilter_string);
}

QString LockInAmplifier::inputLineNotchFilterStringFromNumber(const int &inputLineNotchFilter_number) const
{
    return stringFromNumber(this->State.notchFilterList, inputLineNotchFilter_number);
}

bool LockInAmplifier::setInputLineNotchFilter(const int &inputLineNotchFilter) const
{
    if (!isValidNumber(this->State.notchFilterList, inputLineNotchFilter))
        return false;

    QString command = "ILIN " + QString::number(inputLineNotchFilter);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setInputLineNotchFilter(const QString &inputLineNotchFilter) const
{
    return setInputLineNotchFilter(inputLineNotchFilterNumberFromString(inputLineNotchFilter));
}

QString LockInAmplifier::getInputLineNotchFilter() const
{
    return inputLineNotchFilterStringFromNumber(to_QString(ask("ILIN?")).toInt());
}

void LockInAmplifier::initSensivityList()
{
    this->State.sensivityList.clear();

    this->State.sensivityList.push_back(  "2 nV/fA");
    this->State.sensivityList.push_back(  "5 nV/fA");
    this->State.sensivityList.push_back( "10 nV/fA");
    this->State.sensivityList.push_back( "20 nV/fA");
    this->State.sensivityList.push_back( "50 nV/fA");
    this->State.sensivityList.push_back("100 nV/fA");
    this->State.sensivityList.push_back("200 nV/fA");
    this->State.sensivityList.push_back("500 nV/fA");
    this->State.sensivityList.push_back(  "1 uV/pA");
    this->State.sensivityList.push_back(  "2 uV/pA");
    this->State.sensivityList.push_back(  "5 uV/pA");
    this->State.sensivityList.push_back( "10 uV/pA");
    this->State.sensivityList.push_back( "20 uV/pA");
    this->State.sensivityList.push_back( "50 uV/pA");
    this->State.sensivityList.push_back("100 uV/pA");
    this->State.sensivityList.push_back("200 uV/pA");
    this->State.sensivityList.push_back("500 uV/pA");
    this->State.sensivityList.push_back(  "1 mV/nA");
    this->State.sensivityList.push_back(  "2 mV/nA");
    this->State.sensivityList.push_back(  "5 mV/nA");
    this->State.sensivityList.push_back( "10 mV/nA");
    this->State.sensivityList.push_back( "20 mV/nA");
    this->State.sensivityList.push_back( "50 mV/nA");
    this->State.sensivityList.push_back("100 mV/nA");
    this->State.sensivityList.push_back("200 mV/nA");
    this->State.sensivityList.push_back("500 mV/nA");
    this->State.sensivityList.push_back(  "1 V/uA");

    return;
}

QStringList LockInAmplifier::getSensivityList() const
{
    return this->State.sensivityList;
}

int LockInAmplifier::sensivityNumberFromString(const QString &sensivity_string) const
{
    return numberFromString(this->State.sensivityList, sensivity_string);
}

QString LockInAmplifier::sensivityStringFromNumber(const int &sensivity_number) const
{
    return stringFromNumber(this->State.sensivityList, sensivity_number);
}

bool LockInAmplifier::setSensivity(const int &sensivity) const
{
    if (!isValidNumber(this->State.sensivityList, sensivity))
        return false;

    QString command = "SENS " + QString::number(sensivity);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setSensivity(const QString &sensivity) const
{
    return setSensivity(sensivityNumberFromString(sensivity));
}

QString LockInAmplifier::getSensivity() const
{
    return sensivityStringFromNumber(to_QString(ask("SENS?")).toInt());
}

void LockInAmplifier::initReserveModeList()
{
    this->State.reserveModeList.clear();

    this->State.reserveModeList.push_back("High Reserve");
    this->State.reserveModeList.push_back("Normal");
    this->State.reserveModeList.push_back("Low Noise");

    return;
}

QStringList LockInAmplifier::getReserveModeList() const
{
    return this->State.reserveModeList;
}

int LockInAmplifier::reserveModeNumberFromString(const QString &reserveMode_string) const
{
    return numberFromString(this->State.reserveModeList, reserveMode_string);
}

QString LockInAmplifier::reserveModeStringFromNumber(const int &reserveMode_number) const
{
    return stringFromNumber(this->State.reserveModeList, reserveMode_number);
}

bool LockInAmplifier::setReserveMode(const int &reserveMode) const
{
    if (!isValidNumber(this->State.reserveModeList, reserveMode))
        return false;

    QString command = "RMOD " + QString::number(reserveMode);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setReserveMode(const QString &reserveMode) const
{
    return setReserveMode(reserveModeNumberFromString(reserveMode));
}

QString LockInAmplifier::getReserveMode() const
{
    return reserveModeStringFromNumber(to_QString(ask("RMOD?")).toInt());
}

void LockInAmplifier::initTimeConstantList()
{
    this->State.timeConstantList.clear();

    this->State.timeConstantList.push_back( "10 us");
    this->State.timeConstantList.push_back( "30 us");
    this->State.timeConstantList.push_back("100 us");
    this->State.timeConstantList.push_back("300 us");
    this->State.timeConstantList.push_back(  "1 ms");
    this->State.timeConstantList.push_back(  "3 ms");
    this->State.timeConstantList.push_back( "10 ms");
    this->State.timeConstantList.push_back( "30 ms");
    this->State.timeConstantList.push_back("100 ms");
    this->State.timeConstantList.push_back("300 ms");
    this->State.timeConstantList.push_back(  "1 s");
    this->State.timeConstantList.push_back(  "3 s");
    this->State.timeConstantList.push_back( "10 s");
    this->State.timeConstantList.push_back( "30 s");
    this->State.timeConstantList.push_back("100 s");
    this->State.timeConstantList.push_back("300 s");
    this->State.timeConstantList.push_back(  "1 ks");
    this->State.timeConstantList.push_back(  "3 ks");
    this->State.timeConstantList.push_back( "10 ks");
    this->State.timeConstantList.push_back( "30 ks");

    return;
}

QStringList LockInAmplifier::getTimeConstantList() const
{
    return this->State.timeConstantList;
}

int LockInAmplifier::timeConstantNumberFromString(const QString &timeConstant_string) const
{
    return numberFromString(this->State.timeConstantList, timeConstant_string);
}

QString LockInAmplifier::timeConstantStringFromNumber(const int &timeConstant_number) const
{
    return stringFromNumber(this->State.timeConstantList, timeConstant_number);
}

bool LockInAmplifier::setTimeConstant(const int &timeConstant) const
{
    if (!isValidNumber(this->State.timeConstantList, timeConstant))
        return false;

    QString command = "OFLT " + QString::number(timeConstant);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setTimeConstant(const QString &timeConstant) const
{
    return setTimeConstant(timeConstantNumberFromString(timeConstant));
}

QString LockInAmplifier::getTimeConstant() const
{
    return timeConstantStringFromNumber(to_QString(ask("OFLT?")).toInt());
}

void LockInAmplifier::initFilterList()
{
    this->State.filterList.clear();

    this->State.filterList.push_back( "6 dB/oct");
    this->State.filterList.push_back("12 dB/oct");
    this->State.filterList.push_back("18 dB/oct");
    this->State.filterList.push_back("24 dB/oct");

    return;
}

QStringList LockInAmplifier::getFilterList() const
{
    return this->State.filterList;
}

int LockInAmplifier::filterNumberFromString(const QString &filter_string) const
{
    return numberFromString(this->State.filterList, filter_string);
}

QString LockInAmplifier::filterStringFromNumber(const int &filter_number) const
{
    return stringFromNumber(this->State.filterList, filter_number);
}

bool LockInAmplifier::setFilter(const int &filter) const
{
    if (!isValidNumber(this->State.filterList, filter))
        return false;

    QString command = "OFSL " + QString::number(filter);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setFilter(const QString &filter) const
{
    return setFilter(filterNumberFromString(filter));
}

QString LockInAmplifier::getFilter() const
{
    return filterStringFromNumber(to_QString(ask("OFSL?")).toInt());
}

bool LockInAmplifier::enableSynchronousFilter(const bool &enable) const
{
    std::string command = "SYNC ";
    if (enable)
        command += "1";
    else
        command += "0";

    return sendCommand(command);
}

bool LockInAmplifier::getSynchronousFilterEnabled() const
{
    return to_QString(ask("SYNC?")).toInt();
}

bool LockInAmplifier::enableRS232outputInterface() const
{
    return sendCommand("OUTX 0");
}

bool LockInAmplifier::autoGain() const
{
    return sendCommand("AGAN");
}

bool LockInAmplifier::autoReserve() const
{
    return sendCommand("ARSV");
}

bool LockInAmplifier::autoPhase() const
{
    return sendCommand("APHS");
}
/*
bool SR830::autoOffset(const int &i) const
{
    if (i < 1 || i > 3)
        return false;

    return sendCommand("AGAN" + QString::number(i));
}

bool SR830::autoOffsetAll() const
{
    bool ans = true;

    for (int i = 1;i <= 3;i++)
        ans &= autoOffset(i);

    return ans;
}
*/
void LockInAmplifier::initSampleRateList()
{
    this->State.sampleRateList.clear();

    this->State.sampleRateList.push_back("62.5 mHz");
    this->State.sampleRateList.push_back( "125 mHz");
    this->State.sampleRateList.push_back( "250 mHz");
    this->State.sampleRateList.push_back( "500 mHz");
    this->State.sampleRateList.push_back(   "1 Hz");
    this->State.sampleRateList.push_back(   "2 Hz");
    this->State.sampleRateList.push_back(   "4 Hz");
    this->State.sampleRateList.push_back(   "8 Hz");
    this->State.sampleRateList.push_back(  "16 Hz");
    this->State.sampleRateList.push_back(  "32 Hz");
    this->State.sampleRateList.push_back(  "64 Hz");
    this->State.sampleRateList.push_back( "128 Hz");
    this->State.sampleRateList.push_back( "256 Hz");
    this->State.sampleRateList.push_back( "512 Hz");
    this->State.sampleRateList.push_back("Trigger");

    return;
}

QStringList LockInAmplifier::getSampleRateList() const
{
    return this->State.sampleRateList;
}

int LockInAmplifier::sampleRateNumberFromString(const QString &sampleRate_string) const
{
    return numberFromString(this->State.sampleRateList, sampleRate_string);
}

QString LockInAmplifier::sampleRateStringFromNumber(const int &sampleRate_number) const
{
    return stringFromNumber(this->State.sampleRateList, sampleRate_number);
}

bool LockInAmplifier::setSampleRate(const int &sampleRate) const
{
    if (!isValidNumber(this->State.sampleRateList, sampleRate))
        return false;

    QString command = "SRAT " + QString::number(sampleRate);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setSampleRate(const QString &sampleRate) const
{
    return setSampleRate(sampleRateNumberFromString(sampleRate));
}

QString LockInAmplifier::getSampleRate() const
{
    return sampleRateStringFromNumber(to_QString(ask("SRAT?")).toInt());
}

void LockInAmplifier::initBufferModeList()
{
    this->State.bufferModeList.clear();

    this->State.bufferModeList.push_back("Shot");
    this->State.bufferModeList.push_back("Loop");

    return;
}

QStringList LockInAmplifier::getBufferModeList() const
{
    return this->State.bufferModeList;
}

int LockInAmplifier::bufferModeNumberFromString(const QString &bufferMode_string) const
{
    return numberFromString(this->State.bufferModeList, bufferMode_string);
}

QString LockInAmplifier::bufferModeStringFromNumber(const int &bufferMode_number) const
{
    return stringFromNumber(this->State.bufferModeList, bufferMode_number);
}

bool LockInAmplifier::setBufferMode(const int &bufferMode) const
{
    if (!isValidNumber(this->State.bufferModeList, bufferMode))
        return false;

    QString command = "SEND " + QString::number(bufferMode);
    return sendCommand(to_StdString(command));
}

bool LockInAmplifier::setBufferMode(const QString &bufferMode) const
{
    return setBufferMode(bufferModeNumberFromString(bufferMode));
}

QString LockInAmplifier::getBufferMode() const
{
    return bufferModeStringFromNumber(to_QString(ask("SEND?")).toInt());
}

bool LockInAmplifier::startBuffer() const
{
    return sendCommand("STRT");
}

bool LockInAmplifier::pauseBuffer() const
{
    return sendCommand("PAUS");
}

bool LockInAmplifier::stopBuffer() const
{
    return sendCommand("REST");
}

void LockInAmplifier::initOutputNumberList()
{
    this->State.outputNumberList.clear();

    this->State.outputNumberList.push_back("X");
    this->State.outputNumberList.push_back("Y");
    this->State.outputNumberList.push_back("R");
    this->State.outputNumberList.push_back("Theta");
    this->State.outputNumberList.push_back("Aux In 1");
    this->State.outputNumberList.push_back("Aux In 2");
    this->State.outputNumberList.push_back("Aux In 3");
    this->State.outputNumberList.push_back("Aux In 4");
    this->State.outputNumberList.push_back("Reference Frequency");
    this->State.outputNumberList.push_back("CH1 display");
    this->State.outputNumberList.push_back("CH2 display");

    return;
}

QStringList LockInAmplifier::getOutputNumberList() const
{
    return this->State.outputNumberList;
}

int LockInAmplifier::outpNumberFromString(const QString &outp_string) const
{
    return numberFromString(this->State.outputNumberList, outp_string);
}

QString LockInAmplifier::outpStringFromNumber(const int &outp_number) const
{
    return stringFromNumber(this->State.outputNumberList, outp_number);
}

double LockInAmplifier::getOUTP(const int &i) const
{
    if (!isValidNumber(this->State.outputNumberList, i))
        return -1;

    QString command = "OUTP? " + QString::number(i);
    std::string response;
    sendQuery(to_StdString(command), response);
    QString response_q = to_QString(response);
    return response_q.trimmed().toDouble();
}

double LockInAmplifier::getOUTP(const QString &i) const
{
    if (State.outputNumberList.indexOf(i) != -1)
        return getOUTP(State.outputNumberList.indexOf(i));
    return -1;
}

double LockInAmplifier::getX() const
{
    return getOUTP(1);
}

double LockInAmplifier::getY() const
{
    return getOUTP(2);
}

double LockInAmplifier::getR() const
{
    return getOUTP(3);
}

double LockInAmplifier::getTheta() const
{
    return getOUTP(4);
}

bool LockInAmplifier::getAB(const int & Apos, double &A, const int &Bpos, double &B) const
{
    QString command = "SNAP? " + QString::number(Apos) + "," + QString::number(Bpos);
    std::string response;
    if (!sendQuery(to_StdString(command), response))
        return false;

    QString response_q = to_QString(response);
    QStringList responseList = response_q.trimmed().split(',');
    QString _a = responseList.at(0);
    QString _b = responseList.at(1);
    A = _a.trimmed().toDouble();
    B = _b.trimmed().toDouble();

    return true;
}

bool LockInAmplifier::getABC(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C) const
{
    QString command = "SNAP? " + QString::number(Apos) + "," + QString::number(Bpos) + "," + QString::number(Cpos);
    std::string response;
    if (!sendQuery(to_StdString(command), response))
        return false;

    QString response_q = to_QString(response);
    QStringList responseList = response_q.trimmed().split(',');
    QString _a = responseList.at(0);
    QString _b = responseList.at(1);
    QString _c = responseList.at(2);
    A = _a.trimmed().toDouble();
    B = _b.trimmed().toDouble();
    C = _c.trimmed().toDouble();

    return true;
}

bool LockInAmplifier::getABCDE(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C, const int &Dpos, double &D, const int &Epos, double &E) const
{
    QString command = "SNAP? " + QString::number(Apos) + "," + QString::number(Bpos) + "," + QString::number(Cpos) + "," + QString::number(Dpos) + "," + QString::number(Epos);
    std::string response;
    if (!sendQuery(to_StdString(command), response))
        return false;

    QString response_q = to_QString(response);
    QStringList responseList = response_q.trimmed().split(',');
    QString _a = responseList.at(0);
    QString _b = responseList.at(1);
    QString _c = responseList.at(2);
    QString _d = responseList.at(3);
    QString _e = responseList.at(4);
    A = _a.trimmed().toDouble();
    B = _b.trimmed().toDouble();
    C = _c.trimmed().toDouble();
    D = _d.trimmed().toDouble();
    E = _e.trimmed().toDouble();

    return true;
}

bool LockInAmplifier::getABCDEF(const int &Apos, double &A, const int &Bpos, double &B, const int &Cpos, double &C, const int &Dpos, double &D, const int &Epos, double &E, const int &Fpos, double &F) const
{
    QString command = "SNAP? " + QString::number(Apos) + "," + QString::number(Bpos) + "," + QString::number(Cpos) + "," + QString::number(Dpos) + "," + QString::number(Epos) + "," + QString::number(Fpos);
    std::string response;
    if (!sendQuery(to_StdString(command), response))
        return false;

    QString response_q = to_QString(response);
    QStringList responseList = response_q.trimmed().split(',');
    QString _a = responseList.at(0);
    QString _b = responseList.at(1);
    QString _c = responseList.at(2);
    QString _d = responseList.at(3);
    QString _e = responseList.at(4);
    QString _f = responseList.at(5);
    A = _a.trimmed().toDouble();
    B = _b.trimmed().toDouble();
    C = _c.trimmed().toDouble();
    D = _d.trimmed().toDouble();
    E = _e.trimmed().toDouble();
    F = _f.trimmed().toDouble();

    return true;
}

bool LockInAmplifier::getXY(double &X, double &Y) const
{
    return getAB(1, X, 2, Y);
}

bool LockInAmplifier::getRTheta(double &R, double &Theta) const
{
    return getAB(3, R, 4, Theta);
}

bool LockInAmplifier::getRThetaF(double &R, double &Theta, double &F) const
{
    return getABC(3, R, 4, Theta, 9, F);
}

bool LockInAmplifier::getXYRThetaF(double &X, double&Y, double &R, double &Theta, double &F) const
{
    return getABCDE(1, X, 2, Y, 3, R, 4, Theta, 9, F);
}

bool LockInAmplifier::setDisplayData(const int &channel, const int &data) const
{
    return sendCommand(to_StdString("DDEF " + QString::number(channel) + "," + QString::number(data)));
}

int LockInAmplifier:: getBufferSize() const
{
    return to_QString(ask("SPTS?")).toInt();
}

double LockInAmplifier::getPointFromBuffer(const int &channel, const int &number) const
{
    return to_QString(ask(to_StdString("TRCA? " + QString::number(channel) + "," + QString::number(number) + ",1"))).toDouble();
}

std::vector < double > LockInAmplifier::getChannelFromBuffer(const int &channel) const
{
    std::vector < double > ans;

    int size = getBufferSize();
    for (int i = 0;i < size;i++) {
        ans.push_back(getPointFromBuffer(channel, i));
    }

    return ans;
}

int LockInAmplifier::getBuffer(std::vector<double> &ch1, std::vector<double> &ch2) const
{
    ch1.clear();
    ch2.clear();

    int size = getBufferSize();
    for (int i = 0;i < size;i++) {
        ch1.push_back(getPointFromBuffer(1, i));
        ch2.push_back(getPointFromBuffer(2, i));
    }

    return size;
}

