#pragma once
#include "Radio.h"
#include "Clock.h"
#include <iostream>
using namespace std;

class RadioClock : public Radio, public Clock
{
private:
// Almacenar la hora, minuto y segundo de la alarma respectivamente:
	int a_Hour;
	int a_Minute;
	int a_Second;
// Indica el estado de la alarma
	bool status;
// Método que activa la alarma
	void activate_Alarm();

public:
// inicializa la clase RadioClock con la hora, minuto, segundo, estado de encendido de la radio y estado de la alarma
	RadioClock(int pHour, int pMinute, int pSecond, bool pPower, bool pStatus); 
	void setAlarm(int pHour, int pMinute, int pSecond);  // Establece el estado de la alarma
	void switch_Alarm();                                 // Cambia el estado de la alarma  
	bool verify_Alarm();	                               // Verifica si la alarma debe activarse 
};
