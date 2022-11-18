#ifndef TOD_IMAGE_H_
#define TOD_IMAGE_H_

#include <stdbool.h>
#include <SDL2/SDL.h>

#define TOD_IMAGE_NAME_SIZE     50

typedef struct 
{
    char name[TOD_IMAGE_NAME_SIZE];
    SDL_Surface *surface;
} tod_image_t;

bool tod_image_load_bmp (tod_image_t *tod_image, const char *name, const char *file);
bool tod_image_free_bmp (tod_image_t *tod_image);

#endif /* TOD_IMAGE_H_ */
