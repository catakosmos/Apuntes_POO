#include <fstream>
#include <vector>
#include "PlanDeEstudios.h"
#include "Asignatura.h"

PlanDeEstudios::PlanDeEstudios(string fileName){
	int nRamos, creditos, nota;
	
	ifstream file(fileName);
	file >> nRamos;  // número de ramos del archivo
	for (int i=0; i< nRamos; i++){
		file >> creditos >> nota;
		plan.push_back(new Asignatura(creditos, nota));		
	}
}

int PlanDeEstudios::getTotalCreditosAprobados(){
	int nc=0;
	for (int i=0; i<plan.size(); i++)
		if (plan[i]->estaAprobada())
			nc+=plan[i]->getCreditos();
	return nc;
}

Ramo * PlanDeEstudios::operator[](int i){
	return plan[i];
}