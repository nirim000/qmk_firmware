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
    [0] = LAYOUT_ortho_3x5(
        RGB_MODE_REVERSE,   RGB_VAI,   RGB_MODE_FORWARD,
        KC_D,   RGB_VAD,   KC_F,
        KC_G,   KC_H,   KC_I,
        KC_J,   KC_Q,   KC_M,
        KC_L,   KC_N,   RGB_TOG
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { { KC_VOLD, KC_VOLU }, { RGB_MOD, RGB_RMOD } },
};
#endif
