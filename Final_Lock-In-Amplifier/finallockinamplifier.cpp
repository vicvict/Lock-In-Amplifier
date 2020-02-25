#include "finallockinamplifier.h"

finalLockInAmplifier::finalLockInAmplifier() {

}

finalLockInAmplifier::finalLockInAmplifier(const std::string new_model){
    lockInAmplifierModel = new_model;
}

finalLockInAmplifier::~finalLockInAmplifier() {
    sr830->~SR830();
    sr844->~SR844();
    sr865->~SR865();
    delete this->sr830;
    delete this->sr844;
    delete this->sr865;
}

std::string finalLockInAmplifier::getModel() const {
    return this->lockInAmplifierModel;
}

void finalLockInAmplifier::setModel(const std::string new_model) {
    lockInAmplifierModel = new_model;
    return;
}

void finalLockInAmplifier::setWriteTimeout(const int &new_write_timeout) {
    if(this->lockInAmplifierModel == "SR830"){
        this->sr830->setWriteTimeout(new_write_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR844") {
        this->sr844->setWriteTimeout(new_write_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR865") {
        this->sr865->setWriteTimeout(new_write_timeout);
        return;
    }
}

int finalLockInAmplifier::getWriteTimeout() const {
    if(this->lockInAmplifierModel == "SR830")
        return  this->sr830->getWriteTimeout();
    if(this->lockInAmplifierModel == "SR844")
        return  this->sr844->getWriteTimeout();
    if(this->lockInAmplifierModel == "SR865")
        return  this->sr865->getWriteTimeout();
    return -1;
}

void finalLockInAmplifier::setReadTimeout(const int &new_read_timeout) {
    if(this->lockInAmplifierModel == "SR830"){
        this->sr830->setReadTimeout(new_read_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR844") {
        this->sr844->setReadTimeout(new_read_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR865") {
        this->sr865->setReadTimeout(new_read_timeout);
        return;
    }
}

int finalLockInAmplifier::getReadTimeout() const {
    if(this->lockInAmplifierModel == "SR830")
        return  this->sr830->getReadTimeout();
    if(this->lockInAmplifierModel == "SR844")
        return  this->sr844->getReadTimeout();
    if(this->lockInAmplifierModel == "SR865")
        return  this->sr865->getReadTimeout();
    return -1;
}

void finalLockInAmplifier::setReadWaitTimeout(const int &new_read_wait_timeout) {
    if(this->lockInAmplifierModel == "SR830"){
        this->sr830->setReadWaitTimeout(new_read_wait_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR844") {
        this->sr844->setReadWaitTimeout(new_read_wait_timeout);
        return;
    }
    if (this->lockInAmplifierModel == "SR865") {
        this->sr865->setReadWaitTimeout(new_read_wait_timeout);
        return;
    }
}

int finalLockInAmplifier::getReadWaitTimeout() const {
    if(this->lockInAmplifierModel == "SR830")
        return  this->sr830->getReadWaitTimeout();
    if(this->lockInAmplifierModel == "SR844")
        return  this->sr844->getReadWaitTimeout();
    if(this->lockInAmplifierModel == "SR865")
        return  this->sr865->getReadWaitTimeout();
    return -1;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name, const std::string &new_baudrate, const std::string &new_data_bits, const std::string &new_stop_bits, const std::string &new_parity, const std::string &new_flow_control, const std::string &new_model) {
    setModel(new_model);
    if(this->lockInAmplifierModel == "SR830") {
        this->sr830 = new class SR830();
        return this->sr830->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);}
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);
    if(this->lockInAmplifierModel == "SR865") {
        this->sr865 = new class SR865();
        std::cout << "LOX\n";
        return this->sr865->connect(new_port_name, new_baudrate, new_data_bits,new_stop_bits,new_parity, new_flow_control);}
    std::cout << "kva\n";
    return false;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name, const std::string &new_baudrate, const std::string &new_data_bits, const std::string &new_stop_bits, const std::string &new_parity, const std::string &new_flow_control) {
    this->srs = new SRS();
    srs->connect(new_port_name,new_baudrate, new_data_bits, new_stop_bits, new_parity, new_flow_control);
    setModel(srs->getModel());
    srs->disconnect();
    if(this->lockInAmplifierModel == "SR830") {
        this->sr830 = new class SR830();
        sr830->setSerial(srs->getSerial());
        return this->sr830->connect(new_port_name);
    }
    if(this->lockInAmplifierModel == "SR844") {
        this->sr844 = new class SR844();
        sr844->setSerial(srs->getSerial());
        return this->sr844->connect(new_port_name);
    }
    if(this->lockInAmplifierModel == "SR865")  {
        this->sr865 = new class SR865();
        sr865->setSerial(srs->getSerial());
        return this->sr865->connect(new_port_name);
    }
    return false;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name, const std::string &new_baudrate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->connect(new_port_name, new_baudrate);
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->connect(new_port_name, new_baudrate);
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->connect(new_port_name, new_baudrate);
    return false;
}

bool finalLockInAmplifier::connect(const std::string &new_port_name) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->connect(new_port_name);
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->connect(new_port_name);
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->connect(new_port_name);
    return false;
}

bool finalLockInAmplifier::disconnect() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->disconnect();
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->disconnect();
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->disconnect();
    return false;
}

bool finalLockInAmplifier::recieve(std::string &response) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->recieve(response);
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->recieve(response);
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->recieve(response);
    return false;
}

