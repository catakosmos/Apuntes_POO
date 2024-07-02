#include "Matriz2x2.h"
Matriz2x2 Matriz2x2::operator * (const Matriz2x2 &B) const {   // Define el operador de multiplicación * que toma una referencia constante a otra Matriz2x2 y retorna una nueva instancia de Matriz2x2. La función es constante, lo que significa que no modifica los miembros de la clase.
    Matriz2x2 temp;                                            // Declara una instancia temporal de Matriz2x2 que almacenará el resultado de la multiplicación.
    for (int k = 0; k<2; k++)                                  // Implementan la multiplicación de matrices utilizando tres bucles anidados.
        for (int i = 0; i<2; i++)
            for (int j = 0; j<2; j++)
                temp.values[i][j] += values[i][k] * B.values[k][j];
    return temp;
}

  Matriz2x2 Matriz2x2::operator + (const Matriz2x2 &B) const {  // Define el operador de suma + que toma una referencia constante a otra Matriz2x2 y retorna una nueva instancia de Matriz2x2. La función es constante, lo que significa que no modifica los miembros de la clase.
    Matriz2x2 temp;                                             // Declara una instancia temporal de Matriz2x2 que almacenará el resultado de la suma.
    for (int i = 0; i<2; i++)                                   // Implementan la suma de matrices utilizando dos bucles anidados.
        for (int i = 0; i<2; i++)
        for (int j = 0; j<2; j++)
            temp.values[i][j] = values[i][j] + B.values[i][j];
    return temp;
}

ostream & operator << (ostream &os, const Matriz2x2 &A) {  // Define el operador de inserción << que toma una referencia a un flujo de salida (ostream) y una referencia constante a una Matriz2x2. Devuelve una referencia al flujo de salida.
    for (int i = 0; i<2; i++) {                            // Implementa la lógica para imprimir la matriz
        for (int j = 0; j<2; j++)
            os <<" "<< A.values[i][j];
        os <<"\n";
    }
  return os;
}
