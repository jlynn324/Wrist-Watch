#include <pebble.h>
    
Window *g_window;

void window_load(Window *window)
{
    //We will add the creation of Window's elements
}

void window_unload(Window *window)
{
    //We will safely estroy the Window's elements here    
    window_destroy(g_window);
}

void init()
{
    //Create app elements here  
    g_window = window_create();
    window_set_window_handlers(g_window, (WindowHandlers) {
        .load = window_load,
        .unload = window_unload,
    });
    
    window_stack_push(g_window, true);
}

void deinit()
{
    //Destroy app elements here
}

int main(void)
{
    init();
    //handles all events that happen from start of app to end of app
    app_event_loop();
    deinit();
}