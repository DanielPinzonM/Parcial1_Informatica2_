#include <iostream>
#include "Matriz.h"

unsigned short int** CrearMatriz(unsigned short int Dimension)
{
    unsigned short int** Matriz;
    Matriz = new unsigned short int*[Dimension];    //Se coloca a apuntar a un arreglo dinámico de punteros a int de tamaño dimensión (filas)

    for (short int Fila=1; Fila<=(Dimension/2)+1; Fila++)   //Se recorren las filas hasta la centro del arreglo anterior
    {
        if (Fila != ((Dimension)/2)+1)  //Si se está en una fila diferente a la centro
        {
            Matriz[Fila-1] = new unsigned short int[Dimension];             //    Se asigna a cada apuntador de las filas opuestas a apuntar
            Matriz[Dimension-Fila] = new unsigned short int[Dimension];     //    a un arreglo dinámico de enteros de tamaño dimension (columnas)

            for  (short int Columna=1; Columna<=(Dimension); Columna++)   //Se recorren los arreglos de enteros (columnas) recien creados
            {
                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(Fila, Columna, &Dimension);                                                     //   Se asignan a las columnas opuestas sus respectivos
                Matriz[(Dimension)-Fila][(Dimension)-Columna] = ObtenerValorCasilla( (Dimension)-Fila+1, (Dimension)-Columna+1, &Dimension);    //   valores con ayuda de la funcion para obtener el valor
            }
        }
        else    //Si se está en la fila centro
        {
            Matriz[Fila-1] = new unsigned short int[Dimension];   //Se direcciona el apuntador de la fila centro a una matriz de enteros

            for (short int Columna=1; Columna<=((Dimension)/2); Columna++)   //Se reccorre las columnas de la fila centro hasta antes de la casilla centro
            {
                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(Fila, Columna, &Dimension);                                                     //   Se asignan a las columnas
                Matriz[(Dimension)-Fila][(Dimension)-Columna] = ObtenerValorCasilla( (Dimension)-Fila+1, (Dimension)-Columna+1, &Dimension);    //   opuestas sus respectivos
            }
        }
    }

    Matriz[(Dimension/2)][(Dimension/2)] = 0;   //Se asigna 0 a la casilla centro

    return Matriz;
}

void RotarMatriz(unsigned short int** Matriz, unsigned short int CantRotaciones)
{
    unsigned short int Dimension = ObtenerDimension(Matriz);

    while (CantRotaciones > 3)   //Siempre que la cantidad de rotaciones sea mayor que tres, se le resta cuatro
    {
        CantRotaciones -= 4;
    }

    for (short int Fila=1; Fila<=(Dimension/2)+1; Fila++)   //Se recorren las filas hasta la fila centro de la matriz
    {
        if (Fila < (Dimension/2)+1)   //Si se está en una fila menor que la centro
        {
            for (short int Columna=1; Columna<=Dimension; Columna++)    //Se recorren las columnas
            {
                //Se asigna a las columnas opuestas de las filas opuestas el valor de la casilla transformada a una cantidad de rotaciones

                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(TransformarFila(Fila, Columna, &Dimension, &CantRotaciones), TransformarColumna(Fila, Columna, &Dimension, &CantRotaciones), &Dimension);
                Matriz[Dimension-Fila][Dimension-Columna] = ObtenerValorCasilla(TransformarFila(Dimension-Fila+1, Dimension-Columna+1, &Dimension, &CantRotaciones), TransformarColumna(Dimension-Fila+1, Dimension-Columna+1, &Dimension, &CantRotaciones), &Dimension);
            }
        }
        else     //Si se está en la fila centro
        {
            for (short int Columna=1; Columna<=(Dimension/2); Columna++)    //Se reccorre las columnas de la fila centro hasta antes de la casilla centro
            {
                //Se asigna a las columnas opuestas el valor de la casilla transformada a una cantidad de rotaciones

                Matriz[Fila-1][Columna-1] = ObtenerValorCasilla(TransformarFila(Fila, Columna, &Dimension, &CantRotaciones), TransformarColumna(Fila, Columna, &Dimension, &CantRotaciones), &Dimension);
                Matriz[Dimension-Fila][Dimension-Columna] = ObtenerValorCasilla(TransformarFila(Dimension-Fila+1, Dimension-Columna+1, &Dimension, &CantRotaciones), TransformarColumna(Dimension-Fila+1, Dimension-Columna+1, &Dimension, &CantRotaciones), &Dimension);
            }
        }
    }
}

