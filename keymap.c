
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

    // Combos
    CB_NEQL,
    CB_PAN,
    CB_BRC,
    CB_CBR,
    CB_ABK,

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
        _______, _______, _______, _______, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, KC_COPY, KC_PSTE, _______,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_SYM_] = LAYOUT(
        XXXXXXX, KC_LCBR, KC_RCBR, KC_EQL,  KC_GRV,       KC_AT,   KC_MINS, KC_RABK, KC_LABK, XXXXXXX,
        KC_PLUS, KC_LPRN, KC_RPRN, KC_0,    KC_SLSH,      KC_CIRC, KC_1,    KC_RBRC, KC_LBRC, KC_ASTR,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_PERC,      KC_TILD, KC_2,    KC_3,    KC_4,    KC_5,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_FUN_] = LAYOUT(
        XXXXXXX, _______, _______, _______, QK_BOOT,      _______, _______, TO_ONE, _______, XXXXXXX,
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
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, KC_T,    KC_I,    KC_O,    _______,      _______, KC_O,    KC_I,    KC_T,    _______,
        _______, KC_A,    KC_N,    KC_E,    _______,      _______, KC_E,    KC_N,    KC_A,    _______,
                                   KC_BSPC, KC_SPC,       KC_SPC,  KC_BSPC
    ),

    [_OHB_] = LAYOUT(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, KC_F,    KC_M,    KC_U,    _______,      _______, KC_U,    KC_M,    KC_F,    _______,
        _______, KC_Y,    KC_B,    KC_W,    _______,      _______, KC_Y,    KC_B,    KC_W,    _______,
                                   _______, _______,      _______, _______
    ),
};

enum combos{
    DEFAULT_COMBO_START,

    DEF_Q,
    DEF_Z,

    DEF_BS,
    DEF_ESC,
    DEF_TAB,
    DEF_DEL,
    DEF_INS,
    DEF_CAPS,

    DEF_COLN,
    DEF_SCLN,
    DEF_EXLM,
    DEF_QUES,
    DEF_DOT,
    DEF_SLSH,

    DEF_WM,
    DEF_NUMPAD,

    SYM_DLR,
    SYM_HASH,
    SYM_AMPR,
    SYM_PIPE,
    SYM_BSLS,

    SYM_NEQL,

    SYM_PAN,
    SYM_BRC,
    SYM_CBR,
    SYM_ABK,

    DEFAULT_COMBO_END,

    ONE_HAND_COMBO_START,

    OHA_H,
    OHA_L,
    OHA_C,
    OHA_S,
    OHA_R,
    OHA_D,

    OHA_SW,

    OHA_SPC,
    OHA_BS,
    OHA_ESC,
    OHA_TAB,
    OHA_ENTER,

    OHA_SFT,
    OHA_CTL,
    OHA_GUI,
    OHA_ALT,

    OHB_G,
    OHB_P,
    OHB_V,
    OHB_K,
    OHB_J,
    OHB_X,
    OHB_Q,
    OHB_Z,

    OHB_2DEF,

    TIP_F,
    TIP_M,
    TIP_U,
    TIP_Y,
    TIP_B,
    TIP_W,

    TIP_G,
    TIP_P,
    TIP_V,
    TIP_K,
    TIP_J,
    TIP_X,
    TIP_Q,
    TIP_Z,

    ONE_HAND_COMBO_END,
};

// Default Layer
const uint16_t PROGMEM def_q[]      = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM def_z[]      = {KC_C, KC_D, COMBO_END};

const uint16_t PROGMEM def_bs[]     = {HM_N, HM_E, COMBO_END};
const uint16_t PROGMEM def_esc[]    = {HM_T, HM_S, COMBO_END};
const uint16_t PROGMEM def_tab[]    = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM def_del[]    = {KC_M, HM_N, COMBO_END};
const uint16_t PROGMEM def_ins[]    = {HM_T, KC_G, COMBO_END};
const uint16_t PROGMEM def_caps[]   = {HM_R, HM_T, COMBO_END};

const uint16_t PROGMEM def_coln[]   = {MAGIC, KC_Y, COMBO_END};
const uint16_t PROGMEM def_scln[]   = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM def_exlm[]   = {KC_H, KC_U, COMBO_END};
const uint16_t PROGMEM def_ques[]   = {KC_U, KC_COMM, COMBO_END};
const uint16_t PROGMEM def_dot[]    = {HM_E, HM_I, COMBO_END};
const uint16_t PROGMEM def_slsh[]   = {HM_R, HM_S, COMBO_END};

const uint16_t PROGMEM def_wm[]     = {HM_R, HM_S, HM_T, COMBO_END};
const uint16_t PROGMEM def_numpad[] = {HM_N, HM_E, HM_I, COMBO_END};

