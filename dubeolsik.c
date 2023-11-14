#include QMK_KEYBOARD_H
#include "dubeolsik.h"
#include "keymap.h"

uint16_t read_dbs_keymap(keyrecord_t *record) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;
    uint16_t unicode = dbs_keymap[row][col];

    // Shifted keys (e.g. KC_LSFT + ㅂ = ㅃ)
    if (get_mods() & MOD_MASK_SHIFT) {
        switch (unicode) {
            case KR_B: // ㅂ
            case KR_J: // ㅈ
            case KR_D: // ㄷ
            case KR_G: // ㄱ
            case KR_S: // ㅅ
                return unicode + 1;
            case KR_AE: // ㅐ
            case KR_E:  // ㅔ
                return unicode + 2;
        }
    }

    return unicode;
}

// clang-format off
uint16_t combine(uint16_t first, uint16_t second) {
    switch (first) {
        case KR_G: // ㄱ
            switch (second) {
                case KR_S: return KR_GS; // ㄳ
            }
            break;
        case KR_N: // ㄴ
            switch (second) {
                case KR_J: return KR_NJ; // ㄵ
                case KR_H: return KR_NH; // ㄶ
            }
            break;
        case KR_L: // ㄹ
            switch (second) {
                case KR_G: return KR_LG; // ㄺ
                case KR_M: return KR_LM; // ㄻ
                case KR_B: return KR_LB; // ㄼ
                case KR_S: return KR_LS; // ㄽ
                case KR_T: return KR_LT; // ㄾ
                case KR_P: return KR_LP; // ㄿ
                case KR_H: return KR_LH; // ㅀ
            }
            break;
        case KR_B: // ㅂ
            switch (second) {
                case KR_S: return KC_BS; // ㅄ
            }
            break;
        case KR_O: // ㅗ
            switch (second) {
                case KR_A: return KR_WA; // ㅘ
                case KR_AE: return KR_WAE; // ㅙ
                case KR_I: return KR_OE; // ㅚ
            }
            break;
        case KR_U: // ㅜ
            switch (second) {
                case KR_EO: return KR_WO; // ㅝ
                case KR_E: return KR_WE; // ㅞ
                case KR_I: return KR_WI; // ㅟ
            }
            break;
        case KR_EU: // ㅡ
            switch (second) {
                case KR_I: return KR_UI; // ㅢ
            }
            break;
    }
    return 0;
}

bool divide(uint16_t compound, uint16_t *first, uint16_t *second) {
    switch (compound) {
        case KR_GS:  *first  = KR_G;  *second = KR_S;  return true; // ㄳ
        case KR_NJ:  *first  = KR_N;  *second = KR_J;  return true; // ㄵ
        case KR_NH:  *first  = KR_N;  *second = KR_H;  return true; // ㄶ
        case KR_LG:  *first  = KR_L;  *second = KR_G;  return true; // ㄺ
        case KR_LM:  *first  = KR_L;  *second = KR_M;  return true; // ㄻ
        case KR_LB:  *first  = KR_L;  *second = KR_B;  return true; // ㄼ
        case KR_LS:  *first  = KR_L;  *second = KR_S;  return true; // ㄽ
        case KR_LT:  *first  = KR_L;  *second = KR_T;  return true; // ㄾ
        case KR_LP:  *first  = KR_L;  *second = KR_P;  return true; // ㄿ
        case KR_LH:  *first  = KR_L;  *second = KR_H;  return true; // ㅀ
        case KC_BS:  *first  = KR_B;  *second = KR_S;  return true; // ㅄ
        case KR_WA:  *first  = KR_O;  *second = KR_A;  return true; // ㅘ
        case KR_WAE: *first  = KR_O;  *second = KR_AE; return true; // ㅙ
        case KR_OE:  *first  = KR_O;  *second = KR_I;  return true; // ㅚ
        case KR_WO:  *first  = KR_U;  *second = KR_EO; return true; // ㅝ
        case KR_WE:  *first  = KR_U;  *second = KR_E;  return true; // ㅞ
        case KR_WI:  *first  = KR_U;  *second = KR_I;  return true; // ㅟ
        case KR_UI:  *first  = KR_EU; *second = KR_I;  return true; // ㅢ
        default: return false;
    }
}
// clang-format on

bool is_valid_final(uint16_t consonant) {
    switch (consonant) {
        case KR_DD: // ㄸ
        case KC_BB: // ㅃ
        case KR_JJ: // ㅉ
            return false;
        default:
            return true;
    }
}

