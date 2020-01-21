#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../lockinamplifier.h"

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

    try {
      //  model = obj.detect("COM7");
        ui->lineEditResponse->setText(to_QString(model));
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString(s));
    }

    try {
        obj.connect("COM7","19200","8","1", "NO", "NO");
        ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));
        ui->lineEditPhase ->setText(obj.getPhase());
        ui->lineEditHarmonic -> setText(obj.getHarmonic());
        ui->lineEditFrequency -> setText(obj.getFrequency());
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
