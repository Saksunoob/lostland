#pragma once
#include "engine.h"
#include "vectors.h"

namespace Engine {
    namespace Input {
        enum Key {
            KEY_BACKSPACE,
            KEY_TAB,
            KEY_CLEAR,
            KEY_RETURN,
            KEY_PAUSE,
            KEY_ESCAPE,
            KEY_SPACE,
            KEY_EXCLAIM,
            KEY_QUOTEDBL,
            KEY_HASH,
            KEY_DOLLAR,
            KEY_AMPERSAND,
            KEY_QUOTE,
            KEY_LEFTPAREN,
            KEY_RIGHTPAREN,
            KEY_ASTERISK,
            KEY_PLUS,
            KEY_COMMA,
            KEY_MINUS,
            KEY_PERIOD,
            KEY_SLASH,
            KEY_0,
            KEY_1,
            KEY_2,
            KEY_3,
            KEY_4,
            KEY_5,
            KEY_6,
            KEY_7,
            KEY_8,
            KEY_9,
            KEY_COLON,
            KEY_SEMICOLON,
            KEY_LESS,
            KEY_EQUALS,
            KEY_GREATER,
            KEY_QUESTION,
            KEY_AT,
            KEY_LEFTBRACKET,
            KEY_BACKSLASH,
            KEY_RIGHTBRACKET,
            KEY_CARET,
            KEY_UNDERSCORE,
            KEY_BACKQUOTE,
            KEY_A,
            KEY_B,
            KEY_C,
            KEY_D,
            KEY_E,
            KEY_F,
            KEY_G,
            KEY_H,
            KEY_I,
            KEY_J,
            KEY_K,
            KEY_L,
            KEY_M,
            KEY_N,
            KEY_O,
            KEY_P,
            KEY_Q,
            KEY_R,
            KEY_S,
            KEY_T,
            KEY_U,
            KEY_V,
            KEY_W,
            KEY_X,
            KEY_Y,
            KEY_Z,
            KEY_DELETE,
            KEY_KP0,
            KEY_KP1,
            KEY_KP2,
            KEY_KP3,
            KEY_KP4,
            KEY_KP5,
            KEY_KP6,
            KEY_KP7,
            KEY_KP8,
            KEY_KP9,
            KEY_KP_PERIOD,
            KEY_KP_DIVIDE,
            KEY_KP_MULTIPLY,
            KEY_KP_MINUS,
            KEY_KP_PLUS,
            KEY_KP_ENTER,
            KEY_KP_EQUALS,
            KEY_UP,
            KEY_DOWN,
            KEY_RIGHT,
            KEY_LEFT,
            KEY_INSERT,
            KEY_HOME,
            KEY_END,
            KEY_PAGEUP,
            KEY_PAGEDOWN,
            KEY_F1,
            KEY_F2,
            KEY_F3,
            KEY_F4,
            KEY_F5,
            KEY_F6,
            KEY_F7,
            KEY_F8,
            KEY_F9,
            KEY_F10,
            KEY_F11,
            KEY_F12,
            KEY_F13,
            KEY_F14,
            KEY_F15,
            KEY_NUMLOCK,
            KEY_CAPSLOCK,
            KEY_SCROLLOCK,
            KEY_RSHIFT,
            KEY_LSHIFT,
            KEY_RCTRL,
            KEY_LCTRL,
            KEY_RALT,
            KEY_LALT,
            KEY_LSUPER,
            KEY_RSUPER,
            KEY_MODE,
            KEY_HELP,
            KEY_PRINT,
            KEY_SYSREQ,
            KEY_MENU,
            KEY_POWER,
            KEYS_AMOUNT,
        };

        enum MouseButton {
            MOUSE_1,
            MOUSE_2,
            MOUSE_3,
            MOUSE_4,
            MOUSE_5,
            MOUSE_6,
            MOUSE_7,
            MOUSE_8,
            MOUSE_LEFT = 0,
            MOUSE_RIGHT = 1,
            MOUSE_MIDDLE = 2,
        };

        struct KeyState {
            bool pressed = false, just_changed = false;
        };

        static KeyState key_states[KEYS_AMOUNT];
        static KeyState mouse_button_states[8];
        static IVec2 mouse_pos, mouse_delta;

        void newFrame();
        void processInputEvent(SDL_Event event);

        bool get_key_pressed(Key key);
        bool get_key_just_pressed(Key key);
        bool get_key_released(Key key);
        bool get_key_just_released(Key key);

        bool get_mouse_button_pressed(MouseButton button);
        bool get_mouse_button_just_pressed(MouseButton button);
        bool get_mouse_button_released(MouseButton button);
        bool get_mouse_button_just_released(MouseButton button);

        IVec2 get_mouse_pos();
        IVec2 get_mouse_delta();

        Input::Key key_from_sdlkey(SDL_Keysym sdl_key);
    }
}