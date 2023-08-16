
// $ qmk flash -kb ferris/sweep -km uima -e CONVERT_TO=promicro_rp2040

#include QMK_KEYBOARD_H

enum layers_names {
    _DEF_,
    _NAV_,
    _SYM_,
    _FUN_,
    _WM_,
    _NUMP_,

    _OHA_,
    _OHB_,
    _OHN_,

    _GAME_,
};

enum custom_keycodes {
    KEYCODE = SAFE_RANGE,

    NAV_SPC = LT(_NAV_, KC_SPC),
    SYM_ENT = LT(_SYM_, KC_ENT),

    // Home Row Mod
    HM_A = LALT_T(KC_A),
    HM_R = LGUI_T(KC_R),
    HM_S = LCTL_T(KC_S),
    HM_T = LSFT_T(KC_T),

    HM_N = RSFT_T(KC_N),
    HM_E = RCTL_T(KC_E),
    HM_I = RGUI_T(KC_I),
    HM_O = RALT_T(KC_O),

    // Switch Layer
    TO_DEF = TO(_DEF_),
    TO_ONE = TO(_OHA_),
    TO_GAME = TO(_GAME_),

    // Combos
    CB_HMD,

    // Magic keys
    MAGIC = QK_ALT_REPEAT_KEY,

    MC_ND,
    MC_LE,
    MC_OR,
    MC_HT,
    MC_ON,
    MC_ENT,
    MC_UE,
    MC_ION,
    MC_HE,
    MC_ER,
    MC_OU,

    MC_THE,
    MC_UPDIR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF_] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    MAGIC,   KC_Y,    KC_SCLN,
        HM_A,    HM_R,    HM_S,    HM_T,    KC_G,         KC_M,    HM_N,    HM_E,    HM_I,    HM_O,
        KC_UNDS, KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_U,    KC_COMM, KC_DOT,
                                   XXXXXXX, NAV_SPC,      SYM_ENT, XXXXXXX
    ),

    [_NAV_] = LAYOUT(
        XXXXXXX, _______, _______, _______, _______,      _______, _______, _______, _______, XXXXXXX,
        KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, KC_COPY, KC_PSTE, _______,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_SYM_] = LAYOUT(
        XXXXXXX, KC_HASH, KC_LPRN, KC_RPRN, CB_HMD,       KC_AT,   KC_LCBR, KC_RCBR, KC_DLR,  XXXXXXX,
        KC_EXLM, KC_1,    KC_2,    KC_3,    KC_GRV,       _______, KC_EQL,  KC_MINS, KC_PLUS, KC_ASTR,
        KC_QUES, KC_8,    KC_9,    KC_0,    KC_PERC,      _______, KC_LBRC, KC_RBRC, _______, _______,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_FUN_] = LAYOUT(
        XXXXXXX, _______, _______, _______, QK_BOOT,      _______, TO_GAME, TO_ONE,  _______, XXXXXXX,
        _______, KC_F12,  KC_F11,  KC_F10,  _______,      _______, KC_F1,   _______, _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______,      _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_WM_] = LAYOUT(
        XXXXXXX, _______, _______, _______, _______,      _______, _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______, _______,      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4),
        _______, _______, _______, _______, _______,      _______, G(KC_5), G(KC_6), G(KC_7), G(KC_8),
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_NUMP_] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_NUMP_),   XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,
                                   XXXXXXX, XXXXXXX,      KC_0,    XXXXXXX
    ),

    [_OHA_] = LAYOUT(
        _______, KC_T,    KC_I,    KC_O,    _______,      _______, KC_O,    KC_I,    KC_T,    _______,
        _______, KC_A,    KC_N,    KC_E,    _______,      _______, KC_E,    KC_N,    KC_A,    _______,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                   KC_BSPC, KC_SPC,       KC_SPC,  KC_BSPC
    ),

    [_OHB_] = LAYOUT(
        _______, KC_B,    KC_V,    KC_Y,    _______,      _______, KC_B,    KC_V,    KC_Y,    _______,
        _______, KC_X,    KC_K,    KC_J,    _______,      _______, KC_J,    KC_K,    KC_X,    _______,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                   _______, _______,      _______, _______
    ),

    [_OHN_] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    _______,      _______, KC_3,    KC_2,    KC_1,    _______,
        _______, KC_8,    KC_9,    KC_0,    _______,      _______, KC_0,    KC_9,    KC_8,    _______,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                   _______, _______,      _______, _______
    ),

    [_GAME_] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_ENT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                                   KC_ESC,  KC_SPC,          KC_SPC,  KC_TAB
    ),

};

/* Create Combos */
#undef COMB
#define COMB(name, key, ...) name,
enum combos {
#include "combos.def"
};

#undef COMB
#define COMB(name, key, ...) const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
#include "combos.def"

