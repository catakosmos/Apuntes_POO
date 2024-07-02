#ifndef RAMO_H
#define RAMO_H

class Ramo {
private:
	const int creditos;
public:
	Ramo(int c=0): creditos(c){};
	int getCreditos() {return creditos;};
	virtual bool estaAprobada()=0;
};
#endif