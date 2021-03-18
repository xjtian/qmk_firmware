#include QMK_KEYBOARD_H

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum microdox_layers {
    _QWERTY,
    _NUM,
    _SYMBOL,
    _ADJUST,
};

#define MON MO(_NUM)
#define MOS MO(_SYMBOL)
#define MOA MO(_ADJUST)

#define LTS LT(_SYMBOL, KC_ESC)
#define LTN LT(_NUM, KC_ENT)

#define HM_F CMD_T(KC_F)
#define HM_D ALT_T(KC_D)
#define HM_S CTL_T(KC_S)
#define HM_Z SFT_T(KC_Z)

#define HM_J CMD_T(KC_J)
#define HM_K ALT_T(KC_K)
#define HM_L CTL_T(KC_L)
#define HM_SL SFT_T(KC_SLSH)

#define TH_BS CMD_T(KC_BSPC)
#define TH_TAB RALT_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3( \
  //,-------------------------------------------.                    ,--------------------------------------------.
      KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  \
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_A,    HM_S,   HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L,   KC_SCLN,\
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      HM_Z,    KC_X,   KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,   KC_COMM, KC_DOT,   HM_SL, \
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                TH_BS,   LTS,   KC_LSFT,      KC_SPC,  LTN,    TH_TAB \
                            //`--------------------------'  `--------------------------'

  ),

  [_NUM] = LAYOUT_split_3x5_3( \
  //,--------------------------------------------.                    ,--------------------------------------------.
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_7,    KC_8,    KC_9,   KC_0, \
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_4,   KC_5,     KC_6,  KC_SLSH, \
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_LSHIFT,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_1,   KC_2,     KC_3,   KC_DOT, \
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 _______,  MOA,  _______,     _______,   _______, _______ \
                             //`--------------------------'  `--------------------------'
    ),

  [_SYMBOL] = LAYOUT_split_3x5_3( \
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, \
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_DQT, KC_PIPE, KC_LCBR, KC_LPRN, KC_LBRC,                      KC_RBRC, KC_RPRN, KC_RCBR, KC_BSLS, KC_QUOTE,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_TILD, KC_GRV,  XXXXXXX, RGB_MOD, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                _______, _______, _______,     _______,  MOA,    _______ \
                             //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x5_3( \
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_MPLY,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RESET, \
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_VOLU,                      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_VOLD,                      RGB_TOG, RGB_MOD, RGB_SAD, RGB_VAD, RGB_HUD,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                _______, _______, _______,    _______, _______, _______ \
                             //`--------------------------'  `--------------------------'
  )
};


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_BS:
        case HM_F:
        case HM_D:
        case HM_S:
        case HM_Z:
        case HM_J:
        case HM_K:
        case HM_L:
        case HM_SL:
            return false;
        default:
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LTS:
        case LTN:
        case TH_BS:
        case TH_TAB:
            return 100;
        default:
            return 200;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LTS:
        case LTN:
        case TH_BS:
        case TH_TAB:
            return false;
        default:
            return true;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LTS:
        case LTN:
        case TH_BS:
        case TH_TAB:
            return true;
        default:
            return false;
    }
}
