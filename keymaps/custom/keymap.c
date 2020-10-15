#include QMK_KEYBOARD_H
#include "version.h"

#define FORCE_NKRO


#define _BASE 0   // default layer
#define _CMD 1    // Like Control keys
#define _SYMB 2  // Enter and Shift (Symbol layer)
#define _LFN 3   // Fn key
#define _RFN 4   // Fn key

enum custom_keycodes {
    BASE = SAFE_RANGE,
    CMD,      // like ctrl or alt
    SYMB,     // symbol
    LFN,      // left fn
    RFN,      // right fn
    KANA,     // kana or 
    ALT_TAB,  // alttab
    Z_ALT,    // for custom alttab
    Z_TAB,    // for custom alttab
    Z_CAPS,   // for custom caps
    Z_ESC,    // for custom caps
};

#define CTL_TAB LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `(~)  |   1  |   2  |   3  |   4  |   5  |  6  |           |   6  |   7  |   8  |   9  |   0  |   -   |    =  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |   Y  |           |  T   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|  H   |           |  B   |------+------+------+------+------+--------|
 * | LShift |SFT(Z)|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | _FN  | LAlt | LWin| LAlt | _CMD  |                                       | KANA |  [   |   ]  | RWin | _FN   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Esc  | Del  |       | PSCR  |  _FN  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Enter |       | Esc  |        |Enter |
 *                                 | Space|LShift|------|       |------| RCtrl  |   &  |
 *                                 |      |      | BS   |       | Del  |        | _SYMB|
 *                                 `--------------------'       `----------------------'
 */
[_BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRV,   KC_1,         KC_2,    KC_3,     KC_4,    KC_5,    KC_6,       KC_6,      KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,   KC_EQL,
  Z_TAB,    KC_Q,         KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,       KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_BSLS,
  KC_LCTL,  KC_A,         KC_S,    KC_D,     KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_QUOT,
  KC_LSFT,  SFT_T(KC_Z),  KC_X,    KC_C,     KC_V,    KC_B,    KC_H,       KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_RSFT,
  LFN,      Z_ALT,        KC_LGUI, Z_ALT,    CMD,                                              KANA,    KC_LBRC, KC_RBRC,  KC_RGUI,   RFN,
                                                    KC_ESC, KC_PSCR,       KC_PSCR,   TG(4),
                                                             KC_DEL,       KC_ESC,
                                           KC_SPC, KC_LSFT,  KC_ENT,       KC_DEL, KC_BSPC, SYMB
),

/* 
 * Keymap 1: like a control key 
 */
[_CMD] = LAYOUT_ergodox_pretty(
  // left hand
  LALT(KC_GRV),  S(KC_CAPS),  KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,         KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,     KC_F11,     KC_F12, 
  ALT_TAB,       LCTL(KC_Q),  LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), LCTL(KC_T), LCTL(KC_Y),    LCTL(KC_T), LCTL(KC_Y), LCTL(KC_U), KC_ESC,    LCTL(KC_O), KC_LBRC,    KC_RBRC,
  _______,       LCTL(KC_A),  LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_G),                            KC_LEFT,    KC_DOWN,    KC_UP,     KC_RGHT,    KC_BSPC,    KC_DEL,
  _______,       LCTL(KC_Z),  LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B), LCTL(KC_H),    LCTL(KC_B), LCTL(KC_N), KC_ENT,     KC_HOME,   KC_END,     C(KC_BSPC), _______,
  _______,       _______,     _______,    _______,    _______,                                            _______,   LCTL(KC_LBRC),    LCTL(KC_RBRC),    _______,   _______,
                                                                  _______,    _______,       _______, _______,
                                                                              _______,       _______,
                                                         _______, _______,    _______,       _______, KC_DEL, S(KC_CAPS)
),
/* 
 * Keymap 2: Enter and shift keys
 */
