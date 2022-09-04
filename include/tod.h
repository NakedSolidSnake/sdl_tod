#ifndef TOD_H_
#define TOD_H_

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct 
{
    SDL_Window *window;
    SDL_Surface *surface;
} tod_t;

typedef struct 
{
    const char *title;
    uint16_t width;
    uint16_t height;
} tod_args_t;

bool tod_init (tod_t *tod);
bool tod_open (tod_t *tod, tod_args_t *args);
bool tod_run (tod_t *tod);
bool tod_close (tod_t *tod);

void tod_set_window_image (tod_t *tod, SDL_Surface *surface);

#endif /* TOD_H_ */
