#include <tod.h>
#include <tod_image.h>

void on_press (void *object, tod_key_t key)
{
   tod_t *tod =  (tod_t *)object;
   tod_image_t *image = NULL;

   switch (key)
   {
   case tod_key_down:
    image = tod_get_image_by_name (tod, "down");
    break;

    case tod_key_up:
    image = tod_get_image_by_name (tod, "up");
    break;

    case tod_key_left:
    image = tod_get_image_by_name (tod, "left");
    break;

    case tod_key_right:
    image = tod_get_image_by_name (tod, "right");
    break;
   
   default:
    image = tod_get_image_by_name (tod, "background");
    break;
   }

   tod_set_window_image (tod, image->surface);
}

int main (int argc, char *argv[])
{
    tod_t tod;
    tod_image_t image;

    tod_args_t args = 
    {
        .title = "Hello SDL",
        .width = 800,
        .height = 600
    };

    tod_init (&tod);
    tod_open (&tod, &args);

    tod_image_load_bmp (&image, "background", "assets/hello.bmp");
    tod_add_image (&tod, image);
    tod_set_window_image (&tod, image.surface);

    tod_image_load_bmp (&image, "up", "assets/up.bmp");
    tod_add_image (&tod, image);

    tod_image_load_bmp (&image, "down", "assets/down.bmp");
    tod_add_image (&tod, image);

    tod_image_load_bmp (&image, "left", "assets/left.bmp");
    tod_add_image (&tod, image);

    tod_image_load_bmp (&image, "right", "assets/right.bmp");
    tod_add_image (&tod, image);

    tod_set_key_event (&tod, on_press);

    tod_run (&tod);

    tod_image_free_bmp (&image);
    tod_close (&tod);

    return 0;
}