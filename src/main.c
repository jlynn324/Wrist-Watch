#include <pebble.h>
#include <Watch_App_Face.h>
    void init2();
    void deinit2();
static Window *s_main_window;
Window *g_window;

// -------------------  BLUETOOTH combo attempt begin --------------------------

static TextLayer *try;

//Helper function-send numbers 1-3 corresponding to the options
//to the phone

 void send_int(int key, int value) {
  DictionaryIterator *iter;
  app_message_outbox_begin(&iter);
  dict_write_int(iter, key, &value, sizeof(int), true);
    //Send the data!
  app_message_outbox_send();
}


// --------------------------------------Begin Button Press-------------------------------------------

 void up_click_handler(ClickRecognizerRef recognizer, void *context) {
    //TODO: Change to Emergency Call connection
  
     init2();
     
     text_layer_set_text(try, "Calling emergency contact");
    if(window_stack_contains_window(s_main_window))
        
     APP_LOG(APP_LOG_LEVEL_INFO, "PRESENT.");
     //send_int(1, 1);
    psleep(10000);
     deinit2();


}

 void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  
     
    init2();
    text_layer_set_text(try, "Calling 911");
    //send_int(2, 2);
    
    
     deinit2();


}

 void down_click_handler(ClickRecognizerRef recognizer, void *context) {
    //TODO: Change to Send Text Message connection
  init2();
     
     text_layer_set_text(try, "Sending message");
    
    
    //send_int(3, 3);
     
     deinit2();

}

 void click_config_provider(void *context) {
  // Register the ClickHandlers
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

 void main_window_load(Window *window) {

     // Create output TextLayer
    try = text_layer_create(GRect(10, 5, 144, 168));  
    text_layer_set_background_color(try, GColorClear);
    text_layer_set_text_color(try, GColorBlack);
    
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(try));
//     window_set_click_config_provider(s_main_window, click_config_provider);
     
    

}

 void main_window_unload(Window *window) {
  // Destroy output TextLayer
  text_layer_destroy(try);
}

// -------------------  BLUETOOTH combo attempt end --------------------------

void init() {
    //----------------------watch_app-------------------------------------
    g_window = window_create();
    window_set_window_handlers(g_window, (WindowHandlers) 
    {
        .load = window_load,
        .unload = window_unload,
    });
    
    window_set_click_config_provider(g_window, click_config_provider);
    window_stack_push(g_window, true); 
    psleep(100);
    
    

    //----------------------bluetooth-----------------------------------------------
  // Create main Window 
    
}

void deinit() {
    
    //bluetooth
    // Destroy main Window
    
    //watch app
    window_stack_remove(g_window,true);

    window_destroy(g_window);

}

void init2()
{
    s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
    window_stack_push(s_main_window, true);

     APP_LOG(APP_LOG_LEVEL_INFO, "PUSHED.");
}

void deinit2()
{
    window_stack_remove(s_main_window,true);
    
     APP_LOG(APP_LOG_LEVEL_INFO, "POPPED.");
     window_destroy(s_main_window);
}

int main(void) 
{
  init();
  app_event_loop();
  deinit();
}


