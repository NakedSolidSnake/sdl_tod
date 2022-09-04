#include <tod.h>
#include <string.h>

static bool tod_sdl_init (void);
static bool tod_create_window (tod_t *tod, const char *title, uint16_t width, uint16_t height);

bool tod_init (tod_t *tod)
{
    bool status = false;

    if (tod != NULL)
    {
        memset (tod, 0, sizeof (tod_t));
        status = true;
    }

    return status;
}

bool tod_open (tod_t *tod, tod_args_t *args)
{
    bool status = false;

    if (tod != NULL && args != NULL)
    {
        if (tod_sdl_init () == true && 
            tod_create_window (tod, args->title, args->width, args->height) == true)
        {
            status = true;
        }
    }

    return status;
}

bool tod_run (tod_t *tod)
{
    bool status = false;
    SDL_Surface *surface;

    if (tod != NULL)
    {
        do
        {
            surface = SDL_GetWindowSurface (tod->window);

            SDL_FillRect (surface, NULL, SDL_MapRGB (surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface (tod->window);
            SDL_Delay (2000);
        } while (false);

        status = true;
    }

    return status;
}

bool tod_close (tod_t *tod)
{
    bool status = false;

    if (tod != NULL)
    {
        memset (tod, 0, sizeof (tod_t));
        status = true;
    }

    return status;
}

static bool tod_sdl_init (void)
{
    bool status = false;

    if (SDL_Init (SDL_INIT_EVERYTHING) >= 0)
        status = true;

    return status;
}

static bool tod_create_window (tod_t *tod, const char *title, uint16_t width, uint16_t height)
{
    bool status = false;

    tod->window = SDL_CreateWindow (title,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    width,
                                    height, 
                                    SDL_WINDOW_SHOWN);

    if (tod->window != NULL)
        status = true;

    return status;
}