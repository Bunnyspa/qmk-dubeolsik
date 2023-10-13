#include QMK_KEYBOARD_H
#include "dubeolsik.h"
#include "keymap.h"

uint16_t read_dbs_map(keyrecord_t *record) {
    uint8_t  row     = record->event.key.row;
    uint8_t  col     = record->event.key.col;
    uint16_t unicode = dbs_map[row][col];

    // Shifted keys (e.g. KC_LSFT + ㅂ = ㅃ)
    if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)) {
        switch (unicode) {
            case ㅂ:
            case ㅈ:
            case ㄷ:
            case ㄱ:
            case ㅅ:
                return unicode + 1;
            case ㅐ:
            case ㅔ:
                return unicode + 2;
        }
    }

    return unicode;
}

// clang-format off
uint16_t combine(uint16_t first, uint16_t second) {
    switch (first) {
        case ㄱ:
            switch (second) {
                case ㅅ: return ㄳ;
            }
            break;
        case ㄴ:
            switch (second) {
                case ㅈ: return ㄵ;
                case ㅎ: return ㄶ;
            }
            break;
        case ㄹ:
            switch (second) {
                case ㄱ: return ㄺ;
                case ㅁ: return ㄻ;
                case ㅂ: return ㄼ;
                case ㅅ: return ㄽ;
                case ㅌ: return ㄾ;
                case ㅍ: return ㄿ;
                case ㅎ: return ㅀ;
            }
            break;
        case ㅂ:
            switch (second) {
                case ㅅ: return ㅄ;
            }
            break;
        case ㅗ:
            switch (second) {
                case ㅏ: return ㅘ;
                case ㅐ: return ㅙ;
                case ㅣ: return ㅚ;
            }
            break;
        case ㅜ:
            switch (second) {
                case ㅓ: return ㅝ;
                case ㅔ: return ㅞ;
                case ㅣ: return ㅟ;
            }
            break;
        case ㅡ:
            switch (second) {
                case ㅣ: return ㅢ;
            }
            break;
    }
    return 0;
}

bool divide(uint16_t compound, uint16_t *first, uint16_t *second) {
    switch (compound) {
        case ㄳ: *first  = ㄱ; *second = ㅅ; return true;
        case ㄵ: *first  = ㄴ; *second = ㅈ; return true;
        case ㄶ: *first  = ㄴ; *second = ㅎ; return true;
        case ㄺ: *first  = ㄹ; *second = ㄱ; return true;
        case ㄻ: *first  = ㄹ; *second = ㅁ; return true;
        case ㄼ: *first  = ㄹ; *second = ㅂ; return true;
        case ㄽ: *first  = ㄹ; *second = ㅅ; return true;
        case ㄾ: *first  = ㄹ; *second = ㅌ; return true;
        case ㄿ: *first  = ㄹ; *second = ㅍ; return true;
        case ㅀ: *first  = ㄹ; *second = ㅎ; return true;
        case ㅄ: *first  = ㅂ; *second = ㅅ; return true;
        case ㅘ: *first  = ㅗ; *second = ㅏ; return true;
        case ㅙ: *first  = ㅗ; *second = ㅐ; return true;
        case ㅚ: *first  = ㅗ; *second = ㅣ; return true;
        case ㅝ: *first  = ㅜ; *second = ㅓ; return true;
        case ㅞ: *first  = ㅜ; *second = ㅔ; return true;
        case ㅟ: *first  = ㅜ; *second = ㅣ; return true;
        case ㅢ: *first  = ㅡ; *second = ㅣ; return true;
        default: return false;
    }
}
// clang-format on

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

void to_jamo(uint16_t unicode, uint16_t *initial, uint16_t *medial, uint16_t *final) {
    if (unicode < 가) {
        return;
    }

    uint16_t value = unicode - 가;

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
    int medial_index  = medial - ㅏ;
    int final_index   = (final == 0) ? 0 : final - ㄱ - final_offset;

    return initial_index * 588 + medial_index * 28 + final_index + 가;
}

static uint16_t unicode_recent = 0;

/**
 * Process Input
 */
void reset_dbs_input(void) {
    unicode_recent = 0;
}

void add_unicode(uint16_t unicode) {
    register_unicode(unicode);
    unicode_recent = unicode;
}

void edit_unicode(uint16_t unicode) {
    tap_code(KC_BSPC);
    register_unicode(unicode);
    unicode_recent = unicode;
}

bool process_record_dbs(uint16_t keycode, keyrecord_t *record) {
    // Fallthru shift (No reset)
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        return false;
    }

    uint16_t initial, medial, final;
    to_jamo(unicode_recent, &initial, &medial, &final);

    // Backspace
    if (keycode == KC_BSPC) {
        if (unicode_recent == 0) {
            // Fallthru if no recent korean is typed
            return false;
        }

        if (unicode_recent < 가) {
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
        return true;
    }

    uint16_t unicode = read_dbs_map(record);

    // Fallthru unmapped unicodes
    if (unicode == 0) {
        reset_dbs_input();
        return false;
    }

    // Tap non-korean unicodes (e.g. KC_SCLN)
    if (unicode < ㄱ || ㅣ < unicode) {
        reset_dbs_input();
        tap_code(unicode);
        return true;
    }

    bool is_jaum = ㄱ <= unicode && unicode <= ㅎ;

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

    return true;
}
