#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "utilidades_SDL.h"

bool iniciar_SDL(SDL_Window *ventana, SDL_Renderer *puntos) { 
	return (SDL_Init(SDL_INIT_VIDEO) < 0) ?
		(printf("SDL no pudo ser iniciado, error %s\n", SDL_GetError()), false) 
		:
		((ventana = SDL_CreateWindow("Entorno 3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, ALTO_VENTANA,SDL_WINDOW_RESIZABLE)) == NULL) ? 
			(printf("La ventana no pudo ser creada, error %s\n", SDL_GetError()), false)
			:
			((puntos = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED)) == NULL) ?
				(printf("El render no pudo ser creado, error %s\n", SDL_GetError()), false)
				:
				true;			
}

int limpiar_SDL(SDL_Window *ventana, SDL_Renderer *puntos) {
	return (puntos == NULL || ventana == NULL) ?
		(printf("El render o la ventana ya eran nulos, favor revisar el motivo %s\n", SDL_GetError()), 1)
		:
		(SDL_DestroyRenderer(puntos), SDL_DestroyWindow(ventana),
		(puntos != NULL || ventana != NULL) ?
			(printf("La ventana o  el renderer no fueron festruidos, favor revisar el motivo %s\n", SDL_GetError()), 1)
			:
			(printf("Ventana y render destruidos exitosamente\n"), 0)
		);
}

bool redimensionar_V(SDL_Event *redim_v) {
	while (SDL_PollEvent(redim_v) != 0) {
		switch (redim_v->type) {
		case SDL_QUIT: {
			return false;
            }
		case SDL_WINDOWEVENT: {
			return (redim_v->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) ?
			(printf("Ancho de ventana: %d Altura de ventana: %d\n", redim_v->window.data1, redim_v->window.data2), true) 
			: (printf("Dimensionas de la ventana sin cambios\n"),true);
            }
		default: { return true; }
        }
    }
	return true;
}

void motor_grafico(bool ejecucion, SDL_Window *ventana, SDL_Renderer *puntos, SDL_Event *redim_v) {
	while(ejecucion) { ejecucion = redimensionar_V(redim_v); }
	limpiar_SDL(ventana, puntos);
}