bool finalLockInAmplifier::send(const std::string &command, std::string &response, const bool &wait_for_response, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->send(command, response, wait_for_response, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->send(command, response, wait_for_response, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->send(command, response, wait_for_response, terminate);
    return false;
}

bool finalLockInAmplifier::sendCommand(const std::string &command, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->sendCommand(command, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->sendCommand(command, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->sendCommand(command, terminate);
    return false;
}

bool finalLockInAmplifier::sendQuery(const std::string &command, std::string &response, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->sendQuery(command, response, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->sendQuery(command, response, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->sendQuery(command, response, terminate);
    return false;
}

std::string finalLockInAmplifier::ask(const std::string &command, const std::string &terminate) const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->ask(command, terminate);
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->ask(command, terminate);
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->ask(command, terminate);
    return "wrong model";
}

double finalLockInAmplifier::getTTS() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->getTTS();
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->getTTS();
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->getTTS();;
}

double finalLockInAmplifier::getTTR() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->getTTR();
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->getTTR();
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->getTTR();;
}

std::vector < std::string > finalLockInAmplifier::getSupportedList() const {
    if(this->lockInAmplifierModel == "SR830")
       return this->sr830->getSupportedList();
    if(this->lockInAmplifierModel == "SR844")
       return this->sr844->getSupportedList();
    if(this->lockInAmplifierModel == "SR865")
       return this->sr865->getSupportedList();
}

int finalLockInAmplifier::getAttemptsToConnect() const {
    if(this->lockInAmplifierModel == "SR830")
       return this->sr830->getAttemptsToConnect();
    if(this->lockInAmplifierModel == "SR844")
       return this->sr844->getAttemptsToConnect();
    if(this->lockInAmplifierModel == "SR865")
       return this->sr865->getAttemptsToConnect();
}

void finalLockInAmplifier::setAttemptsToConnect(const int &new_attempts_to_connect) {
    this->sr830->setAttemptsToConnect(new_attempts_to_connect);
    this->sr844->setAttemptsToConnect(new_attempts_to_connect);
    this->sr865->setAttemptsToConnect(new_attempts_to_connect);

    return;
}

std::string finalLockInAmplifier::getIDN(bool* succeed) const {
    if(this->lockInAmplifierModel == "SR830")
       return this->sr830->getIDN();
    if(this->lockInAmplifierModel == "SR844")
       return this->sr844->getIDN();
    if(this->lockInAmplifierModel == "SR865")
       return this->sr865->getIDN();
    return "No this model brute\n";
}

std::string finalLockInAmplifier::getModel(bool* succeed) const {
    if(this->lockInAmplifierModel == "SR830")
       return this->sr830->getModel();
    if(this->lockInAmplifierModel == "SR844")
       return this->sr844->getModel();
    if(this->lockInAmplifierModel == "SR865")
       return this->sr865->getModel();
    return "No this model brute\n";
}

bool finalLockInAmplifier::isActive() const {
    if(this->lockInAmplifierModel == "SR830")
        return this->sr830->isActive();
    if(this->lockInAmplifierModel == "SR844")
        return this->sr844->isActive();
    if(this->lockInAmplifierModel == "SR865")
        return this->sr865->isActive();;
    return false;
}


bool finalLockInAmplifier::workWithPhase() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

bool finalLockInAmplifier::workWithAutoPhase() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinPhase() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMinPhase();
    if (lockInAmplifierModel == "SR844")
        return sr844->getMinPhase();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMinPhase();
}

double finalLockInAmplifier::getMaxPhase() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMaxPhase();
    if (lockInAmplifierModel == "SR844")
        return sr844->getMaxPhase();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMaxPhase();
}


bool finalLockInAmplifier::setInternalPhase(const double &phase) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setInternalPhase(phase);
    if (lockInAmplifierModel == "SR844")
        return sr844->setInternalPhase(phase);
    if (lockInAmplifierModel == "SR865")
        return sr865->setInternalPhase(phase);
    return false;
}

std::string finalLockInAmplifier::getPhase() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getPhase();
    if (lockInAmplifierModel == "SR844")
        return sr844->getPhase();
    if (lockInAmplifierModel == "SR865")
        return sr865->getPhase();
    return  "No ths model";
}

bool finalLockInAmplifier::testPhase(const double &interval, const double &epsilon) const {
    std::string oldPhase = this->getPhase();
    double currentPhase = this->getMinPhase()+interval;
    while (currentPhase < this->getMaxPhase()) {
        this->setInternalPhase(currentPhase);
        if (abs(std::stod(this->getPhase()) - currentPhase) < epsilon)
            currentPhase += interval;
        else {
            this->setInternalPhase(std::stod(oldPhase));
            return false;
        }
    }
    this->setInternalPhase(std::stod(oldPhase));
    return true;
}

bool finalLockInAmplifier::autoPhase() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->autoPhase();
    if (lockInAmplifierModel == "SR844")
        return sr844->autoPhase();
    if (lockInAmplifierModel == "SR865")
        return sr865->autoPhase();
    return false;
}

bool finalLockInAmplifier::workWithFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinInternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMinInternalFrequency();
    if (lockInAmplifierModel == "SR844")
        return sr844->getMinInternalFrequency();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMinInternalFrequency();
    return -1;
}

double finalLockInAmplifier::getMaxInternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMaxInternalFrequency();
    if (lockInAmplifierModel == "SR844")
        return sr844->getMaxInternalFrequency();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMaxInternalFrequency();
    return -1;
}

bool finalLockInAmplifier::isValidInternalFrequency(const double &frequency) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->isValidInternalFrequency(frequency);
    if (lockInAmplifierModel == "SR844")
        return sr844->isValidInternalFrequency(frequency);
    if (lockInAmplifierModel == "SR865")
        return sr865->isValidInternalFrequency(frequency);
    return false;
}

bool finalLockInAmplifier::setFrequency(const double &frequency) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setFrequency(frequency);
    if (lockInAmplifierModel == "SR844")
        return sr844->setFrequency(frequency);
    if (lockInAmplifierModel == "SR865")
        return sr865->setFrequency(frequency);
    return false;
}

std::string finalLockInAmplifier::getFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return sr844->getFrequency();
    if (lockInAmplifierModel == "SR865")
        return sr865->getFrequency();
    return  "No this model";
}

std::string finalLockInAmplifier::getInternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return sr844->getFrequency();
    if (this->lockInAmplifierModel == "SR865")
        return sr865->getInternalFrequency();
    return  "no this model";
}

std::string finalLockInAmplifier::getExternalFrequency() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return sr844->getFrequency();
    if (this->lockInAmplifierModel == "SR865")
        return sr865->getExternalFrequency();
    return  "no this model";
}

std::string finalLockInAmplifier::getFrequencyDetect() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getFrequency();
    if (lockInAmplifierModel == "SR844")
        return sr844->getFrequencyDetect();
    if (this->lockInAmplifierModel == "SR865")
        return sr865->getFrequencyDetect();
    return  "no this model";
}

