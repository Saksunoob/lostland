#include "input.h"

using namespace Engine;

void Input::newFrame() {
    for (int key_i = 0; key_i < KEYS_AMOUNT; key_i++) {
        Input::key_states[key_i].just_changed = false;
    }

    for (int m_button = 0; m_button < 8; m_button++) {
        Input::mouse_button_states[m_button].just_changed = false;
    }
}

void Input::processInputEvent(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN: {
            KeyState *state = &Input::key_states[Input::key_from_sdlkey(event.key.keysym)];
            state->just_changed = true;
            state->pressed = true;
            break;
        }
        case SDL_KEYUP: {
            KeyState *state = &Input::key_states[Input::key_from_sdlkey(event.key.keysym)];
            state->just_changed = true;
            state->pressed = false;
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            KeyState *state = &Input::mouse_button_states[event.button.button-1];
            state->just_changed = true;
            state->pressed = true;
            break;
        }
        case SDL_MOUSEBUTTONUP: {
            KeyState *state = &Input::mouse_button_states[event.button.button-1];
            state->just_changed = true;
            state->pressed = false;
            break;
        }
        case SDL_MOUSEMOTION: {
            mouse_pos.x = event.motion.x;
            mouse_pos.y = event.motion.y;
            mouse_delta.x = event.motion.xrel;
            mouse_delta.y = event.motion.yrel;
        }
    }
}

bool Input::get_key_pressed(Key key) {
    return key_states[key].pressed;
}
bool Input::get_key_released(Key key) {
    return !key_states[key].pressed;
}
bool Input::get_key_just_pressed(Key key) {
    KeyState key_state = key_states[key];
    return key_state.pressed && key_state.just_changed;
}
bool Input::get_key_just_released(Key key) {
    KeyState key_state = key_states[key];
    return !key_state.pressed && key_state.just_changed;
}

bool Input::get_mouse_button_pressed(MouseButton button) {
    return mouse_button_states[button].pressed;
}
bool Input::get_mouse_button_just_pressed(MouseButton button) {
    KeyState button_state = mouse_button_states[button];
    return button_state.pressed && button_state.just_changed;
}
bool Input::get_mouse_button_released(MouseButton button) {
    return !mouse_button_states[button].pressed;
}
bool Input::get_mouse_button_just_released(MouseButton button) {
    KeyState button_state = mouse_button_states[button];
    return !button_state.pressed && button_state.just_changed;
}

