#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LAYER1 1
#define _LAYER2 2

#define LAYER1 TT(_LAYER1)
#define LAYER2 MO(_LAYER2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_EQL , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
        KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH, KC_GRV,
                         KC_LEFT,KC_RGHT,                                                       KC_UP, KC_DOWN,
                                         KC_BSPC, KC_DEL,                        KC_ENT,  KC_SPC,
                                         KC_LALT, KC_RGUI,                       KC_LGUI, KC_RCTL,
                                         KC_MUTE, LAYER1,                        KC_LBRC, KC_RBRC
    ),

    [_LAYER1] = LAYOUT_5x6(
        KC_ESC , KC_F1   , KC_F2  , KC_F3  , KC_F4  , KC_F5,                 KC_F6  , KC_F7,   KC_F8,   KC_F9,  KC_F10 , KC_F11,
        KC_TRNS, KC_TRNS , KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS,               KC_TRNS, KC_1,    KC_2,    KC_3,   KC_TRNS, KC_F12,
        KC_CAPS, KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_DOT,  KC_4,    KC_5,    KC_6,   KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_0,    KC_7,    KC_8,    KC_9,   KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS,                                                   KC_TRNS, KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS,
                                                LAYER2, KC_TRNS,             KC_TRNS,KC_TRNS

    ),

    [_LAYER2] = LAYOUT_5x6(
        KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS , KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS,               KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_1    , KC_2   , KC_3   , KC_4   , KC_5,                  KC_6   , KC_7   , KC_8   , KC_9  , KC_0   ,  KC_TRNS,
        KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,
                           KC_TRNS, KC_TRNS,                                                   KC_TRNS, KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS,
                                                KC_TRNS, KC_TRNS,            KC_TRNS,KC_TRNS

    )
};

#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Animation parameters
#define FRAME_DURATION 666 // How long each frame lasts in milliseconds

// Animation variables
uint32_t timer = 0;
uint8_t current_frame = 0;

