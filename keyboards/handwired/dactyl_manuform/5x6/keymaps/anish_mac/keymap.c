#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LAYER 1

#define LAYER TT(_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_EQL , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
        KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH, KC_GRV,
                         KC_LEFT,KC_RGHT,                                                       KC_UP, KC_DOWN,
                                         KC_BSPC, KC_DEL,                        KC_ENT,  KC_SPC,
                                         KC_LALT, KC_RGUI,                       KC_RCTL, KC_LGUI,
                                         KC_MUTE, LAYER,                         KC_RBRC, KC_LBRC
    ),

    [_LAYER] = LAYOUT_5x6(
        KC_ESC , KC_F1   , KC_F2  , KC_F3  , KC_F4  , KC_F5,                 KC_F6  , KC_F7  , KC_F8  , KC_F9 , KC_F10 , KC_TRNS,
        KC_TAB , KC_TRNS , KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS,               KC_TRNS, KC_VOLD, KC_VOLU, KC_F11, KC_F12 , KC_TRNS,
        KC_CAPS, KC_1    , KC_2   , KC_3   , KC_4   , KC_5,                  KC_6   , KC_7   , KC_8   , KC_9  , KC_0   , KC_TRNS,
        KC_LSFT, KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS,                                                   KC_TRNS, KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS

    )
};
