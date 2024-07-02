#pragma once
#include <iostream>

class Radio
{
protected:		
	bool power;

public:
	Radio(bool pPower);     // constructor de la clase que inicializa el atributo power
	void switch_Radio();    // método que cambia el estado de encendido/apagado de la radio al negar el valor de power
};
