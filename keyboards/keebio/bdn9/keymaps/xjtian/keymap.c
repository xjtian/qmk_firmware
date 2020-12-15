/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum custom_keys {
    MISSION = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE, KC_MPLY, MISSION,
        KC_NO,   KC_UP  , RGB_MOD,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MISSION:
            if (record->event.pressed) {
                // no-op (open mission control on keyup)
            } else {
                register_code(KC_LCTL);
                tap_code(KC_UP);
                unregister_code(KC_LCTL);
            }
            break;
    }
    return true;
}


void encoder_update_user(uint8_t index, bool clockwise) {
    // idk how I fucked this up but the encoders are registering in reverse
    bool is_cw = !clockwise;

    if (index == _LEFT) {
        if (is_cw) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == _MIDDLE) {
        if (is_cw) {
            tap_code(KC_MFFD);
        } else {
            tap_code(KC_MRWD);
        }
    }
    else if (index == _RIGHT) {
        if (is_cw) {
            register_code(KC_LCTL);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCTL);
        } else {
            register_code(KC_LCTL);
            tap_code(KC_LEFT);
            unregister_code(KC_LCTL);
        }
    }
}
