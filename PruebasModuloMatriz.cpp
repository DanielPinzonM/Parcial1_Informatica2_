#include <iostream>
#include "Matriz.h"

int main()
{
    PruebaModulo();

    return 0;
}

void PruebaModulo()
{
    unsigned short int Dimension = 5;

    unsigned short int** Matriz = CrearMatriz(&Dimension);

    ImprimirMatriz(Matriz, &Dimension);

    std::cout << "\n\n";

    RotarMatriz(Matriz, &Dimension, 1);

    ImprimirMatriz(Matriz, &Dimension);

    std::cout << "\nEstado de rotacion = " << ObtenerEstadoRotacion(Matriz, &Dimension);

    std::cout << "\n\n";

    for (short int Fila=0; Fila<(Dimension); Fila++)
    {
        for (short int Columna=0; Columna<(Dimension); Columna++)
        {
            if (Matriz[Fila][Columna] != 0)
            {
                std::cout << "(" << ObtenerFilaOriginal(Matriz[Fila][Columna], &Dimension) << ", " << ObtenerColumnaOriginal(Matriz[Fila][Columna], &Dimension) << ") ";

            }
            else
            {
                std::cout << "(C,C) ";
            }
        }

        std::cout << "\n";
    }

    EliminarMatriz(Matriz, &Dimension);

    return;
}