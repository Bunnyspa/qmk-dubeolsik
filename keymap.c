#include QMK_KEYBOARD_H
#include "dubeolsik.h"

enum custom_keycodes {
    TG_DBS = SAFE_RANGE,
};

static bool dubeolsik_enable = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
    switch (keycode) {
        case TG_DBS:
            if (record->event.pressed) {
                dubeolsik_enable = !dubeolsik_enable;
            }
            return false;
        default:
            if (record->event.pressed) {
                if (dubeolsik_enable && process_record_dubeolsik(keycode))
                {
                    return false;
                }
            }
            break;
    }
    return true;
}
