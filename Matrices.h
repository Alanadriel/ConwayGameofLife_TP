#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAXF 100
#define MAXC 100

#define MURIENDO 3
#define NACIENDO 2
#define VIVO 1
#define MUERTO 0

int** crearMatriz_int(size_t , size_t );
void destruirMatriz(int**,size_t);
void inicializarZero(int**, size_t, size_t);

void MostrarMAt(int [MAXC][MAXC]);
void cargarOscilador2(int** matriz, size_t, size_t);
int ContVecinos(int** matriz, size_t, size_t);
void calcularEstado(int** matriz);
void aplicarEstado(int** matriz);


#endif // MATRICES_H_INCLUDED