[_SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  S(KC_BSLS),  S(KC_1),     S(KC_2),    S(KC_3),    S(KC_4),     S(KC_5),     S(KC_6),      S(KC_6),  S(KC_7),      S(KC_8),   S(KC_9),    S(KC_0),    S(KC_MINS),  S(KC_EQL), 
  _______,     S(KC_QUOT),  S(KC_LBRC), S(KC_RBRC), S(KC_4),     S(KC_5),     S(KC_6),      S(KC_5),  S(KC_6),      S(KC_U),    KC_ESC,    S(KC_O),    S(KC_P),     _______,
  _______,     S(KC_A),     S(KC_9),    S(KC_0),    KC_EQL,      S(KC_EQL),                           S(KC_GRV),    KC_DOWN,    KC_UP,     KC_RGHT,    KC_BSPC,     KC_DEL,
  _______,     S(KC_SCLN),  KC_LBRC,    KC_RBRC,    S(KC_MINS),  S(KC_BSLS),  S(KC_GRV),    S(KC_B),  S(KC_N),      KC_ENT,     KC_HOME,   KC_END,     Z_CAPS,      _______,
  _______,     _______,     _______,    _______,    _______,                                                        _______,    _______,   _______,    _______,     _______,
                                                                 _______,     _______,      _______, _______,
                                                                              _______,      _______,
                                                        _______, _______,     _______,      _______, _______, _______
),
/* 
 * Keymap 3: Left FN 
 */
[_LFN] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,        KC_F1,       KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F6,         KC_F7,      KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12, 
  LCTL(KC_TAB),  LALT(KC_F4), LCTL(KC_W), KC_UP,   S(KC_4), S(KC_5), S(KC_6),           S(KC_6),       S(KC_7),    S(KC_8), S(KC_9), S(KC_0), S(KC_LBRC),S(KC_RBRC),
  _______,       KC_HOME,     KC_LEFT,    KC_DOWN, KC_RGHT, KC_GRV,                                    KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,   KC_APP,
  _______,       LCTL(KC_Z),  LCTL(KC_X), LCTL(KC_INS), S(KC_INS), KC_TILD, KC_LEFT,    LCTL(KC_LEFT), LCTL(KC_N), KC_ENT,  S(KC_HOME), S(KC_END), S(KC_SLSH),   _______,
  _______,       _______,     _______,    _______,      _______,                                                   _______, KC_PGUP, KC_PGDOWN, _______, _______,
                                                                   _______, _______,    _______, _______,
                                                                            _______,    _______,
                                                          _______, _______, _______,    _______, _______, _______
),
/* 
 * Keymap 4: Right FN 
 */
[_RFN] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,        KC_F1,       KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F6,         KC_F7,      KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12, 
  LCTL(KC_TAB),  LALT(KC_F4), LCTL(KC_W), KC_UP,   S(KC_4), S(KC_5), S(KC_6),           S(KC_6),       S(KC_7),    S(KC_8), S(KC_9), S(KC_0), S(KC_INS), KC_UP,
  _______,       KC_HOME,     KC_LEFT,    KC_DOWN, KC_RGHT, KC_GRV,                                    KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, KC_LEFT,   KC_RGHT,
  _______,       LCTL(KC_Z),  LCTL(KC_X), LCTL(KC_INS), S(KC_INS), KC_TILD, KC_LEFT,    LCTL(KC_LEFT), LCTL(KC_N), KC_ENT,  KC_HOME, KC_END,  KC_DOWN,   _______,
  _______,       _______,     _______,    _______,      _______,                                                   _______, KC_PGUP, KC_PGDOWN, _______, _______,
                                                                   _______, _______,    _______, _______,
                                                                            _______,    RESET,
                                                          _______, _______, _______,    _______, _______, _______
),
};

