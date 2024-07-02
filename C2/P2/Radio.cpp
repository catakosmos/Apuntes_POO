#include "Radio.h"

Radio::Radio(bool pPower)      // incializa el atributo power
{
	power = pPower;  
}

void Radio::switch_Radio()      // cambia el estado de encendido/apagado al negar el valor actual de power
{
	power = !power;
}