uint16_t from_jamo(uint16_t initial, uint16_t medial, uint16_t final) {
    if (medial == 0) {
        return initial;
    }

    int initial_offset = KR_S <= initial   ? 11 // ㅅ ... ㅎ
                         : KR_M <= initial ? 10 // ㅁ ... ㅃ
                         : KR_D <= initial ? 3  // ㄷ ... ㄹ
                         : KR_N == initial ? 1  // ㄴ
                                           : 0; // ㄱ

    int final_offset = KR_CH <= final   ? 2  // ㅊ ... ㅎ
                       : KC_BS <= final ? 1  // ㅄ ... ㅈ
                       : KR_L <= final  ? 0  // ㄹ ... ㅂ
                                        : -1; // ㄱ ... ㄷ

    int initial_index = initial - KR_G - initial_offset;
    int medial_index = medial - KR_A;
    int final_index = (final == 0) ? 0 : final - KR_G - final_offset;

    return initial_index * 588 + medial_index * 28 + final_index + KR_SYLLABLE_OFFSET;
}

void to_jamo(uint16_t unicode, uint16_t *initial, uint16_t *medial, uint16_t *final) {
    if (unicode < KR_SYLLABLE_OFFSET) {
        return;
    }

    uint16_t value = unicode - KR_SYLLABLE_OFFSET;

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

    *initial = KR_G + initial_index + initial_offset;
    *medial = KR_A + medial_index;
    *final = (final_index == 0) ? 0 : KR_G + final_index + final_offset;
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

/**
 * Resets input.
 */
void reset_dbs_input(void) {
    unicode_recent = 0;
}

/**
 * Processes input. Acts like the process_record_*() functions.
 * Returns true if the key press will not be handled here and requires processing outside the function, whether by QMK or process_record_*() functions.
 */
bool process_record_dbs(uint16_t keycode, keyrecord_t *record, uint16_t ls_keycode, uint16_t rs_keycode) {
    // Skip handling shift (No Reset)
    if (keycode == ls_keycode || keycode == rs_keycode) {
        return true;
    }

    // Skip modifier and one shot combinations except for Shift (Reset)
    if (((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT) != 0) {
        reset_dbs_input();
        return true;
    }

    uint16_t initial, medial, final;
    to_jamo(unicode_recent, &initial, &medial, &final);

    // Backspace
    if (keycode == KC_BSPC) {
        if (unicode_recent == 0) {
            // Skip handling usual backspace
            return true;
        }

        if (unicode_recent < KR_SYLLABLE_OFFSET) {
            if (final != 0) {
                uint16_t f1, f2;
                if (divide(final, &f1, &f2)) {
                    // 갃 + BSPC = 각
                    edit_unicode(from_jamo(initial, medial, f1));
                } else {
                    // 각 + BSPC = 가
                    edit_unicode(from_jamo(initial, medial, 0));
                }
            } else {
                uint16_t m1, m2;
                if (divide(medial, &m1, &m2)) {
                    // 각 + BSPC = 가
                    edit_unicode(from_jamo(initial, m1, 0));
                } else {
                    // 가 + BSPC = ㄱ
                    edit_unicode(from_jamo(initial, 0, 0));
                }
            }
        } else {
            uint16_t d1, d2;
            if (divide(unicode_recent, &d1, &d2)) {
                // ㄳ + BSPC = ㄱ
                // ㅘ + BSPC = ㅗ
                edit_unicode(d1);
            } else {
                // ㄱ + BSPC = []
                reset_dbs_input();
                tap_code(KC_BSPC);
            }
        }
        return false;
    }

    uint16_t unicode = read_dbs_keymap(record);

    // Skip handling unmapped unicodes
    if (unicode == 0) {
        reset_dbs_input();
        return true;
    }

    // Tap non-korean unicodes (e.g. KC_SCLN)
    if (unicode < KR_G || KR_I < unicode) {
        reset_dbs_input();
        tap_code(unicode);
        return false;
    }

    bool is_jaum = KR_G <= unicode && unicode <= KR_H;

    // No recent korean input
    if (unicode_recent == 0) {
        add_unicode(unicode);
        return false;
    }

    // Recent korean input is a single jaum
    if (KR_G <= unicode_recent && unicode_recent <= KR_H) {
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
        return false;
    }

    // Recent korean input is a single moum
    if (KR_A <= unicode_recent && unicode_recent <= KR_I) {
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
        return false;
    }

    if (final == 0) {
        if (is_jaum) {
            if (is_valid_final(unicode)) {
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
            uint16_t f1, f2;
            if (divide(final, &f1, &f2)) {
                // 갃 + ㅏ = 각사
                edit_unicode(from_jamo(initial, medial, f1));
                add_unicode(from_jamo(f2, unicode, 0));
            } else {
                // 각 + ㅏ = 가가
                edit_unicode(from_jamo(initial, medial, 0));
                add_unicode(from_jamo(final, unicode, 0));
            }
        }
    }

    return false;
}
