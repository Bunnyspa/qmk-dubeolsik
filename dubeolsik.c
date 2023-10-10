#include QMK_KEYBOARD_H

#define SYLLABLE_BASE 0xac00 // 가

#define ㄱ 0x3131
#define ㄲ 0x3132
#define ㄳ 0x3133
#define ㄴ 0x3134
#define ㄵ 0x3135
#define ㄶ 0x3136
#define ㄷ 0x3137
#define ㄸ 0x3138
#define ㄹ 0x3139
#define ㄺ 0x313a
#define ㄻ 0x313b
#define ㄼ 0x313c
#define ㄽ 0x313d
#define ㄾ 0x313e
#define ㄿ 0x313f
#define ㅀ 0x3140
#define ㅁ 0x3141
#define ㅂ 0x3142
#define ㅃ 0x3143
#define ㅄ 0x3144
#define ㅅ 0x3145
#define ㅆ 0x3146
#define ㅇ 0x3147
#define ㅈ 0x3148
#define ㅉ 0x3149
#define ㅊ 0x314a
#define ㅋ 0x314b
#define ㅌ 0x314c
#define ㅍ 0x314d
#define ㅎ 0x314e

#define ㅏ 0x314f
#define ㅐ 0x3150
#define ㅑ 0x3151
#define ㅒ 0x3152
#define ㅓ 0x3153
#define ㅔ 0x3154
#define ㅕ 0x3155
#define ㅖ 0x3156
#define ㅗ 0x3157
#define ㅘ 0x3158
#define ㅙ 0x3159
#define ㅚ 0x315a
#define ㅛ 0x315b
#define ㅜ 0x315c
#define ㅝ 0x315d
#define ㅞ 0x315e
#define ㅟ 0x315f
#define ㅠ 0x3160
#define ㅡ 0x3161
#define ㅢ 0x3162
#define ㅣ 0x3163

#define U_SEMICOLON 0x003b

static uint32_t korean_recent = 0;

void process_korean_input(uint16_t keycode) {
    uint32_t unicode = to_korean_unicode(keycode);

    //
    switch (unicode) {
        case 0:
            tap_code(keycode);
            reset_korean_input();
            return;
        case U_SEMICOLON:
            tap_code(KC_SEMICOLON);
            reset_korean_input();
            return;
    }

    // No recent korean
    if (korean_recent == 0) {
        register_unicode(unicode);
        korean_recent = unicode;
        return;
    }

    bool is_jaum = ㄱ <= unicode && unicode <= ㅎ;
    int *recent_jamo = to_jamo(korean_recent);
    int initial = recent_jamo[0];
    int medial = recent_jamo[1];
    int final = recent_jamo[2];

    if (medial == 0) {
        if (is_jaum) {
            // 초 + 초
            uint32_t combined = combine(initial + ㄱ, unicode);
            if (combined != 0) {
                edit_syllable(combined);
            }
        } else {
            // 초 + 중
            uint32_t syllable = from_jamo(initial, unicode - ㅏ, 0);
            edit_syllable(syllable);
        }
    } else if (final == 0) {
        if (is_jaum) {
            // 초중 + 종
            uint32_t syllable = from_jamo(initial, medial, unicode - ㄱ);
            edit_syllable(syllable);
        } else {
            // 초중 + 중
            uint32_t combined = combine(medial + ㅏ, unicode);
            if (combined != 0) {
                uint32_t syllable = from_jamo(initial, combined - ㅏ, 0);
                edit_syllable(syllable);
            }
        }
    } else {
        if (is_jaum) {
            // 초중종 + 종
            uint32_t combined = combine(final + ㄱ, unicode);
            if (combined != 0) {
                uint32_t syllable = from_jamo(initial, medial, combined - ㄱ);
                edit_syllable(syllable);
            }
        } else {
            // 초중 + 초중
            uint32_t first = from_jamo(initial, medial, 0);
            tap_code(KC_BSPC);
            register_unicode(first);
            uint32_t second = from_jamo(final, unicode - ㅏ, 0);
            register_unicode(second);
            korean_recent = second;
        }
    }
}

void edit_syllable(uint32_t unicode) {
    tap_code(KC_BSPC);
    register_unicode(unicode);
    korean_recent = unicode;
}

void reset_korean_input(void) {
    korean_recent = 0;
}

uint32_t combine(uint32_t first, uint32_t second) {
    switch (first) {
        case ㄱ:
            switch (second) {
                case ㅅ:
                    return ㄳ;
            }
            break;
        case ㄴ:
            switch (second) {
                case ㅈ:
                    return ㄵ;
                case ㅎ:
                    return ㄶ;
            }
            break;
        case ㄹ:
            switch (second) {
                case ㄱ:
                    return ㄺ;
                case ㅁ:
                    return ㄻ;
                case ㅂ:
                    return ㄼ;
                case ㅅ:
                    return ㄽ;
                case ㅌ:
                    return ㄾ;
                case ㅍ:
                    return ㄿ;
                case ㅎ:
                    return ㅀ;
            }
            break;
        case ㅂ:
            switch (second) {
                case ㅅ:
                    return ㅄ;
            }
            break;
        case ㅗ:
            switch (second) {
                case ㅏ:
                    return ㅘ;
                case ㅐ:
                    return ㅙ;
                case ㅣ:
                    return ㅚ;
            }
            break;
        case ㅜ:
            switch (second) {
                case ㅓ:
                    return ㅝ;
                case ㅔ:
                    return ㅞ;
                case ㅣ:
                    return ㅟ;
            }
            break;
        case ㅡ:
            switch (second) {
                case ㅣ:
                    return ㅢ;
            }
            break;
    }
    return 0;
}

int *to_jamo(uint32_t unicode) {
    uint32_t value = unicode - SYLLABLE_BASE;
    int final = value % 28;
    value /= 28;
    int medial = value % 21;
    int initial = value / 21;
    int jamo[] = {initial, medial, final};
    return jamo;
}

uint32_t from_jamo(int initial, int medial, int final) { return initial * 588 + medial * 28 + final + SYLLABLE_BASE; }

// Colemak-DH <-> Dubeolsik
uint32_t *to_korean_unicode(uint16_t keycode) {
    switch (keycode) {
        case KC_Q:
            return ㅂ;
        case KC_W:
            return ㅈ;
        case KC_F:
            return ㄷ;
        case KC_P:
            return ㄱ;
        case KC_G:
            return ㅅ;
        case KC_J:
            return ㅛ;
        case KC_L:
            return ㅕ;
        case KC_U:
            return ㅑ;
        case KC_Y:
            return ㅐ;
        case KC_SEMICOLON:
            return ㅔ;
        case KC_A:
            return ㅁ;
        case KC_R:
            return ㄴ;
        case KC_S:
            return ㅇ;
        case KC_T:
            return ㄹ;
        case KC_G:
            return ㅎ;
        case KC_M:
            return ㅗ;
        case KC_N:
            return ㅓ;
        case KC_E:
            return ㅏ;
        case KC_I:
            return ㅣ;
        case KC_O:
            return U_SEMICOLON;
        case KC_Z:
            return ㅋ;
        case KC_X:
            return ㅌ;
        case KC_C:
            return ㅊ;
        case KC_D:
            return ㅍ;
        case KC_V:
            return ㅠ;
        case KC_K:
            return ㅜ;
        case KC_H:
            return ㅡ;
        default:
            return 0;
    }
}
