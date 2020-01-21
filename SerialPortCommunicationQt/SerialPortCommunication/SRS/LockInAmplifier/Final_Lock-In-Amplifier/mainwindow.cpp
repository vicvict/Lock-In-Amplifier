#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../SRS.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SRS obj;
    std::string model;

    try {
//        model = obj.detect("COM7", sucseed);
        ui->lineEditResponse->setText(to_QString(model));
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString(s));
    }

    try {
        obj.connect("COM7", "19200", "8", "1", "NO", "NO");
        ui->lineEditResponse->setText(QString(obj.getIDN().c_str()));
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString("fail"));
    }

    QString my_command = "OFLT " + QString::number(7);
    std::string my_response;
    std::string command_s = to_StdString(my_command);
    std::string command = "OFLT?";
    try {
        obj.sendCommand("OFLT 3");
        obj.sendCommand("SCAL 4");
        ui->lineEditResponse->setText(to_QString(obj.ask("FREQ?").c_str()));
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString("kek"));
    }

    /*try {
        obj.sendQuery(command, my_response, "\n");
        ui->lineEditResponse->setText(to_QString(my_response));
    } catch (std:: string s) {
        ui->lineEditResponse->setText(to_QString(s));
    }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

