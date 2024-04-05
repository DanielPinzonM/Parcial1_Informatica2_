#ifndef CERRADURA_H
#define CERRADURA_H

unsigned short int*** CrearCerradura(unsigned short int *Dimension, unsigned short int NumComparaciones);
unsigned short int ObtenerDimension(unsigned short int* Fila, unsigned short int* Columna);
void EliminarCerradura(unsigned short int*** Cerradura,unsigned short int *Dimension , unsigned short int NumComparaciones);


#endif // CERRADURA_H