#include <iostream>
#include "Matriz.h"

int main()
{
    unsigned short int Dimension = 5;

    unsigned short int** Matriz = CrearMatriz(&Dimension);

    ImprimirMatriz(Matriz, &Dimension);

    std::cout << "\n\n";

    RotarMatriz(Matriz, &Dimension, 2);

    ImprimirMatriz(Matriz, &Dimension);

    std::cout << "\nEstado de rotacion = " << ObtenerEstadoRotacion(Matriz, &Dimension);

    EliminarMatriz(Matriz, &Dimension);

    return 0;
}