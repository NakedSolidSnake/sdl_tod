#include <tod_image.h>
#include <string.h>

bool tod_image_load_bmp (tod_image_t *tod_image, const char *name, const char *file)
{
    bool status = false;

    if (tod_image != NULL && name != NULL &&file != NULL)
    {
        memset (tod_image, 0, sizeof (tod_image_t));
        tod_image->surface = SDL_LoadBMP (file);
        strncpy (tod_image->name, name, TOD_IMAGE_NAME_SIZE);
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