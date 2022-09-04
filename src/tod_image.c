#include <tod_image.h>

bool tod_image_load_bmp (tod_image_t *tod_image, const char *file)
{
    bool status = false;

    if (tod_image != NULL && file != NULL)
    {
        tod_image->surface = SDL_LoadBMP (file);
        status = true;
    }

    return status;
}

bool tod_image_free_bmp (tod_image_t *tod_image)
{
    bool status = false;

    if (tod_image != NULL && tod_image->surface != NULL)
    {
        SDL_FreeSurface (tod_image->surface);
        status = true;
    }

    return status;
}