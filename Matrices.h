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

void MostrarMAt(int [MAXC][MAXC]);
void cargarOscilador2(int matriz[MAXF][MAXC], int, int);
int ContVecinos(int matriz[MAXF][MAXC], int, int);
void calcularEstado(int matriz[MAXF][MAXC]);
void aplicarEstado(int matriz[MAXF][MAXC]);


#endif // MATRICES_H_INCLUDED
