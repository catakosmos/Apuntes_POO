#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include "squarecolor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();
    void onSliderValueChanged(int value);

private:
    Ui::MainWindow *ui;
    int counter;    // counter
    SquareColor * colorSquare;
    QSlider *brightnessSlider;
};

#endif // MAINWINDOW_H