bool finalLockInAmplifier::testFrequency(const double &interval, const double &epsilon) const {
    std::string oldFrequency = this->getFrequency();
    std::string oldRefSourse = this->getRefSource();
    std::string oldHarmonic = this->getHarmonic();
    this->setRefSource("INT");
    if((this->lockInAmplifierModel == "SR830") || (this->lockInAmplifierModel == "SR865"))
        this->setHarmonic(1);
    if(this->lockInAmplifierModel == "SR844")
        this->setHarmonic(0);
    double currentFrequency = this->getMinInternalFrequency();
    while (this->isValidInternalFrequency(currentFrequency)) {
        this->setFrequency(currentFrequency);
        if (abs(std::stod(this->getFrequency())-currentFrequency) < epsilon)
            currentFrequency += interval;
        else {
            this->setFrequency(std::stod(oldFrequency));
            this->setRefSource(oldRefSourse);
            this->setHarmonic(std::stoi(oldHarmonic));
            return false;
        }
    }
    this->setFrequency(std::stod(oldFrequency));
    this->setRefSource(oldRefSourse);
    this->setHarmonic(std::stoi(oldHarmonic));
    return true;
}

bool finalLockInAmplifier::workWithHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

int finalLockInAmplifier::getMinHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMinHarmonic();
    if (lockInAmplifierModel == "SR844")
        return sr844->getMinHarmonic();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMinHarmonic();
    return -1;
}

int finalLockInAmplifier::getMaxHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMaxHarmonic();
    if (lockInAmplifierModel == "SR844")
        return sr844->getMaxHarmonic();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMaxHarmonic();
    return -1;
}

bool finalLockInAmplifier::setHarmonic(const int &harmonic) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setHarmonic(harmonic);
    if (lockInAmplifierModel == "SR844")
        return sr844->setHarmonic(harmonic);
    if (lockInAmplifierModel == "SR865")
        return sr865->setHarmonic(harmonic);
    return false;
}

std::string finalLockInAmplifier::getHarmonic() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getHarmonic();
    if (lockInAmplifierModel == "SR844")
        return sr844->getHarmonic();
    if (lockInAmplifierModel == "SR865")
        return sr865->getHarmonic();
    return  "No this model";
}

/*std::string finalLockInAmplifier::testHarmonic(const int &interval) const {
    std::string oldHarmonic = this->getHarmonic();
}*/

bool finalLockInAmplifier::workWithDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

int finalLockInAmplifier::getMinDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getMinDualHarmonic();
    return -1;
}

int finalLockInAmplifier::getMaxDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getMaxDualHarmonic();
    return -1;
}


bool finalLockInAmplifier::setDualHarmonic(const int &harmonic) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setDualHarmonic(harmonic);
    return false;
}

std::string finalLockInAmplifier::getDualHarmonic() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getDualHarmonic();
    return  "No this model or this model can't work with dual harmonic";
}

bool finalLockInAmplifier::workWithSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMinSineAmplitude();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMinSineAmplitude();
    return -1;
}

double finalLockInAmplifier::getMaxSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getMaxSineAmplitude();
    if (lockInAmplifierModel == "SR865")
        return sr865->getMaxSineAmplitude();
    return -1;
}

bool finalLockInAmplifier::setSineAmplitude(const double &sineAmplitude) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setSineAmplitude(sineAmplitude);
    if (lockInAmplifierModel == "SR865")
        return sr865->setSineAmplitude(sineAmplitude);
    return false;
}

std::string finalLockInAmplifier::getSineAmplitude() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getSineAmplitude();
    if (lockInAmplifierModel == "SR865")
        return sr865->getSineAmplitude();
    return  "No this model";
}

bool finalLockInAmplifier::testSineAmplitude(const double &interval, const double &epsilon) const {
    std::string oldSineAmplitude = getSineAmplitude();
    double currentSineAmplitude = getMinSineAmplitude();
    while(currentSineAmplitude <= getMaxSineAmplitude()) {
        setSineAmplitude(currentSineAmplitude);
        if (abs(std::stod(getSineAmplitude())-currentSineAmplitude) < epsilon)
            currentSineAmplitude +=interval;
        else {
            setSineAmplitude(std::stod(oldSineAmplitude));
            return false;
        }
    }
    setSineAmplitude(std::stod(oldSineAmplitude));
    return true;
}

bool finalLockInAmplifier::workWithSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

double finalLockInAmplifier::getMinSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getMinSineDCLevel();
    return -1;
}

double finalLockInAmplifier::getMaxSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getMaxSineDCLevel();
    return -1;
}

bool finalLockInAmplifier::setSineDCLevel(const double &voltage) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setSineDCLevel(voltage);
    return false;
}

std::string finalLockInAmplifier::getSineDCLevel() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getSineDCLevel();
    return  "No this model or this model can't work with dual harmonic";
}

bool finalLockInAmplifier::testSineDCLevel(const double &interval, const double &epsilon) const{
    std::string oldSineDCLevel = getSineDCLevel();
    double currentSineDCLevel = getMinSineDCLevel();
    while(currentSineDCLevel <= getMaxSineDCLevel()) {
        setSineDCLevel(currentSineDCLevel);
        if (abs(std::stod(getSineDCLevel())-currentSineDCLevel) < epsilon)
            currentSineDCLevel +=interval;
        else {
            setSineDCLevel(std::stod(oldSineDCLevel));
            return false;
        }
    }
    setSineDCLevel(std::stod(oldSineDCLevel));
    return true;
}

bool finalLockInAmplifier::workWithRefSourse() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getRefSourceList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getRefSourceList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getRefSourceList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getRefSourceList();
}

bool finalLockInAmplifier::setRefSource(const int &refSource) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setRefSource(refSource);
    if (lockInAmplifierModel == "SR844")
        return sr844->setRefSource(refSource);
    if (lockInAmplifierModel == "SR865")
        return sr865->setRefSource(refSource);
    return false;
}

bool finalLockInAmplifier::setRefSource(const std::string &refSource) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setRefSource(refSource);
    if (lockInAmplifierModel == "SR844")
        return sr844->setRefSource(refSource);
    if (lockInAmplifierModel == "SR865")
        return sr865->setRefSource(refSource);
    return false;
}

