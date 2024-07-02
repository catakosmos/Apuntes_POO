#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_timbreBtn_clicked();
    void myTimeout();

private:
    Ui::MainWindow *ui;
    QGraphicsRectItem * rectangle;
    QGraphicsScene scene;
    QTimer myTimer;
};
#endif // MAINWINDOW_H