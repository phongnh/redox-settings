#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum redox_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum redox_keycodes {
    EPRM = SAFE_RANGE,
    LOWER,
    RAISE,
};

#define LWR_PUP LT(_LOWER, KC_PGUP)     // Turn on _LOWER layer held, PgUp when tapped
#define RSE_END LT(_RAISE, KC_END)      // Turn on _RAISE layer held, End when tapped
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left Control when held, z when tapped
#define CTL_SCL LCTL_T(KC_SCLN)         // Left Control when held, ; when tapped
#define CTL_SLS RCTL_T(KC_SLSH)         // Right Control when held, / when tapped
#define GUI_QUO RGUI_T(KC_QUOT)         // Right Gui when held, " when tapped
#define CAG_QUO LCAG_T(KC_QUOT)         // Ctrl+Alt+Gui when held, " when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │                                           │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │  Del   │                         │  Esc   │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │   [    │                         │   ]    │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │PgUp /L1│  PgDn  │       │  Home  │End / L2│   N    │   M    │   ,    │   .    │ / / CTL│ Shift  │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │   `    │   '    │   [    │   ]    │    │  GUI   │   │ Space  │ BkSpace│       │  Tab   │  Enter │   │  Alt   │    │  Left  │  Down  │   Up   │ Right  │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_QWERTY] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,                                    KC_ESC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                                   KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LWR_PUP, KC_PGDN,        KC_HOME, RSE_END, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT,
        KC_GRV,  CAG_QUO, KC_LBRC, KC_RBRC,     KC_LGUI,      KC_SPC,  KC_BSPC,        KC_TAB,  KC_ENT,      KC_RALT,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │  F12   │   F1   │   F2   │   F3   │   F4   │   F5   │                                           │   F6   │   F7   │   F8   │   F9   │  F10   │  F11   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │   !    │   @    │   #    │   $    │   %    │        │                         │        │   ^    │   &    │   *    │   (    │   )    │  F12   │
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
     * │  F12   │   F1   │   F2   │   F3   │   F4   │   F5   │                                           │   F6   │   F7   │   F8   │   F9   │  F10   │  F11   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │   !    │   @    │   #    │   $    │   %    │        │                         │        │   ^    │   &    │   *    │   (    │   )    │  F12   │
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
     * │ RESET  │        │        │        │        │  VAL-  │                                           │  VAL+  │        │        │        │        │ EPRM   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ AG_NORM│        │        │        │        │  SAT-  │  TOG   │                         │  M_P   │  SAT+  │        │        │        │        │ AG_SWAP│
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │  HUE-  │  RMOD  │                         │  MOD   │  HUE+  │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_ADJUST] = LAYOUT(
        RESET,   _______, _______, _______, _______, RGB_VAD,                                             RGB_VAI, _______, _______, _______, _______, EPRM,
        AG_NORM, _______, _______, _______, _______, RGB_SAD, RGB_TOG,                          RGB_M_P,  RGB_SAI, _______, _______, _______, _______, AG_SWAP,
        _______, _______, _______, _______, _______, RGB_HUD, RGB_RMOD,                         RGB_MOD,  RGB_HUI, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,      _______,      _______, _______, _______, _______
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
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case EPRM:
        if (record->event.pressed) {
            eeconfig_init();
        }
        return false;
        break;
    }
    return true;
}
