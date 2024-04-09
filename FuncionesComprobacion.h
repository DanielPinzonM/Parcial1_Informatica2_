#ifndef FUNCIONESCOMPROBACION_H
#define FUNCIONESCOMPROBACION_H

bool Abrecerradura( unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones, short int CantidadComprobaciones,unsigned short int DimensionOriginal);
void CambiosCerradura(unsigned short int ***Cerradura,unsigned short int Fila, unsigned short Columna,short int *Arreglo_Comparaciones, short int CantidadComparaciones,unsigned short int DimensionOriginal);
void RetornarConfiguracionX(unsigned short int ***Cerradura,short int Tamanio);
void Menu ();
short int* ObtenerClave(unsigned short int* Fila, unsigned short int* Columna, short int* CantidadComparaciones, bool *Clave);
void IgnorarCin(unsigned short int* Fila, unsigned short int* Columna, short int *CantidadComparaciones, bool* Clave);

#endif // FUNCIONESCOMPROBACION_H