#ifndef MATRIZ_H
#define MATRIZ_H

unsigned short int** CrearMatriz(unsigned short int* Dimension);
void RotarMatriz(unsigned short int** Matriz, unsigned short int* Dimension, short int CantRotaciones);
unsigned short int ObtenerEstadoRotacion(unsigned short int** Matriz, unsigned short int* Dimension);
void EliminarMatriz(unsigned short int** Matriz, unsigned short int* Dimension);

#endif // MATRIZ_H
