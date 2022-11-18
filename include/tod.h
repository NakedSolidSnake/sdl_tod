#ifndef TOD_H_
#define TOD_H_

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <tod_key_events.h>
#include <tod_image.h>

#define TOD_IMAGES_AMOUNT       10

typedef void (*event_t) (void *object, tod_key_t key);

typedef struct 
{
    SDL_Window *window;
    SDL_Surface *surface;
    bool running;
    struct
    {
        tod_image_t image[TOD_IMAGES_AMOUNT];
        int amount;
    } images;
    tod_key_event_t events;
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
bool tod_add_image (tod_t *tod, tod_image_t image);
tod_image_t *tod_get_image_by_name (tod_t *tod, const char *name);
void tod_set_key_event (tod_t *tod, event_t event);

#endif /* TOD_H_ */
