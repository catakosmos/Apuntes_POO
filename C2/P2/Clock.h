#pragma once                      //  asegura que el contenido del archivo de inclusión solo se incluya una vez en un programa
#include <iostream>
using namespace std;

class Clock
{
protected:                        // atributos protegidos
	int hour;
	int minute;
	int second;

public:                            
	Clock(int pHour, int pMinute, int pSecond);    // constructor de la clase, inicializa los atributos
	void setHour(int pHour);
	void setMinute(int pMinute);
	void setSecond(int pSecond);
	void tick();                      // simula el avance del tiempo  
	void showTime();                  // muestra por consola el reloj
};
