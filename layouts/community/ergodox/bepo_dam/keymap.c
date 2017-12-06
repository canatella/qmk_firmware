#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"

// keymaps
#define BEPO 0	// default layer, for bepo compatible systems
#define LOWERED 1
#define RAISED 2
#define ALTGRED 3
#define EMACS 4
#define FNAV 5	// function / navigation / mouse layer
#define NUMK 6	// numeric keypad layer

// macros
enum custom_keycodes {
  KP_00 = SAFE_RANGE,	// keypad "double 0"
  EM_PRFX,
  EM_MKBUF,
  EM_1WIN,
  EM_2HWIN,
  EM_2VWIN,
  EM_TWIN,
  EM_SWBUF,
  EM_ARG,
  EM_UNDO,
  EM_MARK,
  EM_DEL,
  EM_KWRD,
  EM_KILL,
  EM_COPY,
  EM_KSEXP,
  EM_MKWRD,
  EM_MKSXP,
  EM_YANK,
  EM_RYANK,
  EM_REPL,
  EM_QUIT,
  EM_FFILE,
  EM_BSXP,
  EM_USXP,
  EM_DSXP,
  EM_FSXP,
  EM_KBUF,
  EM_SFILE,
  EM_BACK,
  EM_PREV,
  EM_NEXT,
  EM_FORW,
  EM_HELP,
  EM_WFILE,
  EM_BLINE,
  EM_BWRD,
  EM_FWRD,
  EM_ELINE,
  EM_MDEF
};

// Modifier Keys
#define WS_LEFT LALT(LCTL(KC_LEFT))
#define WS_RIGHT LALT(LCTL(KC_RIGHT))
#define SL_EMACS MO(EMACS)
#define SL_FNAV  TT(FNAV)
#define SL_NUMK  TT(NUMK)
#define RAISE(KC) LT(RAISED, KC)
#define LOWER(KC) LT(LOWERED, KC)

#define EMACS_C_X LCTL(BP_X)

const uint8_t layer_leds[] = {
  [BEPO] = 0,
  [RAISED] = 0,
  [LOWERED] = 0,
  [FNAV] = 2,
  [NUMK] = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BEPO] = LAYOUT_ergodox(
// Left hand
KC_ESCAPE,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
KC_TAB,		BP_B,		BP_E_ACUTE,	BP_P,		BP_O,		BP_E_GRAVE,	KC_BSPC,
KC_LSHIFT,	BP_A,		BP_U,		BP_I,		BP_E,		BP_COMMA,
KC_LGUI,	BP_A_GRAVE,	BP_Y,		BP_X,		BP_DOT,		BP_K,		KC_ENTER,
KC_INSERT,	KC_DELETE,	KC_HOME,	KC_END,		SL_EMACS,
														KC_VOLD,	KC_VOLU,
																KC_MUTE,
												LOWER(KC_SPACE),KC_LCTRL,	KC_LALT,
// Right hand
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,	 	KC_NO,		KC_NO,
				SL_FNAV,	BP_DCRC,	BP_V,		BP_D,		BP_L,		BP_J,		BP_Z,
						BP_C,		BP_T,		BP_S,		BP_R,		BP_N,		SFT_T(BP_M),
				SL_NUMK,	BP_APOS,	BP_Q,		BP_G,		BP_H,		BP_F,		GUI_T(BP_W),
				SL_EMACS,	MO(ALTGRED),	KC_NO,		KC_PGUP,	KC_PGDOWN,
KC_INT3,	KC_INT4,
KC_NO,
KC_LALT,	KC_RCTRL,	RAISE(KC_ENTER)),

[RAISED] = LAYOUT_ergodox(
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_TRNS,
KC_F12,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_TRNS,
BP_HASH,        BP_1,		BP_2,		BP_3,		BP_4,		BP_5,
KC_TRNS,	KC_TAB,		BP_LCBR,	BP_RCBR,	BP_BSLS,	LCTL(BP_X),	KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS, 	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
				KC_TRNS,	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,
						BP_6,		BP_7,		BP_8,		BP_9,		BP_0,		BP_DEGR,
				KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS),

[LOWERED] = LAYOUT_ergodox(
KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
KC_TRNS, 	BP_EN_DASH,	BP_UNDS,	BP_PIPE,	BP_LBRC, 	BP_RBRC,	KC_TRNS,
BP_DOLLAR,      BP_DQOT,	BP_LESS,	BP_GREATER,	BP_LPRN,	BP_RPRN,
KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS, 	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,

				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
				KC_TRNS,	BP_LCBR,	BP_RCBR,	BP_EQUAL,	BP_BSLS,	BP_GRAVE,	BP_PERCENT,
						BP_AT,		BP_PLUS,	BP_MINUS,	BP_SLSH,	BP_ASTR,	BP_EQUAL,
				KC_TRNS,	LALT(BP_X),	WS_LEFT,	KC_UP,		WS_RIGHT,	BP_PERC,	KC_TRNS,
								KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_TRNS,	KC_TRNS,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS),

[ALTGRED] = LAYOUT_ergodox(
KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
KC_TRNS, 	BP_PIPE,	BP_DACT,	BP_AMPR,	BP_OE,	 	BP_DGRV,	KC_TRNS,
KC_TRNS,      	BP_AE,		BP_UGRV,	BP_DTRM,	BP_EURO,	BP_TAPO,
KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	BP_ELPS,	BP_TILDE,	KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS, 	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,

				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
				KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
						KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
				KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS),