std::string finalLockInAmplifier::getRefSource() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getRefSource();
    if (lockInAmplifierModel == "SR844")
        return sr844->getRefSource();
    if (lockInAmplifierModel == "SR865")
        return sr865->getRefSource();
    return "No this model";
}

bool finalLockInAmplifier:: testRefSource() const {
    if (workWithRefSourse()) {
        std::string oldRefSource = getRefSource();
        for(auto refSourse: getRefSourceList()) {
            setRefSource(refSourse);
            if (refSourse != getRefSource()) {
                setRefSource(oldRefSource);
                return false;
            }
        }
        setRefSource(oldRefSource);
        return  true;
    }
    return  false;
}

bool finalLockInAmplifier::workWithRefTriggerMode() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getRefTriggerModeList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getRefTriggerModeList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getRefTriggerModeList();
    std::vector <std::string> incorrectData;
    incorrectData.clear();
    return incorrectData;
}

bool finalLockInAmplifier::setRefTriggerMode(const int &refTriggerMode) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setRefTriggerMode(refTriggerMode);
    if (lockInAmplifierModel == "SR865")
        return sr865->setRefTriggerMode(refTriggerMode);
    return false;
}

bool finalLockInAmplifier::setRefTriggerMode(const std::string &refTriggerMode) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setRefTriggerMode(refTriggerMode);
    if (lockInAmplifierModel == "SR865")
        return sr865->setRefTriggerMode(refTriggerMode);
    return false;
}

std::string finalLockInAmplifier::getRefTriggerMode() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getRefTriggerMode();
    if (lockInAmplifierModel == "SR865")
        return sr865->getRefTriggerMode();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier:: testRefTriggerMode() const {
    if (workWithRefTriggerMode()) {
        std::string oldRefTriggerMode = getRefTriggerMode();
        for(auto refTriggerMode: getRefTriggerModeList()) {
            setRefTriggerMode(refTriggerMode);
            if (refTriggerMode != getRefTriggerMode()) {
                setRefTriggerMode(oldRefTriggerMode);
                return false;
            }
        }
        setRefTriggerMode(oldRefTriggerMode);
        return  true;
    }
    return  false;
}

bool finalLockInAmplifier::workWithRefTriggerOutput() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getRefTriggerOutputList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getRefTriggerOutputList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getRefTriggerOutputList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getRefTriggerOutputList();
}

bool finalLockInAmplifier::setRefTriggerOutput(const int &refTriggerOutput) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR844")
        return sr844->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR865")
        return sr865->setRefTriggerOutput(refTriggerOutput);
    return false;
}

bool finalLockInAmplifier::setRefTriggerOutput(const std::string &refTriggerOutput) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR844")
        return sr844->setRefTriggerOutput(refTriggerOutput);
    if (lockInAmplifierModel == "SR865")
        return sr865->setRefTriggerOutput(refTriggerOutput);
    return false;
}

std::string finalLockInAmplifier::getRefTriggerOutput() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getRefTriggerOutput();
    if (lockInAmplifierModel == "SR844")
        return sr844->getRefTriggerOutput();
    if (lockInAmplifierModel == "SR865")
        return sr865->getRefTriggerOutput();
    return "No this model";
}

bool finalLockInAmplifier:: testRefTriggerOutput() const {
    if (workWithRefTriggerOutput()) {
        std::string oldRefTriggerOutput = getRefTriggerOutput();
        for(auto refTriggerOutput: getRefTriggerOutputList()) {
            setRefTriggerOutput(refTriggerOutput);
            if (refTriggerOutput != getRefTriggerOutput()) {
                setRefTriggerOutput(oldRefTriggerOutput);
                return false;
            }
        }
        setRefTriggerOutput(oldRefTriggerOutput);
        return  true;
    }
    return  false;
}


bool finalLockInAmplifier::workWithInputSignal() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputSignalList() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputSignalList();
}

bool finalLockInAmplifier::setInputSignal(const int &inputSignal) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputSignal(inputSignal);
    return false;
}

bool finalLockInAmplifier::setInputSignal(const std::string &inputSignal) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputSignal(inputSignal);
    return false;
}

std::string finalLockInAmplifier::getInputSignal() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputSignal();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier:: testInputSignal() const {
    if (workWithInputSignal()) {
        std::string oldInputSignal = getInputSignal();
        for(auto inputSignal: getInputSignalList()) {
            setInputSignal(inputSignal);
            if (inputSignal != getInputSignal()) {
                setInputSignal(oldInputSignal);
                return false;
            }
        }
        setInputSignal(oldInputSignal);
        return  true;
    }
    return  false;
}


bool finalLockInAmplifier::workWithInputVoltageMode() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageModeList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getInputVoltageModeList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageModeList();
}

bool finalLockInAmplifier::setInputVoltageMode(const int &inputVoltageMode) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setInputVoltageMode(inputVoltageMode);
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageMode(inputVoltageMode);
    return false;
}

bool finalLockInAmplifier::setInputVoltageMode(const std::string &inputVoltageMode) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setInputVoltageMode(inputVoltageMode);
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageMode(inputVoltageMode);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageMode() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getInputVoltageMode();
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageMode();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier:: testInputVoltageMode() const {
    std::string oldInputVoltageMode = getInputVoltageMode();
    for(auto inputVoltageMode: getInputVoltageModeList()) {
        setInputVoltageMode(inputVoltageMode);
        if (inputVoltageMode != getInputVoltageMode()) {
            setInputVoltageMode(oldInputVoltageMode);
            return false;
        }
    }
    setInputVoltageMode(oldInputVoltageMode);
    return  true;
}


bool finalLockInAmplifier::workWithInputVoltageCoupling() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageCouplingList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getInputVoltageCouplingList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageCouplingList();
}

bool finalLockInAmplifier::setInputVoltageCoupling(const int &inputVoltageCoupling) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setInputVoltageCoupling(inputVoltageCoupling);
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageCoupling(inputVoltageCoupling);
    return false;
}

