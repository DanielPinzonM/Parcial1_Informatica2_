#include "Matriz.h"
#include "Cerradura.h"
#include "FuncionesComprobacion.h"
#include <iostream>

using namespace std;

void CambiosCerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones, short int CantidadComparaciones,unsigned short int DimensionOriginal)
{
    unsigned short int FilaOriginal, ColumnaOriginal;
    unsigned short int Dimension_Matriz_Primera, Dimension_Matriz_Segunda,DiferenciaM1,DiferenciaM2;
    unsigned short int Dimension;

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
                    Dimension = ObtenerDimension(Cerradura[i])+2;
                    EliminarMatriz(Cerradura[i]);
                    Cerradura[i] = CrearMatriz(Dimension);
                }
                else if	( FilaOriginal > (Dimension_Matriz_Primera/2) && ColumnaOriginal<=((Dimension_Matriz_Primera/2)+1))
                {
                    if(Dimension_Matriz_Primera < Dimension_Matriz_Segunda)
                    {
                        Dimension = ObtenerDimension(Cerradura[i+1]);
                        EliminarMatriz(Cerradura[i]);
                        Cerradura[i] = CrearMatriz(Dimension);
                    }
                    RotarMatriz(Cerradura[i+1],ObtenerEstadoRotacion(Cerradura[i])+1);
                }
                else if ( (ColumnaOriginal == Dimension_Matriz_Primera && FilaOriginal>(Dimension_Matriz_Primera/2) ) || (ColumnaOriginal>( (Dimension_Matriz_Primera/2) +1) && FilaOriginal >(Dimension_Matriz_Primera/2)))
                {
                    if(Dimension_Matriz_Primera < Dimension_Matriz_Segunda)
                    {
                        Dimension = ObtenerDimension(Cerradura[i+1]);
                        EliminarMatriz(Cerradura[i]);
                        Cerradura[i] = CrearMatriz(Dimension);
                    }
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
                    Dimension = ObtenerDimension(Cerradura[i+1])+2;
                    EliminarMatriz(Cerradura[i+1]);
                    Cerradura[i+1] = CrearMatriz(Dimension);
                }
                else if	( FilaOriginal <= ( (Dimension_Matriz_Primera/2)+1 ) && ColumnaOriginal> ((Dimension_Matriz_Primera/2)))
                {
                    if(Dimension_Matriz_Primera > Dimension_Matriz_Segunda)
                    {
                        Dimension = ObtenerDimension(Cerradura[i]);
                        EliminarMatriz(Cerradura[i+1]);
                        Cerradura[i+1] = CrearMatriz(Dimension);
                    }
                    RotarMatriz(Cerradura[i+1],ObtenerEstadoRotacion(Cerradura[i])+1);
                }
                else if ( (ColumnaOriginal == 1 && FilaOriginal>((Dimension_Matriz_Primera/2)+1 ) ) || (ColumnaOriginal<= (Dimension_Matriz_Primera/2)  && FilaOriginal <= ((Dimension_Matriz_Primera/2)+1 )))
                {
                    if(Dimension_Matriz_Primera > Dimension_Matriz_Segunda)
                    {
                        Dimension = ObtenerDimension(Cerradura[i]);
                        EliminarMatriz(Cerradura[i+1]);
                        Cerradura[i+1] = CrearMatriz(Dimension);
                    }
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
                        Dimension = ObtenerDimension(Cerradura[i]);
                        EliminarMatriz(Cerradura[i+1]);
                        Cerradura[i+1] = CrearMatriz(Dimension);
                    }
                    else
                    {
                        Dimension = ObtenerDimension(Cerradura[i+1]);
                        EliminarMatriz(Cerradura[i]);
                        Cerradura[i] = CrearMatriz(Dimension);
                    }
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

