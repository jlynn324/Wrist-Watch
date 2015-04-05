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
