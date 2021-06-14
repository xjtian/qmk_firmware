#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */
//#define MASTER_LEFT

#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
// See https://github.com/qmk/qmk_firmware/pull/9404
// Currently, this branch is rebased on top of this PR
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
