//TODO:Fix the font crash

/*#include <pebble.h>
    
Window *g_window;
TextLayer *g_text_layer;
static GFont s_time_font;
// static TextLayer *s_time_layer;

void window_load(Window *window)
{
    //We will add the creation of Window's elements, 
    //such as, in this case, layered text
    
    //makes text layer and sets its frame to the full screen
    g_text_layer = text_layer_create(GRect(10, 0, 144, 168));
    //makes bgd color transparent
    text_layer_set_background_color(g_text_layer, GColorClear);
    //set text color black
    text_layer_set_text_color(g_text_layer, GColorBlack);
    
    //TODO: change font size to bigger size
    // Create GFont
    s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_TEXT_18));

    // Apply to TextLayer
    text_layer_set_font(g_text_layer, s_time_font);
    
    //child (root) layers drawn in front of parent (window) layers
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(g_text_layer));
    
    //display whatever text you want in quotes
    text_layer_set_text(g_text_layer, "\nEmergency call\n \n \nCall 911\n \n \nSend text message");
}

void window_unload(Window *window)
{
    //We will safely destroy the Window's elements here    
    window_destroy(g_window);
    text_layer_destroy(g_text_layer);
    // Unload GFont
    fonts_unload_custom_font(s_time_font);
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
    window_unload(g_window);
}

int main(void)
{
    init();
    //handles all events that happen from start of app to end of app
    app_event_loop();
    deinit();
}*/

//original
/*
#include <pebble.h>
    
Window *g_window;
TextLayer *g_text_layer;
static GFont s_time_font;
// static TextLayer *s_time_layer;

void window_load(Window *window)
{
    //We will add the creation of Window's elements, 
    //such as, in this case, layered text
    
    //makes text layer and sets its frame to the full screen
    g_text_layer = text_layer_create(GRect(10, 0, 144, 168));
    //makes bgd color transparent
    text_layer_set_background_color(g_text_layer, GColorClear);
    //set text color black
    text_layer_set_text_color(g_text_layer, GColorBlack);
    
    //TODO: change font size to bigger size
    // Create GFont
    s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_TEXT_18));

    // Apply to TextLayer
    text_layer_set_font(g_text_layer, s_time_font);
    
    //child (root) layers drawn in front of parent (window) layers
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(g_text_layer));
    
    //display whatever text you want in quotes
    text_layer_set_text(g_text_layer, "\nEmergency call\n \n \nCall 911\n \n \nSend text message");
}

void window_unload(Window *window)
{
    //We will safely destroy the Window's elements here    
    window_destroy(g_window);
    text_layer_destroy(g_text_layer);
    // Unload GFont
    fonts_unload_custom_font(s_time_font);
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
    window_unload(g_window);
}

int main(void)
{
    init();
    //handles all events that happen from start of app to end of app
    app_event_loop();
    deinit();
}*/