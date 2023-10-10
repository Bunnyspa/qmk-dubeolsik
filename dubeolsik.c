#include QMK_KEYBOARD_H

const uint32_t SYLLABLE_BASE = 0xac00; // 가

const uint32_t ㄱ = 0x3131;
const uint32_t ㄲ = 0x3132;
const uint32_t ㄳ = 0x3133;
const uint32_t ㄴ = 0x3134;
const uint32_t ㄵ = 0x3135;
const uint32_t ㄶ = 0x3136;
const uint32_t ㄷ = 0x3137;
const uint32_t ㄸ = 0x3138;
const uint32_t ㄹ = 0x3139;
const uint32_t ㄺ = 0x313a;
const uint32_t ㄻ = 0x313b;
const uint32_t ㄼ = 0x313c;
const uint32_t ㄽ = 0x313d;
const uint32_t ㄾ = 0x313e;
const uint32_t ㄿ = 0x313f;
const uint32_t ㅀ = 0x3140;
const uint32_t ㅁ = 0x3141;
const uint32_t ㅂ = 0x3142;
const uint32_t ㅃ = 0x3143;
const uint32_t ㅄ = 0x3144;
const uint32_t ㅅ = 0x3145;
const uint32_t ㅆ = 0x3146;
const uint32_t ㅇ = 0x3147;
const uint32_t ㅈ = 0x3148;
const uint32_t ㅉ = 0x3149;
const uint32_t ㅊ = 0x314a;
const uint32_t ㅋ = 0x314b;
const uint32_t ㅌ = 0x314c;
const uint32_t ㅍ = 0x314d;
const uint32_t ㅎ = 0x314e;

const uint32_t ㅏ = 0x314f;
const uint32_t ㅐ = 0x3150;
const uint32_t ㅑ = 0x3151;
const uint32_t ㅒ = 0x3152;
const uint32_t ㅓ = 0x3153;
const uint32_t ㅔ = 0x3154;
const uint32_t ㅕ = 0x3155;
const uint32_t ㅖ = 0x3156;
const uint32_t ㅗ = 0x3157;
const uint32_t ㅘ = 0x3158;
const uint32_t ㅙ = 0x3159;
const uint32_t ㅚ = 0x315a;
const uint32_t ㅛ = 0x315b;
const uint32_t ㅜ = 0x315c;
const uint32_t ㅝ = 0x315d;
const uint32_t ㅞ = 0x315e;
const uint32_t ㅟ = 0x315f;
const uint32_t ㅠ = 0x3160;
const uint32_t ㅡ = 0x3161;
const uint32_t ㅢ = 0x3162;
const uint32_t ㅣ = 0x3163;

const uint32_t U_SEMICOLON = 0x003b;

// Colemak-DH <-> Dubeolsik
uint32_t to_korean_unicode(uint16_t keycode) {
    switch (keycode) {
        case KC_Q:
            return ㅂ;
        case KC_W:
            return ㅈ;
        case KC_F:
            return ㄷ;
        case KC_P:
            return ㄱ;
        case KC_B:
            return ㅅ;
        case S(KC_Q):
            return ㅃ;
        case S(KC_W):
            return ㅉ;
        case S(KC_F):
            return ㄸ;
        case S(KC_P):
            return ㄲ;
        case S(KC_B):
            return ㅆ;
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
        case S(KC_Y):
            return ㅒ;
        case S(KC_SEMICOLON):
            return ㅖ;
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

void to_jamo(uint32_t unicode, int* initial, int* medial, int* final) {
    uint32_t value = unicode - SYLLABLE_BASE;

    *final = value % 28;
    value /= 28;
    *medial  = value % 21;
    *initial = value / 21;
}

uint32_t from_jamo(int initial, int medial, int final) {
    return initial * 588 + medial * 28 + final + SYLLABLE_BASE;
}

static uint32_t korean_recent = 0;

void edit_syllable(uint32_t unicode) {
    tap_code(KC_BSPC);
    register_unicode(unicode);
    korean_recent = unicode;
}

void reset_korean_input(void) {
    korean_recent = 0;
}

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
    int  initial, medial, final;
    to_jamo(korean_recent, &initial, &medial, &final);

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
