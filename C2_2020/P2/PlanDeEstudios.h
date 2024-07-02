#ifndef PLAN_DE_ESTUDIOS_H
#define PLAN_DE_ESTUDIOS_H
#include <vector>
#include <string>
#include "Ramo.h"
using namespace std;

class PlanDeEstudios {
private:
	vector<Ramo *> plan;
public:
	PlanDeEstudios(){};
	PlanDeEstudios(string file);
	int getTotalCreditosAprobados();
	Ramo * operator[](int i);
};
#endif