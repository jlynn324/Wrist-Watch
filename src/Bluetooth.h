#ifndef BLUETOOTH_H   /* Include guard */
#define BLUETOOTH_H
    
#include <pebble.h>

//sends the int values to phone through Bluetooth
 void send_int(int key, int value);
//detects up button

 void up_click_handler(ClickRecognizerRef recognizer, void *context);
//detects middle button

 void select_click_handler(ClickRecognizerRef recognizer, void *context); 
//detects down button

 void down_click_handler(ClickRecognizerRef recognizer, void *context);
//configures button stuff

 void click_config_provider(void *context);
//loads window

 void main_window_load(Window *window);
//unloads window

 void main_window_unload(Window *window);
//initializer

#endif