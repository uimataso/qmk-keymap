#pragma once
#include QMK_KEYBOARD_H

enum layers_names {
    _DEF_,
    _COLEMAK_,
    _NERPS_,
    _NAV_,
    _NUM_,
    _FUN_,
    _WM_,
};

enum custom_keycodes {
    KEYCODE = SAFE_RANGE,

    NAV_SPC = LT(_NAV_, KC_SPC),
    NUM_ENT = LT(_NUM_, KC_ENT),

    NUMWORD,

    // Home Row Mod
    HM_A = LALT_T(KC_A),
    HM_S = LGUI_T(KC_S),
    HM_D = LCTL_T(KC_D),
    HM_F = LSFT_T(KC_F),

    HM_J = RSFT_T(KC_J),
    HM_K = RCTL_T(KC_K),
    HM_L = RGUI_T(KC_L),
    HM_P = RALT_T(KC_P),

    // HRM for Nerps
    CM_A = LALT_T(KC_A),
    CM_R = LGUI_T(KC_R),
    CM_S = LCTL_T(KC_S),
    CM_T = LSFT_T(KC_T),

    CM_N = RSFT_T(KC_N),
    CM_E = RCTL_T(KC_E),
    CM_I = RGUI_T(KC_I),
    CM_O = RALT_T(KC_O),

    // HRM for Nerps
    NE_N = LALT_T(KC_N),
    NE_R = LGUI_T(KC_R),
    NE_T = LCTL_T(KC_T),
    NE_S = LSFT_T(KC_S),

    NE_H = RSFT_T(KC_H),
    NE_E = RCTL_T(KC_E),
    NE_I = RGUI_T(KC_I),
    NE_A = RALT_T(KC_A),

    // Switch Layer
    TO_DEF = TO(_DEF_),

    // String
    ST_HMD,
    ST_PRNP,
    ST_PRNL,
    ST_BRCP,
    ST_BRCL,
    ST_CBRP,
    ST_CBRL,
    ST_ABKP,
    ST_ABKL,


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

    MC_UPDIR,
    MC_HELP,
    MC_THE,
};
