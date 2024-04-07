#include <iostream>
#include "Cerradura.h"
#include "Matriz.h"

void PruebaModulo();

int main()
{
    PruebaModulo();

    return 0;
}

void PruebaModulo()
{
    unsigned short int Fila=4, Columna=3;

    unsigned short int*** Cerradura = CrearCerradura(&Fila, &Columna, 3);

    ImprimirMatriz(Cerradura[0]);
    ImprimirMatriz(Cerradura[2]);

    std::cout << std::endl;

    RotarMatriz(Cerradura[0], 1);
    RotarMatriz(Cerradura[2], 3);

    ImprimirMatriz(Cerradura[0]);
    ImprimirMatriz(Cerradura[2]);

    std::cout << std::endl;

    IgualarRotacion(Cerradura[0], Cerradura[2]);

    ImprimirMatriz(Cerradura[0]);
    ImprimirMatriz(Cerradura[2]);

    CambiarMatriz(Cerradura[2], 7);

    std::cout << std::endl;

    ImprimirMatriz(Cerradura[0]);
    ImprimirMatriz(Cerradura[2]);

    EliminarCerradura(Cerradura, 3);

    return;
}