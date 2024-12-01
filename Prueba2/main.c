#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "headers/utilidades_SDL.h"

int main(int argc, char* argv[]) {
	SDL_Window *ventana = NULL;
	SDL_Renderer *puntos = NULL; 
	SDL_Event redim_v;
	bool ejecucion = iniciar_SDL(ventana, puntos);

	motor_grafico(ejecucion, ventana, puntos, &redim_v);
	limpiar_SDL(ventana, puntos);
	return 0;
}