bool finalLockInAmplifier::setInputVoltageCoupling(const std::string &inputVoltageCoupling) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setInputVoltageCoupling(inputVoltageCoupling);
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageCoupling(inputVoltageCoupling);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageCoupling() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getInputVoltageCoupling();
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageCoupling();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier:: testInputVoltageCoupling() const {
    std::string oldInputVoltageCoupling = getInputVoltageCoupling();
    for(auto inputVoltageCoupling: getInputVoltageCouplingList()) {
        setInputVoltageCoupling(inputVoltageCoupling);
        if (inputVoltageCoupling != getInputVoltageCoupling()) {
            setInputVoltageCoupling(oldInputVoltageCoupling);
            return false;
        }
    }
    setInputVoltageCoupling(oldInputVoltageCoupling);
    return  true;
}


bool finalLockInAmplifier::workWithInputVoltageShields() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageShieldsList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getInputVoltageShieldsList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageShieldsList();
}

bool finalLockInAmplifier::setInputVoltageShields(const int &inputVoltageShields) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setInputVoltageShields(inputVoltageShields);
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageShields(inputVoltageShields);
    return false;
}

bool finalLockInAmplifier::setInputVoltageShields(const std::string &inputVoltageShields) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setInputVoltageShields(inputVoltageShields);
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageShields(inputVoltageShields);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageShields() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getInputVoltageShields();
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageShields();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testInputVoltageShields() const {
    std::string oldInputVoltageShields = getInputVoltageShields();
    for(auto inputVoltageShields: getInputVoltageShieldsList()) {
        setInputVoltageShields(inputVoltageShields);
        if (inputVoltageShields != getInputVoltageShields()) {
            setInputVoltageShields(oldInputVoltageShields);
            return false;
        }
    }
    setInputVoltageShields(oldInputVoltageShields);
    return  true;
}

bool finalLockInAmplifier::workWithInputVoltageRange() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputVoltageRangeList() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageRangeList();
}

bool finalLockInAmplifier::setInputVoltageRange(const int &inputVoltageRange) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageRange(inputVoltageRange);
    return false;
}

bool finalLockInAmplifier::setInputVoltageRange(const std::string &inputVoltageRange) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputVoltageRange(inputVoltageRange);
    return false;
}

std::string finalLockInAmplifier::getInputVoltageRange() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputVoltageRange();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testInputVoltageRange() const {
    std::string oldInputVoltageRange = getInputVoltageRange();
    for(auto inputVoltageRange: getInputVoltageRangeList()) {
        setInputVoltageRange(inputVoltageRange);
        if (inputVoltageRange != getInputVoltageRange()) {
            setInputVoltageRange(oldInputVoltageRange);
            return false;
        }
    }
    setInputVoltageRange(oldInputVoltageRange);
    return  true;
}

bool finalLockInAmplifier::workWithInputCurrentGain() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputCurrentGainList() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputCurrentGainList();
}

bool finalLockInAmplifier::setInputCurrentGain(const int &inputCurrentGain) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputCurrentGain(inputCurrentGain);
    return false;
}

bool finalLockInAmplifier::setInputCurrentGain(const std::string &inputCurrentGain) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setInputCurrentGain(inputCurrentGain);
    return false;
}

std::string finalLockInAmplifier::getInputCurrentGain() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getInputCurrentGain();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testInputCurrentGain() const {
    std::string oldInputCurrentGain = getInputCurrentGain();
    for(auto inputCurrentGain: getInputCurrentGainList()) {
        setInputCurrentGain(inputCurrentGain);
        if (inputCurrentGain != getInputCurrentGain()) {
            setInputCurrentGain(oldInputCurrentGain);
            return false;
        }
    }
    setInputCurrentGain(oldInputCurrentGain);
    return  true;
}

bool finalLockInAmplifier::workWithSignalStrength() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

std::string finalLockInAmplifier::getSignalStrength() const {
    if (lockInAmplifierModel == "SR865")
        return  sr865->getSignalStrength();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::workWithSensitivity() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getSensitivityList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getSensitivityList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getSensitivityList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getSensitivityList();
}

bool finalLockInAmplifier::setSensitivity(const int &sensitivity) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR844")
        return sr844->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR865")
        return sr865->setSensitivity(sensitivity);
    return false;
}

bool finalLockInAmplifier::setSensitivity(const std::string &sensitivity) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR844")
        return sr844->setSensitivity(sensitivity);
    if (lockInAmplifierModel == "SR865")
        return sr865->setSensitivity(sensitivity);
    return false;
}

std::string finalLockInAmplifier::getSensitivity() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getSensitivity();
    if (lockInAmplifierModel == "SR844")
        return sr844->getSensitivity();
    if (lockInAmplifierModel == "SR865")
        return sr865->getSensitivity();
    return "No this model";
}

bool finalLockInAmplifier::testSensitivity() const {
    std::string oldSensitivity = getSensitivity();
    for(auto sensitivity: getSensitivityList()) {
        setSensitivity(sensitivity);
        if (sensitivity != getSensitivity()) {
            setSensitivity(oldSensitivity);
            return false;
        }
    }
    setSensitivity(oldSensitivity);
    return  true;
}


bool finalLockInAmplifier::workWithTimeConstant() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getTimeConstantList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getTimeConstantList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getTimeConstantList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getTimeConstantList();
}

bool finalLockInAmplifier::setTimeConstant(const int &timeConstant) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR844")
        return sr844->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR865")
        return sr865->setTimeConstant(timeConstant);
    return false;
}

bool finalLockInAmplifier::setTimeConstant(const std::string &timeConstant) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR844")
        return sr844->setTimeConstant(timeConstant);
    if (lockInAmplifierModel == "SR865")
        return sr865->setTimeConstant(timeConstant);
    return false;
}

std::string finalLockInAmplifier::getTimeConstant() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getTimeConstant();
    if (lockInAmplifierModel == "SR844")
        return sr844->getTimeConstant();
    if (lockInAmplifierModel == "SR865")
        return sr865->getTimeConstant();
    return "No this model";
}

bool finalLockInAmplifier::testTimeConstant() const {
    if (workWithTimeConstant()) {
        std::string oldTimeConstant = getTimeConstant();
        for(auto timeConstant: getTimeConstantList()) {
            setTimeConstant(timeConstant);
            if (timeConstant != getTimeConstant()) {
                setTimeConstant(oldTimeConstant);
                return false;
            }
        }
        setTimeConstant(oldTimeConstant);
        return  true;
    }
    return  false;
}


