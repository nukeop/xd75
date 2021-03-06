#include "xd75.h"

#define _QW 0
#define _FN 1

#define TAB MT(MOD_LCTL, KC_TAB)
#define ESC MT(MOD_LGUI, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = { /* QWERTY */
           { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,    KC_7,    KC_8,     KC_9,   KC_0,   KC_MINUS, KC_EQUAL, KC_PSCR, KC_BSPACE },
           { ESC,     KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_INS,  KC_HOME, KC_PGUP,  KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,    KC_QUOT   },
           { TAB,     KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_DEL,  KC_END,  KC_PGDN,  KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN, KC_ENT    },
           { KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_LBRC, KC_RBRC, KC_BSLS,  KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, KC_RSPC   },
           { KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, KC_RALT, KC_RGUI, KC_RCTRL, KC_SPC, KC_SPC, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT   },
  },
 
  [_FN] = { /* FUNCTION */
           { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______  },
           { _______, _______, _______, _______, _______,  _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______  },
           { _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  _______, KC_VOLD, _______, _______, _______, _______, RESET,  _______, _______, _______  },
           { _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______  },
           { _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
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
