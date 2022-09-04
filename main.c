#include <tod.h>
#include <tod_image.h>

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

    tod_image_load_bmp (&image, "assets/hello.bmp");
    tod_set_window_image (&tod, image.surface);

    tod_run (&tod);

    tod_image_free_bmp (&image);
    tod_close (&tod);

    return 0;
}