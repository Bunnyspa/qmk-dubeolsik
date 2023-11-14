bool process_record_dbs(uint16_t keycode, keyrecord_t *record, uint16_t ls_keycode, uint16_t rs_keycode);
void reset_dbs_input(void);

// Korean consonant unicodes (ㄱ ... ㅎ)
#define KR_G 0x3131
#define KR_GG 0x3132
#define KR_GS 0x3133
#define KR_N 0x3134
#define KR_NJ 0x3135
#define KR_NH 0x3136
#define KR_D 0x3137
#define KR_DD 0x3138
#define KR_L 0x3139
#define KR_LG 0x313a
#define KR_LM 0x313b
#define KR_LB 0x313c
#define KR_LS 0x313d
#define KR_LT 0x313e
#define KR_LP 0x313f
#define KR_LH 0x3140
#define KR_M 0x3141
#define KR_B 0x3142
#define KC_BB 0x3143
#define KC_BS 0x3144
#define KR_S 0x3145
#define KR_SS 0x3146
#define KR_X 0x3147
#define KR_J 0x3148
#define KR_JJ 0x3149
#define KR_CH 0x314a
#define KR_K 0x314b
#define KR_T 0x314c
#define KR_P 0x314d
#define KR_H 0x314e

// Korean vowel unicodes (ㅏ ... ㅣ)
#define KR_A 0x314f
#define KR_AE 0x3150
#define KR_YA 0x3151
#define KR_YAE 0x3152
#define KR_EO 0x3153
#define KR_E 0x3154
#define KR_YEO 0x3155
#define KR_YE 0x3156
#define KR_O 0x3157
#define KR_WA 0x3158
#define KR_WAE 0x3159
#define KR_OE 0x315a
#define KR_YO 0x315b
#define KR_U 0x315c
#define KR_WO 0x315d
#define KR_WE 0x315e
#define KR_WI 0x315f
#define KR_YU 0x3160
#define KR_EU 0x3161
#define KR_UI 0x3162
#define KR_I 0x3163

// Korean syllable unicode offset (가)
#define KR_SYLLABLE_OFFSET 0xac00
