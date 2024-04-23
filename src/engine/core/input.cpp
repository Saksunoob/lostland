#include "input.h"

using namespace Engine;

void Input::init() {

}

/*
void Input::processInput(SDL_Window* window) {
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

    for (int m_button = 0; m_button < 8; m_button++) {
        bool new_state = glfwGetMouseButton(window, m_button);
        KeyState* button_state = &mouse_button_states[m_button];
        if (button_state->pressed == new_state) {
            button_state->just_changed = false;
            continue;
        }

        button_state->pressed = new_state;
        button_state->just_changed = true;
    }

    IVec2 old_pos = mouse_pos;
    Vec2 new_pos;
    glfwGetCursorPos(window, &new_pos.x, &new_pos.y);
    mouse_pos = new_pos.to_IVec2();
    mouse_delta = mouse_pos - old_pos;
}*/

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
}


int Input::get_glfw_key(Key key) {
    switch (key) {
        case KEY_SPACE: return GLFW_KEY_SPACE;
        case KEY_APOSTROPHE: return GLFW_KEY_APOSTROPHE;
        case KEY_COMMA: return GLFW_KEY_COMMA;
        case KEY_MINUS: return GLFW_KEY_MINUS;
        case KEY_PERIOD: return GLFW_KEY_PERIOD;
        case KEY_SLASH: return GLFW_KEY_SLASH;
        case KEY_0: return GLFW_KEY_0;
        case KEY_1: return GLFW_KEY_1;
        case KEY_2: return GLFW_KEY_2;
        case KEY_3: return GLFW_KEY_3;
        case KEY_4: return GLFW_KEY_4;
        case KEY_5: return GLFW_KEY_5;
        case KEY_6: return GLFW_KEY_6;
        case KEY_7: return GLFW_KEY_7;
        case KEY_8: return GLFW_KEY_8;
        case KEY_9: return GLFW_KEY_9;
        case KEY_SEMICOLON: return GLFW_KEY_SEMICOLON;
        case KEY_EQUAL: return GLFW_KEY_EQUAL;
        case KEY_A: return GLFW_KEY_A;
        case KEY_B: return GLFW_KEY_B;
        case KEY_C: return GLFW_KEY_C;
        case KEY_D: return GLFW_KEY_D;
        case KEY_E: return GLFW_KEY_E;
        case KEY_F: return GLFW_KEY_F;
        case KEY_G: return GLFW_KEY_G;
        case KEY_H: return GLFW_KEY_H;
        case KEY_I: return GLFW_KEY_I;
        case KEY_J: return GLFW_KEY_J;
        case KEY_K: return GLFW_KEY_K;
        case KEY_L: return GLFW_KEY_L;
        case KEY_M: return GLFW_KEY_M;
        case KEY_N: return GLFW_KEY_N;
        case KEY_O: return GLFW_KEY_O;
        case KEY_P: return GLFW_KEY_P;
        case KEY_Q: return GLFW_KEY_Q;
        case KEY_R: return GLFW_KEY_R;
        case KEY_S: return GLFW_KEY_S;
        case KEY_T: return GLFW_KEY_T;
        case KEY_U: return GLFW_KEY_U;
        case KEY_V: return GLFW_KEY_V;
        case KEY_W: return GLFW_KEY_W;
        case KEY_X: return GLFW_KEY_X;
        case KEY_Y: return GLFW_KEY_Y;
        case KEY_Z: return GLFW_KEY_Z;
        case KEY_LEFT_BRACKET: return GLFW_KEY_LEFT_BRACKET;
        case KEY_BACKSLASH: return GLFW_KEY_BACKSLASH;
        case KEY_RIGHT_BRACKET: return GLFW_KEY_RIGHT_BRACKET;
        case KEY_GRAVE_ACCENT: return GLFW_KEY_GRAVE_ACCENT;
        case KEY_WORLD_1: return GLFW_KEY_WORLD_1;
        case KEY_WORLD_2: return GLFW_KEY_WORLD_2;
        case KEY_ESCAPE: return GLFW_KEY_ESCAPE;
        case KEY_ENTER: return GLFW_KEY_ENTER;
        case KEY_TAB: return GLFW_KEY_TAB;
        case KEY_BACKSPACE: return GLFW_KEY_BACKSPACE;
        case KEY_INSERT: return GLFW_KEY_INSERT;
        case KEY_DELETE: return GLFW_KEY_DELETE;
        case KEY_RIGHT: return GLFW_KEY_RIGHT;
        case KEY_LEFT: return GLFW_KEY_LEFT;
        case KEY_DOWN: return GLFW_KEY_DOWN;
        case KEY_UP: return GLFW_KEY_UP;
        case KEY_PAGE_UP: return GLFW_KEY_PAGE_UP;
        case KEY_PAGE_DOWN: return GLFW_KEY_PAGE_DOWN;
        case KEY_HOME: return GLFW_KEY_HOME;
        case KEY_END: return GLFW_KEY_END;
        case KEY_CAPS_LOCK: return GLFW_KEY_CAPS_LOCK;
        case KEY_SCROLL_LOCK: return GLFW_KEY_SCROLL_LOCK;
        case KEY_NUM_LOCK: return GLFW_KEY_NUM_LOCK;
        case KEY_PRINT_SCREEN: return GLFW_KEY_PRINT_SCREEN;
        case KEY_PAUSE: return GLFW_KEY_PAUSE;
        case KEY_F1: return GLFW_KEY_F1;
        case KEY_F2: return GLFW_KEY_F2;
        case KEY_F3: return GLFW_KEY_F3;
        case KEY_F4: return GLFW_KEY_F4;
        case KEY_F5: return GLFW_KEY_F5;
        case KEY_F6: return GLFW_KEY_F6;
        case KEY_F7: return GLFW_KEY_F7;
        case KEY_F8: return GLFW_KEY_F8;
        case KEY_F9: return GLFW_KEY_F9;
        case KEY_F10: return GLFW_KEY_F10;
        case KEY_F11: return GLFW_KEY_F11;
        case KEY_F12: return GLFW_KEY_F12;
        case KEY_F13: return GLFW_KEY_F13;
        case KEY_F14: return GLFW_KEY_F14;
        case KEY_F15: return GLFW_KEY_F15;
        case KEY_F16: return GLFW_KEY_F16;
        case KEY_F17: return GLFW_KEY_F17;
        case KEY_F18: return GLFW_KEY_F18;
        case KEY_F19: return GLFW_KEY_F19;
        case KEY_F20: return GLFW_KEY_F20;
        case KEY_F21: return GLFW_KEY_F21;
        case KEY_F22: return GLFW_KEY_F22;
        case KEY_F23: return GLFW_KEY_F23;
        case KEY_F24: return GLFW_KEY_F24;
        case KEY_F25: return GLFW_KEY_F25;
        case KEY_KP_0: return GLFW_KEY_KP_0;
        case KEY_KP_1: return GLFW_KEY_KP_1;
        case KEY_KP_2: return GLFW_KEY_KP_2;
        case KEY_KP_3: return GLFW_KEY_KP_3;
        case KEY_KP_4: return GLFW_KEY_KP_4;
        case KEY_KP_5: return GLFW_KEY_KP_5;
        case KEY_KP_6: return GLFW_KEY_KP_6;
        case KEY_KP_7: return GLFW_KEY_KP_7;
        case KEY_KP_8: return GLFW_KEY_KP_8;
        case KEY_KP_9: return GLFW_KEY_KP_9;
        case KEY_KP_DECIMAL: return GLFW_KEY_KP_DECIMAL;
        case KEY_KP_DIVIDE: return GLFW_KEY_KP_DIVIDE;
        case KEY_KP_MULTIPLY: return GLFW_KEY_KP_MULTIPLY;
        case KEY_KP_SUBTRACT: return GLFW_KEY_KP_SUBTRACT;
        case KEY_KP_ADD: return GLFW_KEY_KP_ADD;
        case KEY_KP_ENTER: return GLFW_KEY_KP_ENTER;
        case KEY_KP_EQUAL: return GLFW_KEY_KP_EQUAL;
        case KEY_LEFT_SHIFT: return GLFW_KEY_LEFT_SHIFT;
        case KEY_LEFT_CONTROL: return GLFW_KEY_LEFT_CONTROL;
        case KEY_LEFT_ALT: return GLFW_KEY_LEFT_ALT;
        case KEY_LEFT_SUPER: return GLFW_KEY_LEFT_SUPER;
        case KEY_RIGHT_SHIFT: return GLFW_KEY_RIGHT_SHIFT;
        case KEY_RIGHT_CONTROL: return GLFW_KEY_RIGHT_CONTROL;
        case KEY_RIGHT_ALT: return GLFW_KEY_RIGHT_ALT;
        case KEY_RIGHT_SUPER: return GLFW_KEY_RIGHT_SUPER;
        case KEY_MENU: return GLFW_KEY_MENU;
    default: return -1;
    }
}