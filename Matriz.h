#ifndef MATRIZ_H
#define MATRIZ_H

unsigned short int** CrearMatriz(unsigned short int* Dimension);
void RotarMatriz(unsigned short int** Matriz, unsigned short int* Dimension,unsigned short int CantRotaciones);
unsigned short int ObtenerEstadoRotacion(unsigned short int** Matriz, unsigned short int* Dimension);
void EliminarMatriz(unsigned short int** Matriz, unsigned short int* Dimension);
short unsigned int TransformarFila(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension, unsigned short int* CantRotaciones);
short unsigned int TransformarColumna(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension, unsigned short int* CantRotaciones);
short unsigned int ObtenerFilaOriginal(unsigned short int Valor, unsigned short int* Dimension);
short unsigned int ObtenerColumnaOriginal(unsigned short int Valor, unsigned short int* Dimension);
unsigned short int ObtenerValorCasilla(unsigned short int Fila, unsigned short int Columna, unsigned short int* Dimension);
char PosRespectoCentro(unsigned short int* Fila, unsigned short int* Columna, unsigned short int* Dimension);
void ImprimirMatriz(unsigned short int** Matriz, unsigned short int* Dimension);

#endif // MATRIZ_H
