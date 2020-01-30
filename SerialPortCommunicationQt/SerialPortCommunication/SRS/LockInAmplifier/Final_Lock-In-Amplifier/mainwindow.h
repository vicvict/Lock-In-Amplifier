#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../lockinamplifier.h"
#include "../../SR865/sr865.h"

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

    void on_comboBoxAdvanceFilter_activated(const QString &arg1);

    void on_comboBoxSynchronousFilter_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;

    SR865 obj;
};

#endif // MAINWINDOW_H
