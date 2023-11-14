#include QMK_KEYBOARD_H
#include "dubeolsik.h"

enum layers {
    _QWERTY = 0,
    _FN,
};

enum custom_keycodes {
    TG_DBS = SAFE_RANGE,
};

// clang-format off

// Example keymaps from kbdcraft/adam64
// This layout is Colemak-DH
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_64_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(1),
        KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC,                             TG_DBS,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT_64_ansi(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, 
        KC_NO,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, KC_PSCR, KC_SCRL, KC_PAUS, KC_NO, 
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_SPI, RGB_SPD, KC_HOME, KC_PGUP,          EE_CLR, 
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   NK_TOGG, KC_NO,   KC_NO,   KC_INS,  KC_END,  KC_PGDN, KC_VOLU, KC_MUTE, 
        KC_NO,   KC_NO,   KC_NO,                     KC_NO,                              KC_NO,   KC_TRNS, RGB_MOD, KC_VOLD, RGB_TOG
    )
};

// This keymap determines which korean input to send
const uint16_t dbs_keymap[MATRIX_ROWS][MATRIX_COLS] = 
          LAYOUT_64_ansi(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KR_B,    KR_J,    KR_D,    KR_G,    KR_S,    KR_YO,   KR_YEO,  KR_YA,   KR_AE,   KR_E,    XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KR_M,    KR_N,    KR_X,    KR_L,    KR_H,    KR_O,    KR_EO,   KR_A,    KR_I,    KC_SCLN, XXXXXXX,          XXXXXXX,
        XXXXXXX, KR_K,    KR_T,    KR_CH,   KR_P,    KR_YU ,  KR_U,    KR_EU,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
);

// clang-format on

static bool dbs_enable = false;
static uint16_t dbs_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_DBS:
            if (record->event.pressed) {
                reset_dbs_input();
                dbs_enable = !dbs_enable;
            }
            return false;
        default:
            if (record->event.pressed) {
                if (dbs_enable && get_highest_layer(layer_state) == _QWERTY) {
                    // If you have custom shift keycodes, such as space cadet shifts,
                    // Replace KC_LSFT and KC_RSFT to the custom shift keycodes.
                    if (!process_record_dbs(keycode, record, KC_LSFT, KC_RSFT)) {
                        dbs_timer = (record->event.time + DBS_TIMEOUT_MS) | 1;
                        return false;
                    }
                }
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (dbs_timer && timer_expired(timer_read(), dbs_timer)) {
        reset_dbs_input();
        dbs_timer = 0;
    }
}
