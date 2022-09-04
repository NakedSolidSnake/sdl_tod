#include <tod.h>

int main (int argc, char *argv[])
{
    tod_t tod;

    tod_args_t args = 
    {
        .title = "Hello SDL",
        .width = 800,
        .height = 600
    };

    tod_init (&tod);
    tod_open (&tod, &args);
    tod_run (&tod);
    tod_close (&tod);

    return 0;
}