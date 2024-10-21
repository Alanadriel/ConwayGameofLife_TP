#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAXFil 80
#define MAXCol 80

#define MURIENDO 3
#define NACIENDO 2
#define VIVO 1
#define MUERTO 0

#define TAM_Cuadrado 5

int** crearMatriz_int(size_t , size_t );
void destruirMatriz(int**,size_t);
void inicializarZero(int**, size_t, size_t);


void cargarOscilador2(int** matriz, size_t, size_t);
int ContVecinos(int** matriz, size_t, size_t,size_t, size_t);
void calcularEstado(int** matriz,size_t ,size_t );
void aplicarEstado(int** matriz,size_t ,size_t );


#endif // MATRICES_H_INCLUDED
