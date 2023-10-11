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

const uint32_t U_SCLN = 0x003b;

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
        case KC_SCLN:
            return ㅔ;
        case S(KC_Y):
            return ㅒ;
        case S(KC_SCLN):
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
            return U_SCLN;
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

void decompose(uint32_t composed, uint32_t* first, uint32_t* second) {
    switch (composed) {
        case ㄳ:
            *first  = ㄱ;
            *second = ㅅ;
            break;
        case ㄵ:
            *first  = ㄴ;
            *second = ㅈ;
            break;
        case ㄶ:
            *first  = ㄴ;
            *second = ㅎ;
            break;
        case ㄺ:
            *first  = ㄹ;
            *second = ㄱ;
            break;
        case ㄻ:
            *first  = ㄹ;
            *second = ㅁ;
            break;
        case ㄼ:
            *first  = ㄹ;
            *second = ㅂ;
            break;
        case ㄽ:
            *first  = ㄹ;
            *second = ㅅ;
            break;
        case ㄾ:
            *first  = ㄹ;
            *second = ㅌ;
            break;
        case ㄿ:
            *first  = ㄹ;
            *second = ㅍ;
            break;
        case ㅀ:
            *first  = ㄹ;
            *second = ㅎ;
            break;
        case ㅄ:
            *first  = ㅂ;
            *second = ㅅ;
            break;
        default:
            *first  = 0;
            *second = composed;
            break;
    }
}

void to_jamo(uint32_t unicode, uint32_t* initial, uint32_t* medial, uint32_t* final) {
    uint32_t value = unicode - SYLLABLE_BASE;

    int final_index = value % 28;
    value /= 28;
    int medial_index  = value % 21;
    int initial_index = value / 21;

    switch (initial_index) {
        case 0:
            *initial = ㄱ;
            break;
        case 1:
            *initial = ㄲ;
            break;
        case 2:
            *initial = ㄴ;
            break;
        case 3:
            *initial = ㄷ;
            break;
        case 4:
            *initial = ㄸ;
            break;
        case 5:
            *initial = ㄹ;
            break;
        case 6:
            *initial = ㅁ;
            break;
        case 7:
            *initial = ㅂ;
            break;
        case 8:
            *initial = ㅃ;
            break;
        case 9:
            *initial = ㅅ;
            break;
        case 10:
            *initial = ㅆ;
            break;
        case 11:
            *initial = ㅇ;
            break;
        case 12:
            *initial = ㅈ;
            break;
        case 13:
            *initial = ㅉ;
            break;
        case 14:
            *initial = ㅊ;
            break;
        case 15:
            *initial = ㅋ;
            break;
        case 16:
            *initial = ㅌ;
            break;
        case 17:
            *initial = ㅍ;
            break;
        case 18:
            *initial = ㅎ;
            break;
    }

    switch (medial_index) {
        case 0:
            *medial = ㅏ;
            break;
        case 1:
            *medial = ㅐ;
            break;
        case 2:
            *medial = ㅑ;
            break;
        case 3:
            *medial = ㅒ;
            break;
        case 4:
            *medial = ㅓ;
            break;
        case 5:
            *medial = ㅔ;
            break;
        case 6:
            *medial = ㅕ;
            break;
        case 7:
            *medial = ㅖ;
            break;
        case 8:
            *medial = ㅗ;
            break;
        case 9:
            *medial = ㅘ;
            break;
        case 10:
            *medial = ㅙ;
            break;
        case 11:
            *medial = ㅚ;
            break;
        case 12:
            *medial = ㅛ;
            break;
        case 13:
            *medial = ㅜ;
            break;
        case 14:
            *medial = ㅝ;
            break;
        case 15:
            *medial = ㅞ;
            break;
        case 16:
            *medial = ㅟ;
            break;
        case 17:
            *medial = ㅠ;
            break;
        case 18:
            *medial = ㅡ;
            break;
        case 19:
            *medial = ㅢ;
            break;
        case 20:
            *medial = ㅣ;
            break;
    }

    switch (final_index) {
        case 0:
            *final = 0;
            break;
        case 1:
            *final = ㄱ;
            break;
        case 2:
            *final = ㄲ;
            break;
        case 3:
            *final = ㄳ;
            break;
        case 4:
            *final = ㄴ;
            break;
        case 5:
            *final = ㄵ;
            break;
        case 6:
            *final = ㄶ;
            break;
        case 7:
            *final = ㄷ;
            break;
        case 8:
            *final = ㄹ;
            break;
        case 9:
            *final = ㄺ;
            break;
        case 10:
            *final = ㄻ;
            break;
        case 11:
            *final = ㄼ;
            break;
        case 12:
            *final = ㄽ;
            break;
        case 13:
            *final = ㄾ;
            break;
        case 14:
            *final = ㄿ;
            break;
        case 15:
            *final = ㅀ;
            break;
        case 16:
            *final = ㅁ;
            break;
        case 17:
            *final = ㅂ;
            break;
        case 18:
            *final = ㅄ;
            break;
        case 19:
            *final = ㅅ;
            break;
        case 20:
            *final = ㅆ;
            break;
        case 21:
            *final = ㅇ;
            break;
        case 22:
            *final = ㅈ;
            break;
        case 23:
            *final = ㅊ;
            break;
        case 24:
            *final = ㅋ;
            break;
        case 25:
            *final = ㅌ;
            break;
        case 26:
            *final = ㅍ;
            break;
        case 27:
            *final = ㅎ;
            break;
    }
}

