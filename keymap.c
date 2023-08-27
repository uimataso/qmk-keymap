
// $ qmk flash -kb ferris/sweep -km uima -e CONVERT_TO=promicro_rp2040

#include QMK_KEYBOARD_H
#include "keycode.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF_] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    MAGIC,   KC_Y,    KC_SCLN,
        HM_A,    HM_R,    HM_S,    HM_T,    KC_G,         KC_M,    HM_N,    HM_E,    HM_I,    HM_O,
        KC_UNDS, KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_U,    KC_COMM, KC_DOT,
                                   XXXXXXX, NAV_SPC,      NUM_ENT, NUMWORD
    ),

    [_NAV_] = LAYOUT(
        XXXXXXX, _______, _______, _______, _______,      _______, _______, _______, _______, XXXXXXX,
        KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, KC_COPY, KC_PSTE, _______,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_NUM_] = LAYOUT(
        XXXXXXX, KC_HASH, KC_LPRN, KC_RPRN, ST_HMD,       KC_AT,   KC_LCBR, KC_RCBR, KC_DLR,  XXXXXXX,
        KC_EXLM, KC_1,    KC_2,    KC_3,    KC_GRV,       _______, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR,
        KC_QUES, KC_8,    KC_9,    KC_0,    KC_TILD,      _______, KC_LBRC, KC_RBRC, _______, _______,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_NUMWORD_] = LAYOUT(
        XXXXXXX, KC_HASH, KC_LPRN, KC_RPRN, ST_HMD,       KC_AT,   KC_LCBR, KC_RCBR, KC_DLR,  XXXXXXX,
        NW_6,    NW_4,    NW_0,    NW_2,    KC_G,         _______, NW_3,    NW_1,    NW_5,    NW_7,
        KC_UNDS, _______, _______, KC_8,    KC_TILD,      _______, NW_9,    _______, KC_COMM, KC_DOT,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_FUN_] = LAYOUT(
        XXXXXXX, _______, _______, _______, QK_BOOT,      _______, _______, _______, _______, XXXXXXX,
        _______, KC_F12,  KC_F11,  KC_F10,  _______,      _______, KC_F1,   _______, _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______,      _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,
                                   XXXXXXX, _______,      _______, XXXXXXX
    ),

    [_WM_] = LAYOUT(
        XXXXXXX, _______, _______, _______, _______,      _______, _______, _______, _______, XXXXXXX,
        _______, G(KC_1), G(KC_K), G(KC_J), _______,      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4),
        _______, _______, _______, _______, _______,      _______, G(KC_5), G(KC_6), G(KC_7), G(KC_8),
                                   XXXXXXX, _______,      _______, XXXXXXX
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

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        /* Enable def combo if def layer is enable */
        case DEFAULT_COMBO_START ... DEFAULT_COMBO_END:
            if (layer_state_is(_DEF_)) return true;
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

// 0 => acting like MO, 1 => undetermined, 2 => acting like OSL.
static uint8_t numword_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    switch (keycode) {
        // Tri Layer Implementation
        case NAV_SPC:
            if (record->event.pressed) layer_on(_NAV_);
            else layer_off(_NAV_);
            update_tri_layer(_NAV_, _NUM_, _FUN_);
            // return false;
            return true;
        case NUM_ENT:
            if (record->event.pressed) layer_on(_NUM_);
            else layer_off(_NUM_);
            update_tri_layer(_NAV_, _NUM_, _FUN_);
            // return false;
            return true;

        case NUMWORD:
            static uint32_t tap_deadline = 0;
            if (record->event.pressed) {  // On pressed.
                tap_deadline = timer_read32() + TAPPING_TERM;
                layer_on(_NUM_);
                numword_state = 1;  // Set undetermined state.
            } else {  // On release.
                layer_off(_NUM_);
                if (numword_state && !timer_expired32(timer_read32(), tap_deadline)) {
                    // NUMWORD was released without pressing another key within 200 ms.
                    layer_on(_NUMWORD_);
                    numword_state = 2;  // Acting like OSL.
                }
            }
            update_tri_layer(_NAV_, _NUM_, _FUN_);
            return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            // Num word
            case NW_1: SEND_STRING("1"); return false; break;
            case NW_2: SEND_STRING("2"); return false; break;
            case NW_3: SEND_STRING("3"); return false; break;
            case NW_4: SEND_STRING("4"); return false; break;
            case NW_5: SEND_STRING("5"); return false; break;
            case NW_6: SEND_STRING("6"); return false; break;
            case NW_7: SEND_STRING("7"); return false; break;
            case NW_8: SEND_STRING("8"); return false; break;
            case NW_9: SEND_STRING("9"); return false; break;
            case NW_0: SEND_STRING("0"); return false; break;

            // String
            case ST_HMD: SEND_STRING("~/"); return false; break;

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

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Turn off the layer if another key is pressed while acting like OSL. The
    // `(numword_state >>= 1)` both tests that state = 2 and shifts it toward zero.

    switch(keycode) {
        case NUMWORD:
        case NW_1 ... NW_0:
            break;

        default:
            if (numword_state >>= 1) {
                layer_off(_NUMWORD_);
            }
    }
}
