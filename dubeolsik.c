#include QMK_KEYBOARD_H

#define 가 0xac00

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

bool shifted(void) {
    return keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT);
}

// Colemak-DH <-> Dubeolsik
uint16_t to_korean_unicode(uint16_t keycode) {
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

uint16_t combine(uint16_t first, uint16_t second) {
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

bool divide(uint16_t composed, uint16_t *first, uint16_t *second) {
    switch (composed) {
        case ㄳ:
            *first = ㄱ;
            *second = ㅅ;
            return true;
        case ㄵ:
            *first = ㄴ;
            *second = ㅈ;
            return true;
        case ㄶ:
            *first = ㄴ;
            *second = ㅎ;
            return true;
        case ㄺ:
            *first = ㄹ;
            *second = ㄱ;
            return true;
        case ㄻ:
            *first = ㄹ;
            *second = ㅁ;
            return true;
        case ㄼ:
            *first = ㄹ;
            *second = ㅂ;
            return true;
        case ㄽ:
            *first = ㄹ;
            *second = ㅅ;
            return true;
        case ㄾ:
            *first = ㄹ;
            *second = ㅌ;
            return true;
        case ㄿ:
            *first = ㄹ;
            *second = ㅍ;
            return true;
        case ㅀ:
            *first = ㄹ;
            *second = ㅎ;
            return true;
        case ㅄ:
            *first = ㅂ;
            *second = ㅅ;
            return true;
        case ㅘ:
            *first = ㅗ;
            *second = ㅏ;
            return true;
        case ㅙ:
            *first = ㅗ;
            *second = ㅐ;
            return true;
        case ㅚ:
            *first = ㅗ;
            *second = ㅣ;
            return true;
        case ㅝ:
            *first = ㅜ;
            *second = ㅓ;
            return true;
        case ㅞ:
            *first = ㅜ;
            *second = ㅔ;
            return true;
        case ㅟ:
            *first = ㅜ;
            *second = ㅣ;
            return true;
        case ㅢ:
            *first = ㅡ;
            *second = ㅣ;
            return true;
        default:
            *first = 0;
            *second = composed;
            return false;
    }
}

bool final_able(uint16_t consonant) {
    switch (consonant) {
        case ㄸ:
        case ㅃ:
        case ㅉ:
            return false;
        default:
            return true;
    }
}

bool to_jamo(uint16_t unicode, uint16_t *initial, uint16_t *medial, uint16_t *final) {
    if (unicode < 가) {
        return false;
    }

    uint16_t value = unicode - 가;

    int final_index = value % 28;
    value /= 28;
    int medial_index = value % 21;
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
    *medial = ㅏ + medial_index;
    *final = (final_index == 0) ? 0 : ㄱ + final_index + final_offset;

    return true;
}

uint16_t from_jamo(uint16_t initial, uint16_t medial, uint16_t final) {
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
    int medial_index = medial - ㅏ;
    int final_index = (final == 0) ? 0 : final - ㄱ - final_offset;

    return initial_index * 588 + medial_index * 28 + final_index + 가;
}

static uint16_t unicode_recent = 0;

void add_unicode(uint16_t unicode) {
    register_unicode(unicode);
    unicode_recent = unicode;
}

void edit_unicode(uint16_t unicode) {
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

    uint16_t initial, medial, final;
    bool jamo = to_jamo(unicode_recent, &initial, &medial, &final);

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
                uint16_t f1, f2;
                divide(final, &f1, &f2); // If not dividable, f1 = 0
                edit_unicode(from_jamo(initial, medial, f1));
            } else {
                // 가 + BSPC = ㄱ
                // 각 + BSPC = 가
                uint16_t m1, m2;
                divide(medial, &m1, &m2); // If not dividable, m1 = 0
                edit_unicode(from_jamo(initial, m1, 0));
            }
        } else {
            uint16_t d1, d2;
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

    uint16_t unicode = to_korean_unicode(keycode);

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
            uint16_t combined = combine(unicode_recent, unicode);
            if (combined == 0) {
                // ㄱ + ㄱ = ㄱㄱ
                add_unicode(unicode);
            } else {
                // ㄱ + ㅅ = ㄳ
                edit_unicode(combined);
            }
        } else {
            uint16_t i1, i2;
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
            uint16_t combined = combine(unicode_recent, unicode);
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
            uint16_t combined = combine(medial, unicode);
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
            uint16_t combined = combine(final, unicode);
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
            uint16_t f1, f2;
            divide(final, &f1, &f2); // If not dividable, f1 = 0, f2 = final
            edit_unicode(from_jamo(initial, medial, f1));
            add_unicode(from_jamo(f2, unicode, 0));
        }
    }

    return true;
}