// Render animation
static void render_animation(void) {

    /*
    // 'astro dog1', 32x128px
    static const char epd_bitmap_astro_dog1 [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x38, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xa0, 0x10, 0x18, 0xa0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x04, 0x0c, 0x1a, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x40, 0x60, 0x60, 0x40, 0xc0, 0xc0,
        0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x30, 0xfe, 0x87, 0xcb, 0xd9, 0x15, 0x27, 0x53, 0x52, 0x43, 0x3c, 0x09,
        0xd3, 0x9c, 0x04, 0x07, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x06, 0x04, 0x6d, 0x66, 0x94, 0x0c, 0xc6, 0x07,
        0xa1, 0x42, 0x07, 0x09, 0x10, 0x11, 0xf1, 0x72, 0x4c, 0x88, 0x30, 0x20, 0x40, 0x40, 0x00, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00,
        0x03, 0x14, 0x10, 0x38, 0x28, 0x00, 0x10, 0x0e, 0x01, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x08, 0x08, 0x10, 0x32, 0x0c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x20, 0x20, 0x24, 0xfc, 0xc4, 0x03, 0xc6, 0xee, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // 'astro dog2', 32x128px
    static const char epd_bitmap_astro_dog2 [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0c, 0x0e, 0x32, 0x3e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xa0, 0xa0, 0x20, 0x20, 0x60,
        0xc0, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xff, 0xe1, 0xf7, 0x2c, 0x8a, 0xa7, 0x1b, 0x09, 0x21, 0x0c,
        0x80, 0xf1, 0x0c, 0x00, 0x85, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x13, 0x0e, 0x36, 0x8b, 0x8f, 0x06, 0x26, 0x23,
        0x63, 0x02, 0x07, 0x01, 0x11, 0xe1, 0xe2, 0x94, 0x98, 0x20, 0x40, 0x00, 0x80, 0x00, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11,
        0x00, 0x10, 0x30, 0x40, 0x20, 0x00, 0x0c, 0x02, 0x01, 0x01, 0x02, 0x00, 0x00, 0x00, 0x02, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
        0x0c, 0x0c, 0x1e, 0x71, 0xe1, 0x1a, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x20, 0x20, 0x78, 0x6c, 0x07, 0xc4, 0x60, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    */

    // 'kwala 1', 32x128px
    static const char epd_bitmap_kwala_1 [] PROGMEM = {
        0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x40, 0x83, 0x04, 0x08, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0xf8, 0x03, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0xf0, 0x03,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08, 0x09, 0x11, 0x02,
        0x42, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c, 0x83, 0x60, 0x0e, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x70, 0x00, 0x01, 0x0e, 0x08, 0x06, 0xc1, 0x10, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x04, 0x10, 0x60, 0x80, 0x07, 0x18, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x18, 0x60, 0x81, 0x06, 0x18, 0x60, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0xe0, 0x60, 0x20, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x60,
        0x78, 0xd8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0xf0, 0x00, 0x01, 0x0e,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x02, 0x03, 0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10,
        0x10, 0x18, 0x7c, 0xce, 0x8a, 0x0a, 0x9a, 0x66, 0x6c, 0xf0, 0x80, 0x80, 0x00, 0x3c, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x6e, 0x42, 0xc9, 0x4d, 0x43, 0x80, 0xa0, 0xa0, 0xd0, 0x88, 0x98,
        0xe4, 0x94, 0x90, 0x60, 0x21, 0x1f, 0xc2, 0x42, 0x41, 0xc0, 0x00, 0x00, 0x01, 0x02, 0xfe, 0x00,
        0x00, 0x00, 0x07, 0x05, 0x04, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0e, 0x1a, 0x12, 0x1a,
        0x0e, 0x1f, 0x30, 0x30, 0x1c, 0x03, 0x07, 0x0c, 0x04, 0x07, 0x0e, 0x18, 0x18, 0xde, 0x09, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    // 'kwala 2', 32x128px
    static const char epd_bitmap_kwala_2 [] PROGMEM = {
        0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x40, 0x83, 0x04, 0x08, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
        0x00, 0xf8, 0x03, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0xf0, 0x03,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08, 0x09, 0x11, 0x02,
        0x42, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c, 0x83, 0x60, 0x0c, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x70, 0x80, 0x01, 0x0e, 0x08, 0x06, 0xc1, 0x10, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x04, 0x10, 0x60, 0x80, 0x07, 0x18, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x60, 0xc0, 0xc0, 0x40, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x18, 0x60, 0x81, 0x06, 0x18, 0x60, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0xe0, 0x00, 0x02, 0x06, 0x07, 0x07, 0x06, 0x00, 0x00,
        0x20, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0xf0, 0x00, 0x01, 0x0e,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10,
        0x10, 0x18, 0x7c, 0xde, 0x8a, 0x0a, 0x9a, 0x66, 0x6c, 0xf0, 0x40, 0x80, 0x80, 0x3c, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x6e, 0x42, 0xc9, 0x4d, 0x43, 0x80, 0xa0, 0xa0, 0xd0, 0x88, 0x98,
        0xe4, 0x84, 0x98, 0x48, 0x21, 0x1f, 0xc2, 0x42, 0x41, 0xc0, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x00,
        0x00, 0x00, 0x07, 0x05, 0x04, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0e, 0x1a, 0x12, 0x1a,
        0x0e, 0x1f, 0x30, 0x30, 0x1c, 0x03, 0x06, 0x0c, 0x05, 0x07, 0x0e, 0x18, 0x18, 0x8e, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // Animation frames array
    const char* epd_bitmap_allArray [] = {
        epd_bitmap_kwala_1,
        epd_bitmap_kwala_2
    };

    // Frame sizes array
    uint16_t frame_sizes[2] = {
        sizeof(epd_bitmap_kwala_1),
        sizeof(epd_bitmap_kwala_2)
    };

    // Run animation
    if (timer_elapsed(timer) > FRAME_DURATION) {
        // Set timer to updated time
        timer = timer_read();

        // Increment frame
        current_frame = (current_frame + 1) % (sizeof(epd_bitmap_allArray) / sizeof(epd_bitmap_allArray[0]));

        // Draw frame to OLED
        oled_write_raw_P(epd_bitmap_allArray[current_frame], frame_sizes[current_frame]);
    }
}

// Draw to OLED
bool oled_task_user() {
    // Run Animation
    render_animation();

    return false;
}
#endif
