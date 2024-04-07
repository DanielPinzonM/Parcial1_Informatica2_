#ifndef CERRADURA_H
#define CERRADURA_H

unsigned short int*** CrearCerradura(unsigned short int* Fila, unsigned short int* Columna, unsigned short int NumComparaciones);
unsigned short int DimensionMinima(unsigned short int* Fila, unsigned short int* Columna);
unsigned short int ObtenerDiferencia(unsigned short int DimensionM1, unsigned short int DimensionM2);
void IgualarRotacion(unsigned short int** Matriz1, unsigned short int** Matriz2);
void CambiarMatriz(unsigned short int** Matriz, unsigned short int Dimension);
void EliminarCerradura(unsigned short int*** Cerradura, unsigned short int NumComparaciones);

#endif // CERRADURA_H