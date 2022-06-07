#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x6(
        KC_KP_0,   KC_KP_1,   KC_KP_2,
        KC_KP_3,   KC_KP_4,   KC_KP_5,
        KC_KP_6,   KC_KP_7,   KC_KP_8,
        KC_KP_9,   KC_KP_PLUS,   KC_KP_MINUS,
        KC_KP_ENTER,   KC_KP_SLASH,   KC_KP_ASTERISK,
        DF(0),   RGB_TOG,   KC_NO
    ),

    [1] = LAYOUT_ortho_3x6(
        KC_Q,   KC_W,   KC_E,
        KC_A,   KC_S,   KC_D,
        KC_Z,   KC_X,   KC_C,
        KC_LSFT,   KC_NO,   KC_SPC,
        KC_LCTL,   KC_LALT,   KC_SPC,
        DF(0),   CAPS_WORD,   KC_NO
    ),

    [2] = LAYOUT_ortho_3x6(
        KC_MS_BTN1,   KC_MS_BTN2,   KC_MS_BTN3,
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        QK_BOOT,   QK_RBT,   KC_LWIN,
        DF(0),   KC_NO,   KC_NO
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { { DF(2), DF(1) }, { RGB_MOD, RGB_RMOD } },
    [1] = { { DF(0), DF(2) }, { RGB_VAD, RGB_VAI }  },
    [2] = { { DF(1), DF(0) }, { KC_WH_D, KC_WH_U }  },
};
#endif

#ifdef OLED_ENABLE
#    include QMK_KEYBOARD_H
#    include <stdio.h>
#    include <string.h>

void render_logo(void) {

    static const char qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write(qmk_logo, false);
}


bool oled_task_user(void) {
render_logo();
switch (get_highest_layer(default_layer_state)) {
    case 0:
        oled_write_ln((">Layer:0"), false);
        oled_write_ln((" Layer:1"), false);
        oled_write_ln((" Layer:2"), false);
        break;

    case 1:
        oled_write_ln((" Layer:0"), false);
        oled_write_ln((">Layer:1"), false);
        oled_write_ln((" Layer:2"), false);
        break;

    case 2:
        oled_write_ln((" Layer:0"), false);
        oled_write_ln((" Layer:1"), false);
        oled_write_ln((">Layer:2"), false);
        break;
    }
return false;

}

layer_state_t layer_state_set_user(layer_state_t state) {
  oled_task_user();
  return state;
}

#endif
