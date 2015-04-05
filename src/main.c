#include <pebble.h>
#include <Bluetooth.h>
#include <Watch_App_Face.h>
    
static Window *s_main_window;
Window *g_window;
    
void init() {
    //----------------------watch_app-------------------------------------
    g_window = window_create();
    window_set_window_handlers(g_window, (WindowHandlers) 
    {
        .load = window_load,
        .unload = window_unload,
    });
    window_stack_push(g_window, true); 
    //----------------------bluetooth-----------------------------------------------
  // Create main Window 
    
//   s_main_window = window_create();
//   window_set_window_handlers(s_main_window, (WindowHandlers) {
//     .load = main_window_load,
//     .unload = main_window_unload
//   });
  window_set_click_config_provider(s_main_window, click_config_provider);
  window_stack_push(s_main_window, true);
}

void deinit() {
    
    //bluetooth
    // Destroy main Window
    window_destroy(s_main_window);
    
    //watch app
    window_destroy(g_window);

}

int main(void) 
{
  init();
  app_event_loop();
  deinit();
}