[EMACS] = LAYOUT_ergodox(
KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
EM_MKBUF, 	EM_1WIN,	EM_2HWIN,	EM_2VWIN,	EM_TWIN, 	EM_SWBUF,	EM_ARG,
EM_UNDO,	EM_MARK,	EM_DEL,		EM_KWRD,	EM_KILL,	EM_COPY,
EM_KSEXP,	EM_MKWRD,	EM_MKSXP,	EM_YANK,	EM_RYANK,	EM_REPL,	EM_QUIT,
KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS, 	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,

				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_NO,
				EM_ARG,		EM_FFILE,	EM_BSXP,	EM_USXP,	EM_DSXP,	EM_FSXP,	EM_KBUF,
						EM_SFILE,	EM_BACK,	EM_PREV,	EM_NEXT,	EM_FORW,	EM_HELP,
				EM_QUIT,	EM_WFILE,	EM_BLINE,	EM_BWRD,	EM_FWRD,	EM_ELINE,	EM_MDEF,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS),
/* Keymap 7: function / navigation / mouse layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |VolMut|                                  |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        | Next |LClick|  Up  |RClick| WhUp |VolDwn|                                  |      | PgUp | Home |  Up  |  End |  F11 |  F12   |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        | Prev | Left | Down | Right|WhDown|------|                                  |------| PgDn | Left | Down | Right|  F12 |        |
 * |--------+------+------+------+------+------| VolUp|                 =                |      |------+------+------+------+------+--------|
 * |        | Undo |  Cut | Copy | Paste|      |      |                                  |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |WSLeft|WSRigh|     |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[FNAV] = LAYOUT_ergodox(
// Left hand
KC_NO,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_TRNS,
KC_NO,		KC_MS_BTN5,	KC_MS_BTN1,	KC_MS_UP,	KC_MS_BTN2,	KC_MS_WH_UP,	KC_TRNS,
KC_NO,		KC_MS_BTN4,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	KC_MS_WH_DOWN,
KC_NO,		KC_UNDO,	KC_CUT,		KC_COPY,	KC_PASTE,	KC_NO,		KC_TRNS,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_TRNS,	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_NO,
				KC_TRNS,	KC_PGUP,	KC_HOME,	KC_UP,		KC_END,		KC_F11,		KC_NO,
						KC_PGDOWN,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_F12,		KC_NO,
				KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
								WS_LEFT,	WS_RIGHT,	KC_TRNS,	KC_NO,		KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_TRNS),
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
				KC_TRNS,	KC_NO,		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_KP_PLUS,	KC_NO,
						KC_NO,		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_KP_PLUS,	KC_NO,
				KC_TRNS,       	KC_NO,		KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_KP_ENTER,	KC_NO,
								KC_KP_0,	KP_00,		KC_KP_COMMA,	KC_KP_ENTER,	KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO)
};

bool process_kp_00(keyrecord_t *record) {
  if (record->event.pressed) {
    SEND_STRING(SS_TAP(X_KP_0)SS_TAP(X_KP_0));
    return false;
  }
  return true;
}


#define send_string(STR) return send_str(record, PSTR(STR))
#define EM_C_X SS_LCTRL(SS_TAP(X_C))
#define send_c(STR) send_string(SS_LCTRL(STR))
#define send_m(STR) send_string(SS_LALT(STR))
#define send_cm(STR) send_string(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)STR SS_UP(X_LALT)SS_UP(X_LCTRL))
#define send_cx(STR) send_string(EM_C_X STR)
#define send_cxc(STR) send_cx(SS_LCTRL(STR))
#define send_cxs(STR) send_cx(SS_LSFT(SS_TAP(STR)))

bool send_str(keyrecord_t *record, const char *keys) {
  if (!record->event.pressed)
    return true;

  send_string_P(keys);
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KP_00:
      return process_kp_00(record);
    case EM_PRFX:
      SEND_STRING(SS_LCTRL(SS_TAP(X_C)));
      return false;
    case EM_MKBUF:
      send_cx(".");
    case EM_1WIN:
      send_cxs(X_1);
    case EM_2HWIN:
      send_cxs(X_2);
    case EM_2VWIN:
      send_cxs(X_3);
    case EM_TWIN:
      send_cx("r");
    case EM_SWBUF:
      send_cx("q");
    case EM_ARG:
      send_c("s");
    case EM_UNDO:
      send_c("9");
    case EM_MARK:
      send_cx(" ");
    case EM_DEL:
      send_string(SS_TAP(X_DELETE));
    case EM_KWRD:
      send_m("i");
    case EM_KILL:
      send_c("]");
    case EM_COPY:
      send_m("]");
    case EM_KSEXP:
      send_cm("b");
    case EM_MKWRD:
      send_m("6");
    case EM_MKSXP:
      send_cm("6");
    case EM_YANK:
      send_c("x");
    case EM_RYANK:
      send_m("x");
    case EM_REPL:
      send_m("=");
    case EM_QUIT:
      send_c(",");
    case EM_FFILE:
      send_cxc("/");
    case EM_BSXP:
      send_cm("q");
    case EM_USXP:
      send_cm("i");
    case EM_DSXP:
      send_cm("o");
    case EM_FSXP:
      send_cm("/");
    case EM_KBUF:
      send_cx("b");
    case EM_SFILE:
      send_cxc("k");
    case EM_BACK:
      send_c("q");
    case EM_PREV:
      send_c("e");
    case EM_NEXT:
      send_c(";");
    case EM_FORW:
      send_c("/");
    case EM_HELP:
      send_c(".");
    case EM_WFILE:
      send_cxc("]");
    case EM_BLINE:
      send_c("a");
    case EM_BWRD:
      send_m("q");
    case EM_FWRD:
      send_m("/");
    case EM_ELINE:
      send_c("f");
    case EM_MDEF:
      send_cm(".");
  }
  return true;
}


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_board_led_on();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};


// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  if (layer > 0)
    ergodox_right_led_on(layer_leds[layer]);

  return state;
};
