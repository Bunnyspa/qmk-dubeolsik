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

bool shifted(void) {
    return keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT);
}

// Colemak-DH <-> Dubeolsik
uint32_t to_korean_unicode(uint16_t keycode) {
    switch (keycode) {
        case KC_Q:
            return shifted() ? ㅃ : ㅂ;
        case KC_W:
            return shifted() ? ㅉ : ㅈ;
        case KC_F:
            return shifted() ? ㄸ : ㄷ;
        case KC_P:
            return shifted() ? ㄲ : ㄱ;
        case KC_B:
            return shifted() ? ㅆ : ㅅ;
        case KC_J:
            return ㅛ;
        case KC_L:
            return ㅕ;
        case KC_U:
            return ㅑ;
        case KC_Y:
            return shifted() ? ㅒ : ㅐ;
        case KC_SCLN:
            return shifted() ? ㅖ : ㅔ;
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
            return KC_SCLN;
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

bool divide(uint32_t composed, uint32_t *first, uint32_t *second) {
    switch (composed) {
        case ㄳ:
            *first  = ㄱ;
            *second = ㅅ;
            return true;
        case ㄵ:
            *first  = ㄴ;
            *second = ㅈ;
            return true;
        case ㄶ:
            *first  = ㄴ;
            *second = ㅎ;
            return true;
        case ㄺ:
            *first  = ㄹ;
            *second = ㄱ;
            return true;
        case ㄻ:
            *first  = ㄹ;
            *second = ㅁ;
            return true;
        case ㄼ:
            *first  = ㄹ;
            *second = ㅂ;
            return true;
        case ㄽ:
            *first  = ㄹ;
            *second = ㅅ;
            return true;
        case ㄾ:
            *first  = ㄹ;
            *second = ㅌ;
            return true;
        case ㄿ:
            *first  = ㄹ;
            *second = ㅍ;
            return true;
        case ㅀ:
            *first  = ㄹ;
            *second = ㅎ;
            return true;
        case ㅄ:
            *first  = ㅂ;
            *second = ㅅ;
            return true;
        case ㅘ:
            *first  = ㅗ;
            *second = ㅏ;
            return true;
        case ㅙ:
            *first  = ㅗ;
            *second = ㅐ;
            return true;
        case ㅚ:
            *first  = ㅗ;
            *second = ㅣ;
            return true;
        case ㅝ:
            *first  = ㅜ;
            *second = ㅓ;
            return true;
        case ㅞ:
            *first  = ㅜ;
            *second = ㅔ;
            return true;
        case ㅟ:
            *first  = ㅜ;
            *second = ㅣ;
            return true;
        case ㅢ:
            *first  = ㅡ;
            *second = ㅣ;
            return true;
        default:
            *first  = 0;
            *second = composed;
            return false;
    }
}

bool final_able(uint32_t consonant) {
    switch (consonant) {
        case ㄸ:
        case ㅃ:
        case ㅉ:
            return false;
        default:
            return true;
    }
}

bool to_jamo(uint32_t unicode, uint32_t *initial, uint32_t *medial, uint32_t *final) {
    if (unicode < SYLLABLE_BASE) {
        return false;
    }

    uint32_t value = unicode - SYLLABLE_BASE;

    int final_index = value % 28;
    value /= 28;
    int medial_index  = value % 21;
    int initial_index = value / 21;

    int initial_offset = 9 <= initial_index   ? 11 // ㅅ ... ㅎ
                         : 6 <= initial_index ? 10 // ㅁ ... ㅃ
                         : 3 <= initial_index ? 3  // ㄷ ... ㄹ
                         : 2 == initial_index ? 1  // ㄴ
                                              : 0; // ㄱ

    int final_offset = 23 <= final_index   ? 2  // ㅊ ... ㅎ
                       : 18 <= final_index ? 1  // ㅄ ... ㅈ
                       : 8 <= final_index  ? 0  // ㄹ ... ㅂ
                                           : -1; // ㄱ ... ㄷ

    *initial = ㄱ + initial_index + initial_offset;
    *medial  = ㅏ + medial_index;
    *final   = (final_index == 0) ? 0 : ㄱ + final_index + final_offset;

    return true;
}

uint32_t from_jamo(uint32_t initial, uint32_t medial, uint32_t final) {
    if (medial == 0) {
        return initial;
    }

    int initial_offset = ㅅ <= initial   ? 11 // ㅅ ... ㅎ
                         : ㅁ <= initial ? 10 // ㅁ ... ㅃ
                         : ㄷ <= initial ? 3  // ㄷ ... ㄹ
                         : ㄴ == initial ? 1  // ㄴ
                                         : 0; // ㄱ

    int final_offset = ㅊ <= final   ? 2   // ㅊ ... ㅎ
                       : ㅄ <= final ? 1   // ㅄ ... ㅈ
                       : ㄹ <= final ? 0   // ㄹ ... ㅂ
                                     : -1; // ㄱ ... ㄷ

    int initial_index = initial - ㄱ - initial_offset;
    int medial_index  = medial - ㅏ;
    int final_index   = (final == 0) ? 0 : final - ㄱ - final_offset;

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
    // Fallthru shift (No reset)
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        return false;
    }

    uint32_t initial, medial, final;
    bool     jamo = to_jamo(unicode_recent, &initial, &medial, &final);

    // Backspace
    if (keycode == KC_BSPC) {
        if (unicode_recent == 0) {
            // Fallthru if no recent
            return false;
        }

        if (jamo) {
            if (final != 0) {
                // 각 + BSPC = 가
                // 갃 + BSPC = 각
                uint32_t f1, f2;
                divide(final, &f1, &f2); // If not dividable, f1 = 0
                edit_unicode(from_jamo(initial, medial, f1));
            } else {
                // 가 + BSPC = ㄱ
                // 각 + BSPC = 가
                uint32_t m1, m2;
                divide(medial, &m1, &m2); // If not dividable, m1 = 0
                edit_unicode(from_jamo(initial, m1, 0));
            }
        } else {
            uint32_t d1, d2;
            if (divide(unicode_recent, &d1, &d2)) {
                // ㄳ + BSPC = ㄱ
                // ㅘ + BSPC = ㅗ
                edit_unicode(d1);
            } else {
                // ㄱ + BSPC = []
                tap_code(KC_BSPC);
                reset_dubeolsik();
            }
        }
        return true;
    }

    uint32_t unicode = to_korean_unicode(keycode);

    // Fallthru unmapped keys
    if (unicode == 0) {
        reset_dubeolsik();
        return false;
    }

    bool is_jaum = ㄱ <= unicode && unicode <= ㅎ;

    // When KC_[A-Z] is not jamo in dubeolsik layout
    // e.g. KC_O is semicolon in dubeolsik
    switch (unicode) {
        case KC_SCLN:
            tap_code(KC_SCLN);
            reset_dubeolsik();
            return true;
        default:
            break;
    }

    // No recent syllable typed
    if (unicode_recent == 0) {
        add_unicode(unicode);
        return true;
    }

    // Recent syllable is a single jaum
    if (ㄱ <= unicode_recent && unicode_recent <= ㅎ) {
        if (is_jaum) {
            uint32_t combined = combine(unicode_recent, unicode);
            if (combined == 0) {
                // ㄱ + ㄱ = ㄱㄱ
                add_unicode(unicode);
            } else {
                // ㄱ + ㅅ = ㄳ
                edit_unicode(combined);
            }
        } else {
            uint32_t i1, i2;
            if (divide(unicode_recent, &i1, &i2)) {
                // ㄳ + ㅏ = ㄱ사
                edit_unicode(i1);
                add_unicode(from_jamo(i2, unicode, 0));
            } else {
                // ㄱ + ㅏ = 가
                edit_unicode(from_jamo(unicode_recent, unicode, 0));
            }
        }
        return true;
    }

    // Recent syllable is a single moum
    if (ㅏ <= unicode_recent && unicode_recent <= ㅣ) {
        if (is_jaum) {
            // ㅏ + ㄱ = ㅏㄱ
            add_unicode(unicode);
        } else {
            uint32_t combined = combine(unicode_recent, unicode);
            if (combined == 0) {
                // ㅏ + ㅏ = ㅏㅏ
                add_unicode(unicode);
            } else {
                // ㅗ + ㅏ = ㅘ
                edit_unicode(combined);
            }
        }
        return true;
    }

    if (final == 0) {
        if (is_jaum) {
            if (final_able(unicode)) {
                // 가 + ㄱ = 각
                edit_unicode(from_jamo(initial, medial, unicode));
            } else {
                // 가 + ㄸ = 가ㄸ
                add_unicode(unicode);
            }
        } else {
            uint32_t combined = combine(medial, unicode);
            if (combined == 0) {
                // 가 + ㅏ = 가ㅏ
                add_unicode(unicode);
            } else {
                // 고 + ㅏ = 과
                edit_unicode(from_jamo(initial, combined, 0));
            }
        }
    } else {
        if (is_jaum) {
            uint32_t combined = combine(final, unicode);
            if (combined == 0) {
                // 각 + ㄱ = 각ㄱ
                add_unicode(unicode);
            } else {
                // 각 + ㅅ = 갃
                edit_unicode(from_jamo(initial, medial, combined));
            }
        } else {
            // 갃 + ㅏ = 각사
            // 각 + ㅏ = 가가
            uint32_t f1, f2;
            divide(final, &f1, &f2); // If not dividable, f1 = 0, f2 = final
            edit_unicode(from_jamo(initial, medial, f1));
            add_unicode(from_jamo(f2, unicode, 0));
        }
    }

    return true;
}
