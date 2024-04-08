#ifndef FUNCIONESCOMPROBACION_H
#define FUNCIONESCOMPROBACION_H


bool Abrecerradura( unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones,int CantidadComprobaciones,unsigned short int DimensionOriginal);
void CambiosCerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones,int CantidadComparaciones,unsigned short int DimensionOriginal);
void Menu ();
void RetornarConfiguracionX(unsigned short int ***Cerradura,short int Tamanio);
#endif // FUNCIONESCOMPROBACION_H

