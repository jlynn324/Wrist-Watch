#include <Bluetooth.h>

static TextLayer *s_output_layer;

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
  text_layer_set_text(s_output_layer, "Calling emergency contact");
    
    send_int(1, 1);

}

 void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_output_layer, "Calling 911");
    
    send_int(2, 2);

}

 void down_click_handler(ClickRecognizerRef recognizer, void *context) {
    //TODO: Change to Send Text Message connection
  text_layer_set_text(s_output_layer, "Sending message");
    
    send_int(3, 3);
}

 void click_config_provider(void *context) {
  // Register the ClickHandlers
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

 void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect window_bounds = layer_get_bounds(window_layer);

    //TODO: Put the home screen stuff in this
  // Create output TextLayer
     
//   s_output_layer = text_layer_create(GRect(5, 0, window_bounds.size.w - 5, window_bounds.size.h));
//   text_layer_set_font(s_output_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
//   text_layer_set_text(s_output_layer, "No button pressed yet.");
//   text_layer_set_overflow_mode(s_output_layer, GTextOverflowModeWordWrap);
//   layer_add_child(window_layer, text_layer_get_layer(s_output_layer));
}

 void main_window_unload(Window *window) {
  // Destroy output TextLayer
  text_layer_destroy(s_output_layer);
}
