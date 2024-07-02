#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "Ramo.h"

class Asignatura: public Ramo {
private:
	int nota;
public:
	Asignatura(int cred=0, int n=0): Ramo(cred), nota(n){};
	int getNota() { return nota;};
	void setNota(int n) { nota=n;};
	virtual bool estaAprobada() { return nota >=55;};
};
#endif