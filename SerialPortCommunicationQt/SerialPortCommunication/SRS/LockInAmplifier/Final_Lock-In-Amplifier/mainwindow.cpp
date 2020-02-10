#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../lockinamplifier.h"
#include "test.h"
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

    //Добавление voltage coupling
    for (auto inputVoltageCoupling : obj.getInputVoltageCouplingList()) {
        ui->comboBoxInputVoltageCoupling->addItem(to_QString(inputVoltageCoupling));
    }

    //Добавление voltage shields
    for (auto inputVoltageShields : obj.getInputVoltageShieldsList()) {
        ui->comboBoxInputVoltageShields->addItem(to_QString(inputVoltageShields));
    }

    //Добавление voltage range
    for (auto inputVoltageRange : obj.getInputVoltageRangeList()) {
        ui->comboBoxInputVoltageRange->addItem(to_QString(inputVoltageRange));
    }

    //Добавление current gain
    for (auto inputCurrentGain : obj.getInputCurrentGainList()) {
        ui->comboBoxInputCurrentGain->addItem(to_QString(inputCurrentGain));
    }

    //Добавление sensitivity
    for (auto sensitivity : obj.getSensitivityList()) {
        ui->comboBoxSensivitity->addItem(to_QString(sensitivity));
    }


    for (auto filterSlope : obj.getFilterSlopeList()) {
        ui->comboBoxFilterSlope->addItem(to_QString(filterSlope));
    }


    for (auto synchronousFilter : obj.getSynchronousFilterList()) {
        ui->comboBoxSynchronousFilter->addItem(to_QString(synchronousFilter));
    }



    for (auto advanceFilter : obj.getAdvanceFilterList()) {
        ui->comboBoxAdvanceFilter->addItem(to_QString(advanceFilter));
    }


    //Добавление data
    for (auto data : obj.getOutDataList()) {
        ui->comboBoxOutData->addItem(to_QString(data));
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

    ui->pushButtonConnect->setText("Connect");

    ui->lineEditPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditSignalStrength->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

    ui->pushButtonPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoScale->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

    ui->comboBoxOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxRefSource->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxFilterSlope->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputSignal->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxSensivitity->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxTimeConstant->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxAdvanceFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxRefTriggerMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputCurrentGain->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxRefTriggerOutput->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxSynchronousFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageShields->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageCoupling->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

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

void MainWindow::on_pushButtonAutoPhase_clicked() {
    if (obj.autoPhase()) ui->lineEditPhase->setText(to_QString(obj.getPhase()));
    else {
        //do nothing
    }
}

void MainWindow::on_pushButtonAutoRange_clicked() {
    if (obj.autoRange()) {
        ui->comboBoxInputVoltageRange -> setCurrentText(to_QString(obj.getInputVoltageRange()));
        ui->lineEditSignalStrength->setText(to_QString(obj.getSignalStrength()));
    }
    else {
        ui->lineEditError->setText("KVA");
        //do nothing
    }
}

void MainWindow::on_pushButtonAutoScale_clicked() {
    if (obj.autoScale()) ui->comboBoxSensivitity -> setCurrentText(to_QString(obj.getSensitivity()));
    else {
        //do nothing
    }
}

void MainWindow::on_pushButtonSineDCLevel_clicked() {
    bool succeed;
    ui->lineEditSineDCLevel->text().toDouble(&succeed);
    if (succeed) {
        obj.setSineDCLevel(ui->lineEditSineDCLevel->text().toDouble(&succeed));
    }
    else {
        //do nothing
    }
}


void MainWindow::on_comboBoxTimeConstant_activated(const QString &new_text) {
    try {
        obj.setTimeConstant(to_StdString(new_text));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxRefSource_activated(const QString &arg1) {
    try {
        obj.setRefSource(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxRefTriggerMode_activated(const QString &arg1) {
    try {
        obj.setRefTriggerMode(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxRefTriggerOutput_activated(const QString &arg1) {
    try {
        obj.setRefTriggerOutput(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputSignal_activated(const QString &arg1) {
    try {
        obj.setInputSignal(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputVoltageMode_activated(const QString &arg1) {
    try {
        obj.setInputVoltageMode(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputVoltageCoupling_activated(const QString &arg1) {
    try {
        obj.setInputVoltageCoupling(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxSensivitity_activated(const QString &arg1) {
    try {
        obj.setSensitivity(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}



void MainWindow::on_comboBoxInputVoltageShields_activated(const QString &arg1) {
    try {
        obj.setInputVoltageShields(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputVoltageRange_activated(const QString &arg1) {
    try {
        obj.setInputVoltageRange(to_StdString(arg1));
        ui->lineEditSignalStrength->setText(to_QString(obj.getSignalStrength()));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputCurrentGain_activated(const QString &arg1) {
    try {
        obj.setInputCurrentGain(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}




void MainWindow::on_comboBoxFilterSlope_activated(const QString &arg1) {
    try {
        obj.setFilterSlope(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}


void MainWindow::on_comboBoxAdvanceFilter_activated(const QString &arg1)
{
    try {
        obj.setAdvanceFilter(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxSynchronousFilter_activated(const QString &arg1)
{
    try {
        obj.setSynchronousFilter(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxOutData_activated(const QString &arg1) {
    const QString cmd = to_QString("Get ") + arg1;
    ui->pushButtonOutData->setText(cmd);
}

void MainWindow::on_pushButtonOutData_clicked() {
    try {
        QString data = ui->comboBoxOutData->currentText();
        ui->lineEditOutData->setText(to_QString(obj.getOutData(to_StdString(data))));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_pushButtonConnect_clicked()
{
    if(ui->pushButtonConnect->text() == "Connect"){
        try {
            obj.connect("COM5","19200","8","1", "NO", "NO");
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
            ui->comboBoxInputVoltageCoupling -> setCurrentText(to_QString(obj.getInputVoltageCoupling()));
            ui->comboBoxInputVoltageShields -> setCurrentText(to_QString(obj.getInputVoltageShields()));
            ui->comboBoxInputVoltageRange -> setCurrentText(to_QString(obj.getInputVoltageRange()));
            ui->comboBoxInputCurrentGain -> setCurrentText(to_QString(obj.getInputCurrentGain()));
            ui->lineEditSignalStrength->setText(to_QString(obj.getSignalStrength()));
            ui->comboBoxSensivitity -> setCurrentText(to_QString(obj.getSensitivity()));
            ui->comboBoxFilterSlope -> setCurrentText(to_QString(obj.getFilterSlope()));
            ui->comboBoxSynchronousFilter -> setCurrentText(to_QString(obj.getSynchronousFilter()));
            ui->comboBoxAdvanceFilter -> setCurrentText(to_QString(obj.getAdvanceFilter()));

            ui->pushButtonConnect->setText("Disconnect");


            ui->lineEditPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditSignalStrength->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

            ui->pushButtonPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoScale->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

            ui->comboBoxOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxRefSource->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxFilterSlope->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputSignal->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxSensivitity->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxTimeConstant->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxAdvanceFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxRefTriggerMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputCurrentGain->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxRefTriggerOutput->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxSynchronousFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageShields->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageCoupling->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

        } catch (std:: string s) {
            ui->lineEditResponse->setText(to_QString(s));
        }
    }
    else {
        ui->pushButtonConnect->setText("Connect");
        obj.disconnect();


        ui->lineEditPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->lineEditHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->lineEditFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->lineEditOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->lineEditSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->lineEditSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->lineEditSignalStrength->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

        ui->pushButtonPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoScale->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

        ui->comboBoxOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxRefSource->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxFilterSlope->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputSignal->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxSensivitity->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxTimeConstant->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxAdvanceFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxRefTriggerMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputCurrentGain->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxRefTriggerOutput->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxSynchronousFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageShields->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageCoupling->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    }
}
// вначале обязательно конектиться. Потом только можно делать тест
// Тест это костыль погоняющий костыль(потому что я ленивая жопа)
void MainWindow::on_Test_clicked()
{
    try {
        obj.disconnect();
        TestAll();
        obj.connect("COM7","19200","8","1", "NO", "NO");
        obj.setTimeConstant(to_StdString(ui->comboBoxTimeConstant->currentText()));
        obj.setSensitivity(to_StdString(ui->comboBoxSensivitity->currentText()));
        obj.setRefSource(to_StdString(ui->comboBoxRefSource->currentText()));
        obj.setRefTriggerMode(to_StdString(ui->comboBoxRefTriggerMode->currentText()));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }

}
