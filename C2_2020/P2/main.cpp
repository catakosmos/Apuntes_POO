#include <iostream>
#include "PlanDeEstudios.h"
#include "Asignatura.h"
using namespace std;

int main ( int agvc, char * argv[]) {
	PlanDeEstudios juan(argv[1]); 
	cout << "Créditos aprobados por Juan = " << juan.getTotalCreditosAprobados() << endl;
	PlanDeEstudios copiaJuan = juan;
	((Asignatura *)copiaJuan[1])->setNota(20);
	cout << "Créditos aprobados por Juan = " << juan.getTotalCreditosAprobados() << endl;	
}