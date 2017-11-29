#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"

// keymaps
#define BEPO 0	// default layer, for bepo compatible systems
#define FNAV 1	// function / navigation / mouse layer
#define NUMK 2	// numeric keypad layer

// macros
#define KP_00 0	// keypad "double 0"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: default layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  |Delete|                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   B  |E_ACUT|   P  |   O  |E_GRAV|Backsp|                                  |CapsLo|   ^  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ,  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|  Tab |                                  | NumLo|------+------+------+------+------+--------|
 * | E_CIRC |A_GRAV|   Y  |   X  |   .  |   K  |      |                                  |      |   '  |   Q  |   G  |   H  |   F  | C_CEDIL|
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper| LCtrl|  LAlt|             | BEPO |QWERTY|      |AZERTY| BEPO |             | AltGr| RCtrl|RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |L_NumK|      |L_NumK|      |      |
 *                                             | Space|LShift|------|      |------|RShift|Enter |
 *                                             |      |      |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[BEPO] = LAYOUT_ergodox(
// Left hand
BP_DOLLAR,	BP_DQOT,	BP_LGIL,	BP_RGIL,	BP_LPRN,	BP_RPRN,	KC_DEL,
BP_PERCENT,	BP_B,		BP_E_ACUTE,	BP_P,		BP_O,		BP_E_GRAVE,	KC_BSPC,
BP_W,		BP_A,		BP_U,		BP_I,		BP_E,		BP_COMMA,
BP_ECRC,	BP_A_GRAVE,	BP_Y,		BP_X,		BP_DOT,		BP_K,		KC_TAB,
KC_ESC,		KC_INS,		KC_LGUI,	KC_LCTL,	KC_LALT,
														DF(BEPO),	DF(QW_B),
																MO(NUMK),
												KC_SPC,		KC_LSHIFT,	MO(FNAV),
// Right hand
				KC_SLCK,	BP_AT,		BP_PLUS,	BP_MINUS,	BP_SLASH,	BP_ASTR,	BP_EQUAL,
				KC_CAPSLOCK,	BP_DCRC,	BP_V,		BP_D,		BP_L,		BP_J,		BP_Z,
						BP_C,		BP_T,		BP_S,		BP_R,		BP_N,		BP_M,
				KC_NUMLOCK,	BP_APOS,	BP_Q,		BP_G,		BP_H,		BP_F,		BP_CCED,
								BP_ALGR,	KC_RCTL,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
DF(AZ_B),	DF(BEPO),
MO(NUMK),
MO(FNAV),	KC_RSHIFT,	KC_ENTER),
/* Keymap 7: function / navigation / mouse layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |VolMut|                                  |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        | Next |LClick|  Up  |RClick| WhUp |VolDwn|                                  |      | PgUp | Home |  Up  |  End |  F11 |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        | Prev | Left | Down | Right|WhDown|------|                                  |------| PgDn | Left | Down | Right|  F12 |        |
 * |--------+------+------+------+------+------| VolUp|                                  |      |------+------+------+------+------+--------|
 * |        | Undo |  Cut | Copy | Paste|      |      |                                  |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[FNAV] = LAYOUT_ergodox(
// Left hand
KC_NO,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_MUTE,
KC_NO,		KC_MS_BTN5,	KC_MS_BTN1,	KC_MS_UP,	KC_MS_BTN2,	KC_MS_WH_UP,	KC_VOLU,
KC_NO,		KC_MS_BTN4,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	KC_MS_WH_DOWN,
KC_NO,		KC_UNDO,	KC_CUT,		KC_COPY,	KC_PASTE,	KC_NO,		KC_VOLD,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_NO,		KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_NO,
				KC_NO,		KC_PGUP,	KC_HOME,	KC_UP,		KC_END,		KC_F11,		KC_NO,
						KC_PGDOWN,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_F12,		KC_NO,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO),
/* Keymap 8: numeric keypad layer, sends keypad codes
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      | NumLo|   /  |   *  |   -  |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   1  |   2  |   3  | Enter|        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |   0  |  00  |   .  | Enter|      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[NUMK] = LAYOUT_ergodox(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_NO,		KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_NO,		KC_NUMLOCK,	KC_KP_SLASH,	KC_KP_ASTERISK,	KC_KP_MINUS,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_KP_PLUS,	KC_NO,
						KC_NO,		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_KP_PLUS,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_KP_ENTER,	KC_NO,
								KC_KP_0,	M(KP_00),	KC_KP_COMMA,	KC_KP_ENTER,	KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    // keypad "double 0"
    case KP_00:
      if (record->event.pressed) {
        return MACRO( T(KP_0), D(KP_0), END );
      } else {
        return MACRO( U(KP_0), END );
      }
      break;
  }
  return MACRO_NONE;
};
