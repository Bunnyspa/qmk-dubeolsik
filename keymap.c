#include QMK_KEYBOARD_H
#include "dubeolsik.h"

enum custom_keycodes {
    TG_KOR = SAFE_RANGE
};

static bool korean_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_KOR:
            if (record->event.pressed) {
                korean_enabled = !korean_enabled;
            }
            return false;
        case KC_A ... KC_Z:
        case KC_SEMICOLON:
            if (record->event.pressed) {
                if (korean_enabled) {
                    process_korean_input(keycode);
                    return false;
                }
            }
            reset_korean_input();
            break;
        default:
            if (record->event.pressed) {
                reset_korean_input();
            }
            break;
    }
    return true;
}