IVec2 Input::get_mouse_pos() {
    return mouse_pos;
}
IVec2 Input::get_mouse_delta() {
    return mouse_delta;
}Input::Key Input::key_from_sdlkey(SDL_Keysym sdl_key) {


    switch (sdl_key.sym) {
        case SDLK_BACKSPACE:
            return KEY_BACKSPACE;
        case SDLK_TAB:
            return KEY_TAB;
        case SDLK_CLEAR:
            return KEY_CLEAR;
        case SDLK_RETURN:
            return KEY_RETURN;
        case SDLK_PAUSE:
            return KEY_PAUSE;
        case SDLK_ESCAPE:
            return KEY_ESCAPE;
        case SDLK_SPACE:
            return KEY_SPACE;
        case SDLK_EXCLAIM:
            return KEY_EXCLAIM;
        case SDLK_QUOTEDBL:
            return KEY_QUOTEDBL;
        case SDLK_HASH:
            return KEY_HASH;
        case SDLK_DOLLAR:
            return KEY_DOLLAR;
        case SDLK_AMPERSAND:
            return KEY_AMPERSAND;
        case SDLK_QUOTE:
            return KEY_QUOTE;
        case SDLK_LEFTPAREN:
            return KEY_LEFTPAREN;
        case SDLK_RIGHTPAREN:
            return KEY_RIGHTPAREN;
        case SDLK_ASTERISK:
            return KEY_ASTERISK;
        case SDLK_PLUS:
            return KEY_PLUS;
        case SDLK_COMMA:
            return KEY_COMMA;
        case SDLK_MINUS:
            return KEY_MINUS;
        case SDLK_PERIOD:
            return KEY_PERIOD;
        case SDLK_SLASH:
            return KEY_SLASH;
        case SDLK_0:
            return KEY_0;
        case SDLK_1:
            return KEY_1;
        case SDLK_2:
            return KEY_2;
        case SDLK_3:
            return KEY_3;
        case SDLK_4:
            return KEY_4;
        case SDLK_5:
            return KEY_5;
        case SDLK_6:
            return KEY_6;
        case SDLK_7:
            return KEY_7;
        case SDLK_8:
            return KEY_8;
        case SDLK_9:
            return KEY_9;
        case SDLK_COLON:
            return KEY_COLON;
        case SDLK_SEMICOLON:
            return KEY_SEMICOLON;
        case SDLK_LESS:
            return KEY_LESS;
        case SDLK_EQUALS:
            return KEY_EQUALS;
        case SDLK_GREATER:
            return KEY_GREATER;
        case SDLK_QUESTION:
            return KEY_QUESTION;
        case SDLK_AT:
            return KEY_AT;
        case SDLK_LEFTBRACKET:
            return KEY_LEFTBRACKET;
        case SDLK_BACKSLASH:
            return KEY_BACKSLASH;
        case SDLK_RIGHTBRACKET:
            return KEY_RIGHTBRACKET;
        case SDLK_CARET:
            return KEY_CARET;
        case SDLK_UNDERSCORE:
            return KEY_UNDERSCORE;
        case SDLK_BACKQUOTE:
            return KEY_BACKQUOTE;
        case SDLK_a:
            return KEY_A;
        case SDLK_b:
            return KEY_B;
        case SDLK_c:
            return KEY_C;
        case SDLK_d:
            return KEY_D;
        case SDLK_e:
            return KEY_E;
        case SDLK_f:
            return KEY_F;
        case SDLK_g:
            return KEY_G;
        case SDLK_h:
            return KEY_H;
        case SDLK_i:
            return KEY_I;
        case SDLK_j:
            return KEY_J;
        case SDLK_k:
            return KEY_K;
        case SDLK_l:
            return KEY_L;
        case SDLK_m:
            return KEY_M;
        case SDLK_n:
            return KEY_N;
        case SDLK_o:
            return KEY_O;
        case SDLK_p:
            return KEY_P;
        case SDLK_q:
            return KEY_Q;
        case SDLK_r:
            return KEY_R;
        case SDLK_s:
            return KEY_S;
        case SDLK_t:
            return KEY_T;
        case SDLK_u:
            return KEY_U;
        case SDLK_v:
            return KEY_V;
        case SDLK_w:
            return KEY_W;
        case SDLK_x:
            return KEY_X;
        case SDLK_y:
            return KEY_Y;
        case SDLK_z:
            return KEY_Z;
        case SDLK_DELETE:
            return KEY_DELETE;
        case SDLK_KP_0:
            return KEY_KP0;
        case SDLK_KP_1:
            return KEY_KP1;
        case SDLK_KP_2:
            return KEY_KP2;
        case SDLK_KP_3:
            return KEY_KP3;
        case SDLK_KP_4:
            return KEY_KP4;
        case SDLK_KP_5:
            return KEY_KP5;
        case SDLK_KP_6:
            return KEY_KP6;
        case SDLK_KP_7:
            return KEY_KP7;
        case SDLK_KP_8:
            return KEY_KP8;
        case SDLK_KP_9:
            return KEY_KP9;
        case SDLK_KP_PERIOD:
            return KEY_KP_PERIOD;
        case SDLK_KP_DIVIDE:
            return KEY_KP_DIVIDE;
        case SDLK_KP_MULTIPLY:
            return KEY_KP_MULTIPLY;
        case SDLK_KP_MINUS:
            return KEY_KP_MINUS;
        case SDLK_KP_PLUS:
            return KEY_KP_PLUS;
        case SDLK_KP_ENTER:
            return KEY_KP_ENTER;
        case SDLK_KP_EQUALS:
            return KEY_KP_EQUALS;
        case SDLK_UP:
            return KEY_UP;
        case SDLK_DOWN:
            return KEY_DOWN;
        case SDLK_RIGHT:
            return KEY_RIGHT;
        case SDLK_LEFT:
            return KEY_LEFT;
        case SDLK_INSERT:
            return KEY_INSERT;
        case SDLK_HOME:
            return KEY_HOME;
        case SDLK_END:
            return KEY_END;
        case SDLK_PAGEUP:
            return KEY_PAGEUP;
        case SDLK_PAGEDOWN:
            return KEY_PAGEDOWN;
        case SDLK_F1:
            return KEY_F1;
        case SDLK_F2:
            return KEY_F2;
        case SDLK_F3:
            return KEY_F3;
        case SDLK_F4:
            return KEY_F4;
        case SDLK_F5:
            return KEY_F5;
        case SDLK_F6:
            return KEY_F6;
        case SDLK_F7:
            return KEY_F7;
        case SDLK_F8:
            return KEY_F8;
        case SDLK_F9:
            return KEY_F9;
        case SDLK_F10:
            return KEY_F10;
        case SDLK_F11:
            return KEY_F11;
        case SDLK_F12:
            return KEY_F12;
        case SDLK_F13:
            return KEY_F13;
        case SDLK_F14:
            return KEY_F14;
        case SDLK_F15:
            return KEY_F15;
        case SDLK_NUMLOCKCLEAR:
            return KEY_NUMLOCK;
        case SDLK_CAPSLOCK:
            return KEY_CAPSLOCK;
        case SDLK_SCROLLLOCK:
            return KEY_SCROLLOCK;
        case SDLK_RSHIFT:
            return KEY_RSHIFT;
        case SDLK_LSHIFT:
            return KEY_LSHIFT;
        case SDLK_RCTRL:
            return KEY_RCTRL;
        case SDLK_LCTRL:
            return KEY_LCTRL;
        case SDLK_RALT:
            return KEY_RALT;
        case SDLK_LALT:
            return KEY_LALT;
        case SDLK_LGUI:
            return KEY_LSUPER;
        case SDLK_RGUI:
            return KEY_RSUPER;
        case SDLK_MODE:
            return KEY_MODE;
        case SDLK_HELP:
            return KEY_HELP;
        case SDLK_PRINTSCREEN:
            return KEY_PRINT;
        case SDLK_SYSREQ:
            return KEY_SYSREQ;
        case SDLK_MENU:
            return KEY_MENU;
        case SDLK_POWER:
            return KEY_POWER;
    }
}