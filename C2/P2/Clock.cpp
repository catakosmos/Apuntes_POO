#include "Clock.h"

Clock::Clock(int pHour, int pMinute, int pSecond) { // Parámetros
	hour = pHour;                                     // Atributos a los que se asignan los parámetros
	minute = pMinute;
	second = pSecond;
}

void Clock::setHour(int pHour) {                // Métodos que establecen los valores
	hour = pHour;
}

void Clock::setMinute(int pMinute) {
	minute = pMinute;
}

void Clock::setSecond(int pSecond) {
	second = pSecond;
}

void Clock::tick()                               // Método tick: simula el avance del reloj
{
	if (second < 59) {
		second++;
	}
	else if (minute < 59)
	{
		minute++;
		second = 0;
	}
	else if (hour < 23)
	{
		hour++;
		minute = 0;
		second = 0;
	}
	else 
    {
		hour = 0;
		minute = 0;
		second = 0;
	}
	
}
void Clock::showTime() {                            // Método que imprime por consola la hora actual
	cout << endl << hour << " " << minute <<" " << second << endl <<endl;
}
