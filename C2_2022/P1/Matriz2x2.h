#ifndef MATRIZ2x2_H
#define MATRIZ2x2_H
#include <iostream>
using namespace std;

class Matriz2x2 {
public: 
    Matriz2x2(){                                     // Constructor por defecto de la clase Matriz2x2. Inicializa todos los valores de la matriz a 0.
        for (int i = 0; i<2; i++)
            for (int j = 0; j<2; j++)
                values[i][j] = 0;
    }
    Matriz2x2(int a11, int a12, int a21, int a22){   // Constructor sobrecargado que permite inicializar la matriz con valores específicos proporcionados como argumentos.
        values[0][0] = a11;
        values[0][1] = a12;
        values[1][0] = a21;
        values[1][1] = a22;
    }
    Matriz2x2 operator * (const Matriz2x2 &) const;    // Declara el operador de multiplicación
    Matriz2x2 operator + (const Matriz2x2 &) const;    // Declara el operador de suma
    friend ostream & operator<< (ostream &, const Matriz2x2 &);   // Declara el operador de inserción como una función amiga para que la funcion pueda acceder a los privs de Matriz2x2.
private:  
        int values[2][2];                               // Matriz privada de enteros de 2x2 que almacena los valores de la matriz.
};

#endif
