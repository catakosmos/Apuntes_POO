#include <iostream>
#include "RadioClock.h"
using namespace std;

int main()
{	
	int hour = 11, minute = 25, second = 15;
	int a_hour = 13, a_minute = 26, a_second = 16;
	
	RadioClock radioAlarma(hour, minute, second, true, true);  // HORA ACTUAL  
	radioAlarma.setAlarm(a_hour, a_minute, a_second);	    // establece la hora de la alarma

	while (!radioAlarma.verify_Alarm()) {                 // verifica continuamente si es necesario activar la alarma
		radioAlarma.tick();
		radioAlarma.showTime();
	}
	return 0;
}
