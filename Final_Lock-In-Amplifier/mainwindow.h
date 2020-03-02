#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "finallockinamplifier.h"

#include "windows.h"

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
    void on_pushButtonPhase_clicked();

    void on_pushButtonHarmonic_clicked();

    void on_pushButtonFrequency_clicked();

    void on_pushButtonSineAmplitude_clicked();

    void on_pushButtonAutoPhase_clicked();

    void on_pushButtonSineDCLevel_clicked();

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

    void on_doubleSpinBoxPhase_valueChanged(const QString &arg1);

    void on_doubleSpinBoxPhase_valueChanged(double arg1);

    void on_doubleSpinBoxPhase_editingFinished();

    void on_doubleSpinBoxFrequency_valueChanged(double arg1);

    void on_doubleSpinBoxHarm_valueChanged(double arg1);

    void on_doubleSpinBoxAmplitude_valueChanged(double arg1);

    void on_doubleSpinBoxDCLevel_valueChanged(double arg1);

    void on_doubleSpinBoxHarmonic_valueChanged(double arg1);

    void on_doubleSpinBoxSineAmplitude_valueChanged(double arg1);

    void on_doubleSpinBoxSineDCLevel_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

    finalLockInAmplifier obj;
};

#endif // MAINWINDOW_H
