#include <pebble.h>

//sends the int values to phone through Bluetooth
static void send_int(int key, int value);
//detects up button
static void up_click_handler(ClickRecognizerRef recognizer, void *context);
//detects down button
static void select_click_handler(ClickRecognizerRef recognizer, void *context); 