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
    bool done=1 ;
    int k;
    int matr[MAXF][MAXC] = {{0}};
    cargarOscilador2(matr,25,25);
    cargarOscilador2(matr,10,10);

    //Mucha de esta parametrizacion puede venir por linea de comando!!
    int delay               = 100;
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
                                                540*2, // Ancho
                                                360*2, // Alto
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

        for(int i =0 ; i < MAXF; i++){
            for(int j=0; j<MAXC; j++){
                if(matr[i][j]== VIVO ){
                    fillRect.x = i*10; //Pos X
                    fillRect.y = j*10; //Pos Y
                    fillRect.h = 10; //Alto
                    fillRect.w = 10; //Ancho

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

        //Titulo/caption de la ventana
        SDL_SetWindowTitle(window, "conway's life gamee");
        SDL_Delay(delay);

        //Procesamiento de matriz?
        calcularEstado(matr);
        aplicarEstado(matr);
    }

    //destruyo todos los elementos creados
    //Observar ni mas ni menos que destructores, en la asignatura no inventamos nada!
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


