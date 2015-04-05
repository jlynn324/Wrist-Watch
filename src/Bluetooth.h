#include <pebble.h>

//sends the int values to phone through Bluetooth
static void send_int(int key, int value);
//detects up button
static void up_click_handler(ClickRecognizerRef recognizer, void *context);
//detects middle button
static void select_click_handler(ClickRecognizerRef recognizer, void *context); 
//detects down button
static void down_click_handler(ClickRecognizerRef recognizer, void *context);
//configures button stuff
static void click_config_provider(void *context);
//loads window
static void main_window_load(Window *window);
//unloads window
static void main_window_unload(Window *window);
//initializer
static void init(); 
//deinitializer
static void deinit(); 
