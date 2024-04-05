#include "Cerradura.h"
#include "Matriz.h"

unsigned short int*** CrearCerradura(unsigned short int *Dimension, unsigned short int NumComparaciones)
{
    unsigned short int*** Cerradura = new unsigned short int**[NumComparaciones+1];

    for (short int Posicion=0; Posicion<(NumComparaciones+1); Posicion++)
    {
        Cerradura[Posicion] = CrearMatriz(Dimension);
    }

    return Cerradura;
}

unsigned short int ObtenerDimension(unsigned short int* Fila, unsigned short int* Columna)
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

void EliminarCerradura(unsigned short int*** Cerradura,unsigned short int *Dimension , unsigned short int NumComparaciones)
{
    for (short int Posicion=0; Posicion<(NumComparaciones+1); Posicion++)
    {
        EliminarMatriz(Cerradura[Posicion], Dimension);
    }

    delete Cerradura;
}