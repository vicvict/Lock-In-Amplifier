#include "mainwindow.h"
#include "ui_mainwindow.h"

//Проблема: при попытке detect'a не receiv'ит сингналы, пока не поменяешь read_wait_timeout
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string model;

    ui->pushButtonConnect->setText("Connect");

    ui->lineEditPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditSignalStrength->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditResponse->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditSend->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditError->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditRecieve->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->lineEditTest->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

    ui->pushButtonPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoScale->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonSend->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonTest->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoReserve->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->pushButtonAutoWideReserve->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

    ui->comboBoxOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxRefSource->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxFilterSlope->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputSignal->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxSensivitity->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxTimeConstant->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxAdvancedFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxRefTriggerMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputCurrentGain->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxRefTriggerOutput->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxSynchronousFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageShields->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputVoltageCoupling->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxWideReserveMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxCloseReserveMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxInputSignalZ->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->comboBoxBufferMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

    ui->doubleSpinBoxPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->doubleSpinBoxFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->doubleSpinBoxHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->doubleSpinBoxSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    ui->doubleSpinBoxSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
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
    if (obj.autoPhase()) {
        Sleep(2000);
        ui->lineEditPhase->setText(to_QString(obj.getPhase()));
    }
    else {
        //do nothing
    }
}

void MainWindow::on_pushButtonAutoRange_clicked() {
    if (obj.autoRange()) {
        Sleep(2000);
        ui->comboBoxInputVoltageRange -> setCurrentText(to_QString(obj.getInputVoltageRange()));
        ui->lineEditSignalStrength->setText(to_QString(obj.getSignalStrength()));
    }
    else {
        ui->lineEditError->setText("KVA");
        //do nothing
    }
}

void MainWindow::on_pushButtonAutoScale_clicked() {
    if (obj.autoScale()) {
        Sleep(2000);
        ui->comboBoxSensivitity -> setCurrentText(to_QString(obj.getSensitivity()));
    }
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


void MainWindow::on_comboBoxAdvancedFilter_activated(const QString &arg1)
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
                ui->labelInputVoltageShields->show();
                ui->comboBoxInputVoltageShields->show();
                ui->comboBoxInputVoltageShields->setCurrentText(to_QString(obj.getInputVoltageShields()));
            }
            else {
                ui->labelInputVoltageShields->hide();
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
                ui->labelSynchronousFilter->show();
                ui->comboBoxSynchronousFilter->show();
                ui->comboBoxSynchronousFilter->setCurrentText(to_QString(obj.getSynchronousFilter()));
            }
            else {
                ui->labelSynchronousFilter->hide();
                ui->comboBoxSynchronousFilter->hide();
            }


            //добавление дополнительного фильтра
            if (obj.workWithAdvanceFilter()) {
                for (auto advanceFilter : obj.getAdvanceFilterList()) {
                    ui->comboBoxAdvancedFilter->addItem(to_QString(advanceFilter));
                }
                ui->labelAdvancedFilter->show();
                ui->comboBoxAdvancedFilter->show();
                ui->comboBoxAdvancedFilter->setCurrentText(to_QString(obj.getAdvanceFilter()));
            }
            else {
                ui->labelAdvancedFilter->hide();
                ui->comboBoxAdvancedFilter->hide();
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

            //добавление close reserve mode
            if (obj.workWithCloseReserveMode()) {
                for (auto data : obj.getCloseReserveModeList()) {
                    ui->comboBoxCloseReserveMode->addItem(to_QString(data));
                }
                ui->comboBoxCloseReserveMode->show();
                ui->labelCloseReserveMode->show();
            }
            else {
                ui->comboBoxCloseReserveMode->hide();
                ui->labelCloseReserveMode->hide();
            }

            if (obj.workWithWideReserveMode()) {
                for (auto data : obj.getWideReserveModeList()) {
                    ui->comboBoxWideReserveMode->addItem(to_QString(data));
                }
                ui->comboBoxWideReserveMode->show();
                ui->labelWideReserveMode->show();
            }
            else {
                ui->comboBoxWideReserveMode->hide();
                ui->labelWideReserveMode->hide();
            }

            if (obj.workWithInputSignalZ()) {
                for (auto data : obj.getInputSignalZList()) {
                    ui->comboBoxInputSignalZ->addItem(to_QString(data));
                }
                ui->comboBoxInputSignalZ->show();
                ui->labelInputSignalZ->show();
            }
            else {
                ui->comboBoxInputSignalZ->hide();
                ui->labelInputSignalZ->hide();
            }

            if (obj.workWithBufferMode()) {
                for (auto data : obj.getBufferModeList()) {
                    ui->comboBoxBufferMode->addItem(to_QString(data));
                }
                ui->comboBoxBufferMode->show();
            }
            else {
                ui->comboBoxBufferMode->hide();
            }


            ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));

            if (obj.workWithPhase()) {
                ui->labelPhase->show();
                ui->doubleSpinBoxPhase->show();
                ui->doubleSpinBoxPhase->setMinimum(obj.getMinPhase());
                ui->doubleSpinBoxPhase->setMaximum(obj.getMaxPhase());
                ui->doubleSpinBoxPhase->setValue(std:: stod(obj.getPhase()));

                ui->lineEditPhase->show();
                ui->lineEditPhase->setText(to_QString(obj.getPhase()));
                ui->pushButtonPhase->show();
            }
            else {
                ui->labelPhase->hide();
                ui->doubleSpinBoxPhase->hide();

                ui->lineEditPhase->hide();
                ui->pushButtonPhase->hide();
            }
