#include QMK_KEYBOARD_H

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum corne_layers {
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
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_A,    HM_S,   HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L,   KC_SCLN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  HM_Z,    KC_X,   KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,   KC_COMM, KC_DOT,   HM_SL,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TH_BS,   LTS,   KC_LSFT,      KC_SPC,  LTN,    TH_TAB \
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_7,    KC_8,    KC_9,   KC_0,     XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_4,   KC_5,     KC_6,  KC_SLSH,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_LSHIFT,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_1,   KC_2,     KC_3,   KC_DOT,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  MOA,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

  [_SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_DQT, KC_PIPE, KC_LCBR, KC_LPRN, KC_LBRC,                      KC_RBRC, KC_RPRN, KC_RCBR, KC_BSLS, KC_QUOTE, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_TILD, KC_GRV,  XXXXXXX, RGB_MOD, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______,  MOA,    _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_MPLY,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RESET,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_VOLU,                      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_VOLD,                      RGB_TOG, RGB_MOD, RGB_SAD, RGB_VAD, RGB_HUD, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
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


void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

//const char *read_rgb_info(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  return true;
}
