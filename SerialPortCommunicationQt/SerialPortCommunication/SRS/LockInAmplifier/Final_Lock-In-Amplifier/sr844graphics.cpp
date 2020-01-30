#include "sr844graphics.h"
#include "ui_sr844graphics.h"
#include "../lockinamplifier.h"

SR844Graphics::SR844Graphics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SR844Graphics)
{
    ui->setupUi(this);

    for (auto refSource : obj.getRefSourceList()) {
        ui->comboBoxRefSource->addItem(to_QString(refSource));
    }

    //Добавление ref trigger output
    for (auto refTriggerOutput : obj.getRefTriggerOutputList()) {
        ui->comboBoxRefTriggerOutput->addItem(to_QString(refTriggerOutput));
    }

    //Добавление input signal Z
    for (auto inputSignalZ : obj.getInputSignalZList()) {
        ui->comboBoxInputSignalZ->addItem(to_QString(inputSignalZ));
    }

    //Добавление sensitivity
    for (auto sensitivity : obj.getSensitivityList()) {
        ui->comboBoxSensitivity->addItem(to_QString(sensitivity));
    }

    //Добавление close reserve mode
    for (auto closeReserveMode : obj.getCloseReserveModeList()) {
        ui->comboBoxCloseReserveMode->addItem(to_QString(closeReserveMode));
    }

    //добавление Time constant
    for (auto timeConstant : obj.getTimeConstantList()) {
        ui->comboBoxTimeConstant->addItem(to_QString(timeConstant));
    }

    //добавление filter slope
    for (auto filterSlope : obj.getFilterSlopeList()) {
        ui->comboBoxFilterSlope->addItem(to_QString(filterSlope));
    }

    try {
        obj.connect("COM7","9600","8","1", "NO", "NO");
        ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));
        ui->lineEditPhase ->setText(to_QString(obj.getPhase()));
        ui->lineEditFrequency -> setText(to_QString(obj.getFrequency()));
        ui->lineEditHarmonic -> setText(to_QString(obj.getHarmonic()));
        //ui->lineEditSineAmplitude -> setText(to_QString(obj.getSineAmplitude()));
        //ui->lineEditSineDCLevel -> setText(to_QString(obj.getSineDCLevel()));
        ui->comboBoxTimeConstant -> setCurrentText(to_QString(obj.getTimeConstant()));
        ui->comboBoxRefSource -> setCurrentText(to_QString(obj.getRefSource()));
        //ui->comboBoxRefTriggerMode -> setCurrentText(to_QString(obj.getRefTriggerMode()));
        ui->comboBoxRefTriggerOutput -> setCurrentText(to_QString(obj.getRefTriggerOutput()));
        //ui->comboBoxInputSignal -> setCurrentText(to_QString(obj.getInputSignal()));
        //ui->comboBoxInputVoltageMode -> setCurrentText(to_QString(obj.getInputVoltageMode()));
        //ui->comboBoxInputVoltageCoupling -> setCurrentText(to_QString(obj.getInputVoltageCoupling()));
        //ui->comboBoxInputVoltageShields -> setCurrentText(to_QString(obj.getInputVoltageShields()));
        //ui->comboBoxInputVoltageRange -> setCurrentText(to_QString(obj.getInputVoltageRange()));
        //ui->comboBoxInputCurrentGain -> setCurrentText(to_QString(obj.getInputCurrentGain()));
        //ui->lineEditSignalStrength->setText(to_QString(obj.getSignalStrength()));
        ui->comboBoxSensitivity -> setCurrentText(to_QString(obj.getSensitivity()));
        ui->comboBoxFilterSlope -> setCurrentText(to_QString(obj.getFilterSlope()));
        //ui->comboBoxSynchronousFilter -> setCurrentText(to_QString(obj.getSynchronousFilter()));
        //ui->comboBoxAdvanceFilter -> setCurrentText(to_QString(obj.getAdvanceFilter()));
        ui->comboBoxInputSignalZ-> setCurrentText(to_QString(obj.getInputSignalZ()));
        ui->comboBoxCloseReserveMode-> setCurrentText(to_QString(obj.getCloseReserveMode()));

    } catch (std:: string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

SR844Graphics::~SR844Graphics()
{
    delete ui;
}

void SR844Graphics::on_comboBoxRefSource_activated(const QString &arg1) {
    try {
        obj.setRefSource(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}
void SR844Graphics::on_pushButtonHarmonic_clicked(){
    bool succeed;
    ui->lineEditHarmonic->text().toInt(&succeed);
    if (succeed) {
        obj.setHarmonic(ui->lineEditHarmonic->text().toInt(&succeed));
    }
    else {
        //do nothing
    }
}

void SR844Graphics::on_pushButtonFrequency_clicked()
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

void SR844Graphics::on_pushButtonPhase_clicked(){
    bool succeed;
    ui->lineEditPhase->text().toDouble(&succeed);
    if (succeed) {
        obj.setInternalPhase(ui->lineEditPhase->text().toDouble(&succeed));
    }
    else {
        //do nothing
    }
}

void SR844Graphics::on_pushButtonAutoPhase_clicked(){
    if (obj.autoPhase()) ui->lineEditPhase->setText(to_QString(obj.getPhase()));
    else {
        //do nothing
    }
}

void SR844Graphics::on_comboBoxRefTriggerOutput_activated(const QString &arg1){
    try {
        obj.setRefTriggerOutput(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void SR844Graphics::on_pushButtonAutoWideReverse_clicked(){
    obj.autoWideReverse();
}

void SR844Graphics::on_comboBoxRefTriggerInputSignalZ_activated(const QString &arg1)
{
    try {
        obj.setInputSignalZ(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}


void SR844Graphics::on_comboBoxInputSensitivity_activated(const QString &arg1) {
    try {
        obj.setSensitivity(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void SR844Graphics::on_pushButtonAutoScale_clicked() {
    if (obj.autoScale()) ui->comboBoxSensitivity -> setCurrentText(to_QString(obj.getSensitivity()));
    else {
        //do nothing
    }
}

void SR844Graphics::on_pushButtonAutoReserve_clicked() {
    if (obj.autoReserve()) ui->comboBoxCloseReserveMode -> setCurrentText(to_QString(obj.getCloseReserveMode()));
    else {
        //do nothing
    }
}

void SR844Graphics::on_comboBoxCloseTimeConstant_activated(const QString &arg1) {
    try {
        obj.setTimeConstant(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}

void SR844Graphics::on_comboBoxFilterSlope_activated(const QString &arg1) {
    try {
        obj.setFilterSlope(to_StdString(arg1));
    } catch (std::string s) {
        ui->lineEditError->setText(to_QString(s));
    }
}
