#include "Cerradura.h"
#include "Matriz.h"

unsigned short int*** CrearCerradura(unsigned short int* Fila, unsigned short int* Columna, unsigned short int NumComparaciones)
{
    unsigned short int Dimension = DimensionMinima(Fila, Columna);

    unsigned short int*** Cerradura = new unsigned short int**[NumComparaciones+1];

    for (short int Posicion=0; Posicion<(NumComparaciones+1); Posicion++)
    {
        Cerradura[Posicion] = CrearMatriz(Dimension);
    }

    return Cerradura;
}

unsigned short int DimensionMinima(unsigned short int* Fila, unsigned short int* Columna)
{
    if((*Fila) > 3 || (*Columna) > 3)
    {
        if((*Fila) >= (*Columna))
        {
            if((*Fila)%2 == 0)
            {
                return (*Fila)+1;
            }
            else
            {
                return (*Fila);
            }
        }
        else
        {
            if((*Columna)%2 == 0)
            {
                return (*Columna)+1;
            }
            else
            {
                return (*Columna);
            }
        }
    }
    else
    {
        return 3;
    }
}

unsigned short int ObtenerDiferencia(unsigned short int DimensionM1, unsigned short int DimensionM2)
{
    if (DimensionM1 > DimensionM2)
    {
        return (DimensionM1-DimensionM2)/2;
    }
    else
    {
        return (DimensionM2-DimensionM1)/2;
    }
}

void IgualarRotacion(unsigned short int** Matriz1, unsigned short int** Matriz2)
{
        RotarMatriz(Matriz2, ObtenerEstadoRotacion(Matriz1));

}

void EliminarCerradura(unsigned short int*** Cerradura, unsigned short int NumComparaciones)
{
    for (short int Posicion=0; Posicion<(NumComparaciones+1); Posicion++)
    {
        EliminarMatriz(Cerradura[Posicion]);
    }

    delete Cerradura;
}