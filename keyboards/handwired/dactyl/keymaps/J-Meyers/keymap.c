#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0  // default layer
#define NUM 1   // Number
#define MDIA 2  // media and mouse keys
#define FPS 3   // FPS keybinds
#define MOBA 4  // MOBA keybinds
#define INV 5   // Inventor keybinds
#define FNC 6   // Function keys

 // For TT defines how many taps to toggle - tapping toggle, defined in config.h

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Caps |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |PrtSc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |  '"  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   \  |   A  |   O  |   E  |   U  |   I  |                    |   D  |   H  |   T  |   N  |   S  |   /  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|;/Ctrl|   Q  |   J  |   K  |   X  |                    |   B  |   M  |   W  |   V  |Z/Ctrl|RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |   ~  |  Alt |CtShft| Left | Right|                                  |  Up  | Down |   [  |   ]  |   =  |
 * `----------------------------------'                                  `----------------------------------'
    *                                      ,-------------.  ,-------------.
    *                                      |  L1  | LGui |  |  Esc | H(L2)|
    *                               ,------|------|------|  |------+------+------.
    *                               |      |      |  L3  |  |  L5  |      |      |
    *                               | Space|Backsp|------|  |------|  Tab |Enter |
    *                               |      |ace   |  L4  |  |MO(L6)|      |      |
    *                               `--------------------'  `--------------------'
 */