uint32_t from_jamo(uint32_t initial, uint32_t medial, uint32_t final) {
    int initial_index = 0;
    switch (initial) {
        case ㄱ:
            initial_index = 0;
            break;
        case ㄲ:
            initial_index = 1;
            break;
        case ㄴ:
            initial_index = 2;
            break;
        case ㄷ:
            initial_index = 3;
            break;
        case ㄸ:
            initial_index = 4;
            break;
        case ㄹ:
            initial_index = 5;
            break;
        case ㅁ:
            initial_index = 6;
            break;
        case ㅂ:
            initial_index = 7;
            break;
        case ㅃ:
            initial_index = 8;
            break;
        case ㅅ:
            initial_index = 9;
            break;
        case ㅆ:
            initial_index = 10;
            break;
        case ㅇ:
            initial_index = 11;
            break;
        case ㅈ:
            initial_index = 12;
            break;
        case ㅉ:
            initial_index = 13;
            break;
        case ㅊ:
            initial_index = 14;
            break;
        case ㅋ:
            initial_index = 15;
            break;
        case ㅌ:
            initial_index = 16;
            break;
        case ㅍ:
            initial_index = 17;
            break;
        case ㅎ:
            initial_index = 18;
            break;
    }

    int medial_index = 0;
    switch (medial) {
        case ㅏ:
            medial_index = 0;
            break;
        case ㅐ:
            medial_index = 1;
            break;
        case ㅑ:
            medial_index = 2;
            break;
        case ㅒ:
            medial_index = 3;
            break;
        case ㅓ:
            medial_index = 4;
            break;
        case ㅔ:
            medial_index = 5;
            break;
        case ㅕ:
            medial_index = 6;
            break;
        case ㅖ:
            medial_index = 7;
            break;
        case ㅗ:
            medial_index = 8;
            break;
        case ㅘ:
            medial_index = 9;
            break;
        case ㅙ:
            medial_index = 10;
            break;
        case ㅚ:
            medial_index = 11;
            break;
        case ㅛ:
            medial_index = 12;
            break;
        case ㅜ:
            medial_index = 13;
            break;
        case ㅝ:
            medial_index = 14;
            break;
        case ㅞ:
            medial_index = 15;
            break;
        case ㅟ:
            medial_index = 16;
            break;
        case ㅠ:
            medial_index = 17;
            break;
        case ㅡ:
            medial_index = 18;
            break;
        case ㅢ:
            medial_index = 19;
            break;
        case ㅣ:
            medial_index = 20;
            break;
    }

    int final_index = 0;
    switch (final) {
        case ㄱ:
            final_index = 1;
            break;
        case ㄲ:
            final_index = 2;
            break;
        case ㄳ:
            final_index = 3;
            break;
        case ㄴ:
            final_index = 4;
            break;
        case ㄵ:
            final_index = 5;
            break;
        case ㄶ:
            final_index = 6;
            break;
        case ㄷ:
            final_index = 7;
            break;
        case ㄹ:
            final_index = 8;
            break;
        case ㄺ:
            final_index = 9;
            break;
        case ㄻ:
            final_index = 10;
            break;
        case ㄼ:
            final_index = 11;
            break;
        case ㄽ:
            final_index = 12;
            break;
        case ㄾ:
            final_index = 13;
            break;
        case ㄿ:
            final_index = 14;
            break;
        case ㅀ:
            final_index = 15;
            break;
        case ㅁ:
            final_index = 16;
            break;
        case ㅂ:
            final_index = 17;
            break;
        case ㅄ:
            final_index = 18;
            break;
        case ㅅ:
            final_index = 19;
            break;
        case ㅆ:
            final_index = 20;
            break;
        case ㅇ:
            final_index = 21;
            break;
        case ㅈ:
            final_index = 22;
            break;
        case ㅊ:
            final_index = 23;
            break;
        case ㅋ:
            final_index = 24;
            break;
        case ㅌ:
            final_index = 25;
            break;
        case ㅍ:
            final_index = 26;
            break;
        case ㅎ:
            final_index = 27;
            break;
    }

    return initial_index * 588 + medial_index * 28 + final_index + SYLLABLE_BASE;
}

