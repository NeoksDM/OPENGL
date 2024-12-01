#ifndef UTILIDADES_SDL_H
#define UTILIDADES_SDL_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#define ANCHO_VENTANA 800
#define ALTO_VENTANA 600

bool iniciar_SDL(SDL_Window *ventana, SDL_Renderer *puntos);
int limpiar_SDL(SDL_Window *ventana, SDL_Renderer *puntos);
bool redimensionar_V(SDL_Event *redim_v);
void motor_grafico(bool ejecucion, SDL_Window *ventana, SDL_Renderer *puntos, SDL_Event *redim_v);

#endif
