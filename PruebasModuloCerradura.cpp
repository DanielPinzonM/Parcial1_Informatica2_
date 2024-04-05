#include <iostream>
#include "Cerradura.h"
#include "Matriz.h"

int main()
{
    PruebaModulo();

    return 0;
}

void PruebaModulo()
{
    unsigned short int Fila=4, Columna=3;

    unsigned short int Dimension = ObtenerDimension(&Fila, &Columna);

    unsigned short int*** Cerradura = CrearCerradura(&Dimension, 3);

    EliminarCerradura(Cerradura, &Dimension, 3);

    return;
}