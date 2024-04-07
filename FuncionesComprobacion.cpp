#include "FuncionesMatriz.h"

bool ComprobacionDeCerradura()
{
    for(unsigned short int i;i<7;i++) //Se necesita cauntas matrices componen la cerradura
    {

    }



    return false;
}

bool Abrecerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones,int CantidadMatrices )
{
    unsigned short int Diferencia_entre_dimensiones;
    unsigned short int    Dimension_Matriz_Primera, Dimension_Matriz_Segunda;
    /*
    unsigned short int valor_matriz1, valor_matriz2, Valor_dimensiones_diferentes11, Valor_dimensiones_diferentes21,Valor_dimensiones_diferentes12,Valor_dimensiones_diferentes22;
    */

    for(int i=0;  i < CantidadMatrices-2; i++) //se necesita cuantas matrices componen la cerradura y se lo remplaza por el 3, se empieza desde 0 ya que en la prueba son 4 pero como comienza desde 0
    {


        Dimension_Matriz_Primera=ObtenerDimension(Cerradura[0+i]);      //se necesita cuantas matrices componen la cerradura y se lo remplaza por el 3
        Dimension_Matriz_Segunda=ObtenerDimension(Cerradura[0+1+i]);    //se obtienen 2 matrices para compararlas
        /*
        Numerodecomparacion=Arreglo_Comparaciones[(CantidadMatrices-1)-1-i];
        */






        if ((Fila > Dimension_Matriz_Primera) or (Columna > Dimension_Matriz_Primera) or (Fila > Dimension_Matriz_Segunda) or (Columna > Dimension_Matriz_Segunda)  )
        {
            return false;

        }
        else
        {
        if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == 1)                  //se necesita saber el largo del Arreglo de comparaciones y se lo remplaza por el 3
        {
                if(Dimension_Matriz_Primera == Dimension_Matriz_Segunda) // solo puede ser mayor o igual porque si es menor la primera es imposible que sea mayor
            {

                if(Cerradura[0+i][Fila-1][Columna-1] > Cerradura[0+1+i][Fila-1][Columna-1])
                {
                }
                else
                {
                    return false;
                }
            }
            else        // que se hace si las dimensiones no son iguales
            {
                        //se halla la diferencia de dimensiones
                        //obtenego la columna y la casilla y las comparo
                if (Dimension_Matriz_Primera > Dimension_Matriz_Segunda)        // solo puede ser mayor o igual porque si es menor la primera es imposible que sea mayor
                    {
                    Diferencia_entre_dimensiones = Dimension_Matriz_Primera - Dimension_Matriz_Segunda;
                    /*
                    Valor_dimensiones_diferentes11=Cerradura[0+i][Fila-1][Columna-1] ;
                    Valor_dimensiones_diferentes21= Cerradura[0+1+i][Fila-1-(Diferencia_entre_dimensiones)/2][Columna-1-(Diferencia_entre_dimensiones)/2];
                    */
                        //se tiene la diferencia de dimensiones entonces se compara
                    if (Cerradura[0+i][Fila-1][Columna-1] >  Cerradura[0+1+i][Fila-1-(Diferencia_entre_dimensiones)/2][Columna-1-(Diferencia_entre_dimensiones)/2] )
                        {

                        }
                    else
                        {
                        return false;
                        }
                    }

                else
                    {
                        return false;

                    }

                    }
            Fila=Fila -(Diferencia_entre_dimensiones)/2;
            Columna=Columna -(Diferencia_entre_dimensiones)/2;
            }
         if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == 0)
        {

            if(Dimension_Matriz_Primera == Dimension_Matriz_Segunda) // si la dimenension no es igual retorna falso
            {
            if(ObtenerEstadoRotacion(Cerradura[0+i])==ObtenerEstadoRotacion(Cerradura[0+1+i]))    //si la posicion no es igual retorna falso
                {
                }
            else
            {
                return false;
            }
            }
            else
            {
                return false;
            }
           // se compara lo que se hace en el caso 0
        }
         if (Arreglo_Comparaciones[(CantidadMatrices-1)-1-i] == -1)
        {
            if(Dimension_Matriz_Primera == Dimension_Matriz_Segunda) // si la dimenension no es igual retorna falso
            {

                if(Cerradura[0+i][Fila-1][Columna-1] < Cerradura[0+1+i][Fila-1][Columna-1])
                {
                }
                else
                {
                return false;
                }
            }
            else        // que se hace si las dimensiones no son iguales
            {
                //se halla la diferencia de dimensiones
                //obtenego la columna y la casilla y las comparo
                if (Dimension_Matriz_Primera < Dimension_Matriz_Segunda)        //si la dimension de la primera es mayor
                {
                 Diferencia_entre_dimensiones =  Dimension_Matriz_Segunda  - Dimension_Matriz_Primera ;
                /*
                Valor_dimensiones_diferentes12=Cerradura[0+i][Fila-1][Columna-1] ;
                Valor_dimensiones_diferentes22= Cerradura[0+1+i][Fila-1+(Diferencia_entre_dimensiones)/2][Columna-1+(Diferencia_entre_dimensiones)/2];
                */
                if (Cerradura[0+i][Fila-1][Columna-1] <  Cerradura[0+1+i+(Diferencia_entre_dimensiones)/2][Fila-1][Columna-1+(Diferencia_entre_dimensiones)/2])
                {   }

                else
                {
                        return false;
                }

                }


                else
                {
                return false;
                }

            }
            Fila=Fila +(Diferencia_entre_dimensiones)/2;
            Columna=Columna +(Diferencia_entre_dimensiones)/2;
        }
        }

    }
    return true;
}
