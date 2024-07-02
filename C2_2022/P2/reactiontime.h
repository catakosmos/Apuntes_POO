#ifndef REACTIONTIME_H
#define REACTIONTIME_H
#include <QWidget>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class ReactionTime; }
QT_END_NAMESPACE

class ReactionTime : public QWidget              // declara a la clase ReactionTime que hereda de QWidget
{
    Q_OBJECT  

public:                                          
    ReactionTime(QWidget *parent = nullptr);     // constructor
    ~ReactionTime();                             // destructor
public slots:                  
    void startStopTime();                        // funcion dentro de la ranura que se ejecuta cuando aprete el boton de start/stop

private:
    Ui::ReactionTime *ui;                        // puntero a la clase que gestiona la interfaz de usuario
    QTime time;                                  // mide el tiempo
    bool timeRunning;                            // indica si el cronometro está en funcionamiento
};
#endif // REACTIONTIME_H
