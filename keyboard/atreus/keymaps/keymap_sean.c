// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_TRNS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    },
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_TRNS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN },
  {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LGUI,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH },
  {KC_ESC, KC_TAB, KC_LALT, KC_BSPC, KC_LSFT,  KC_LCTL, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT,  KC_ENT  }
},
[_RS] = { /* [> RAISE <] */
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0  },
  {KC_GRV,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS},
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LGUI, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
  {TG(_LW), KC_TAB,  KC_TRNS, KC_LSFT, KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, RESET,   KC_BSLS, KC_EQL}
},
[_LW] = { /* [> LOWER <]*/
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
