#ifndef TOD_H_
#define TOD_H_

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct 
{
    SDL_Window *window;
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

#endif /* TOD_H_ */
