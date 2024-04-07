#include "Matriz.h"
#include "Cerradura.h"

void CambiosCerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones,int CantidadComparaciones,unsigned short int DimensionOriginal)
{
    unsigned short int FilaOriginal, ColumnaOriginal;
    unsigned short int Dimension_Matriz_Primera, Dimension_Matriz_Segunda,DiferenciaM1,DiferenciaM2;

    for(int i=CantidadComparaciones-1;  i >= 0; i--)
    {
        Dimension_Matriz_Primera=ObtenerDimension(Cerradura[i]);
        Dimension_Matriz_Segunda=ObtenerDimension(Cerradura[1+i]);
        DiferenciaM1=(ObtenerDimension(Cerradura[i])-(DimensionOriginal))/2;
        DiferenciaM2=(ObtenerDimension(Cerradura[i+1])-(DimensionOriginal))/2;
        FilaOriginal=ObtenerFilaOriginal(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1],Dimension_Matriz_Primera);
        ColumnaOriginal=ObtenerColumnaOriginal(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1],Dimension_Matriz_Primera);

        if (Arreglo_Comparaciones[i] == 1)
        {
            if(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1] <= Cerradura[i+1][Fila-1+DiferenciaM2][Columna-1+DiferenciaM2])
            {
                if ( FilaOriginal <= (Dimension_Matriz_Primera/2 ) && (ColumnaOriginal < Dimension_Matriz_Primera))
                {

                    CambiarMatriz(Cerradura[i],ObtenerDimension(Cerradura[i])+2);
                }
                else if	( FilaOriginal > (Dimension_Matriz_Primera/2) && ColumnaOriginal<=((Dimension_Matriz_Primera/2)+1))
                {
                    RotarMatriz(Cerradura[i+1],ObtenerEstadoRotacion(Cerradura[i])+1);
                }
                else if ( (ColumnaOriginal == Dimension_Matriz_Primera && FilaOriginal>(Dimension_Matriz_Primera/2) ) || (ColumnaOriginal>( (Dimension_Matriz_Primera/2) +1) && FilaOriginal >(Dimension_Matriz_Primera/2)))
                {
                    RotarMatriz(Cerradura[i+1],ObtenerEstadoRotacion(Cerradura[i])+3);
                }
            }
        }

        else if (Arreglo_Comparaciones[i] == -1)
        {
            if(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1] >= Cerradura[i+1][Fila-1+DiferenciaM2][Columna-1+DiferenciaM2])
            {
                if ( FilaOriginal > ((Dimension_Matriz_Primera/2)+1 ) && (ColumnaOriginal > 1 ))
                {
                    CambiarMatriz(Cerradura[i+1],ObtenerDimension(Cerradura[i+1])+2);
                }
                else if	( FilaOriginal <= ( (Dimension_Matriz_Primera/2)+1 ) && ColumnaOriginal> ((Dimension_Matriz_Primera/2)))
                {
                    RotarMatriz(Cerradura[i+1],ObtenerEstadoRotacion(Cerradura[i])+1);
                }
                else if ( (ColumnaOriginal == 1 && FilaOriginal>((Dimension_Matriz_Primera/2)+1 ) ) || (ColumnaOriginal<= (Dimension_Matriz_Primera/2)  && FilaOriginal <= ((Dimension_Matriz_Primera/2)+1 )))
                {
                    RotarMatriz(Cerradura[i+1],ObtenerEstadoRotacion(Cerradura[i])+3);
                }
            }
        }
        else if (Arreglo_Comparaciones[i] == 0)
        {
            if(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1] != Cerradura[i+1][Fila-1+DiferenciaM2][Columna-1+DiferenciaM2])
            {
                if(Dimension_Matriz_Primera != Dimension_Matriz_Segunda) // si la dimenension no es igual retorna falso
                {
                    if(Dimension_Matriz_Primera > Dimension_Matriz_Segunda)
                    {
                        CambiarMatriz(Cerradura[i+1],ObtenerDimension(Cerradura[i]));
                    }
                    else
                    {
                        CambiarMatriz(Cerradura[i],ObtenerDimension(Cerradura[i+1]));
                    }
                    IgualarRotacion(Cerradura[i],Cerradura[i+1]);

                }
                else if (ObtenerEstadoRotacion(Cerradura[i]) != ObtenerEstadoRotacion(Cerradura[i+1]))
                {
                    IgualarRotacion(Cerradura[i],Cerradura[i+1]);
                }
            }
        }
    }

    //sale del bucle;
}

bool Abrecerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones,int CantidadComparaciones, unsigned short int DimensionOriginal )
{
    unsigned short int DiferenciaM1, DiferenciaM2;


    for(int i=0;  i < CantidadComparaciones; i++)
    {
        DiferenciaM1=(ObtenerDimension(Cerradura[i])-(DimensionOriginal))/2;
        DiferenciaM2=(ObtenerDimension(Cerradura[i+1])-(DimensionOriginal))/2;


        if (Arreglo_Comparaciones[i] == 1)
        {
            if(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1] <= Cerradura[i+1][Fila-1+DiferenciaM2][Columna-1+DiferenciaM2])
            {
                return false;
            }
        }

        else if (Arreglo_Comparaciones[i] == -1)
        {
            if(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1] >= Cerradura[i+1][Fila-1+DiferenciaM2][Columna-1+DiferenciaM2])
            {
                return false;
            }
        }

        else if (Arreglo_Comparaciones[i] == 0)
        {
            if(Cerradura[i][Fila-1+DiferenciaM1][Columna-1+DiferenciaM1] != Cerradura[i+1][Fila-1+DiferenciaM2][Columna-1+DiferenciaM2])
            {
                return false;
            }
        }
    }
    return true;
}
