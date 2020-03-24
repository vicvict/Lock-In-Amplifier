#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "finallockinamplifier.h"

#include "windows.h"

#include <QTest>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAutoPhase_clicked();

    void on_comboBoxTimeConstant_activated(const QString &new_text);

    void on_comboBoxRefSource_activated(const QString &arg1);

    void on_comboBoxRefTriggerMode_activated(const QString &arg1);

    void on_comboBoxRefTriggerOutput_activated(const QString &arg1);

    void on_comboBoxInputSignal_activated(const QString &arg1);

    void on_comboBoxInputVoltageMode_activated(const QString &arg1);

    void on_pushButtonAutoRange_clicked();

    void on_pushButtonAutoScale_clicked();

    void on_comboBoxInputVoltageCoupling_activated(const QString &arg1);

    void on_comboBoxInputVoltageShields_activated(const QString &arg1);

    void on_comboBoxInputVoltageRange_activated(const QString &arg1);

    void on_comboBoxInputCurrentGain_activated(const QString &arg1);

    void on_comboBoxSensivitity_activated(const QString &arg1);

    void on_comboBoxFilterSlope_activated(const QString &arg1);

    void on_comboBoxAdvancedFilter_activated(const QString &arg1);

    void on_comboBoxSynchronousFilter_activated(const QString &arg1);

    void on_comboBoxOutData_activated(const QString &arg1);

    void on_pushButtonOutData_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonTest_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButtonAutoReserve_clicked();

    void on_comboBoxCloseReserveMode_activated(const QString &arg1);

    void on_comboBoxWideReserveMode_activated(const QString &arg1);

    void on_pushButtonAutoWideReserve_clicked();

    void on_comboBoxInputSignalZ_activated(const QString &arg1);

    void on_comboBoxBufferMode_activated(const QString &arg1);

    void on_doubleSpinBoxPhase_valueChanged(double arg1);

    void on_doubleSpinBoxFrequency_valueChanged(double arg1);

    void on_doubleSpinBoxHarmonic_valueChanged(double arg1);

    void on_doubleSpinBoxSineAmplitude_valueChanged(double arg1);

    void on_doubleSpinBoxSineDCLevel_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

    finalLockInAmplifier obj;

    //Флаг того, что соответствующий spinbox инициализирован. Нужен для корректной обработки события
    //valueChanged()
    bool phaseInitFlag = false;
    bool freqInitFlag = false;
    bool harmInitFlag = false;
    bool amplInitFlag = false;
    bool dcLevelInitFlag = false;
};

#endif // MAINWINDOW_H
