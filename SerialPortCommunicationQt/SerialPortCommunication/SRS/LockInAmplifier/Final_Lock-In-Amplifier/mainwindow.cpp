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
    bool *succeed = nullptr;
    //Добавление моделей
    for (auto model : obj.getSupportedList()) {
        ui->comboBoxLockInAmplifierModel->addItem(to_QString(model));
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
        obj.connect("COM4","19200","8","1", "NO", "NO");
        ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));
        ui->lineEditPhase ->setText(obj.getPhase());
        ui->lineEditFrequency -> setText(obj.getFrequency());

        const int i = 5;
        if (obj.setHarmonic(i)) ui->lineEditHarmonic -> setText(obj.getHarmonic());
        else ui->lineEditHarmonic -> setText(to_QString("Lox"));
        //obj.sendCommand("HARM 3");


        //ui->lineEditHarmonic -> setText(obj.getHarmonic());
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
    obj.setInternalPhase((ui ->lineEditPhase->text()).toDouble());
    ui->lineEditPhase ->setText(obj.getPhase());
}
