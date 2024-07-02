#include <iostream>
#include "Matriz2x2.h"
using namespace std;

int main(void) {
   Matriz2x2 A(2,4,5,7), B(-3,9,2,8), C;    // declara e inicializa 3 instancias de la matriz
   C = A*B;                                 // multiplica las matrices y los asigna a C
   cout << C;                               // imprime C con su nuevo valor  
   cout << A+B;                             // Suma A + B e imprime su resultado
}

/* output esperado
   2 50
  -1 101
  -1 13
  7 15
*/
