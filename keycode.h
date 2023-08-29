#pragma once
#include QMK_KEYBOARD_H

enum layers_names {
    _DEF_,
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
    HM_R = LGUI_T(KC_R),
    HM_S = LCTL_T(KC_S),
    HM_T = LSFT_T(KC_T),

    HM_N = RSFT_T(KC_N),
    HM_E = RCTL_T(KC_E),
    HM_I = RGUI_T(KC_I),
    HM_O = RALT_T(KC_O),

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

    MC_THE,
    MC_UPDIR,
};
