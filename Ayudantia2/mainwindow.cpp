#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
# include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , counter(0)
{
    ui->setupUi(this);

    // create square and append to layout:
    colorSquare = new SquareColor(this);
    colorSquare->setFixedSize(500, 350);
    ui->verticalLayout->addWidget(colorSquare);

    // create slider and append to layout:
    brightnessSlider = new QSlider(Qt::Horizontal, this);
    brightnessSlider->setRange(0, 255);  // Range from 0 (dark) to 255 (light)
    brightnessSlider->setValue(255);     // Default value for full brightness
    brightnessSlider->setFixedSize(500, 30);
    ui->verticalLayout->addWidget(brightnessSlider);

    resize(600, 500 + ui->pushButton->height() + brightnessSlider->height());  // ajustar ventana

    // connect button to slot to change square color:
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->pushButton, &QPushButton::clicked, colorSquare, &SquareColor::changeColor);

    // connect progress bar value change to slot:
    connect(brightnessSlider, &QSlider::valueChanged, this, &MainWindow::onSliderValueChanged);

    // initial background setup:
    onSliderValueChanged(brightnessSlider->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked(){
    counter++;
    ui->label->setText(QString::number(counter));
}

void MainWindow::onSliderValueChanged(int value) {
    // Calculate the color for the background
    QColor backgroundColor = QColor::fromRgb(value, value, value); // Shades of gray
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, backgroundColor); // Set background color
    this->setPalette(palette);
}