// layer on & off
static bool cmd_pressed = false;
static uint16_t cmd_pressed_time = 0;
static bool symb_pressed = false;
static uint16_t symb_pressed_time = 0;
static bool kana_pressed = false;
static uint16_t kana_pressed_time = 0;
// custom AltTab 
static bool alt_pressed = false;
static bool is_alttab_active = false;
// capslock state control
static bool caps_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMD:
            if (record->event.pressed) {
                cmd_pressed = true;
                cmd_pressed_time = record->event.time;
                layer_on(_CMD);
            } else {
                layer_off(_CMD);
                if (cmd_pressed && (TIMER_DIFF_16(record->event.time, cmd_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_LSFT);
                    register_code(KC_CAPS);
                    unregister_code(KC_CAPS);
                    unregister_code(KC_LSFT);
                } else if (is_alttab_active) {
                    is_alttab_active = false;
                    unregister_code(KC_LALT);
                }
                cmd_pressed = false;
            }
            return false;
            break;
        case SYMB:
            if (record->event.pressed) {
                symb_pressed = true;
                symb_pressed_time = record->event.time;
                layer_on(_SYMB);
            } else {
                layer_off(_SYMB);
                if (symb_pressed && (TIMER_DIFF_16(record->event.time, symb_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_ENT);
                    unregister_code(KC_ENT);
                }
                symb_pressed = false;
            }
            return false;
            break;
        case LFN:
            if (record->event.pressed) {
                layer_on(_LFN);
            } else {
                layer_off(_LFN);
            }
            return false;
            break;
        case RFN:
            if (record->event.pressed) {
                layer_on(_RFN);
            } else {
                layer_off(_RFN);
            }
            return false;
            break;
        case KANA:
            if (record->event.pressed) {
                kana_pressed = true;
                kana_pressed_time = record->event.time;
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
                if (kana_pressed && (TIMER_DIFF_16(record->event.time, kana_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_F23);
                    unregister_code(KC_F23);
                }
                kana_pressed = false;
            }
            return false;
            break;
        // AltTab with CMD key 
        case ALT_TAB:
            if (record->event.pressed) {
                is_alttab_active = true;
                register_code(KC_LALT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
            break;
        // custom AltTab
        case Z_ALT:
            if (record->event.pressed) {
                alt_pressed = true;
                register_code(KC_LALT);
            } else {
                alt_pressed = false;
                if (is_alttab_active) {
                    is_alttab_active = false;
                    layer_off(_CMD);
                }
                unregister_code(KC_LALT);
            }
            return false;
            break;
        case Z_TAB:
            if (record->event.pressed) {
                if (alt_pressed) {
                    is_alttab_active = true;
                    layer_on(_CMD);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
            break;
        // control capslock state
        case Z_CAPS:
            if (record->event.pressed) {
                if (!caps_on) {
                    caps_on = true;
                } else if (caps_on) {
                    caps_on = false;
                }
                register_code(KC_CAPS);
            } else {
                unregister_code(KC_CAPS);
            }
            return false;
            break;
        case Z_ESC:
            if (record->event.pressed) {
                if (caps_on) {
                    caps_on = false;
                    register_code(KC_CAPS);
                    unregister_code(KC_CAPS);
                }
                register_code(KC_ESC);
            } else {
                unregister_code(KC_ESC);
            }
            return false;
            break;
        default:
            if (record->event.pressed) {
                // reset the flags
                cmd_pressed = false;
                symb_pressed = false;
                kana_pressed = false;
            }
            break;
    }
    return true;
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// #define RGBLIGHT_COLOR_LAYER_0 0x00, 0x00, 0xFF
/* #define RGBLIGHT_COLOR_LAYER_1 0xFF, 0x00, 0x00 */
/* #define RGBLIGHT_COLOR_LAYER_2 0x00, 0x00, 0xFF */
/* #define RGBLIGHT_COLOR_LAYER_3 0x00, 0xFF, 0x00 */
/* #define RGBLIGHT_COLOR_LAYER_4 0xFF, 0xFF, 0x00 */
/* #define RGBLIGHT_COLOR_LAYER_5 0x00, 0xFF, 0xFF */
/* #define RGBLIGHT_COLOR_LAYER_6 0xFF, 0x00, 0xFF */
/* #define RGBLIGHT_COLOR_LAYER_7 0xFF, 0xFF, 0xFF */

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        /* ergodox_right_led_3_on(); */
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        /* ergodox_right_led_2_on(); */
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        /* ergodox_right_led_1_on(); */
        /* ergodox_right_led_2_on(); */
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
