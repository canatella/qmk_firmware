#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"

#define MAIN     0
#define PROG     1
#define RAISED   2
#define LOWERED  3
#define NUM      4
#define NAV      5
#define SUPL     6

#define SUPL_T(KC) LT(SUPL, KC)
#define NAV_T(KC) LT(NAV, KC)
#define LOWER_T(KC) LT(LOWERED, KC)
#define RAISE_T(KC) LT(RAISED, KC)
#define CS_LWKSP HYPR(BP_LESS)
#define CS_RWKSP HYPR(BP_GREATER)

const uint8_t layer_leds[] = {
[MAIN] = 0,
[PROG] = 0,
[RAISED] = 0,
[LOWERED] = 0,
[NUM] = 0,
[NAV] = 0,
[SUPL] = 0,
};

enum custom_keycodes {
MY_0_MACRO = SAFE_RANGE,
MY_1_MACRO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case MY_0_MACRO:
        SEND_STRING(SS_LCTRL("c"));
        return false;
      case MY_1_MACRO:
        SEND_STRING(" - ");
        return false;
    }
  }
  return true;
}

/*
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│         │B        │É   .´   │P   §    │O   œ    │È   .`  _│         │!   ↟    │V   ⇇    │D   ↑    │L   ⇉    │J   ⤒   F│Z        │
│         │       F9│{     F10│      F11│      F12│_        │         │<       +│        7│        8│        9│         │         │
│esc   res│b       —│é       –│p        │o       n│è        │bks      │.^      ~│v        │d       %│l       \│j       `│z     int│
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│Ç        │A   æ   &│U   ù   |│I      .¨│E     bks│;   ’  ^x│         │C   ↡    │T   ←    │S   ↓    │R   →    │N   ⤓    │M        │
│(  shi   │   nav F5│   sup F6│   alt F7│   ctr F8│         │         │        0│   ctr  4│   alt  5│   sup  6│   nav  *│   shi   │
│ç        │a        │u        │i        │e       €│,        │         │c       @│t       +│s       -│r       /│n       *│m     int│
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│   ⎵==⎵=⎵│À   >    │Y   }   °│X   ]    │:   )    │K        │         │?        │Q   (    │G   [    │H   {    │F   <    │W        │
│         │[      F1│       F2│       F3│       F4│         │         │        -│        1│        2│        3│        /│         │
│=        │à        │y        │x        │.        │k        │ent      │'       "│q       #│g       $│h     int│f     int│w     int│
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│         │         │        ↟│      del│         │         │         │         │         │         │         │         │         │
│         │   nav   │         │         │   alt   │   low   │   num   │   rai   │   pro   │        .│        ,│         │         │
│cap      │         │↡        │ins      │         │spa      │         │tab      │         │int      │int      │vol   vol│vol      │
└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAIN] = KEYMAP(
KC_ESC,          BP_B,            BP_E_ACUTE,      BP_P,            BP_O,            BP_E_GRAVE,      KC_BSPC,         BP_DCRC,         BP_V,            BP_D,            BP_L,            BP_J,            BP_Z,           
LSFT_T(BP_CCED), NAV_T(BP_A),     GUI_T(BP_U),     ALT_T(BP_I),     CTL_T(BP_E),     BP_COMMA,                         BP_C,            CTL_T(BP_T),     ALT_T(BP_S),     GUI_T(BP_R),     NAV_T(BP_N),     LSFT_T(BP_M),   
BP_EQUAL,        BP_A_GRAVE,      BP_Y,            BP_X,            BP_DOT,          BP_K,            KC_ENTER,        BP_APOS,         BP_Q,            BP_G,            BP_H,            BP_F,            BP_W,           
KC_CAPS,         TG(NAV),         KC_PGDOWN,       KC_INSERT,       TT(KC_RALT),     LOWER_T(KC_SPACE), TT(NUM),         RAISE_T(KC_TAB), TT(PROG),        KC_INT3,         KC_INT4,         KC_NO,           KC_VOLU
),

[PROG] = KEYMAP(
KC_TRNS,         KC_TRNS,         BP_LCBR,         KC_TRNS,         KC_TRNS,         BP_UNDS,         KC_TRNS,         BP_LESS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
LSFT_T(BP_LPRN), KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                          KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         BP_LBRC,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

[RAISED] = KEYMAP(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_UNDS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         BP_AMPR,         BP_PIPE,         BP_DTRM,         KC_BSPC,         MY_0_MACRO,                       KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
MY_1_MACRO,      KC_TRNS,         BP_DEGR,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_PGUP,         KC_DELETE,       KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

[LOWERED] = KEYMAP(
RESET,           KC_TRNS,         BP_EN_DASH,      KC_TRNS,         BP_N,            KC_TRNS,         KC_TRNS,         BP_TILDE,        KC_TRNS,         BP_PERCENT,      BP_BSLS,         BP_GRAVE,        KC_INT7,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_EURO,         KC_TRNS,                          BP_AT,           BP_PLUS,         BP_MINUS,        BP_SLSH,         BP_ASTR,         KC_INT8,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_DQOT,         BP_HASH,         BP_DOLLAR,       KC_INT5,         KC_INT6,         KC_INT9,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_MUTE,         KC_TRNS
),

[NUM] = KEYMAP(
KC_TRNS,         KC_F9,           KC_F10,          KC_F11,          KC_F12,          KC_TRNS,         KC_TRNS,         BP_PLUS,         BP_7,            BP_8,            BP_9,            KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_F5,           KC_F6,           KC_F7,           KC_F8,           KC_TRNS,                          BP_0,            BP_4,            BP_5,            BP_6,            BP_ASTR,         KC_TRNS,        
KC_TRNS,         KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_TRNS,         KC_TRNS,         BP_MINUS,        BP_1,            BP_2,            BP_3,            BP_SLSH,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_DOT,          BP_COMMA,        KC_TRNS,         KC_TRNS
),

[NAV] = KEYMAP(
KC_TRNS,         KC_TRNS,         BP_DACT,         KC_TRNS,         BP_OE,           BP_DGRV,         KC_TRNS,         KC_PGUP,         CS_LWKSP,        KC_UP,           CS_RWKSP,        KC_HOME,         KC_TRNS,        
KC_TRNS,         BP_AE,           BP_UGRV,         KC_TRNS,         KC_TRNS,         BP_TAPO,                          KC_PGDOWN,       KC_LEFT,         KC_DOWN,         KC_RIGHT,        KC_END,          KC_TRNS,        
KC_TRNS,         BP_GREATER,      BP_RCBR,         BP_RBRC,         BP_RPRN,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_LPRN,         BP_LBRC,         BP_LCBR,         BP_LESS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

[SUPL] = KEYMAP(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                          KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

};
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