#undef COMB
#define COMB(name, key, ...) [name] = COMBO(cmb_##name, key),
combo_t key_combos[] = {
#include "combos.def"
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(*key_combos);

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case ONE_HAND_COMBO_START ... ONE_HAND_COMBO_END:
            return COMBO_TERM + 150;
    }

    return COMBO_TERM;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        /* Enable def combo if def layer is enable */
        case DEFAULT_COMBO_START ... DEFAULT_COMBO_END:
            if (layer_state_is(_GAME_)) return false;
            if (layer_state_is(_DEF_)) return true;
        case ONE_HAND_COMBO_START ... ONE_HAND_COMBO_END:
            if (layer_state_is(_OHA_)) return true;
        case GAME_2_DEF:
            if (layer_state_is(_GAME_)) return true;
    }

    return false;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case HM_A:
        case HM_R:
        case HM_S:
        case HM_T:
        case HM_N:
        case HM_E:
        case HM_I:
        case HM_O:
            return TAPPING_TERM + 30;

        default:
            return TAPPING_TERM;
    }
}


#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
    // {KC_COMM, KC_QUOT}, // Shift , is '
    // {KC_DOT,  KC_DQUO}, // Shift . is "
    {KC_UNDS, KC_SLSH}, // Shift _ is /
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if ((mods & ~MOD_MASK_SHIFT) == 0) {
        switch (keycode) {
            /* Short Cut */   /* w x z  e u */
            case HM_A:  return MC_ND;       // a -> nd  *
            case KC_B:  return MC_LE;       // b -> le          ble / bility
            case KC_C:  return KC_S;        // c -> s   *
            case KC_D:  return KC_T;        // d -> t   .
            case HM_E:  return KC_E;        // e -> _
            case KC_F:  return MC_OR;       // f -> or
            case KC_G:  return MC_HT;       // g -> ht  *
            case KC_H:  return KC_N;        // h -> n           hough
            case HM_I:  return MC_ON;       // i -> on  *
            case KC_J:  return KC_U;        // j -> u   .       ju>jn
            case KC_K:  return KC_N;        // k -> n   *
            case KC_L:  return KC_L;        // l -> l   *
            case KC_M:  return MC_ENT;      // m -> ent *
            case HM_N:  return KC_L;        // n -> l   .       nu>nl>nk>nm>>nj>nh
            case HM_O:  return KC_O;        // o -> o           ough / oul / oo
            case KC_P:  return KC_T;        // p -> t   .
            case KC_Q:  return MC_UE;       // q -> ue  *
            case HM_R:  return KC_A;        // r -> a   *       for reducing redirects like raw/rat
            case HM_S:  return KC_C;        // s -> c   *
            case HM_T:  return MC_ION;      // t -> ion *
            case KC_U:  return KC_U;        // u -> _
            case KC_V:  return MC_ER;       // v -> er
            case KC_W:  return KC_W;        // w ->
            case KC_X:  return KC_X;        // x ->             xp>xa
            case KC_Y:  return MC_OU;       // y -> ou  *
            case KC_Z:  return KC_Z;        // z ->

            case KC_DOT:     return MC_UPDIR;  // . -> ./
            case NAV_SPC:    return MC_THE;    // _ -> the

            /* Reverse Repeat */
            case KC_COPY: return KC_PSTE;   // Copy  -> Paste
            case KC_PSTE: return KC_PSTE;   // Paste -> Paste
        }
    } else {
        switch (keycode) {
            case HM_A:
                if ((mods & MOD_MASK_CTRL)) return C(KC_C);  // Ctrl+A -> Ctrl+C
            case KC_C:
                if ((mods & MOD_MASK_CTRL)) return C(KC_V);  // Ctrl+C -> Ctrl+V
            case KC_TAB:
                if ((mods & MOD_MASK_GUI)) return G(KC_TAB);  // GUI+Tab -> GUI+Tab
        }
    }

    return KC_TRNS;  // Defer to default definitions.
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    // Tri Layer Implementation
    switch (keycode) {
        case NAV_SPC:
            if (record->event.pressed) layer_on(_NAV_);
            else layer_off(_NAV_);
            update_tri_layer(_NAV_, _SYM_, _FUN_);
            // return false;
            return true;
        case SYM_ENT:
            if (record->event.pressed) layer_on(_SYM_);
            else layer_off(_SYM_);
            update_tri_layer(_NAV_, _SYM_, _FUN_);
            // return false;
            return true;
    }

    if (record->event.pressed) {
        switch (keycode) {
            // Combos
            case CB_HMD: SEND_STRING("~/"); return false; break;

            // Magic keys
            case MC_ND:  SEND_STRING("nd"); break;
            case MC_LE:  SEND_STRING("le"); break;
            case MC_OR:  SEND_STRING("or"); break;
            case MC_HT:  SEND_STRING("ht"); break;
            case MC_ON:  SEND_STRING("on"); break;
            case MC_ENT: SEND_STRING("ent"); break;
            case MC_UE:  SEND_STRING("ue"); break;
            case MC_ION: SEND_STRING("ion"); break;
            case MC_HE:  SEND_STRING("he"); break;
            case MC_ER:  SEND_STRING("er"); break;
            case MC_OU:  SEND_STRING("ou"); break;

            case MC_THE:  /* Upcase 't' if holding shift when tap magic key */
                if (get_mods() & MOD_MASK_SHIFT) SEND_STRING("The");
                else SEND_STRING("the");
                break;
            case MC_UPDIR: /* First time, send "./", then "../" */
                if (get_repeat_key_count() == -1) SEND_STRING("./");
                else SEND_STRING("../");
                break;
        }
    }

    return true;
}
