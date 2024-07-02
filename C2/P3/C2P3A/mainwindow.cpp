#include "mainwindow.h"                // Incluye el archivo de encabezado para la clase MainWindow
#include "ui_mainwindow.h"             // Incluye el archivo de interfaz de usuario generado para la clase MainWindow.
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)    // Constructor de la clase MainWindow
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);                     // Inicializa la interfaz de usuario utilizando el método setupUi()
}

MainWindow::~MainWindow() {                // Destructor de la clase MainWindow cuando se destruye el objeto
    delete ui;
}

void MainWindow::on_timbreBtn_clicked()    // Cuando se hace clic en el botón, esta función se ejecutará.
{
    cout << "Timbre accionado" << endl;    // Muestra "Timbre accionado" en la consola cuando se hace clic en el botón
}