bool finalLockInAmplifier::workWithFilterSlope() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getFilterSlopeList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getFilterSlopeList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getFilterSlopeList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getFilterSlopeList();
}

bool finalLockInAmplifier::setFilterSlope(const int &filterSlope) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR844")
        return sr844->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR865")
        return sr865->setFilterSlope(filterSlope);
    return false;
}

bool finalLockInAmplifier::setFilterSlope(const std::string &filterSlope) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR844")
        return sr844->setFilterSlope(filterSlope);
    if (lockInAmplifierModel == "SR865")
        return sr865->setFilterSlope(filterSlope);
    return false;
}

std::string finalLockInAmplifier::getFilterSlope() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getFilterSlope();
    if (lockInAmplifierModel == "SR844")
        return sr844->getFilterSlope();
    if (lockInAmplifierModel == "SR865")
        return sr865->getFilterSlope();
    return "No this model";
}

bool finalLockInAmplifier::testFilterSlope() const {
    std::string oldFilterSlope = getFilterSlope();
    for(auto filterSlope: getFilterSlopeList()) {
        setFilterSlope(filterSlope);
        if (filterSlope != getFilterSlope()) {
            setFilterSlope(oldFilterSlope);
            return false;
        }
    }
    setFilterSlope(oldFilterSlope);
    return  true;
}

bool finalLockInAmplifier::workWithSynchronousFilter() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getSynchronousFilterList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getSynchronousFilterList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getSynchronousFilterList();
}

bool finalLockInAmplifier::setSynchronousFilter(const int &synchronousFilter) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setSynchronousFilter(synchronousFilter);
    if (lockInAmplifierModel == "SR865")
        return sr865->setSynchronousFilter(synchronousFilter);
    return false;
}

bool finalLockInAmplifier::setSynchronousFilter(const std::string &synchronousFilter) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->setSynchronousFilter(synchronousFilter);
    if (lockInAmplifierModel == "SR865")
        return sr865->setSynchronousFilter(synchronousFilter);
    return false;
}

std::string finalLockInAmplifier::getSynchronousFilter() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getSynchronousFilter();
    if (lockInAmplifierModel == "SR865")
        return sr865->getSynchronousFilter();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testSynchronousFilter() const {
    std::string oldSynchronousFilter = getSynchronousFilter();
    for(auto synchronousFilter: getSynchronousFilterList()) {
        setSynchronousFilter(synchronousFilter);
        if (synchronousFilter != getSynchronousFilter()) {
            setSynchronousFilter(oldSynchronousFilter);
            return false;
        }
    }
    setSynchronousFilter(oldSynchronousFilter);
    return  true;
}

bool finalLockInAmplifier::workWithAdvanceFilter() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getAdvanceFilterList() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getAdvanceFilterList();
}

bool finalLockInAmplifier::setAdvanceFilter(const int &advanceFilter) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setAdvanceFilter(advanceFilter);
    return false;
}

bool finalLockInAmplifier::setAdvanceFilter(const std::string &advanceFilter) const {
    if (lockInAmplifierModel == "SR865")
        return sr865->setAdvanceFilter(advanceFilter);
    return false;
}

std::string finalLockInAmplifier::getAdvanceFilter() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->getAdvanceFilter();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testAdvanceFilter() const {
    std::string oldAdvanceFilter = getAdvanceFilter();
    for(auto advanceFilter: getAdvanceFilterList()) {
        setAdvanceFilter(advanceFilter);
        if (advanceFilter != getAdvanceFilter()) {
            setAdvanceFilter(oldAdvanceFilter);
            return false;
        }
    }
    setAdvanceFilter(oldAdvanceFilter);
    return  true;
}

bool finalLockInAmplifier::workWithAutoRange() const {
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

bool finalLockInAmplifier::autoRange() const {
    if (lockInAmplifierModel == "SR865")
        return sr865->autoRange();
    return false;
}

bool finalLockInAmplifier::workWithAutoScale() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

bool finalLockInAmplifier::autoScale() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->autoScale();
    if (lockInAmplifierModel == "SR844")
        return sr844->autoScale();
    if (lockInAmplifierModel == "SR865")
        return sr865->autoRange();
    return false;
}

bool finalLockInAmplifier::workWithOutData() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

std::vector<std::string> finalLockInAmplifier::getOutDataList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutDataList();
}

std::string finalLockInAmplifier::getOutData(const int &outData) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutData(outData);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutData(outData);
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutData(outData);
    return "No this model";
}

std::string finalLockInAmplifier::getOutData(const std::string &outData) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutData(outData);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutData(outData);
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutData(outData);
    return "No this model";
}

bool finalLockInAmplifier::workWithOutDataCouple() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    if (lockInAmplifierModel == "SR865")
        return true;
    return false;
}

std::vector<std::string> finalLockInAmplifier::getOutDataCoupleList() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataCoupleList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataCoupleList();
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutDataCoupleList();
}

