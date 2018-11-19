#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum redox_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
    _SAMPLE,
};

enum redox_keycodes {
    PLACHOLDER = SAFE_RANGE,
    LOWER,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │                                           │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │  Del   │                         │  Esc   │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Esc   │   A    │   S    │   D    │   F    │   G    │   [    │                         │   ]    │   H    │   J    │   K    │   L    │   ;    │   '    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │   Z    │   X    │   C    │   V    │   B    │  PgUp  │  PgDn  │       │  Home  │  End   │   N    │   M    │   ,    │   .    │   \    │ Shift  │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │   `    │   '    │   [    │   ]    │    │  GUI   │   │ Space  │ BkSpace│       │  Tab   │  Enter │   │  Alt   │    │  Left  │  Down  │   Up   │ Right  │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_QWERTY] = LAYOUT(
        KC_EQL,         KC_1,            KC_2,    KC_3,    KC_4,    KC_5,                                                                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                KC_MINS,
        KC_TAB,         KC_Q,            KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,                                       KC_ESC,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                KC_BSLS,
        LCTL_T(KC_ESC), KC_A,            KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                                      KC_RBRC,            KC_H,    KC_J,    KC_K,    KC_L,    LT(_MOUSE, KC_SCLN), RGUI_T(KC_QUOT),
        KC_LSFT,        LCTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    LT(_LOWER, KC_PGUP), KC_PGDN,        KC_HOME, LT(_RAISE, KC_END), KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH),     KC_RSFT,
        KC_GRV,         LCAG_T(KC_QUOT), KC_LBRC, KC_RBRC,     KC_LGUI,      KC_SPC,              KC_BSPC,        KC_TAB,  KC_ENT,                 KC_RALT,      KC_LEFT, KC_DOWN, KC_UP,               KC_RGHT
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                                           │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_LOWER] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                                           │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_RAISE] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                                           │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │ MClick │  MS_U  │ RClick │        │        │                         │        │        │ RClick │  WH_U  │ MClick │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │ LClick │  MS_L  │  MS_D  │  MS_R  │ LClick │        │                         │        │ LClick │  WH_L  │  WH_D  │  WH_R  │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                            _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______, _______,                          _______, _______, KC_BTN2, KC_WH_U, KC_BTN3, _______, _______,
        _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______,                          _______, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
    ),


    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                                           │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_SAMPLE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
    ),
};
