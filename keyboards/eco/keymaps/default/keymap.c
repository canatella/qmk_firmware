#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"

#define MAIN     0
#define RAISED   1
#define LOWERED  2
#define NUM      3
#define NAV      4
#define SUPL     5

#define SUPL_T(KC) LT(SUPL, KC)
#define NAV_T(KC) LT(NAV, KC)
#define LOWER_T(KC) LT(LOWERED, KC)
#define RAISE_T(KC) LT(RAISED, KC)
#define CS_LWKSP HYPR(BP_LESS)
#define CS_RWKSP HYPR(BP_GREATER)

const uint8_t layer_leds[] = {
[MAIN] = 0,
[RAISED] = 0,
[LOWERED] = 0,
[NUM] = 0,
[NAV] = 0,
[SUPL] = 0,
};

/* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│      F12│B      F1│É      F2│P      F3│O      F4│È      F5│    ]   <│    ]   <│!   ↟  F6│V   ⇇  F7│D   ↑  F8│L   ⇉  F9│J   ⤒ F10│Z     F11│
│         │         │         │         │         │         │         │         │        +│        7│        8│        9│         │         │
│esc      │b       –│é   .´  _│p       [│o   œ   ]│è   .`   │bks [   >│bks [   >│.^      =│v       ~│d       %│l       \│j       `│z        │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│Ç        │A       1│U       2│I       3│E       4│;       5│    )   {│    )   {│C   ↡   6│T   ←   7│S   ↓   8│R   →   9│N   ⤓   0│M        │
│   shi   │   nav   │   sup   │   alt   │   ctr   │         │         │         │        =│   ctr  4│   alt  5│   sup  6│   alt  *│   shi   │
│ç        │a   æ   <│u   ù   >│i   .¨  (│e   €   )│,   ’    │ent (   }│ent (   }│c       @│t       +│s       -│r       /│n       *│m        │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│         │À        │Y       °│X       {│:       }│K        │    )   {│    )   {│?        │Q        │G        │H        │F        │W        │
│         │         │         │         │         │         │         │         │        -│        1│        2│        3│        /│         │
│"        │à        │y        │x        │.   …    │k        │ent (   }│ent (   }│'       "│q       #│g       $│h       &│f       |│w        │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│         │         │         │         │         │         │         │         │         │         │         │         │         │         │
│         │         │         │         │         │   low   │   num   │   num   │   rai   │        0│        .│        ,│         │         │
│         │         │         │ins      │del      │spa      │         │         │tab      │int      │int      │vol      │vol      │         │
└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAIN] = KEYMAP(
KC_ESC,          BP_B,            BP_E_ACUTE,      BP_P,            BP_O,            BP_E_GRAVE,      KC_BSPC,         KC_BSPC,         BP_DCRC,         BP_V,            BP_D,            BP_L,            BP_J,            BP_Z,           
LSFT_T(BP_CCED), NAV_T(BP_A),     GUI_T(BP_U),     ALT_T(BP_I),     CTL_T(BP_E),     BP_COMMA,        KC_ENTER,        KC_ENTER,        BP_C,            CTL_T(BP_T),     ALT_T(BP_S),     GUI_T(BP_R),     SUPL_T(BP_N),    LSFT_T(BP_M),   
BP_DQOT,         BP_A_GRAVE,      BP_Y,            BP_X,            BP_DOT,          BP_K,            KC_ENTER,        KC_ENTER,        BP_APOS,         BP_Q,            BP_G,            BP_H,            BP_F,            BP_W,           
KC_NO,           KC_NO,           KC_NO,           KC_INSERT,       KC_DELETE,       LOWER_T(KC_SPACE), TT(NUM),         TT(NUM),         RAISE_T(KC_TAB), KC_INT4,         KC_INT3,         KC_VOLD,         KC_VOLU,         KC_NO
),

[RAISED] = KEYMAP(
KC_F12,          KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,           BP_LESS,         BP_LESS,         KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          KC_F11,         
KC_TRNS,         BP_1,            BP_2,            BP_3,            BP_4,            BP_5,            BP_LCBR,         BP_LCBR,         BP_6,            BP_7,            BP_8,            BP_9,            BP_0,            KC_TRNS,        
KC_TRNS,         KC_TRNS,         BP_DEGR,         BP_LCBR,         BP_RCBR,         KC_TRNS,         BP_LCBR,         BP_LCBR,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

[LOWERED] = KEYMAP(
KC_TRNS,         BP_EN_DASH,      BP_UNDS,         BP_LBRC,         BP_RBRC,         KC_TRNS,         BP_GREATER,      BP_GREATER,      BP_EQUAL,        BP_TILDE,        BP_PERCENT,      BP_BSLS,         BP_GRAVE,        KC_TRNS,        
KC_TRNS,         BP_LESS,         BP_GREATER,      BP_LPRN,         BP_RPRN,         KC_TRNS,         BP_RCBR,         BP_RCBR,         BP_AT,           BP_PLUS,         BP_MINUS,        BP_SLSH,         BP_ASTR,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_RCBR,         BP_RCBR,         BP_DQOT,         BP_HASH,         BP_DOLLAR,       BP_AMPR,         BP_PIPE,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

[NUM] = KEYMAP(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_PLUS,         BP_7,            BP_8,            BP_9,            KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_EQUAL,        BP_4,            BP_5,            BP_6,            BP_ASTR,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_MINUS,        BP_1,            BP_2,            BP_3,            BP_SLSH,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_0,            BP_DOT,          BP_COMMA,        KC_TRNS,         KC_TRNS
),

[NAV] = KEYMAP(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_RBRC,         BP_RBRC,         KC_PGUP,         CS_LWKSP,        KC_UP,           CS_RWKSP,        KC_HOME,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_RPRN,         BP_RPRN,         KC_PGDOWN,       KC_LEFT,         KC_DOWN,         KC_RIGHT,        KC_END,          KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_RPRN,         BP_RPRN,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

[SUPL] = KEYMAP(
KC_TRNS,         KC_TRNS,         BP_DACT,         KC_TRNS,         BP_OE,           BP_DGRV,         BP_LBRC,         BP_LBRC,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         BP_AE,           BP_UGRV,         BP_DTRM,         BP_EURO,         BP_TAPO,         BP_LPRN,         BP_LPRN,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_ELPS,         KC_TRNS,         BP_LPRN,         BP_LPRN,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
),

};
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