///@bug changes values after connection
            if (obj.workWithFrequency()) {
                ui->labelFrequency->show();
                ui->doubleSpinBoxFrequency->show();
                ui->doubleSpinBoxFrequency->setMinimum(obj.getMinInternalFrequency());
                ui->doubleSpinBoxFrequency->setMaximum(obj.getMaxInternalFrequency());
                ui->doubleSpinBoxFrequency->setValue(std:: stod(obj.getFrequency()));

                ui->lineEditFrequency->show();
                ui->lineEditFrequency->setText(to_QString(obj.getFrequency()));
                ui->pushButtonFrequency->show();
            }
            else {
                ui->labelFrequency->hide();
                ui->doubleSpinBoxFrequency->hide();

                ui->lineEditFrequency->hide();
                ui->pushButtonFrequency->hide();
            }

            if (obj.workWithHarmonic()) {
                ui->labelHarmonic->show();
                ui->doubleSpinBoxHarmonic->show();
                ui->doubleSpinBoxHarmonic->setDecimals(0);
                ui->doubleSpinBoxHarmonic->setSingleStep(1.0);
                ui->doubleSpinBoxHarmonic->setMinimum(obj.getMinHarmonic());
                ui->doubleSpinBoxHarmonic->setMaximum(obj.getMaxHarmonic());
                ui->doubleSpinBoxHarmonic->setValue(std:: stod(obj.getHarmonic()));

                ui->lineEditHarmonic->show();
                ui->lineEditHarmonic -> setText(to_QString(obj.getHarmonic()));
                ui->pushButtonHarmonic->show();
            }
            else {
                ui->labelHarmonic->hide();
                ui->doubleSpinBoxHarmonic->hide();

                ui->lineEditHarmonic->hide();
                ui->pushButtonHarmonic->hide();
            }

            if (obj.workWithSineAmplitude()) {
                ui->labelSineAmplitude->show();
                ui->doubleSpinBoxSineAmplitude->show();
                ui->doubleSpinBoxSineAmplitude->setMinimum(obj.getMinSineAmplitude());
                ui->doubleSpinBoxSineAmplitude->setMaximum(obj.getMaxSineAmplitude());
                ui->doubleSpinBoxSineAmplitude->setValue(std:: stod(obj.getSineAmplitude()));

                ui->lineEditSineAmplitude->show();
                ui->lineEditSineAmplitude->setText(to_QString(obj.getSineAmplitude()));
                ui->pushButtonSineAmplitude->show();
            }
            else {
                ui->labelSineAmplitude->hide();
                ui->doubleSpinBoxSineAmplitude->hide();

                ui->lineEditSineAmplitude->hide();
                ui->pushButtonSineAmplitude->hide();
            }

            if (obj.workWithSineDCLevel()){
                ui->labelSineDCLevel->show();
                ui->doubleSpinBoxSineDCLevel->show();
                ui->doubleSpinBoxSineDCLevel->setMinimum(obj.getMinSineDCLevel());
                ui->doubleSpinBoxSineDCLevel->setMaximum(obj.getMaxSineDCLevel());
                ui->doubleSpinBoxSineDCLevel->setValue(std:: stod(obj.getSineDCLevel()));

                ui->lineEditSineDCLevel->show();
                ui->lineEditSineDCLevel -> setText(to_QString(obj.getSineDCLevel()));
                ui->pushButtonSineDCLevel->show();
            }
            else {
                ui->labelSineDCLevel->hide();
                ui->doubleSpinBoxSineDCLevel->hide();

                ui->lineEditSineDCLevel->hide();
                ui->pushButtonSineDCLevel->hide();
            }

            if (obj.workWithAutoPhase())
                ui->pushButtonAutoPhase->show();
            else {
                ui->pushButtonAutoPhase->hide();
            }

            if (obj.workWithAutoRange())
                ui->pushButtonAutoRange->show();
            else {
                ui->pushButtonAutoRange->hide();
            }

            if (obj.workWithAutoScale())
                ui->pushButtonAutoScale->show();
            else {
                ui->pushButtonAutoScale->hide();
            }

            if (obj.workWithAutoReserve())
                ui->pushButtonAutoReserve->show();
            else {
                ui->pushButtonAutoReserve->hide();
            }

            if (obj.workWithAutoWideReverse())
                ui->pushButtonAutoWideReserve->show();
            else {
                ui->pushButtonAutoWideReserve->hide();
            }

            if (obj.workWithSignalStrength()) {
                ui->lineEditSignalStrength->show();
                ui->lineEditSignalStrength->setText(to_QString(obj.getSignalStrength()));
            }
            else {
                ui->lineEditSignalStrength->hide();
            }

            ui->pushButtonConnect->setText("Disconnect");

            ui->lineEditPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditSignalStrength->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->lineEditSend->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

            ui->pushButtonPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoScale->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonSend->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonTest->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoReserve->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->pushButtonAutoWideReserve->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

            ui->comboBoxOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxRefSource->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxFilterSlope->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputSignal->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxSensivitity->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxTimeConstant->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxAdvancedFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxRefTriggerMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputCurrentGain->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxRefTriggerOutput->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxSynchronousFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageShields->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputVoltageCoupling->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxWideReserveMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxCloseReserveMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxInputSignalZ->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->comboBoxBufferMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

            ui->doubleSpinBoxPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->doubleSpinBoxFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->doubleSpinBoxHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->doubleSpinBoxSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
            ui->doubleSpinBoxSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

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
        ui->lineEditSend->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

        ui->pushButtonPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoScale->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonSend->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonTest->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoReserve->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->pushButtonAutoWideReserve->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

        ui->comboBoxOutData->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxRefSource->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxFilterSlope->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputSignal->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxSensivitity->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxTimeConstant->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxAdvancedFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxRefTriggerMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputCurrentGain->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxRefTriggerOutput->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageRange->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxSynchronousFilter->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageShields->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputVoltageCoupling->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxWideReserveMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxCloseReserveMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxInputSignalZ->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->comboBoxBufferMode->setEnabled(ui->pushButtonConnect->text() == "Disconnect");

        ui->doubleSpinBoxPhase->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->doubleSpinBoxFrequency->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->doubleSpinBoxHarmonic->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->doubleSpinBoxSineAmplitude->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
        ui->doubleSpinBoxSineDCLevel->setEnabled(ui->pushButtonConnect->text() == "Disconnect");
    }
}

