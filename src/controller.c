/* Controller/keyboard related code.
*/

#include <SDL2/SDL_stdinc.h>

#include <stdbool.h>
#include <stdlib.h>

#include "controller.h"
#include "modules.h"
#include "macros.h"


void CON_init(
) {
    keyboard              = NULL;
    keyboard              = (controller_t*)malloc(sizeof(controller_t));

    keyboard->available   = true;

    // get the len of SDL keyboard state array
    SDL_GetKeyboardState(&(keyboard->len));
    
    memset(keyboard->state, 0, sizeof(int) * KEY_PRESSED_ALL);
    memset(keyboard->old_state, 0, sizeof(int) * KEY_PRESSED_ALL);
}

// update the state of the controller
void CON_update(
) {
    Uint8* state = NULL;
    state        = (Uint8*)SDL_GetKeyboardState(NULL);
    
    // copy keys
    for (int n=0; n<KEY_PRESSED_ALL; n++) {
        keyboard->old_state[n] = keyboard->state[n];
    }
    
    // zero the current state
    memset(keyboard->state, 0, sizeof(int) * KEY_PRESSED_ALL);

    // update keys (best way EVAH!)
    if (state[SDL_SCANCODE_SPACE]) {
        keyboard->state[KEY_PRESSED_SPACE]++;
    }

    if (state[SDL_SCANCODE_W]) {
        keyboard->state[KEY_PRESSED_UP]++;
    }

    if (state[SDL_SCANCODE_S]) {
        keyboard->state[KEY_PRESSED_DOWN]++;
    }

    if (state[SDL_SCANCODE_A]) {
        keyboard->state[KEY_PRESSED_LEFT]++;
    }

    if (state[SDL_SCANCODE_D]) {
        keyboard->state[KEY_PRESSED_RIGHT]++;
    }
    state = NULL;
}

bool CON_button_pressed(
    int key
) {
    return keyboard->state[key];
}

bool CON_button_is_just_pressed(
    int key
) {
    return keyboard->state[key] && !(keyboard->old_state[key]);
}

bool CON_button_still_pressed(
    int key
) {
    return keyboard->state[key] && keyboard->old_state[key];
}

bool CON_button_is_just_released(
    int key
) {
    return !(keyboard->state[key]) && keyboard->old_state[key];
}

void CON_free(
) {
    free(keyboard);
    keyboard = NULL;
}
