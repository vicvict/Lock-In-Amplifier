#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../lockinamplifier.h"
//Задача: сделать выпадающие порты
//Проблема: не дочитывает сообщения до конца
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string model;
    bool *succeed =nullptr;
    //Добавление моделей
    for (auto model : obj.getSupportedList()) {
        ui->comboBoxLockInAmplifierModel->addItem(to_QString(model));
    }

    try {
        model = obj.detect("COM5", succeed);
        obj.connect("COM5");
        ui->lineEditPhase ->setText(QString(obj.getIDN().c_str()));
        ui->lineEditFrequency ->setText(to_QString(obj.getPortName() + " " + obj.getBaudRate() + " " + obj.getDataBits() + " " + obj.getStopBits() + " " + obj.getFlowControl() + " " + obj.getParity()));
        ui->lineEditResponse->setText(obj.getFrequency());
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString(s));
    }

    /*std:: string my_model = "Stanford_Research_Systems,SR844,s/n49922,ver1.006";
    if (my_model.find("SR844") != std:: string:: npos) ui->lineEditResponse->setText("success");
    else ui->lineEditResponse->setText("fail");

    try {
        obj.connect("COM4","19200","8","1", "NO", "NO");
        ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));
        ui->lineEditPhase ->setText(obj.getPhase());
        ui->lineEditHarmonic -> setText(obj.getHarmonic());
        ui->lineEditFrequency -> setText(obj.getFrequency());
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString(s));
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonPhase_clicked()
{
    obj.setInternalPhase((ui ->lineEditPhase->text()).toDouble());
    ui->lineEditPhase ->setText(obj.getPhase());
}
