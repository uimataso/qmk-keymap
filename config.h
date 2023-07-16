#pragma once

// Tap Hold
#define TAPPING_TERM 120
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0  /* Set to 0 to disable the Quick Tap Term that repeate the key when user holds a key after tapping it */

// Combo
// #define COMBO_COUNT 17
#define COMBO_TERM 40

// Caps Word
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 3000

// Oneshot
#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
