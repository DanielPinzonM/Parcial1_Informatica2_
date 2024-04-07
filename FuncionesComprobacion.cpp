#include "Matriz.h"
#include "Cerradura.h"

void ComprobacionDeCerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones,int CantidadMatrices)
{
    unsigned short int Diferencia_entre_dimensiones, FilaOriginal, ColumnaOriginal;
    unsigned short int Dimension_Matriz_Primera, Dimension_Matriz_Segunda;

    for(int i=CantidadMatrices-2;  i >= 0; i--)
    {
        Dimension_Matriz_Primera=ObtenerDimension(Cerradura[i]);
        Dimension_Matriz_Segunda=ObtenerDimension(Cerradura[1+i]);
        FilaOriginal=ObtenerFilaOriginal(Fila,Dimension_Matriz_Primera);
        ColumnaOriginal=ObtenerColumnaOriginal(Columna,Dimension_Matriz_Primera);

        if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == 1)
        {
            if ( FilaOriginal <= (Dimension_Matriz_Primera/2 +1) && (ColumnaOriginal>Dimension_Matriz_Primera))
            {
                EliminarMatriz(Cerradura[i]);
                if(Dimension_Matriz_Primera > Dimension_Matriz_Segunda)
                {
                    Cerradura[i]=CrearMatriz(Dimension_Matriz_Segunda);
                }
                else
                {
                    Cerradura[i+1]=CrearMatriz(Dimension_Matriz_Primera);
                }
            }
            else if	( FilaOriginal>(Dimension_Matriz_Primera/2) && ColumnaOriginal<=(Dimension_Matriz_Primera/2 +1))
            {
                IgualarRotacion(Cerradura[i],Cerradura[i+1]);
                RotarMatriz(Cerradura[i+1], 2);
            }
            else if (ColumnaOriginal == Dimension_Matriz_Primera && FilaOriginal>(Dimension_Matriz_Primera/2) or ColumnaOriginal>(Dimension_Matriz_Primera/2 +1) && FilaOriginal >(Dimension_Matriz_Primera/2))
            {
                IgualarRotacion(Cerradura[i],Cerradura[i+1]);
                RotarMatriz(Cerradura[i+1], 3);
            }

        }

        else if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == -1)
        {

        }

        else if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == 0)
        {

            if(Dimension_Matriz_Primera != Dimension_Matriz_Segunda) // si la dimenension no es igual retorna falso
            {
                if(Dimension_Matriz_Primera > Dimension_Matriz_Segunda)
                {
                    EliminarMatriz(Cerradura[i]);
                    Cerradura[i]=CrearMatriz(Dimension_Matriz_Segunda);
                }
                else
                {
                    EliminarMatriz(Cerradura[i+1]);
                    Cerradura[i+1]=CrearMatriz(Dimension_Matriz_Primera);
                }
                IgualarRotacion(Cerradura[i],Cerradura[i+1]);

            }
            else if (ObtenerEstadoRotacion(Cerradura[i]) != ObtenerEstadoRotacion(Cerradura[i+1]))
            {
                IgualarRotacion(Cerradura[i],Cerradura[i+1]);
            }
        }
    }

    //sale del bucle;
}

bool Abrecerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones,int CantidadMatrices )
{
    unsigned short int Diferencia_entre_dimensiones;
    unsigned short int Dimension_Matriz_Primera, Dimension_Matriz_Segunda;

    for(int i=0;  i < CantidadMatrices-2; i++)
    {
        Dimension_Matriz_Primera=ObtenerDimension(Cerradura[i]);
        Dimension_Matriz_Segunda=ObtenerDimension(Cerradura[1+i]);

        if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == 1)
        {
            if(Dimension_Matriz_Primera == Dimension_Matriz_Segunda)
            {
                if(Cerradura[i][Fila-1][Columna-1] <= Cerradura[1+i][Fila-1][Columna-1])
                {
                    return false;
                }
            }
            else if (Dimension_Matriz_Primera > Dimension_Matriz_Segunda)
            {
                Diferencia_entre_dimensiones = ObtenerDiferencia(Dimension_Matriz_Primera,Dimension_Matriz_Segunda);

                if (Cerradura[i][Fila-1+(Diferencia_entre_dimensiones)][Columna-1+(Diferencia_entre_dimensiones)] <=  Cerradura[1+i][Fila-1][Columna-1] )
                {
                    return false;
                }

            }
            else if(Dimension_Matriz_Primera < Dimension_Matriz_Segunda)
            {

                Diferencia_entre_dimensiones = ObtenerDiferencia(Dimension_Matriz_Primera,Dimension_Matriz_Segunda);

                if (Cerradura[i][Fila-1][Columna-1] <=  Cerradura[1+i][Fila-1+Diferencia_entre_dimensiones][Columna-1+(Diferencia_entre_dimensiones)] )
                {
                    return false;
                }
            }

        }

        else if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == -1)
        {
            if(Dimension_Matriz_Primera == Dimension_Matriz_Segunda)
            {
                if(Cerradura[i][Fila-1][Columna-1] >= Cerradura[1+i][Fila-1][Columna-1])
                {
                    return false;
                }
            }
            else if (Dimension_Matriz_Primera > Dimension_Matriz_Segunda)
            {
                Diferencia_entre_dimensiones = ObtenerDiferencia(Dimension_Matriz_Primera,Dimension_Matriz_Segunda);

                if (Cerradura[i][Fila-1+(Diferencia_entre_dimensiones)][Columna-1+(Diferencia_entre_dimensiones)] >=  Cerradura[1+i][Fila-1][Columna-1] )
                {
                    return false;
                }

            }
            else if(Dimension_Matriz_Primera < Dimension_Matriz_Segunda)
            {

                Diferencia_entre_dimensiones = ObtenerDiferencia(Dimension_Matriz_Primera,Dimension_Matriz_Segunda);

                if (Cerradura[i][Fila-1][Columna-1] >=  Cerradura[1+i][Fila-1+Diferencia_entre_dimensiones][Columna-1+(Diferencia_entre_dimensiones)] )
                {
                    return false;
                }
            }
        }

        else if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == 0)
        {

            if(Dimension_Matriz_Primera != Dimension_Matriz_Segunda) // si la dimenension no es igual retorna falso
            {
                return  false;
            }
            else if (ObtenerEstadoRotacion(Cerradura[i]) != ObtenerEstadoRotacion(Cerradura[i+1]))
            {
                return false;
            }
        }
    }


    return true;
}