bool Abrecerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones, short int CantidadComparaciones, unsigned short int DimensionOriginal )
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
void RetornarConfiguracionX(unsigned short int ***Cerradura,short int Tamanio)
{
    cout<<"\nConfiguracion de cerradura: X(";

    for(int i =0; i <= Tamanio;i++)
    {
        if (i < Tamanio)
        {
            cout << ObtenerDimension(Cerradura[i]) << "(" << ObtenerEstadoRotacion(Cerradura[i]) << "), ";
        }
        else
        {
            cout << ObtenerDimension(Cerradura[i]) << "(" << ObtenerEstadoRotacion(Cerradura[i]) << ")";
        }
    }
    cout<<")";
}

void Menu ()
{
    unsigned short int Fila, Columna;
    short int CantComparacion = 0;
    short int *Comparaciones;
    bool ClaveObtenida = false;

    while(ClaveObtenida == false)
    {
        Comparaciones = ObtenerClave(&Fila, &Columna, &CantComparacion, &ClaveObtenida);
    }

    unsigned short int*** Cerradura = CrearCerradura(&Fila, &Columna, CantComparacion);

    while (Abrecerradura(Cerradura, Fila, Columna, Comparaciones, CantComparacion, DimensionMinima(&Fila,&Columna))  == false)
    {
        CambiosCerradura(Cerradura,Fila,Columna, Comparaciones, CantComparacion,DimensionMinima(&Fila,&Columna));
    }

    cout<<"\n";

    for(short int i =0; i <= CantComparacion;i++)
    {
        ImprimirMatriz(Cerradura[i]);
        cout<<"\n";
    }

    RetornarConfiguracionX(Cerradura, CantComparacion);

    EliminarCerradura(Cerradura, CantComparacion);

    delete[] Comparaciones;

    return;
}

short int* ObtenerClave(unsigned short int* Fila, unsigned short int* Columna, short int* CantidadComparaciones, bool *Clave)
{
    short int AuxComparaciones[15];
    short int Cantidad;

    cout << "Ingrese la clave (ingrese un numero diferente al final de las comparaciones):\n\n ";

    while(true)
    {
        cin >> Cantidad;

        if(cin.fail())
        {
            cout << "\n***Se ingresaron datos invalidos***\n";
            IgnorarCin(Fila, Columna, CantidadComparaciones, Clave);
            return NULL;
        }
        else if(*CantidadComparaciones == 0)
        {
            if(Cantidad>0)
            {
                *Fila = Cantidad;
            }
            else
            {
                cout << "\n***Se ingreso una fila invalida***\n";
                IgnorarCin(Fila, Columna, CantidadComparaciones, Clave);
                return NULL;
            }
        }
        else if(*CantidadComparaciones == 1)
        {
            if(Cantidad>0)
            {
                *Columna = Cantidad;
            }
            else
            {
                cout << "\n***Se ingreso una columna invalida***\n";
                IgnorarCin(Fila, Columna, CantidadComparaciones, Clave);
                return NULL;
            }
        }
        else if(*CantidadComparaciones>1)
        {
            if(((*CantidadComparaciones)==2 && Cantidad>1) || ((*CantidadComparaciones)==2 && Cantidad<-1))
            {
                cout << "\n***No se ingreso ninguna comparacion***\n";
                IgnorarCin(Fila, Columna, CantidadComparaciones, Clave);
                return NULL;
            }
            else if(Cantidad<=1 && Cantidad>=-1)
            {
                AuxComparaciones[*CantidadComparaciones-2] = Cantidad;
            }
            else
            {
                break;
            }
        }

        *CantidadComparaciones += 1;
    }

    *CantidadComparaciones -= 2;

    short int *Comparaciones = new short int[*CantidadComparaciones];

    for (short int i=0; i<(*CantidadComparaciones); i++)
    {
        Comparaciones[i] = AuxComparaciones[i];
    }

    *Clave = true;

    return Comparaciones;
}

void IgnorarCin(unsigned short int* Fila, unsigned short int* Columna, short int *CantidadComparaciones, bool* Clave)
{
    cin.clear();
    cin.ignore(15, '\n');
    *Fila = 0;
    *Columna = 0;
    *CantidadComparaciones = 0;
    *Clave = false;
    return;
}