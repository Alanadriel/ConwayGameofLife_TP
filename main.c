#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __MINGW32__
    #define SDL_MAIN_HANDLED
    #include <SDL_main.h>
#endif

#include <SDL.h>
#include "matrices.h"
/**
 Plantilla de proyecto codeblocks para juego de la vida.
Funciona con mingw 64 bits y no requiere tener instalado SDL.
Los fuentes son multiplataforma (windows/linux Debian;Ubuntu). Para ubuntu se
requiere de diferente configuración de proyecto.
*/

void drawFilledCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius*radius) {
                SDL_RenderDrawPoint(renderer, cx + x, cy + y);
            }
        }
    }
}


int main(int argc, char *argv[])
{

    int delay = 100, k=0,skip=0,MAXfi, MAXco;
    bool done=1 ;

    if(argc == 1 ){
        MAXfi = MAXFil ;
        MAXco = MAXCol ;
    }else{
        sscanf(argv[1], "%d", &MAXfi);
        sscanf(argv[2], "%d", &MAXco);
        sscanf(argv[3], "%d", &delay);
        sscanf(argv[4], "%d", &skip);
    }

   /* if(argc > 1)
        sscanf(argv[1], "%zu", &MAXfi);
    if(argc > 2)
        sscanf(argv[2], "%zu", &MAXco);
    */
    int** matr = crearMatriz_int(MAXfi,MAXco);
    if(!matr){
        printf("Erorr Matriz");
        return -1;
    }
    inicializarZero(matr,MAXfi,MAXco);
    cargarOscilador2(matr,25,25);
    cargarOscilador2(matr,10,10);


    SDL_Window* window      = NULL;
    SDL_Renderer* renderer  = NULL;
    SDL_Event e;
    SDL_Rect fillRect;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL No se ha podido inicializar! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    //Create window
    window = SDL_CreateWindow("Juego de la vida",
                                                SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                600*2, // Ancho Pantalla
                                                300*2, // Alto Pantalla
                                                SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Error en la creacion de la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Creamos el lienzo
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("No se ha podido crear el lienzo! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    while (done){
        while (SDL_PollEvent(&e) != 0) {
            // Salida del usuario
            if (e.type == SDL_QUIT) {
                done = 0;
            }
        }
        // Se limpia la pantalla
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);

        for(size_t i =0 ; i < MAXfi; i++){
            for(size_t j=0; j<MAXco; j++){
                if(matr[i][j]== VIVO ){
                    fillRect.x = i* TAM_Cuadrado; //Pos X
                    fillRect.y = j*TAM_Cuadrado; //Pos Y
                    fillRect.h = TAM_Cuadrado; //Alto
                    fillRect.w = TAM_Cuadrado; //Ancho

                    //Plantilla para pintar cuadrados
                    SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0x00, 0x00);
                    SDL_RenderFillRect(renderer, &fillRect);
                    //Plantilla para pintar circulos si gusta mas
                    //drawFilledCircle(renderer, X+e_size_w/2, Y+e_size_h/2, (e_size_w>e_size_h?e_size_h/2:e_size_w/2));
                    }


            }
        }
        // Actualizacion del "lienzo"
        SDL_RenderPresent(renderer);
        k++;
        //SDL_UpdateWindowSurface(window);
        char aux[50]="";
        sprintf(aux,"Conway's Life Games Ciclos %d",k);

        //Titulo/caption de la ventana
        SDL_SetWindowTitle(window, aux);
      //  SDL_Delay(delay);
         if(skip<k)
            SDL_Delay(delay);

        //Procesamiento de matriz
        calcularEstado(matr,MAXfi,MAXco);
        aplicarEstado(matr,MAXfi,MAXco);
    }

    //destruyo todos los elementos creados
    destruirMatriz(matr,MAXfi);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


