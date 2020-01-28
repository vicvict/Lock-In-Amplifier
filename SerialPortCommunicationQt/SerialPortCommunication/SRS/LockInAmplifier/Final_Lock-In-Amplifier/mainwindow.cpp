#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../lockinamplifier.h"
//Проблема: при попытке detect'a не receiv'ит сингналы, пока не поменяешь read_wait_timeout
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string model;
    //Добавление моделей
    for (auto model : obj.getSupportedList()) {
        ui->comboBoxLockInAmplifierModel->addItem(to_QString(model));
    }

    //Добавление time constants
    for (auto timeConstant : obj.getTimeConstantList()) {
        ui->comboBoxTimeConstant->addItem(to_QString(timeConstant));
    }

    //Добавление ref sources
    for (auto refSource : obj.getRefSourceList()) {
        ui->comboBoxRefSource->addItem(to_QString(refSource));
    }

    //Добавление ref trigger mode
    for (auto refTriggerMode : obj.getRefTriggerModeList()) {
        ui->comboBoxRefTriggerMode->addItem(to_QString(refTriggerMode));
    }

    //Добавление ref trigger output
    for (auto refTriggerOutput : obj.getRefTriggerOutputList()) {
        ui->comboBoxRefTriggerOutput->addItem(to_QString(refTriggerOutput));
    }

    //Добавление input signal
    for (auto inputSignal : obj.getInputSignalList()) {
        ui->comboBoxInputSignal->addItem(to_QString(inputSignal));
    }

    //Добавление voltage mode
    for (auto inputVoltageMode : obj.getInputVoltageModeList()) {
        ui->comboBoxInputVoltageMode->addItem(to_QString(inputVoltageMode));
    }



    /*try {
        model = obj.detect("COM4", succeed);
        obj.connect("COM4");
        ui->lineEditPhase ->setText(QString(obj.getIDN().c_str()));
        ui->lineEditFrequency ->setText(to_QString(obj.getPortName() + " " + obj.getBaudRate() + " " + obj.getDataBits() + " " + obj.getStopBits() + " " + obj.getFlowControl() + " " + obj.getParity()));
        ui->lineEditResponse->setText(obj.getFrequency());
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString(s));
    }*/



    try {
        obj.connect("COM7","19200","8","1", "NO", "NO");
        ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));
        ui->lineEditPhase ->setText(to_QString(obj.getPhase()));
        ui->lineEditFrequency -> setText(to_QString(obj.getFrequency()));
        ui->lineEditHarmonic -> setText(to_QString(obj.getHarmonic()));
        ui->lineEditSineAmplitude -> setText(to_QString(obj.getSineAmplitude()));
        ui->lineEditSineDCLevel -> setText(to_QString(obj.getSineDCLevel()));
        ui->comboBoxTimeConstant -> setCurrentText(to_QString(obj.getTimeConstant()));
        ui->comboBoxRefSource -> setCurrentText(to_QString(obj.getRefSource()));
        ui->comboBoxRefTriggerMode -> setCurrentText(to_QString(obj.getRefTriggerMode()));
        ui->comboBoxRefTriggerOutput -> setCurrentText(to_QString(obj.getRefTriggerOutput()));
        ui->comboBoxInputSignal -> setCurrentText(to_QString(obj.getInputSignal()));
        ui->comboBoxInputVoltageMode -> setCurrentText(to_QString(obj.getInputVoltageMode()));

    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString(s));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonPhase_clicked()
{
    bool succeed;
    ui->lineEditPhase->text().toDouble(&succeed);
    if (succeed) {
        obj.setInternalPhase(ui->lineEditPhase->text().toDouble(&succeed));
    }
    else {
        //do nothing
    }
}

void MainWindow::on_pushButtonHarmonic_clicked()
{
    bool succeed;
    ui->lineEditHarmonic->text().toInt(&succeed);
    if (succeed) {
        obj.setHarmonic(ui->lineEditHarmonic->text().toInt(&succeed));
    }
    else {
        //do nothing
    }
}

void MainWindow::on_pushButtonFrequency_clicked()
{
    bool succeed;
    ui->lineEditFrequency->text().toDouble(&succeed);
    if (succeed) {
        obj.setInternalFrequency(ui->lineEditFrequency->text().toDouble(&succeed));
    }
    else {
        //do nothing
    }
}

void MainWindow::on_pushButtonSineAmplitude_clicked()
{
    bool succeed;
    ui->lineEditSineAmplitude->text().toDouble(&succeed);
    if (succeed) {
        obj.setSineAmplitude(ui->lineEditSineAmplitude->text().toDouble(&succeed));
    }
    else {
        //do nothing
    }
}

void MainWindow::on_pushButtonAutoPhase_clicked()
{
    if (obj.autoPhase()) ui->lineEditPhase->setText(to_QString(obj.getPhase()));
    else {
        //do nothing
    }
    //obj.autoPhase();
}

void MainWindow::on_pushButtonSineDCLevel_clicked()
{
    bool succeed;
    ui->lineEditSineDCLevel->text().toDouble(&succeed);
    if (succeed) {
        obj.setSineDCLevel(ui->lineEditSineDCLevel->text().toDouble(&succeed));
    }
    else {
        //do nothing
    }
}


void MainWindow::on_comboBoxTimeConstant_activated(const QString &new_text)
{
    try {
        obj.setTimeConstant(to_StdString(new_text));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxRefSource_activated(const QString &arg1)
{
    try {
        obj.setRefSource(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxRefTriggerMode_activated(const QString &arg1)
{
    try {
        obj.setRefTriggerMode(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxRefTriggerOutput_activated(const QString &arg1)
{
    try {
        obj.setRefTriggerOutput(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputSignal_activated(const QString &arg1)
{
    try {
        obj.setInputSignal(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputVoltageMode_activated(const QString &arg1)
{
    try {
        obj.setInputVoltageMode(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}
