#include <pebble.h>

Window *g_window;
TextLayer *choiceOne;

void window_load(Window *window)    //takes care of elements within window object
{
    //Creating the text layer
    choiceOne = text_layer_create(GRect(10, 5, 144, 168));  
    text_layer_set_background_color(choiceOne, GColorClear);
    text_layer_set_text_color(choiceOne, GColorBlack);
    
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(choiceOne));
    text_layer_set_text(choiceOne, "    Emergency \n\n\n\n    911 \n\n\n\n\n    Message Sphere");
}

void window_unload(Window *window)    //same as above but for destruction
{
    text_layer_destroy(choiceOne);
}

void init()
{
    g_window = window_create();
    window_set_window_handlers(g_window, (WindowHandlers) 
    {
        .load = window_load,
        .unload = window_unload,
    });
    
    window_stack_push(g_window, true);    //***TRY using 'false' and commenting this out
}

void deinit()
{
    window_destroy(g_window);
}


int main(void)
{
    init();
    app_event_loop();    //handles event from start of app life to end 
    deinit();
}
