#include QMK_KEYBOARD_H
#include "dubeolsik.h"

enum custom_keycodes {
    TG_DBS = SAFE_RANGE,
};

static bool dubeolsik_enable = false;
static uint16_t dubeolsik_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_DBS:
            if (record->event.pressed) {
                dubeolsik_enable = !dubeolsik_enable;
            }
            reset_dubeolsik();
            return false;
        case KC_A ... KC_Z:
        case KC_SCLN:
        case KC_BSPC:
        case KC_LSFT:
        case KC_RSFT:
            if (record->event.pressed) {
                if (dubeolsik_enable && process_record_dubeolsik(keycode)) {
                    dubeolsik_timer = (record->event.time + DBS_TIMEOUT_MS) | 1;
                    return false;
                }
            }
            break;
        default:
            reset_dubeolsik();
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (dubeolsik_timer && timer_expired(timer_read(), dubeolsik_timer)) {
        reset_dubeolsik();
        dubeolsik_timer = 0;
    }
}

void keyboard_post_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
}