[BASE] = LAYOUT_dactyl(  // layer 0 : default
        // left hand
         KC_CAPS,             KC_1,           KC_2,     KC_3,     KC_4,  KC_5,
          KC_DEL,          KC_QUOT,        KC_COMM,   KC_DOT,     KC_P,  KC_Y,
         KC_BSLS,            KC_A,           KC_O,     KC_E,     KC_U,  KC_I,
          KC_LSFT,  CTL_T(KC_SCLN),           KC_Q,     KC_J,     KC_K,  KC_X,
          KC_GRV,         KC_LALT,  LCTL(KC_LSFT),  KC_LEFT,  KC_RGHT,
                                                                           TG(NUM),   KC_LGUI,
                                                                                     TG(FPS),
                                                             KC_SPC,        KC_BSPC, TG(MOBA),
        // right hand
                             KC_6,   KC_7,     KC_8,     KC_9,            KC_0,         KC_PSCR,
                             KC_F,   KC_G,     KC_C,     KC_R,            KC_L,         KC_MINS,
                             KC_D,   KC_H,     KC_T,     KC_N,            KC_S,         KC_SLSH,
                             KC_B,   KC_M,     KC_W,     KC_V,     CTL_T(KC_Z),         KC_RSFT,
                                    KC_UP,  KC_DOWN,  KC_LBRC,         KC_RBRC,          KC_EQL,
           KC_ESC,  TT(MDIA),
          TG(INV),
          TT(FNC),    KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol and Layer Swap 
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Versn |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |PrtSc | ScrLk| Pause|   {  |   }  | Calc |                    |  Up  |   7  |   8  |   9  |   *  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Inst | Home | PgUp |   (  |   )  |      |                    | Down |   4  |   5  |   6  |   +  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  | End  | PgDn |   [  |   ]  |      |                    |      |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |RESET |      |      | Left | Right|                                  |      |   .  |   0  |   =  |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |   L1 | LGui |  |  Esc |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |Space |Backsp|------|  |------|  Tab | Enter|
 *                               |      | ace  |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
// Layer 1: Number pad
[NUM] = LAYOUT_dactyl(
       // left hand
          VRSN,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
       KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_LCBR,  KC_RCBR,  KC_CALC,
        KC_INS,  KC_HOME,  KC_PGUP,  KC_LPRN,  KC_RPRN,    KC_NO,
        KC_DEL,   KC_END,  KC_PGDN,  KC_LBRC,  KC_RBRC,    KC_NO,
         RESET,    KC_NO,    KC_NO,  KC_LEFT,  KC_RGHT,
                                                         TG(NUM),  KC_LGUI,
                                                                     KC_NO,
                                               KC_SPC,   KC_BSPC,    KC_NO,
       // right hand
                   KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,
                   KC_UP,     KC_7,     KC_8,     KC_9,  KC_ASTR,   KC_F12,
                 KC_DOWN,     KC_4,     KC_5,     KC_6,  KC_PLUS,  KC_MINS,
                   KC_NO,     KC_1,     KC_2,     KC_3,  KC_BSLS,    KC_NO,
                             KC_NO,   KC_DOT,     KC_0,   KC_EQL,    KC_NO,
       KC_ESC,    KC_NO,
        KC_NO,
        KC_NO,    KC_NO,    KC_NO
),

/* Layer 2: Media and mouse keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | MsUp |      |      |                    |      |      |   C  |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      |                    | BBack| BFWD | BSear|      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| Ctrl |      |      |      |   X  |                    | Play | Prev | Next |   V  |   Z  |RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  | VolUp| VolDn| Mute |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |  Esc |  L2  |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |Scroll|Scroll|
 *                               | Lclk | Rclk |------|  |------|  Up  |Down  |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 *
 */
// Layer 2: Media
[MDIA] = LAYOUT_dactyl(
         KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
         KC_NO,    KC_NO,    KC_NO,  KC_MS_U,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,  KC_MS_L,  KC_MS_D,  KC_MS_R,    KC_NO,
       KC_LSFT, KC_LCTRL,    KC_NO,    KC_NO,    KC_NO,     KC_X,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                                           KC_NO,    KC_NO,
                                                                     KC_NO,
                                               KC_BTN1,  KC_BTN2,    KC_NO,
    // right hand
                  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                  KC_NO,    KC_NO,     KC_C,    KC_NO,    KC_NO,    KC_NO,
                KC_WBAK,  KC_WFWD,  KC_WSCH,    KC_NO,    KC_NO,    KC_NO,
                KC_MPLY,  KC_MPRV,  KC_MNXT,     KC_V,     KC_Z,  KC_RSFT,
                          KC_VOLU,  KC_VOLD,  KC_MUTE,    KC_NO,    KC_NO,
       KC_ESC, TG(MDIA),
        KC_NO,
        KC_NO,  KC_WH_U,  KC_WH_D
),
/* Keymap 3: FPS (Left Hand only)
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   0  |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   Q  |   W  |   E  |   T  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   A  |   S  |   D  |   F  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  Ctrl|   Z  |   X  |   C  |  Esc |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |  Alt |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |   6  |   7  |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |   8  |  |      |      |      |
 *                               | Space|  Tab |------|  |------|      |      |
 *                               |      |      |   9  |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[FPS] = LAYOUT_dactyl(  // layer 3: FPS
       // left hand
          KC_0,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
         KC_NO,    KC_NO,     KC_Q,     KC_W,     KC_E,     KC_T,
       TG(FPS),    KC_NO,     KC_A,     KC_S,     KC_D,     KC_F,
       KC_LSFT, KC_LCTRL,     KC_Z,     KC_X,     KC_C,   KC_ESC,
         KC_NO,  KC_LALT,    KC_NO,    KC_NO,    KC_NO,
                                                                      KC_6,     KC_7,
                                                                                KC_8,
                                                          KC_SPC,  KC_BSPC,     KC_9,
        // right hand
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,
         KC_NO,
         KC_NO,    KC_NO,    KC_NO
    ),
/* Keymap 4: MOBA keys (Left Hand Only)
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |  4   |  5   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |  R   |  G   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `/~ |   6  |   7  |   D  |  F   |  V   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |  Ctl | Alt  |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |  Esc | Ctl  |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Tab  |  |      |      |      |
 *                               | Space|   B  |------|  |------|      |      |
 *                               |      |      |  L4  |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[MOBA] = LAYOUT_dactyl(  // layer 4: MOBA
       // left hand
         KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
         KC_NO,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_G,
        KC_GRV,     CTL_T(KC_6),     KC_7,     KC_D,     KC_F,     KC_V,
       KC_RCTL,  KC_RALT,    KC_NO,    KC_NO,    KC_NO,
                                                                    KC_ESC,  KC_RCTL,
                                                                              KC_TAB,
                                                          KC_SPC,     KC_B, TG(MOBA),
        // right hand
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,
         KC_NO,
         KC_NO,    KC_NO,    KC_NO
    ),
/* Keymap 5: Inventor TODO: this is not done
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |  4   |   5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |  R   |  G   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   6  |   7  |   D  |  F   |  V   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |  Esc |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               | Space|   B  |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[INV] = LAYOUT_dactyl(  // layer 5: Inventor
       // left hand
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                                                     KC_NO,    KC_NO,
                                                                               KC_NO,
                                                           KC_NO,    KC_NO,    KC_NO,
        // right hand
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,
       TG(INV),
         KC_NO,    KC_NO,    KC_NO
    ),
/* Keymap 6: FNC Function Keys
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[FNC] = LAYOUT_dactyl(  // layer 6: FNC
       // left hand
       KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                   KC_TRNS,  KC_TRNS,
                                                                             KC_TRNS,
                                                         KC_TRNS,  KC_TRNS,  KC_TRNS,
        // right hand
                             KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_F12,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       TG(FNC),  KC_TRNS,  KC_TRNS
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};
