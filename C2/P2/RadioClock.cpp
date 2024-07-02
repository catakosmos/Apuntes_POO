#include "RadioClock.h"

RadioClock::RadioClock(int pHour, int pMinute, int pSecond, bool pPower, bool pStatus) : Radio(pPower), Clock(pHour, pMinute, pSecond)
{		
	status = pStatus;
} // Constructor que inicializa con una hora, minuto y segundo dados además del estado de encendido de la radio y el estado del reloj, llama a los constructores de clock y radio

void RadioClock::setAlarm(int pHour, int pMinute, int pSecond)
{
	a_Hour = pHour;
	a_Minute = pMinute;
	a_Second = pSecond;
} // Establece la hora, minuto y segundo de la alarma

void RadioClock::switch_Alarm()
{
	status = !status;
} // Activa o desactiva la alarma

bool RadioClock::verify_Alarm()
{
	if (hour == a_Hour && minute == a_Minute && second == a_Second) {
		activate_Alarm();
		switch_Alarm();
		return true;
	}
	return false;
} // Verifica si la hora actual coincide con la hora de la alarma. Si es así, activa la alarma y cambia su estado

void RadioClock::activate_Alarm()
{
	if (power==false)	
		switch_Radio();
	
	for (int i = 0; i < 20; i++) 
		cout << "Beep!" <<endl;	
} // activa la alarma, encendiendo la radio si está apagada y emitiendo un sonido de "Beep!" 20 veces
