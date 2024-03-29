#include "input.h"

using namespace Engine;

void Input::init() {
    for (int i = 0; i < KEYS_AMOUNT; ++i) {
        key_states[i] = { false, false };
    }
}


void Input::processInput(GLFWwindow* window) {
    for (int key_i = 0; key_i < KEYS_AMOUNT; key_i++) {
        Key key = (Key)key_i;
        bool new_state = glfwGetKey(window, Input::get_glfw_key(key));
        KeyState *key_state = &key_states[key];
        if (key_state->pressed == new_state) {
            key_state->just_changed = false;
            continue;
        }

        key_state->pressed = new_state;
        key_state->just_changed = true;
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


int Input::get_glfw_key(Key key) {
    switch (key) {
        case Key::KEY_SPACE: return GLFW_KEY_SPACE;
        case Key::KEY_APOSTROPHE: return GLFW_KEY_APOSTROPHE;
        case Key::KEY_COMMA: return GLFW_KEY_COMMA;
        case Key::KEY_MINUS: return GLFW_KEY_MINUS;
        case Key::KEY_PERIOD: return GLFW_KEY_PERIOD;
        case Key::KEY_SLASH: return GLFW_KEY_SLASH;
        case Key::KEY_0: return GLFW_KEY_0;
        case Key::KEY_1: return GLFW_KEY_1;
        case Key::KEY_2: return GLFW_KEY_2;
        case Key::KEY_3: return GLFW_KEY_3;
        case Key::KEY_4: return GLFW_KEY_4;
        case Key::KEY_5: return GLFW_KEY_5;
        case Key::KEY_6: return GLFW_KEY_6;
        case Key::KEY_7: return GLFW_KEY_7;
        case Key::KEY_8: return GLFW_KEY_8;
        case Key::KEY_9: return GLFW_KEY_9;
        case Key::KEY_SEMICOLON: return GLFW_KEY_SEMICOLON;
        case Key::KEY_EQUAL: return GLFW_KEY_EQUAL;
        case Key::KEY_A: return GLFW_KEY_A;
        case Key::KEY_B: return GLFW_KEY_B;
        case Key::KEY_C: return GLFW_KEY_C;
        case Key::KEY_D: return GLFW_KEY_D;
        case Key::KEY_E: return GLFW_KEY_E;
        case Key::KEY_F: return GLFW_KEY_F;
        case Key::KEY_G: return GLFW_KEY_G;
        case Key::KEY_H: return GLFW_KEY_H;
        case Key::KEY_I: return GLFW_KEY_I;
        case Key::KEY_J: return GLFW_KEY_J;
        case Key::KEY_K: return GLFW_KEY_K;
        case Key::KEY_L: return GLFW_KEY_L;
        case Key::KEY_M: return GLFW_KEY_M;
        case Key::KEY_N: return GLFW_KEY_N;
        case Key::KEY_O: return GLFW_KEY_O;
        case Key::KEY_P: return GLFW_KEY_P;
        case Key::KEY_Q: return GLFW_KEY_Q;
        case Key::KEY_R: return GLFW_KEY_R;
        case Key::KEY_S: return GLFW_KEY_S;
        case Key::KEY_T: return GLFW_KEY_T;
        case Key::KEY_U: return GLFW_KEY_U;
        case Key::KEY_V: return GLFW_KEY_V;
        case Key::KEY_W: return GLFW_KEY_W;
        case Key::KEY_X: return GLFW_KEY_X;
        case Key::KEY_Y: return GLFW_KEY_Y;
        case Key::KEY_Z: return GLFW_KEY_Z;
        case Key::KEY_LEFT_BRACKET: return GLFW_KEY_LEFT_BRACKET;
        case Key::KEY_BACKSLASH: return GLFW_KEY_BACKSLASH;
        case Key::KEY_RIGHT_BRACKET: return GLFW_KEY_RIGHT_BRACKET;
        case Key::KEY_GRAVE_ACCENT: return GLFW_KEY_GRAVE_ACCENT;
        case Key::KEY_WORLD_1: return GLFW_KEY_WORLD_1;
        case Key::KEY_WORLD_2: return GLFW_KEY_WORLD_2;
        case Key::KEY_ESCAPE: return GLFW_KEY_ESCAPE;
        case Key::KEY_ENTER: return GLFW_KEY_ENTER;
        case Key::KEY_TAB: return GLFW_KEY_TAB;
        case Key::KEY_BACKSPACE: return GLFW_KEY_BACKSPACE;
        case Key::KEY_INSERT: return GLFW_KEY_INSERT;
        case Key::KEY_DELETE: return GLFW_KEY_DELETE;
        case Key::KEY_RIGHT: return GLFW_KEY_RIGHT;
        case Key::KEY_LEFT: return GLFW_KEY_LEFT;
        case Key::KEY_DOWN: return GLFW_KEY_DOWN;
        case Key::KEY_UP: return GLFW_KEY_UP;
        case Key::KEY_PAGE_UP: return GLFW_KEY_PAGE_UP;
        case Key::KEY_PAGE_DOWN: return GLFW_KEY_PAGE_DOWN;
        case Key::KEY_HOME: return GLFW_KEY_HOME;
        case Key::KEY_END: return GLFW_KEY_END;
        case Key::KEY_CAPS_LOCK: return GLFW_KEY_CAPS_LOCK;
        case Key::KEY_SCROLL_LOCK: return GLFW_KEY_SCROLL_LOCK;
        case Key::KEY_NUM_LOCK: return GLFW_KEY_NUM_LOCK;
        case Key::KEY_PRINT_SCREEN: return GLFW_KEY_PRINT_SCREEN;
        case Key::KEY_PAUSE: return GLFW_KEY_PAUSE;
        case Key::KEY_F1: return GLFW_KEY_F1;
        case Key::KEY_F2: return GLFW_KEY_F2;
        case Key::KEY_F3: return GLFW_KEY_F3;
        case Key::KEY_F4: return GLFW_KEY_F4;
        case Key::KEY_F5: return GLFW_KEY_F5;
        case Key::KEY_F6: return GLFW_KEY_F6;
        case Key::KEY_F7: return GLFW_KEY_F7;
        case Key::KEY_F8: return GLFW_KEY_F8;
        case Key::KEY_F9: return GLFW_KEY_F9;
        case Key::KEY_F10: return GLFW_KEY_F10;
        case Key::KEY_F11: return GLFW_KEY_F11;
        case Key::KEY_F12: return GLFW_KEY_F12;
        case Key::KEY_F13: return GLFW_KEY_F13;
        case Key::KEY_F14: return GLFW_KEY_F14;
        case Key::KEY_F15: return GLFW_KEY_F15;
        case Key::KEY_F16: return GLFW_KEY_F16;
        case Key::KEY_F17: return GLFW_KEY_F17;
        case Key::KEY_F18: return GLFW_KEY_F18;
        case Key::KEY_F19: return GLFW_KEY_F19;
        case Key::KEY_F20: return GLFW_KEY_F20;
        case Key::KEY_F21: return GLFW_KEY_F21;
        case Key::KEY_F22: return GLFW_KEY_F22;
        case Key::KEY_F23: return GLFW_KEY_F23;
        case Key::KEY_F24: return GLFW_KEY_F24;
        case Key::KEY_F25: return GLFW_KEY_F25;
        case Key::KEY_KP_0: return GLFW_KEY_KP_0;
        case Key::KEY_KP_1: return GLFW_KEY_KP_1;
        case Key::KEY_KP_2: return GLFW_KEY_KP_2;
        case Key::KEY_KP_3: return GLFW_KEY_KP_3;
        case Key::KEY_KP_4: return GLFW_KEY_KP_4;
        case Key::KEY_KP_5: return GLFW_KEY_KP_5;
        case Key::KEY_KP_6: return GLFW_KEY_KP_6;
        case Key::KEY_KP_7: return GLFW_KEY_KP_7;
        case Key::KEY_KP_8: return GLFW_KEY_KP_8;
        case Key::KEY_KP_9: return GLFW_KEY_KP_9;
        case Key::KEY_KP_DECIMAL: return GLFW_KEY_KP_DECIMAL;
        case Key::KEY_KP_DIVIDE: return GLFW_KEY_KP_DIVIDE;
        case Key::KEY_KP_MULTIPLY: return GLFW_KEY_KP_MULTIPLY;
        case Key::KEY_KP_SUBTRACT: return GLFW_KEY_KP_SUBTRACT;
        case Key::KEY_KP_ADD: return GLFW_KEY_KP_ADD;
        case Key::KEY_KP_ENTER: return GLFW_KEY_KP_ENTER;
        case Key::KEY_KP_EQUAL: return GLFW_KEY_KP_EQUAL;
        case Key::KEY_LEFT_SHIFT: return GLFW_KEY_LEFT_SHIFT;
        case Key::KEY_LEFT_CONTROL: return GLFW_KEY_LEFT_CONTROL;
        case Key::KEY_LEFT_ALT: return GLFW_KEY_LEFT_ALT;
        case Key::KEY_LEFT_SUPER: return GLFW_KEY_LEFT_SUPER;
        case Key::KEY_RIGHT_SHIFT: return GLFW_KEY_RIGHT_SHIFT;
        case Key::KEY_RIGHT_CONTROL: return GLFW_KEY_RIGHT_CONTROL;
        case Key::KEY_RIGHT_ALT: return GLFW_KEY_RIGHT_ALT;
        case Key::KEY_RIGHT_SUPER: return GLFW_KEY_RIGHT_SUPER;
        case Key::KEY_MENU: return GLFW_KEY_MENU;
    default: return -1;
    }
}