unsigned short int ObtenerEstadoRotacion(unsigned short int** Matriz)
{
    unsigned short int Dimension = ObtenerDimension(Matriz);

    if (Matriz[0][0] == 1)   //Si el primer elemento corresponde al valor de la esquina superior izquierda en una matriz en estado neutro
    {
        return 0;   //Se encuentra en estado neutro
    }
    else if (Matriz[0][0] ==Dimension)    //Si el primer elemento corresponde al valor de la esquina superior derecha en una matriz en estado neutro
    {
        return 1;    //Se encuentra en rotacion 1
    }
    else if (Matriz[0][0] == (Dimension*Dimension)-1)   //Si el primer elemento corresponde al valor de la esquina inferior derecha en una matriz en estado neutro
    {
        return 2;   //Se encuentra en rotacion 2
    }
    else if (Matriz[0][0] == (Dimension*Dimension)-Dimension)   //Si el primer elemento corresponde al valor de la esquina inferior izquierda en una matriz en estado neutro
    {
        return 3;   //Se encuentra en rotacion 3
    }
}

unsigned short int ObtenerDimension(unsigned short int** Matriz)
{
    unsigned short int Posicion = 1;

    while(true)    //Se recorre la diagonal en busca del centro
    {
        if (Matriz[Posicion][Posicion] == 0)
        {
            break;
        }
        else
        {
            Posicion++;
        }
    }

    return (Posicion*2)+1;
}

void EliminarMatriz(unsigned short int** Matriz)
{
    unsigned short int Dimension = ObtenerDimension(Matriz);

    for (short int Fila=0; Fila<Dimension; Fila++)   //Se recorren las filas de la matriz y se libera la memoria correspondiente
    {
        delete Matriz[Fila];
    }

    delete Matriz;  //Se libera la memoria del arreglo principal
}

short unsigned int TransformarFila(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension, unsigned short int* CantRotaciones)
{
    //Se aplica a la fila la transformación que corresponda a una cantidad de rotaciones específica

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
    //Se aplica a la columna la transformación que corresponda a una cantidad de rotaciones específica

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

short unsigned int ObtenerFilaOriginal(unsigned short int Valor, unsigned short int Dimension)
{
    //Se aplica la formula correspondiente para obtener la fila asociada a un valor en una matriz

    if (Valor < (Dimension*Dimension)/2)    //Si el valor se encuentra detrás de la casilla centro
    {
        Valor--;
    }

    return (Valor/Dimension)+1;
}

short unsigned int ObtenerColumnaOriginal(unsigned short int Valor, unsigned short int Dimension)
{
    //Se aplica la formula correspondiente para obtener la columna asociada a un valor en una matriz

    if (Valor > (Dimension*Dimension)/2)    //Si el valor se encuentra delante de la casilla centro
    {
        Valor++;
    }

    if (Valor%Dimension == 0)    //Si el valor es divisible por la dimensión
    {
        return (Dimension);
    }
    else
    {
        return(Valor%Dimension);
    }
}

unsigned short int ObtenerValorCasilla(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension)
{
    //Se optiene el valor de una casilla con ayuda de la fórmula correspondiente

    if (PosRespectoCentro(&Fila, &Columna, Dimension) == '-')   //Si la casilla dada esta detrás de la casilla centro (-)
    {
        return ( (Columna) + ((Fila-1)*(*Dimension)));
    }
    else if (PosRespectoCentro(&Fila, &Columna, Dimension) == '+')   //Si la casilla dada esta delante de la casilla centro (+)
    {
        return ( (Columna) + ((Fila-1)*(*Dimension)) ) -1;
    }
}

char PosRespectoCentro(unsigned short int* Fila, unsigned short int* Columna, unsigned short int* Dimension)
{
    //Se determina si una casilla dada esta delante (+) o detrás (-) de la casilla centro

    if (*Fila<((*Dimension)/2)+1)   //Si la fila es menor que la fila centro
    {
        return '-';
    }
    else if (*Fila>((*Dimension)/2)+1)   //Si la fila es mayor que la fila centro
    {
        return '+';
    }
    else if (*Fila==((*Dimension)/2)+1)   //Si se está en la fila centro
    {
        if (*Columna<((*Dimension)/2)+1)    //Si la columa es menor que la columna centro
        {
            return '-';
        }
        else if (*Columna>((*Dimension)/2)+1)    //Si la columa es mayor que la columna centro
        {
            return '+';
        }
    }
}

void ImprimirMatriz(unsigned short int** Matriz)
{
    //Se recorre la matriz y se imprime

    for (short int Fila=0; Fila<ObtenerDimension(Matriz); Fila++)
    {
        for (short int Columna=0; Columna<ObtenerDimension(Matriz); Columna++)
        {
            std::cout << Matriz[Fila][Columna] << " ";
        }

        std::cout << "\n";
    }
}