bool finalLockInAmplifier::getOutDataAB(const int &A, std::string &AValue, const int &B, std::string &BValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataAB(A, AValue, B, BValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataAB(A, AValue, B, BValue);
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutDataAB(A, AValue, B, BValue);
    return false;
}

bool finalLockInAmplifier::getOutDataAB(const std::string &A,std::string &AValue, const std::string &B, std::string &BValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataAB(A, AValue, B, BValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataAB(A, AValue, B, BValue);
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutDataAB(A, AValue, B, BValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABC(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABC(A, AValue, B, BValue, C, CValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABC(A, AValue, B, BValue, C, CValue);
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutDataABC(A, AValue, B, BValue, C, CValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABC(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABC(A, AValue, B, BValue, C, CValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABC(A, AValue, B, BValue, C, CValue);
    if (lockInAmplifierModel == "SR865")
        return sr865->getOutDataABC(A, AValue, B, BValue, C, CValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABCD(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABCD(A, AValue, B, BValue, C, CValue, D, DValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABCD(A, AValue, B, BValue, C, CValue, D, DValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABCD(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABCD(A, AValue, B, BValue, C, CValue, D, DValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABCD(A, AValue, B, BValue, C, CValue, D, DValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABCDE(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABCDE(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABCDE(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABCDE(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABCDE(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABCDE(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABCDEF(const int &A, std::string &AValue, const int &B, std::string &BValue, const int &C, std::string &CValue, const int &D, std::string &DValue, const int &E, std::string &EValue, const int &F, std::string &FValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABCDEF(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue, F, FValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABCDEF(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue, F, FValue);
    return false;
}

bool finalLockInAmplifier::getOutDataABCDEF(const std::string &A, std::string &AValue, const std::string &B, std::string &BValue, const std::string &C, std::string &CValue, const std::string &D, std::string &DValue, const std::string &E, std::string &EValue, const std::string &F, std::string &FValue) const {
    if (lockInAmplifierModel == "SR830")
        return sr830->getOutDataABCDEF(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue, F, FValue);
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataABCDEF(A, AValue, B, BValue, C, CValue, D, DValue, E, EValue, F, FValue);
    return false;
}

bool finalLockInAmplifier::workWithAutoWideReverse() const {
    if (lockInAmplifierModel == "SR830")
        return true;
    if (lockInAmplifierModel == "SR844")
        return true;
    return false;
}

bool finalLockInAmplifier::autoWideReverse() const {
    if (lockInAmplifierModel == "SR830")
        return sr830->autoWideReverse();
    if (lockInAmplifierModel == "SR844")
        return sr844->autoWideReverse();
    return false;
}

bool finalLockInAmplifier::workWithAutoReserve() const {
    if (lockInAmplifierModel == "SR844")
        return true;
    return  false;
}

bool finalLockInAmplifier::autoReserve() const {
    if (lockInAmplifierModel == "SR844")
        return sr844->autoReserve();
    return  false;
}

bool finalLockInAmplifier::workWithInputSignalZ() const {
    if (lockInAmplifierModel == "SR844")
        return true;
    return  false;
}

std::vector<std::string> finalLockInAmplifier::getInputSignalZList() const {
    if (lockInAmplifierModel == "SR844")
        return sr844->getInputSignalZList();
}

bool finalLockInAmplifier::setInputSignalZ(const int &inputSignalZ) const {
    if (lockInAmplifierModel == "SR844")
        return sr844->setInputSignalZ(inputSignalZ);
    return false;
}

bool finalLockInAmplifier::setInputSignalZ(const std::string &inputSignalZ) const {
    if (lockInAmplifierModel == "SR844")
        return sr844->setInputSignalZ(inputSignalZ);
    return false;
}

std::string finalLockInAmplifier::getInputSignalZ() const {
    if (lockInAmplifierModel == "SR844")
        return sr844->getInputSignalZ();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testInputSignalZ() const {
    std::string oldInputSignalZ = getInputSignalZ();
    for(auto inputSignalZ: getInputSignalZList()) {
        setInputSignalZ(inputSignalZ);
        if (inputSignalZ != getInputSignalZ()) {
            setInputSignalZ(oldInputSignalZ);
            return false;
        }
    }
    setInputSignalZ(oldInputSignalZ);
    return  true;
}

bool finalLockInAmplifier::workWithCloseReserveMode() const {
    if (lockInAmplifierModel == "SR830")
        return  true;
    if (lockInAmplifierModel == "SR844")
        return true;
    return false;
}

std::vector<std::string> finalLockInAmplifier::getCloseReserveModeList() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getCloseReserveModeList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getCloseReserveModeList();
}

bool finalLockInAmplifier::setCloseReserveMode(const int &closeReserveMode) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setCloseReserveMode(closeReserveMode);
    if (lockInAmplifierModel == "SR844")
        return sr844->setCloseReserveMode(closeReserveMode);
    return false;
}

bool finalLockInAmplifier::setCloseReserveMode(const std::string &closeReserveMode) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setCloseReserveMode(closeReserveMode);
    if (lockInAmplifierModel == "SR844")
        return sr844->setCloseReserveMode(closeReserveMode);
    return false;
}

std::string finalLockInAmplifier::getCloseReserveMode() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getCloseReserveMode();
    if (lockInAmplifierModel == "SR844")
        return sr844->getCloseReserveMode();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testCloseReserveMode() const {
    std::string oldCloseReserveMode = getCloseReserveMode();
    for(auto closeReserveMode: getCloseReserveModeList()) {
        setCloseReserveMode(closeReserveMode);
        if (closeReserveMode != getCloseReserveMode()) {
            setCloseReserveMode(oldCloseReserveMode);
            return false;
        }
    }
    setCloseReserveMode(oldCloseReserveMode);
    return  true;
}

bool finalLockInAmplifier::workWithSetOutDataChannel1() const {
    if (lockInAmplifierModel == "SR830")
        return  true;
    if (lockInAmplifierModel == "SR844")
        return true;
    return false;
}

std::vector<std::string> finalLockInAmplifier::getOutDataChannel1List() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getOutDataChannel1List();
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataChannel1List();
}

bool finalLockInAmplifier::setOutDataChannel1(const int &outData) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setOutDataChannel1(outData);
    if (lockInAmplifierModel == "SR844")
        return sr844->setOutDataChannel1(outData);
    return false;
}

bool finalLockInAmplifier::setOutDataChannel1(const std::string &outData) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setOutDataChannel1(outData);
    if (lockInAmplifierModel == "SR844")
        return sr844->setOutDataChannel1(outData);
    return false;
}

bool finalLockInAmplifier::workWithSetOutDataChannel2() const {
    if (lockInAmplifierModel == "SR830")
        return  true;
    if (lockInAmplifierModel == "SR844")
        return true;
    return false;
}

std::vector<std::string> finalLockInAmplifier::getOutDataChannel2List() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getOutDataChannel2List();
    if (lockInAmplifierModel == "SR844")
        return sr844->getOutDataChannel2List();
}

bool finalLockInAmplifier::setOutDataChannel2(const int &outData) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setOutDataChannel2(outData);
    if (lockInAmplifierModel == "SR844")
        return sr844->setOutDataChannel2(outData);
    return false;
}

bool finalLockInAmplifier::setOutDataChannel2(const std::string &outData) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setOutDataChannel2(outData);
    if (lockInAmplifierModel == "SR844")
        return sr844->setOutDataChannel2(outData);
    return false;
}

bool finalLockInAmplifier::workWithBufferMode() const {
    if (lockInAmplifierModel == "SR830")
        return  true;
    if (lockInAmplifierModel == "SR844")
        return true;
    return false;
}

std::vector<std::string> finalLockInAmplifier::getBufferModeList() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getBufferModeList();
    if (lockInAmplifierModel == "SR844")
        return sr844->getBufferModeList();
}

bool finalLockInAmplifier::setBufferMode(const int &bufferMode) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setBufferMode(bufferMode);
    if (lockInAmplifierModel == "SR844")
        return sr844->setBufferMode(bufferMode);
    return false;
}

bool finalLockInAmplifier::setBufferMode(const std::string &bufferMode) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->setBufferMode(bufferMode);
    if (lockInAmplifierModel == "SR844")
        return sr844->setBufferMode(bufferMode);
    return false;
}

std::string finalLockInAmplifier::getBufferMode() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getBufferMode();
    if (lockInAmplifierModel == "SR844")
        return sr844->getBufferMode();
    return "No this model or this model can't work with reference trigger mode";
}

bool finalLockInAmplifier::testBufferMode() const {
    std::string oldBufferMode = getBufferMode();
    for(auto bufferMode: getBufferModeList()) {
        setBufferMode(bufferMode);
        if (bufferMode != getBufferMode()) {
            setBufferMode(oldBufferMode);
            return false;
        }
    }
    setBufferMode(oldBufferMode);
    return  true;
}

bool finalLockInAmplifier::workWithBuffer() const {
    if (lockInAmplifierModel == "SR830")
        return  true;
    if (lockInAmplifierModel == "SR844")
        return true;
    return false;
}

bool finalLockInAmplifier::startBuffer() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->startBuffer();
    if (lockInAmplifierModel == "SR844")
        return  sr844->startBuffer();
    return false;
}

bool finalLockInAmplifier::stopBuffer() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->stopBuffer();
    if (lockInAmplifierModel == "SR844")
        return  sr844->stopBuffer();
    return false;
}

bool finalLockInAmplifier::pauseBuffer() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->pauseBuffer();
    if (lockInAmplifierModel == "SR844")
        return  sr844->pauseBuffer();
    return false;
}

std::string finalLockInAmplifier::getPointFromBufferChannel1(const int &number) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getPointFromBufferChannel1(number);
    if (lockInAmplifierModel == "SR844")
        return  sr844->getPointFromBufferChannel1(number);
    return "No this model or this model can't work with buffer";
}

std::vector <std::string> finalLockInAmplifier::getChannel1FromBuffer() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getChannel1FromBuffer();
    if (lockInAmplifierModel == "SR844")
        return  sr844->getChannel1FromBuffer();
}

std::string finalLockInAmplifier::getPointFromBufferChannel2(const int &number) const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getPointFromBufferChannel2(number);
    if (lockInAmplifierModel == "SR844")
        return  sr844->getPointFromBufferChannel2(number);
    return "No this model or this model can't work with buffer";
}

std::vector <std::string> finalLockInAmplifier::getChannel2FromBuffer() const {
    if (lockInAmplifierModel == "SR830")
        return  sr830->getChannel2FromBuffer();
    if (lockInAmplifierModel == "SR844")
        return  sr844->getChannel2FromBuffer();
}

std::string finalLockInAmplifier::allTest() const {
    if (workWithPhase())
        if (testPhase(1,0.1) == 0)
            return "Phase test Failed";
    /*if (workWithHarmonic())
        if (testHarmonic() == 0)
            return "Harmonic test failed"; надо придумать как написать тест или исправить функци*/
    /*if (workWithFrequency())
        if(testFrequency(10, 1) == 0)
            return "Frequency test failed";*/
    if (workWithRefSourse())
        if(testRefSource() == 0)
            return "Reference source test failed";
    if (workWithBufferMode())
        if(testBufferMode() == 0)
            return "Buffer mode test failed";
    if (workWithFilterSlope())
        if(testFilterSlope() == 0)
            return "Filter slope test failed";
    if (workWithInputSignal())
        if (testInputSignal() == 0)
            return "Input signal test failed";
    if (workWithSensitivity())
        if (testSensitivity() == 0)
            return "Sensitivity test failed";
    if (workWithSineDCLevel())
        if (testSineDCLevel(0.1, 0.01) == 0)
            return "SineDCLevel test failed";
    /*if (workWithDualHarmonic())
        if (testDualHarmonic() == 0)
            return "Dual Harmonic test failed";*/
    if (workWithInputSignalZ())
        if (testInputSignalZ() == 0)
            return  "Input Signal Z test failed";
    if (workWithTimeConstant())
        if (testTimeConstant() == 0)
            return "Time constant test failed";
    if (workWithAdvanceFilter())
        if (testAdvanceFilter() == 0)
            return "Advance filter test failed";
    if (workWithSineAmplitude())
        if (testSineAmplitude(0.1, 0.01) == 0)
            return "Sine Amplitude test failed";
    if (workWithRefTriggerMode())
        if (testRefTriggerMode() == 0)
            return "reference trigger mode test failed";
    if (workWithCloseReserveMode())
        if (testCloseReserveMode() == 0)
            return "Close reserve mode test failed";
    if (workWithInputCurrentGain())
        if (testInputCurrentGain() == 0)
            return "Input current Gain test failed";
    if (workWithInputVoltageMode())
        if (testInputVoltageMode() == 0)
            return "Input Voltage mode test failed";
    if (workWithRefTriggerOutput())
        if (testRefTriggerOutput() == 0)
            return "Reference trigger output test failed";
    if (workWithInputVoltageRange())
        if (testInputVoltageRange() == 0)
            return "Input voltage range test failed";
    if (workWithSynchronousFilter())
        if (testSynchronousFilter() == 0)
            return "Synchronous filter test failed";
    if (workWithInputVoltageShields())
        if (testInputVoltageShields() == 0)
            return "Input voltage shields test failed";
    if (workWithInputVoltageCoupling())
        if (testInputVoltageCoupling() == 0)
            return "Input voltage coupling test failed";
    return "All test passed";
}