void MainWindow::on_pushButtonTest_clicked()
{
    try {
        ui->lineEditTest->setText(to_QString(obj.allTest()));
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

void MainWindow::on_pushButtonAutoReserve_clicked()
{
    try {
        obj.autoReserve();
        Sleep(2000);
        ui->comboBoxCloseReserveMode->setCurrentText(to_QString(obj.getCloseReserveMode()));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxCloseReserveMode_activated(const QString &arg1) {
    try {
        obj.setCloseReserveMode(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxWideReserveMode_activated(const QString &arg1)
{
    try {
        obj.setWideReserveMode(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_pushButtonAutoWideReserve_clicked()
{
    try {
        obj.autoWideReverse();
        Sleep(2000);
        ui->comboBoxWideReserveMode->setCurrentText(to_QString(obj.getWideReserveMode()));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxInputSignalZ_activated(const QString &arg1)
{
    try {
        obj.setInputSignalZ(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_comboBoxBufferMode_activated(const QString &arg1)
{
    try {
        obj.setBufferMode(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}


void MainWindow::on_doubleSpinBoxPhase_valueChanged(double arg1)
{
    try {
        obj.setInternalPhase(arg1);
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_doubleSpinBoxFrequency_valueChanged(double arg1)
{
    try {
        obj.setFrequency(arg1);
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_doubleSpinBoxHarmonic_valueChanged(double arg1)
{
    try {
        obj.setHarmonic(static_cast<int>(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_doubleSpinBoxSineAmplitude_valueChanged(double arg1)
{
    try {
        obj.setSineAmplitude(arg1);
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void MainWindow::on_doubleSpinBoxSineDCLevel_valueChanged(double arg1)
{
    try {
        obj.setSineDCLevel(arg1);
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}
