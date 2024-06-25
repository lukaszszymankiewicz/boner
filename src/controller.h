#include <stdbool.h>

#ifndef CONTROLLER_H
#define CONTROLLER_H

enum KEY_PRESSED_IDX {
    KEY_PRESSED_UP,
    KEY_PRESSED_DOWN,
    KEY_PRESSED_LEFT,
    KEY_PRESSED_RIGHT,
    KEY_PRESSED_SPACE,
    KEY_PRESSED_ALL
};

#define MAX_KEYS KEY_PRESSED_ALL

typedef struct controller {
    bool available;
    int  len;
    int  state[KEY_PRESSED_ALL];
    int  old_state[KEY_PRESSED_ALL];
} controller_t;

void CON_init();
void CON_update();
void CON_free();

bool CON_button_is_just_pressed(int key);
bool CON_button_is_just_released(int key);
bool CON_button_still_pressed(int key);
bool CON_button_pressed(int key);

#endif
