#include "reactiontime.h"
#include "ui_reactiontime.h"

ReactionTime::ReactionTime(QWidget *parent) // constructor de la clase ReactionTime
    : QWidget(parent)
    , ui(new Ui::ReactionTime)
{
    ui->setupUi(this);
    timeRunning=false;   
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(startStopTime())); 

void ReactionTime::startStopTime() {                                             // controla el inicio y la parada del cronómetro
    if(timeRunning) {                                                            // comprueba si el cronómetro está en funcionamiento
        ui->reactionLabel->setText(QString::number(time.elapsed())+" [ms]");     // actualiza el texto con el tiempo transcurrido desde que se inició el cronómetro   
        ui->startButton->setText("Start");                                       // cambia el texto del botón a start
    } else  {
        time.restart();                                                          // reinicia el cronometro
        ui->reactionLabel->setText("....  [ms]");                                // actualiza el texto
        ui->startButton->setText("Stop");                                        // cambia el texto del botón a stop
    }  
    timeRunning=!timeRunning;                                                    // alterna el estado de timeRunning
}

ReactionTime::~ReactionTime()                  // destructor de la clase ReactionTime
{
    delete ui;
}
