#ifndef SR844GRAPHICS_H
#define SR844GRAPHICS_H

#include <QMainWindow>
#include "../../lockinamplifier.h"
#include "../../SR844/sr844.h"


namespace Ui {
class SR844Graphics;
}

class SR844Graphics : public QMainWindow
{
    Q_OBJECT

public:
    explicit SR844Graphics(QWidget *parent = nullptr);
    ~SR844Graphics();

private slots:
    void on_comboBoxRefSource_activated(const QString &arg1);

    void on_pushButtonHarmonic_clicked();

    void on_pushButtonFrequency_clicked();

    void on_pushButtonPhase_clicked();

    void on_pushButtonAutoPhase_clicked();

    void on_comboBoxRefTriggerOutput_activated(const QString &arg1);

    void on_pushButtonAutoWideReverse_clicked();

    void on_comboBoxRefTriggerInputSignalZ_activated(const QString &arg1);

    void on_comboBoxInputSensitivity_activated(const QString &arg1);

    void on_pushButtonAutoScale_clicked();

    void on_pushButtonAutoReserve_clicked();

    void on_comboBoxCloseTimeConstant_activated(const QString &arg1);

    void on_comboBoxFilterSlope_activated(const QString &arg1);

private:
    Ui::SR844Graphics *ui;

    SR844 obj;
};

#endif // SR844GRAPHICS_H