static uint32_t unicode_recent = 0;

void add_unicode(uint32_t unicode) {
    register_unicode(unicode);
    unicode_recent = unicode;
}

void edit_unicode(uint32_t unicode) {
    tap_code(KC_BSPC);
    register_unicode(unicode);
    unicode_recent = unicode;
}

void reset_dubeolsik(void) {
    unicode_recent = 0;
}

bool process_record_dubeolsik(uint16_t keycode) {
    uint32_t unicode = to_korean_unicode(keycode);

    switch (unicode) {
        case 0:
            // Ignore unmapped keycodes
            reset_dubeolsik();
            return false;
        case U_SCLN:
            // Send semicolon
            tap_code(KC_SCLN);
            reset_dubeolsik();
            return true;
    }

    // No recent syllable typed
    if (unicode_recent == 0) {
        add_unicode(unicode);
        return true;
    }

    // Recent syllable is a single moum
    if (ㅏ <= unicode_recent && unicode_recent <= ㅣ) {
        add_unicode(unicode);
        return true;
    }

    bool is_jaum = ㄱ <= unicode && unicode <= ㅎ;

    // Recent syllable is a single jaum
    if (ㄱ <= unicode_recent && unicode_recent <= ㅎ) {
        if (is_jaum) {
            // 초 + 자음
            uint32_t combined = combine(unicode_recent, unicode);
            if (combined == 0) {
                // = 초 초
                add_unicode(unicode);
            } else {
                // = (초초)
                edit_unicode(combined);
            }
        } else {
            // 초 + 모음
            uint32_t initial1, initial2;
            decompose(unicode_recent, &initial1, &initial2);
            if (initial1 == 0) {
                // = 초중
                edit_unicode(from_jamo(initial2, unicode, 0));
            } else {
                // = 초 초중
                edit_unicode(initial1);
                add_unicode(from_jamo(initial2, unicode, 0));
            }
        }
        return true;
    }

    uint32_t initial, medial, final;
    to_jamo(unicode_recent, &initial, &medial, &final);

    if (final == 0) {
        if (is_jaum) {
            // 초중 + 자음
            // = 초중종
            edit_unicode(from_jamo(initial, medial, unicode));
        } else {
            // 초중 + 모음
            uint32_t combined = combine(medial, unicode);
            if (combined != 0) {
                // = 초(중중)
                edit_unicode(from_jamo(initial, combined, 0));
            } else {
                // = 초중 중
                add_unicode(unicode);
            }
        }
    } else {
        if (is_jaum) {
            // 초중종 + 자음
            uint32_t combined = combine(final, unicode);
            if (combined == 0) {
                // = 초중종 초
                register_unicode(unicode);
                unicode_recent = unicode;
            } else {
                // = 초중(종종)
                edit_unicode(from_jamo(initial, medial, combined));
            }
        } else {
            // 초중종 + 모음
            // = 초중종 초중
            // = 초중 초중
            uint32_t final1, final2;
            decompose(final, &final1, &final2);
            edit_unicode(from_jamo(initial, medial, final1));
            add_unicode(from_jamo(final2, unicode, 0));
        }
    }

    return true;
}
