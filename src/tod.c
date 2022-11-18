#include <tod.h>
#include <string.h>

static bool tod_sdl_init (void);
static bool tod_create_window (tod_t *tod, const char *title, uint16_t width, uint16_t height);
static void tod_handle_events (tod_t *tod);

typedef struct
{
    tod_key_t key;
    int sdl_key;
} tod_key_map_t;

typedef struct 
{
    tod_key_map_t keys[4];
    int amount;
} tod_keys_mapping_t;

static tod_keys_mapping_t mapping = 
{
    .keys = 
    {
        {.key = tod_key_up,    .sdl_key = SDLK_UP},
        {.key = tod_key_down,  .sdl_key = SDLK_DOWN},
        {.key = tod_key_left,  .sdl_key = SDLK_LEFT},
        {.key = tod_key_right, .sdl_key = SDLK_RIGHT},
    },
    .amount = 4
};

static tod_key_t tod_get_key (int sdl_key);

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
            tod->surface = SDL_GetWindowSurface (tod->window);
            tod->running = true;
            status = true;
        }
    }

    return status;
}

bool tod_run (tod_t *tod)
{
    bool status = false;    

    if (tod != NULL)
    {
        while (tod->running == true)
        {
            tod_handle_events (tod);

            SDL_UpdateWindowSurface (tod->window);
            SDL_Delay (20);
        } 

        status = true;
    }

    return status;
}

bool tod_close (tod_t *tod)
{
    bool status = false;

    if (tod != NULL)
    {
        SDL_DestroyWindow (tod->window);
        SDL_Quit ();
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

void tod_set_window_image (tod_t *tod, SDL_Surface *surface)
{
    if (tod != NULL && surface != NULL)
    {
        SDL_BlitSurface (surface, NULL, tod->surface, NULL);
    }
}

static void tod_handle_events (tod_t *tod)
{
    SDL_Event event;

    while (SDL_PollEvent (&event) != 0)
    {
        if (event.type == SDL_QUIT)
            tod->running = false;

        else if (event.type == SDL_KEYDOWN)
        {
            if (tod->events.on_press)
            {
                tod->events.on_press ((void *)tod, tod_get_key (event.key.keysym.sym));
            }
        }
    }
}

bool tod_add_image (tod_t *tod, tod_image_t image)
{
    bool status = false;

    if (tod->images.amount < TOD_IMAGES_AMOUNT)
    {
        memcpy (&tod->images.image[tod->images.amount], &image, sizeof (tod_image_t));
        tod->images.amount++;
        status = true;
    }

    return status;
}

tod_image_t *tod_get_image_by_name (tod_t *tod, const char *name)
{
    tod_image_t *image = NULL;

    for (int i = 0; i < tod->images.amount; i++)
    {
        if (strcmp (name, tod->images.image[i].name) == 0)
        {
            image = &tod->images.image[i];
            break;
        }
    }

    return image;
}

void tod_set_key_event (tod_t *tod, event_t event)
{
    if (tod != NULL && event != NULL)
    {
        tod->events.on_press = event;
    }
}

static tod_key_t tod_get_key (int sdl_key)
{
    tod_key_t key = tod_key_undefined;

    for (int i = 0; i < mapping.amount; i++)
    {
        if (sdl_key == mapping.keys[i].sdl_key)
        {
            key = mapping.keys[i].key;
            break;
        }
    }

    return key;
}