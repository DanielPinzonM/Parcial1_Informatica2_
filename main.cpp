#include <iostream>
#include "Matriz.h"

int main()
{
    unsigned short int Dimension = 7;

    unsigned short int** Matriz = CrearMatriz(&Dimension);

    for (short int Fila=0; Fila<(Dimension); Fila++)
    {
        for (short int Columna=0; Columna<(Dimension); Columna++)
        {
            std::cout << Matriz[Fila][Columna] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}
