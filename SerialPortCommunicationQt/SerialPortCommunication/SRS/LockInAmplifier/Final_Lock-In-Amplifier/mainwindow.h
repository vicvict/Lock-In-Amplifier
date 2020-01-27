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

private:
    Ui::MainWindow *ui;

    SR865 obj;
};

#endif // MAINWINDOW_H
