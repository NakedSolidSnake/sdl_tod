#ifndef TOD_KEY_EVENTS_H_
#define TOD_KEY_EVENTS_H_

#include <tod.h>

typedef enum 
{
    tod_key_up,
    tod_key_down,
    tod_key_left,
    tod_key_right,
    tod_key_undefined
} tod_key_t;

typedef struct 
{
    void (*on_press) (void *object, tod_key_t key);
} tod_key_event_t;

#endif /* TOD_KEY_EVENTS_H_ */
