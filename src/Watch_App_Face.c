#include <Watch_App_Face.h>

TextLayer *choiceOne;

void window_load(Window *window)    
{
    //Creating the text layer
    choiceOne = text_layer_create(GRect(10, 5, 144, 168));  
    text_layer_set_background_color(choiceOne, GColorClear);
    text_layer_set_text_color(choiceOne, GColorBlack);
    
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(choiceOne));
    text_layer_set_text(choiceOne, "    Emergency Call \n\n\n\n    Call 911 \n\n\n\n\n    Send Text Message");
}

void window_unload(Window *window)    
{
    text_layer_destroy(choiceOne);
}
