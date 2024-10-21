#include "matrices.h"


void cargarOscilador2(int** matriz, size_t i, size_t j) {

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

int ContVecinos(int** mtr, size_t i, size_t j,size_t MAXF, size_t MAXC){
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

void calcularEstado(int** matriz,size_t MAXF,size_t MAXC){
    int i,j,cantVeci=0;
    for(i=0; i < MAXF ; i++){
        for(j=0; j < MAXC ; j++){
            cantVeci = ContVecinos(matriz,i,j,MAXF,MAXC);
            if(matriz[i][j]==MUERTO && cantVeci == NACIENDO){
                matriz[i][j] = NACIENDO;
            }
            if(matriz[i][j]==VIVO && ( cantVeci > NACIENDO || cantVeci < MURIENDO    ) ){
                matriz[i][j] = MURIENDO;
            }
        }
    }
}
void aplicarEstado(int** matriz,size_t MAXF,size_t MAXC){
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

int** crearMatriz_int(size_t filas , size_t columns ){
    int** Matriz, **ini;

    Matriz = malloc( filas * sizeof(int*) );
    if(!Matriz){
        printf("Error al asignar memoria Matriz INT");
        return NULL;
    }
    ini = Matriz;
    for(size_t i=0 ; i < filas ;i++){
        *Matriz = malloc(columns * sizeof(int) );
        if(!*Matriz){
            destruirMatriz(Matriz,i);
            printf("Error al asignar memoria Matriz INT");
            return NULL;
        }
        Matriz++;
    }
    return ini;
}
void destruirMatriz(int**mtr, size_t filas){
    int**matriz= mtr;
    for(size_t i =0 ; i<filas; i++){
        free(*mtr);
        mtr++;
    }
    free(matriz);
}
void inicializarZero(int** matr, size_t fil, size_t col){
    size_t i,j;
    for( i= 0 ; i< fil ; i++){
        for( j = 0; j<col ; j++ ){
            matr[i][j] = 0;
        }
    }
}
