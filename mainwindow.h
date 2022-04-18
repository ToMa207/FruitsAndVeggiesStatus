#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "statuswidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const int lowThreshold = 100;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setAppleCount(int count);
    void setOrangeCount(int count);
    void setCarrotCount(int count);
    void setCucumberCount(int count);

private slots:
    void on_applesSpinBox_valueChanged(int value);

    void on_orangesSpinBox_valueChanged(int value);

    void on_carrotsSpinBox_valueChanged(int value);

    void on_cucumbersSpinBox_valueChanged(int value);

    void on_Quit_Button_clicked();

private:
    Ui::MainWindow *ui;
    StatusWidget *fruitStatus;
    StatusWidget *appleStatus;
    StatusWidget *orangeStatus;
    StatusWidget *vegetableStatus;
    StatusWidget *carrotStatus;
    StatusWidget *cucumberStatus;
    int appleCount;
    int orangeCount;
    int carrotCount;
    int cucumberCount;
};
#endif // MAINWINDOW_H
