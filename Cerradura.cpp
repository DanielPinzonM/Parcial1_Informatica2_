#include "Cerradura.h"
#include "Matriz.h"

unsigned short int*** CrearCerradura(unsigned short int* Fila, unsigned short int* Columna, unsigned short int NumComparaciones)
{
    unsigned short int Dimension = DimensionMinima(Fila, Columna);  //Se obtiene la dimensión mínima necesaria para las matrices

    unsigned short int*** Cerradura = new unsigned short int**[NumComparaciones+1];   //Se declara el apuntador triple y se apunta a un arreglo de punteros dobles

    for (short int Posicion=0; Posicion<(NumComparaciones+1); Posicion++)   //Se recorren las posiciones de la cerradura
    {
        Cerradura[Posicion] = CrearMatriz(Dimension);   //Se crean matrices con la dimensión mímina
    }

    return Cerradura;
}

unsigned short int DimensionMinima(unsigned short int* Fila, unsigned short int* Columna)
{
    if((*Fila) > 3 || (*Columna) > 3)   //Si la fila o columna son mayores que tres
    {
        //Se busca el mayor entre la fila y la columna

        if((*Fila) >= (*Columna))   //Si la fila es mayor o igual que la columna
        {
            if((*Fila)%2 == 0)   //Si la fila es par
            {
                return (*Fila)+1;   //Se le suma 1 para obtener un numero impar
            }
            else   //Si la fila es impar
            {
                return (*Fila);
            }
        }
        else    //Si la columna es mayor
        {
            if((*Columna)%2 == 0)   //Si la columna es mayor que la fila
            {
                return (*Columna)+1;   //Se le suma 1 para obtener un numero impar
            }
            else   //Si la columna es impar
            {
                return (*Columna);
            }
        }
    }
    else    //Si la fila y la columna son iguales o menores que tres
    {
        return 3;
    }
}

unsigned short int ObtenerDiferencia(unsigned short int DimensionM1, unsigned short int DimensionM2)
{
    //Se devueleve la diferencia entre las rotaciones de dos matrices, restando a la mayor la menor y dividiendo todo entre dos

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
        RotarMatriz(Matriz2, ObtenerEstadoRotacion(Matriz1));   //Se rota la matriz2 a la misma rotacion de la matriz1

}

void CambiarMatriz(unsigned short int** Matriz, unsigned short int Dimension)
{
    EliminarMatriz(Matriz);   
    Matriz = CrearMatriz(Dimension);
}

void EliminarCerradura(unsigned short int*** Cerradura, unsigned short int NumComparaciones)
{
    for (short int Posicion=0; Posicion<(NumComparaciones+1); Posicion++)   //Se recorre la cerradura
    {
        EliminarMatriz(Cerradura[Posicion]);   //Se elimina la matriz de cada posición de la cerradura
    }

    delete Cerradura;   //Se elimina el arreglo principal
}