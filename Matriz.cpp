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
                Matriz[Fila-1][Columna-1] = Columna + ((Fila-1)*(*Dimension));
                Matriz[(*Dimension)-Fila][(*Dimension)-Columna] = (*Dimension)-Columna+1 + ((((*Dimension)-Fila+1)-1)*(*Dimension))-1;
            }
        }
        else
        {
            Matriz[Fila-1] = new unsigned short int[*Dimension];

            for (short int Columna=1; Columna<=((*Dimension)/2); Columna++)
            {
                Matriz[Fila-1][Columna-1] = Columna + ((Fila-1)*(*Dimension));
                Matriz[(*Dimension)-Fila][(*Dimension)-Columna] = (*Dimension)-Columna+1 + ((((*Dimension)-Fila+1)-1)*(*Dimension))-1;
            }
        }
    }

    Matriz[((*Dimension)/2)][((*Dimension)/2)] = 0;

    return Matriz;
}

void RotarMatriz(unsigned short int** Matriz, unsigned short int* Dimension, short int CantRotaciones)
{

}

unsigned short int ObtenerEstadoRotacion(unsigned short int** Matriz, unsigned short int* Dimension)
{

}

void EliminarMatriz(unsigned short int** Matriz, unsigned short int* Dimension)
{

}

/*void Imprimir()
{
    for (short int Fila=0; Fila<(*Dimension); Fila++)
    {
        for (short int Columna=0; Columna<(*Dimension); Columna++)
        {
            std::cout << Matriz[Fila][Columna] << " ";
        }

        std::cout << "\n";
    }
}*/
