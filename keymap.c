#include "xd75.h"

#define TAPPING_TERM 200

#define _QW 0
#define _FN 1

enum {
  TAP0 = 0,
  TAP1 = 1,
  TAP2 = 2,
  TAP3 = 3,
  TAP4 = 4,
  TAP5 = 5,
  TAP6 = 6,
  TAP7 = 7,
  TAP8 = 8,
  TAP9 = 9
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TAP0]  = ACTION_TAP_DANCE_DOUBLE(KC_0, S(KC_0)),
  [TAP1]  = ACTION_TAP_DANCE_DOUBLE(KC_1, S(KC_1)),
  [TAP2]  = ACTION_TAP_DANCE_DOUBLE(KC_2, S(KC_2)),
  [TAP3]  = ACTION_TAP_DANCE_DOUBLE(KC_3, S(KC_3)),
  [TAP4]  = ACTION_TAP_DANCE_DOUBLE(KC_4, S(KC_4)),
  [TAP5]  = ACTION_TAP_DANCE_DOUBLE(KC_5, S(KC_5)),
  [TAP6]  = ACTION_TAP_DANCE_DOUBLE(KC_6, S(KC_6)),
  [TAP7]  = ACTION_TAP_DANCE_DOUBLE(KC_7, S(KC_7)),
  [TAP8]  = ACTION_TAP_DANCE_DOUBLE(KC_8, S(KC_8)),
  [TAP9]  = ACTION_TAP_DANCE_DOUBLE(KC_9, S(KC_9))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = { /* QWERTY */
    { KC_GESC,        KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_HOME, KC_END,  TD(TAP7), TD(TAP8), TD(TAP9), KC_PGDOWN, KC_PGUP, KC_PSCREEN, KC_MINUS, KC_EQUAL, KC_BSPACE },
    { KC_TAB,         KC_Q,        KC_W,        KC_E,      KC_R,    KC_T,    TD(TAP4), TD(TAP5), TD(TAP6), KC_Y,      KC_U,    KC_I,       KC_O,     KC_P,     KC_QUOT   },
    { ALL_T(_______), KC_A,        KC_S,        KC_D,      KC_F,    KC_G,    TD(TAP1), TD(TAP2), TD(TAP3), KC_H,      KC_J,    KC_K,       KC_L,     KC_SCLN,  KC_ENT    },
    { KC_LSPO,        KC_Z,        KC_X,        KC_C,      KC_V,    KC_B,    TD(TAP0), KC_UP,    KC_INS,   KC_N,      KC_M,    KC_COMM,    KC_DOT,   KC_SLSH,  KC_RSPC   },
    { KC_LCTL,        KC_LGUI,     KC_LALT,     MO(_FN),   KC_SPC,  KC_SPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_SPC,    KC_SPC,  MO(_FN),    KC_RALT,  KC_RGUI,  KC_RCTL   },
  },
 
 [_FN] = { /* FUNCTION */
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_MUTE, KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
  { KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,   KC_F18,  KC_VOLU, KC_CALC, _______, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24  },
  { _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_BTN1, KC_MS_U, KC_BTN3, _______, _______, RESET   },
  { _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, _______, KC_VOLD, KC_MSTP, _______, KC_MS_L, KC_BTN2, KC_MS_R, _______, _______, _______ },
  { _______, _______,  _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_MS_D, KC_WH_U, _______, _______, _______, },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
