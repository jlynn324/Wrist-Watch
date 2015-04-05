#ifndef WATCH_APP_FACE_H   /* Include guard */
#define WATCH_APP_FACE_H
    
#include <pebble.h>

void window_load(Window *window);    //takes care of elements within window object
    
void window_unload(Window *window);    //same as above but for destruction

#endif 