#include "matrices.h"
void MostrarMAt(int m[MAXF][MAXC]){
 int i,j;
 for(i=0; i< MAXF ; i++){
    for(j=0; j<MAXC; j++){
        printf("%d",m[i][j] );
    }
    printf("\n");
  }
}

void cargarOscilador2(int matriz[MAXF][MAXC], int i, int j) {

    matriz[j-4][i-4] = 1;
    matriz[j-4][i-3] = 1;
    matriz[j-4][i-2] = 1;
    matriz[j-4][i-1] = 1;
    matriz[j-4][i] = 1;
    matriz[j-4][i+1] = 1;

    matriz[j-3][i-4] = 1;
    matriz[j-3][i-3] = 1;
    matriz[j-3][i-2] = 1;
    matriz[j-3][i-1] = 1;
    matriz[j-3][i] = 1;
    matriz[j-3][i+1] = 1;

    matriz[j+4][i+4] = 1;
    matriz[j+4][i+3] = 1;
    matriz[j+4][i+2] = 1;
    matriz[j+4][i+1] = 1;
    matriz[j+4][i] = 1;
    matriz[j+4][i-1] = 1;

    matriz[j+3][i+4] = 1;
    matriz[j+3][i+3] = 1;
    matriz[j+3][i+2] = 1;
    matriz[j+3] [i+1]= 1;
    matriz[j+3][i] = 1;
    matriz[j+3][i-1] = 1;

    matriz[j-1][i-4] = 1;
    matriz[j][i-4] = 1;
    matriz[j+1][i-4] = 1;
    matriz[j+2][i-4] = 1;
    matriz[j+3][i-4] = 1;
    matriz[j+4][i-4] = 1;

    matriz[j-1][i-3] = 1;
    matriz[j][i-3] = 1;
    matriz[j+1][i-3] = 1;
    matriz[j+2][i-3] = 1;
    matriz[j+3][i-3] = 1;
    matriz[j+4][i-3] = 1;

    matriz[j-4][i+4] = 1;
    matriz[j-3][i+4] = 1;
    matriz[j-2][i+4] = 1;
    matriz[j-1][i+4] = 1;
    matriz[j][i+4] = 1;
    matriz[j+1][i+4] = 1;

    matriz[j-4][i+3] = 1;
    matriz[j-3][i+3] = 1;
    matriz[j-2][i+3] = 1;
    matriz[j-1][i+3] = 1;
    matriz[j][i+3] = 1;
    matriz[j+1][i+3] = 1;
}

int ContVecinos(int mtr[MAXF][MAXC], int i, int j){
    int f,c,cont=0;

   for(f=i-1; f <= i+1 ; f++ ){
        for(c=j-1; c <= j+1 ; c++){
         if (f >= 0 && f < MAXF && c >= 0 && c < MAXC)
                if (!(f == i && c == j))
                    if (mtr[f][c] == VIVO || mtr[f][c] == MURIENDO)
                        cont++;

        }
   }

    return cont ;
}

void calcularEstado(int matriz[MAXF][MAXC]){
    int i,j,cantVeci=0;
    for(i=0; i < MAXF ; i++){
        for(j=0; j < MAXC ; j++){
            cantVeci = ContVecinos(matriz,i,j);
            if(matriz[i][j]==MUERTO && cantVeci == NACIENDO){
                matriz[i][j] = NACIENDO;
            }
            if(matriz[i][j]==VIVO && ( cantVeci > NACIENDO || cantVeci < MURIENDO    ) ){
                matriz[i][j] = MURIENDO;
            }
        }
    }
}
void aplicarEstado(int matriz[MAXF][MAXC]){
    int i,j;
    for(i=0; i < MAXF ; i++){
        for(j=0; j < MAXC ; j++){
            if(matriz[i][j]== MURIENDO ){
                matriz[i][j] = MUERTO;
            }
            if(matriz[i][j]== NACIENDO){
                matriz[i][j] = VIVO;
            }
        }
    }
}