// Symbol Layer
const uint16_t PROGMEM sym_dlr[]    = {KC_1, KC_RBRC, COMBO_END};
const uint16_t PROGMEM sym_hash[]   = {KC_0, KC_RPRN, COMBO_END};
const uint16_t PROGMEM sym_ampr[]   = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM sym_pipe[]   = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM sym_bsls[]   = {KC_2, KC_3, COMBO_END};

const uint16_t PROGMEM sym_neql[]   = {KC_EQL, KC_RCBR, COMBO_END};
const uint16_t PROGMEM sym_pan[]    = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM sym_brc[]    = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM sym_cbr[]    = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM sym_abk[]    = {KC_LABK, KC_RABK, COMBO_END};

// One Hand Layer
const uint16_t PROGMEM oha_h[]      = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM oha_l[]      = {KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM oha_c[]      = {KC_T, KC_O, COMBO_END};
const uint16_t PROGMEM oha_s[]      = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM oha_r[]      = {KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM oha_d[]      = {KC_A, KC_E, COMBO_END};

const uint16_t PROGMEM oha_sw[]     = {KC_T, KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM oha_spc[]    = {KC_A, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM oha_bs[]     = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM oha_esc[]    = {KC_A, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM oha_tab[]    = {KC_A, KC_N, KC_O, COMBO_END};
const uint16_t PROGMEM oha_enter[]  = {KC_O, KC_E, COMBO_END};

const uint16_t PROGMEM oha_sft[]    = {KC_T, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM oha_ctl[]    = {KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM oha_gui[]    = {KC_T, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM oha_alt[]    = {KC_T, KC_N, COMBO_END};

const uint16_t PROGMEM ohb_g[]      = {KC_M, KC_U, COMBO_END};
const uint16_t PROGMEM ohb_p[]      = {KC_F, KC_M, COMBO_END};
const uint16_t PROGMEM ohb_v[]      = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM ohb_k[]      = {KC_B, KC_W, COMBO_END};
const uint16_t PROGMEM ohb_j[]      = {KC_Y, KC_B, COMBO_END};
const uint16_t PROGMEM ohb_x[]      = {KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM ohb_q[]      = {KC_Y, KC_B, KC_W, COMBO_END};
const uint16_t PROGMEM ohb_z[]      = {KC_M, KC_W, COMBO_END};

const uint16_t PROGMEM ohb_2def[]   = {KC_F, KC_Y, COMBO_END};

const uint16_t PROGMEM tip_f[]      = {KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM tip_m[]      = {KC_SPC, KC_I, COMBO_END};
const uint16_t PROGMEM tip_u[]      = {KC_SPC, KC_O, COMBO_END};
const uint16_t PROGMEM tip_y[]      = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM tip_b[]      = {KC_SPC, KC_N, COMBO_END};
const uint16_t PROGMEM tip_w[]      = {KC_SPC, KC_E, COMBO_END};

const uint16_t PROGMEM tip_g[]      = {KC_SPC, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM tip_p[]      = {KC_SPC, KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM tip_v[]      = {KC_SPC, KC_T, KC_O, COMBO_END};
const uint16_t PROGMEM tip_k[]      = {KC_SPC, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM tip_j[]      = {KC_SPC, KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM tip_x[]      = {KC_SPC, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM tip_q[]      = {KC_SPC, KC_A, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM tip_z[]      = {KC_SPC, KC_I, KC_E, COMBO_END};


combo_t key_combos[] = {
    // Default Layer
    [DEF_Q]      = COMBO(def_q,      KC_Q),
    [DEF_Z]      = COMBO(def_z,      KC_Z),

    [DEF_BS]     = COMBO(def_bs,     KC_BSPC),
    [DEF_ESC]    = COMBO(def_esc,    KC_ESC),
    [DEF_TAB]    = COMBO(def_tab,    KC_TAB),
    [DEF_DEL]    = COMBO(def_del,    KC_DEL),
    [DEF_INS]    = COMBO(def_ins,    KC_INS),
    [DEF_CAPS]   = COMBO(def_caps,   QK_CAPS_WORD_TOGGLE),

    [DEF_COLN]   = COMBO(def_coln,   KC_COLN),
    [DEF_SCLN]   = COMBO(def_scln,   KC_SCLN),
    [DEF_EXLM]   = COMBO(def_exlm,   KC_EXLM),
    [DEF_QUES]   = COMBO(def_ques,   KC_QUES),
    [DEF_DOT]    = COMBO(def_dot,    KC_DOT),
    [DEF_SLSH]   = COMBO(def_slsh,   KC_SLSH),

    [DEF_WM]     = COMBO(def_wm,     OSL(_WM_)),
    [DEF_NUMPAD] = COMBO(def_numpad, TG(_NUMP_)),

    // Symbol Layer
    [SYM_DLR]    = COMBO(sym_dlr,    KC_DLR),
    [SYM_HASH]   = COMBO(sym_hash,   KC_HASH),
    [SYM_AMPR]   = COMBO(sym_ampr,   KC_AMPR),
    [SYM_PIPE]   = COMBO(sym_pipe,   KC_PIPE),
    [SYM_BSLS]   = COMBO(sym_bsls,   KC_BSLS),

    [SYM_NEQL]   = COMBO(sym_neql,   CB_NEQL),

    [SYM_PAN]    = COMBO(sym_pan,    CB_PAN),
    [SYM_BRC]    = COMBO(sym_brc,    CB_BRC),
    [SYM_CBR]    = COMBO(sym_cbr,    CB_CBR),
    [SYM_ABK]    = COMBO(sym_abk,    CB_ABK),


    // One Hand Layer
    [OHA_H]      = COMBO(oha_h,      KC_H),
    [OHA_L]      = COMBO(oha_l,      KC_L),
    [OHA_C]      = COMBO(oha_c,      KC_C),
    [OHA_S]      = COMBO(oha_s,      KC_S),
    [OHA_R]      = COMBO(oha_r,      KC_R),
    [OHA_D]      = COMBO(oha_d,      KC_D),

    [OHA_SW]     = COMBO(oha_sw,     OSL(_OHB_)),

    [OHA_SPC]    = COMBO(oha_spc,    KC_SPC),
    [OHA_BS]     = COMBO(oha_bs,     KC_BSPC),
    [OHA_ESC]    = COMBO(oha_esc,    KC_ESC),
    [OHA_TAB]    = COMBO(oha_tab,    KC_TAB),
    [OHA_ENTER]  = COMBO(oha_enter,  KC_ENT),

    [OHA_SFT]    = COMBO(oha_sft,    OSM(MOD_LSFT)),
    [OHA_CTL]    = COMBO(oha_ctl,    OSM(MOD_LCTL)),
    [OHA_GUI]    = COMBO(oha_gui,    OSM(MOD_LGUI)),
    [OHA_ALT]    = COMBO(oha_alt,    OSM(MOD_LALT)),

    [OHB_G]      = COMBO(ohb_g,      KC_G),
    [OHB_P]      = COMBO(ohb_p,      KC_P),
    [OHB_V]      = COMBO(ohb_v,      KC_V),
    [OHB_K]      = COMBO(ohb_k,      KC_K),
    [OHB_J]      = COMBO(ohb_j,      KC_J),
    [OHB_X]      = COMBO(ohb_x,      KC_X),
    [OHB_Q]      = COMBO(ohb_q,      KC_Q),
    [OHB_Z]      = COMBO(ohb_z,      KC_Z),

    [OHB_2DEF]   = COMBO(ohb_2def,   TO_DEF),

    [TIP_F]  = COMBO(tip_f,  KC_F),
    [TIP_M]  = COMBO(tip_m,  KC_M),
    [TIP_U]  = COMBO(tip_u,  KC_U),
    [TIP_Y]  = COMBO(tip_y,  KC_Y),
    [TIP_B]  = COMBO(tip_b,  KC_B),
    [TIP_W]  = COMBO(tip_w,  KC_W),

    [TIP_G]  = COMBO(tip_g,  KC_G),
    [TIP_P]  = COMBO(tip_p,  KC_P),
    [TIP_V]  = COMBO(tip_v,  KC_V),
    [TIP_K]  = COMBO(tip_k,  KC_K),
    [TIP_J]  = COMBO(tip_j,  KC_J),
    [TIP_X]  = COMBO(tip_x,  KC_X),
    [TIP_Q]  = COMBO(tip_q,  KC_Q),
    [TIP_Z]  = COMBO(tip_z,  KC_Z),

};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(*key_combos);

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        /* Enable def combo if def layer is enable */
        case DEFAULT_COMBO_START ... DEFAULT_COMBO_END:
            if (layer_state_is(_DEF_)) return true;
        case ONE_HAND_COMBO_START ... ONE_HAND_COMBO_END:
            if (layer_state_is(_OHA_)) return true;
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
    {KC_COMM, KC_QUOT}, // Shift , is '
    {KC_DOT,  KC_DQUO}, // Shift . is "
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
            case CB_NEQL:  SEND_STRING("!=");               return false; break;
            case CB_PAN:   SEND_STRING("()"SS_TAP(X_LEFT)); return false; break;
            case CB_BRC:   SEND_STRING("[]"SS_TAP(X_LEFT)); return false; break;
            case CB_CBR:   SEND_STRING("{}"SS_TAP(X_LEFT)); return false; break;
            case CB_ABK:   SEND_STRING("<>"SS_TAP(X_LEFT)); return false; break;

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

            case MC_THE:
                if (get_mods() & MOD_MASK_SHIFT) SEND_STRING("The");
                else SEND_STRING("the");
                break;
            case MC_UPDIR: /* Alt repert key start from -1 */
                if (get_repeat_key_count() == -1) SEND_STRING("./");
                else SEND_STRING("../");
                break;
        }
    }

    return true;
}
