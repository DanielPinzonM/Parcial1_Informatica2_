#include <iostream>
#include "Matriz.h"

unsigned short int** CrearMatriz(unsigned short int* Dimension)
{
    unsigned short int** Matriz;
    Matriz = new unsigned short int*[*Dimension];

    for (short int Fila=1; Fila<=((*Dimension)/2)+1; Fila++)
    {
        if (Fila != ((*Dimension)/2)+1)
        {
            Matriz[Fila-1] = new unsigned short int[*Dimension];
            Matriz[(*Dimension)-Fila] = new unsigned short int[*Dimension];

            for  (short int Columna=1; Columna<=(*Dimension); Columna++)
            {
                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(Fila, Columna, Dimension);
                Matriz[(*Dimension)-Fila][(*Dimension)-Columna] = ObtenerValorCasilla( (*Dimension)-Fila+1, (*Dimension)-Columna+1, Dimension);
            }
        }
        else
        {
            Matriz[Fila-1] = new unsigned short int[*Dimension];

            for (short int Columna=1; Columna<=((*Dimension)/2); Columna++)
            {
                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(Fila, Columna, Dimension);
                Matriz[(*Dimension)-Fila][(*Dimension)-Columna] = ObtenerValorCasilla( (*Dimension)-Fila+1, (*Dimension)-Columna+1, Dimension);
            }
        }
    }

    Matriz[((*Dimension)/2)][((*Dimension)/2)] = 0;

    return Matriz;
}

void RotarMatriz(unsigned short int** Matriz, unsigned short int* Dimension, unsigned short int CantRotaciones)
{
    for (short int Fila=1; Fila<=((*Dimension)/2)+1; Fila++)
    {
        if (Fila < ((*Dimension)/2)+1)
        {
            for (short int Columna=1; Columna<=(*Dimension); Columna++)
            {
                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(TransformarFila(Fila, Columna, Dimension, &CantRotaciones), TransformarColumna(Fila, Columna, Dimension, &CantRotaciones), Dimension);
                Matriz[(*Dimension)-Fila][(*Dimension)-Columna] = ObtenerValorCasilla(TransformarFila((*Dimension)-Fila+1, (*Dimension)-Columna+1, Dimension, &CantRotaciones), TransformarColumna((*Dimension)-Fila+1, (*Dimension)-Columna+1, Dimension, &CantRotaciones), Dimension);
            }
        }
        else
        {
            for (short int Columna=1; Columna<=((*Dimension)/2); Columna++)
            {
                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(TransformarFila(Fila, Columna, Dimension, &CantRotaciones), TransformarColumna(Fila, Columna, Dimension, &CantRotaciones), Dimension);
                Matriz[(*Dimension)-Fila][(*Dimension)-Columna] = ObtenerValorCasilla(TransformarFila((*Dimension)-Fila+1, (*Dimension)-Columna+1, Dimension, &CantRotaciones), TransformarColumna((*Dimension)-Fila+1, (*Dimension)-Columna+1, Dimension, &CantRotaciones), Dimension);
            }
        }
    }
}

unsigned short int ObtenerEstadoRotacion(unsigned short int** Matriz, unsigned short int* Dimension)
{
    if (Matriz[0][0] == 1)
    {
        return 0;
    }
    else if (Matriz[0][0] == (*Dimension))
    {
        return 1;
    }
    else if (Matriz[0][0] == ((*Dimension)*(*Dimension))-1)
    {
        return 2;
    }
    else if (Matriz[0][0] == ((*Dimension)*(*Dimension))-(*Dimension))
    {
        return 3;
    }
}


void EliminarMatriz(unsigned short int** Matriz, unsigned short int* Dimension)
{
    for (short int Fila=0; Fila<(*Dimension); Fila++)
    {
        delete Matriz[Fila];
    }

    delete Matriz;
}

short unsigned int TransformarFila(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension, unsigned short int* CantRotaciones)
{
    if (*CantRotaciones == 1)
    {
        return Columna;
    }
    else if(*CantRotaciones == 2)
    {
        return (*Dimension) - (Fila) + 1;
    }
    else if(*CantRotaciones == 3)
    {
        return (*Dimension) - (Columna) + 1;
    }
}

short unsigned int TransformarColumna(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension, unsigned short int* CantRotaciones)
{
    if (*CantRotaciones == 1)
    {
        return (*Dimension) - (Fila) + 1;
    }
    else if(*CantRotaciones == 2)
    {
        return (*Dimension) - (Columna) + 1;
    }
    else if(*CantRotaciones == 3)
    {
        return Fila;
    }
}

unsigned short int ObtenerValorCasilla(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension)
{
    if (PosRespectoCentro(&Fila, &Columna, Dimension) == '-')
    {
        return ( (Columna) + ((Fila-1)*(*Dimension)) );
    }
    else if (PosRespectoCentro(&Fila, &Columna, Dimension) == '+')
    {
        return ( (Columna) + ((Fila-1)*(*Dimension)) ) -1;
    }
}

char PosRespectoCentro(unsigned short int* Fila, unsigned short int* Columna, unsigned short int* Dimension)
{
    if (*Fila<((*Dimension)/2)+1)
    {
        return '-';
    }
    else if (*Fila>((*Dimension)/2)+1)
    {
        return '+';
    }
    else if (*Fila==((*Dimension)/2)+1)
    {
        if (*Columna<((*Dimension)/2)+1)
        {
            return '-';
        }
        else if (*Columna>((*Dimension)/2)+1)
        {
            return '+';
        }
    }
}

void ImprimirMatriz(unsigned short int** Matriz, unsigned short int* Dimension)
{
    for (short int Fila=0; Fila<(*Dimension); Fila++)
    {
        for (short int Columna=0; Columna<(*Dimension); Columna++)
        {
            std::cout << Matriz[Fila][Columna] << " ";
        }

        std::cout << "\n";
    }
}