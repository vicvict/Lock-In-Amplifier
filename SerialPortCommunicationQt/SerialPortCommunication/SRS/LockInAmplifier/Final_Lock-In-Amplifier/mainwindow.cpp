#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finallockinamplifier.h"
#include "test.h"
//Проблема: при попытке detect'a не receiv'ит сингналы, пока не поменяешь read_wait_timeout
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string model;

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
        obj.setFrequency(ui->lineEditFrequency->text().toDouble(&succeed));
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
            obj.connect("COM7","19200","8","1", "NO", "NO");

            //Добавление моделей
            for (auto model : obj.getSupportedList()) {
                ui->comboBoxLockInAmplifierModel->addItem(to_QString(model));
            }

            //Добавление time constants
            if (obj.workWithTimeConstant()){
                for (auto timeConstant : obj.getTimeConstantList()) {
                    ui->comboBoxTimeConstant->addItem(to_QString(timeConstant));
                }
                ui->comboBoxTimeConstant->show();
                ui->comboBoxTimeConstant->setCurrentText(to_QString(obj.getTimeConstant()));
            }
            else {
                ui->comboBoxTimeConstant->hide();
            }

            //Добавление ref sources
            if (obj.workWithRefSourse()){
                for (auto refSource : obj.getRefSourceList()) {
                    ui->comboBoxRefSource->addItem(to_QString(refSource));
                }
                ui->comboBoxRefSource->show();
                ui->comboBoxRefSource->setCurrentText(to_QString(obj.getRefSource()));
            }
            else {
                ui->comboBoxRefSource->hide();
            }

            //Добавление ref trigger mode
            if (obj.workWithRefTriggerMode()) {
                for (auto refTriggerMode : obj.getRefTriggerModeList()) {
                    ui->comboBoxRefTriggerMode->addItem(to_QString(refTriggerMode));
                }
                ui->comboBoxRefTriggerMode->show();
                ui->comboBoxRefTriggerMode->setCurrentText(to_QString(obj.getRefTriggerMode()));
            }
            else {
                ui->comboBoxRefTriggerMode->hide();
            }

            //Добавление ref trigger output
            if (obj.workWithRefTriggerOutput()) {
                for (auto refTriggerOutput : obj.getRefTriggerOutputList()) {
                    ui->comboBoxRefTriggerOutput->addItem(to_QString(refTriggerOutput));
                }
                ui->comboBoxRefTriggerOutput->show();
                ui->comboBoxRefTriggerOutput->setCurrentText(to_QString(obj.getRefTriggerOutput()));
            }
            else {
                ui->comboBoxRefTriggerOutput->hide();
            }

            //Добавление input signal
            if (obj.workWithInputSignal()) {
                for (auto inputSignal : obj.getInputSignalList()) {
                    ui->comboBoxInputSignal->addItem(to_QString(inputSignal));
                }
                ui->comboBoxInputSignal->show();
                ui->comboBoxInputSignal->setCurrentText(to_QString(obj.getInputSignal()));
            }
            else {
                ui->comboBoxInputSignal->hide();
            }

            //Добавление voltage mode
            if (obj.workWithInputVoltageMode()) {
                for (auto inputVoltageMode : obj.getInputVoltageModeList()) {
                    ui->comboBoxInputVoltageMode->addItem(to_QString(inputVoltageMode));
                }
                ui->comboBoxInputVoltageMode->show();
                ui->comboBoxInputVoltageMode->setCurrentText(to_QString(obj.getInputVoltageMode()));
            }
            else {
                ui->comboBoxInputVoltageMode->hide();
            }

            //Добавление voltage coupling
            if (obj.workWithInputVoltageCoupling()) {
                for (auto inputVoltageCoupling : obj.getInputVoltageCouplingList()) {
                    ui->comboBoxInputVoltageCoupling->addItem(to_QString(inputVoltageCoupling));
                }
                ui->comboBoxInputVoltageCoupling->show();
                ui->comboBoxInputVoltageCoupling->setCurrentText(to_QString(obj.getInputVoltageCoupling()));
            }
            else {
                ui->comboBoxInputVoltageCoupling->hide();
            }

            //Добавление voltage shields
            if (obj.workWithInputVoltageShields()) {
                for (auto inputVoltageShields : obj.getInputVoltageShieldsList()) {
                    ui->comboBoxInputVoltageShields->addItem(to_QString(inputVoltageShields));
                }
                ui->comboBoxInputVoltageShields->show();
                ui->comboBoxInputVoltageShields->setCurrentText(to_QString(obj.getInputVoltageShields()));
            }
            else {
                ui->comboBoxInputVoltageShields->hide();
            }

            //Добавление voltage range
            if (obj.workWithInputVoltageRange()) {
                for (auto inputVoltageRange : obj.getInputVoltageRangeList()) {
                    ui->comboBoxInputVoltageRange->addItem(to_QString(inputVoltageRange));
                }
                ui->comboBoxInputVoltageRange->show();
                ui->comboBoxInputVoltageRange->setCurrentText(to_QString(obj.getInputVoltageRange()));
            }
            else {
                ui->comboBoxInputVoltageRange->hide();
            }

            //Добавление current gain
            if (obj.workWithInputCurrentGain()) {
                for (auto inputCurrentGain : obj.getInputCurrentGainList()) {
                    ui->comboBoxInputCurrentGain->addItem(to_QString(inputCurrentGain));
                }
                ui->comboBoxInputCurrentGain->show();
                ui->comboBoxInputCurrentGain->setCurrentText(to_QString(obj.getInputCurrentGain()));
            }
            else {
                ui->comboBoxInputCurrentGain->hide();
            }

            //Добавление sensitivity
            if (obj.workWithSensitivity()) {
                for (auto sensitivity : obj.getSensitivityList()) {
                    ui->comboBoxSensivitity->addItem(to_QString(sensitivity));
                }
                ui->comboBoxSensivitity->show();
                ui->comboBoxSensivitity->setCurrentText(to_QString(obj.getSensitivity()));
            }
            else {
                ui->comboBoxSensivitity->hide();
            }

            //добавление фильтров
            if (obj.workWithFilterSlope()) {
                for (auto filterSlope : obj.getFilterSlopeList()) {
                    ui->comboBoxFilterSlope->addItem(to_QString(filterSlope));
                }
                ui->comboBoxFilterSlope->show();
                ui->comboBoxFilterSlope->setCurrentText(to_QString(obj.getFilterSlope()));
            }
            else {
                ui->comboBoxFilterSlope->hide();
            }

            //добавление синхронного фильтра
            if (obj.workWithSynchronousFilter()) {
                for (auto synchronousFilter : obj.getSynchronousFilterList()) {
                    ui->comboBoxSynchronousFilter->addItem(to_QString(synchronousFilter));
                }
                ui->comboBoxSynchronousFilter->show();
                ui->comboBoxSynchronousFilter->setCurrentText(to_QString(obj.getSynchronousFilter()));
            }
            else {
                ui->comboBoxSynchronousFilter->hide();
            }


            //добавление дополнительного фильтра
            if (obj.workWithAdvanceFilter()) {
                for (auto advanceFilter : obj.getAdvanceFilterList()) {
                    ui->comboBoxAdvanceFilter->addItem(to_QString(advanceFilter));
                }
                ui->comboBoxAdvanceFilter->show();
                ui->comboBoxAdvanceFilter->setCurrentText(to_QString(obj.getAdvanceFilter()));
            }
            else {
                ui->comboBoxAdvanceFilter->hide();
            }


            //Добавление data
            if (obj.workWithOutData()) {
                for (auto data : obj.getOutDataList()) {
                    ui->comboBoxOutData->addItem(to_QString(data));
                }
                ui->comboBoxOutData->show();
            }
            else {
                ui->comboBoxOutData->hide();
            }


            ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));

            if (obj.workWithPhase()) {
                ui->lineEditPhase->show();
                ui->lineEditPhase->setText(to_QString(obj.getPhase()));
                ui->pushButtonPhase->show();
            }
            else {
                ui->lineEditPhase->hide();
                ui->pushButtonPhase->hide();
            }

            if (obj.workWithFrequency()) {
                ui->lineEditFrequency->show();
                ui->lineEditFrequency->setText(to_QString(obj.getFrequency()));
                ui->pushButtonFrequency->show();
            }
            else {
                ui->lineEditFrequency->hide();
                ui->pushButtonFrequency->hide();
            }

            if (obj.workWithHarmonic()) {
                ui->lineEditHarmonic->show();
                ui->lineEditHarmonic -> setText(to_QString(obj.getHarmonic()));
                ui->pushButtonHarmonic->show();
            }
            else {
                ui->lineEditHarmonic->hide();
                ui->pushButtonHarmonic->hide();
            }

            if (obj.workWithSineAmplitude()) {
                ui->lineEditSineAmplitude->show();
                ui->lineEditSineAmplitude->setText(to_QString(obj.getSineAmplitude()));
                ui->pushButtonSineAmplitude->show();
            }
            else {
                ui->lineEditSineAmplitude->hide();
                ui->pushButtonSineAmplitude->hide();
            }

            if (obj.workWithSineDCLevel()){
                ui->lineEditSineDCLevel->show();
                ui->lineEditSineDCLevel -> setText(to_QString(obj.getSineDCLevel()));
                ui->pushButtonSineDCLevel->show();
            }
            else {
                ui->lineEditSineDCLevel->hide();
                ui->pushButtonSineDCLevel->hide();
            }


            //ui->lineEditSignalStrength->setText(to_QString(obj.getSignalStrength()));

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
            ui->lineEditError->setText(to_QString(s));
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
        obj.connect("COM5","19200","8","1", "NO", "NO");
        obj.setTimeConstant(to_StdString(ui->comboBoxTimeConstant->currentText()));
        obj.setSensitivity(to_StdString(ui->comboBoxSensivitity->currentText()));
        obj.setRefSource(to_StdString(ui->comboBoxRefSource->currentText()));
        obj.setRefTriggerMode(to_StdString(ui->comboBoxRefTriggerMode->currentText()));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }

}

void MainWindow::on_pushButtonSend_clicked() {
    std::string answer;
    try {
        obj.sendQuery(to_StdString(ui->lineEditSend->text()), answer);
        ui -> lineEditRecieve -> setText(to_QString(answer));
    } catch (std::string s) {
        ui -> lineEditError->setText(to_QString(s));
    }

}
