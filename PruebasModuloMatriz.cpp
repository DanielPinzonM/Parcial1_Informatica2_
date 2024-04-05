#include <iostream>
#include "Matriz.h"

void PruebaModulo();

int main()
{
    PruebaModulo();

    return 0;
}

void PruebaModulo()
{
    unsigned short int Dimension = 5;

    unsigned short int** Matriz = CrearMatriz(Dimension);

    ImprimirMatriz(Matriz);

    std::cout << "\n\n";

    RotarMatriz(Matriz, 2);

    ImprimirMatriz(Matriz);

    std::cout << "\nEstado de rotacion = " << ObtenerEstadoRotacion(Matriz);

    std::cout << "\n\n";

    for (short int Fila=0; Fila<(Dimension); Fila++)
    {
        for (short int Columna=0; Columna<(Dimension); Columna++)
        {
            if (Matriz[Fila][Columna] != 0)
            {
                std::cout << "(" << ObtenerFilaOriginal(Matriz[Fila][Columna], Dimension) << ", " << ObtenerColumnaOriginal(Matriz[Fila][Columna], Dimension) << ") ";

            }
            else
            {
                std::cout << "(C,C) ";
            }
        }

        std::cout << "\n";
    }

    EliminarMatriz(Matriz);

    return;
}