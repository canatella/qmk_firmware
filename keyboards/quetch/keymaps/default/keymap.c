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

#define SUPL_T(KC)  LT(SUPL, KC)
#define NAV_T(KC)   LT(NAV, KC)
#define PROG_T(KC)  LT(PROG, KC)
#define LOWER_T(KC) LT(LOWERED, KC)
#define RAISE_T(KC) LT(RAISED, KC)
#define CS_LWKSP    HYPR(BP_LESS)
#define CS_RWKSP    HYPR(BP_GREATER)

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
  MCRO_0 = SAFE_RANGE,
  MCRO_1,
  MCRO_2,
  MCRO_3,
  MCRO_4,
};

#define SHF_CCED         LSFT_T(BP_CCED)
#define SHF_BP_M         LSFT_T(BP_M)
#define SHF_LPRN         LSFT_T(BP_LPRN)
#define NAV_BP_A         NAV_T(BP_A)
#define NAV_BP_N         NAV_T(BP_N)
#define GUI_BP_U         GUI_T(BP_U)
#define GUI_BP_R         GUI_T(BP_R)
#define ALT_BP_I         ALT_T(BP_I)
#define ALT_BP_S         ALT_T(BP_S)
#define CTL_BP_E         CTL_T(BP_E)
#define CTL_BP_T         CTL_T(BP_T)
#define TT_ALTGR         TT(KC_RALT)
#define LOW_SPC          LOWER_T(KC_SPC)
#define RAI_TAB          RAISE_T(KC_TAB)
#define TG_NAV           TG(NAV)
#define TT_NUM           TT(NUM)
#define TT_PROG          TT(PROG)


/*
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│         │B        │É   .´   │P   §    │O   œ    │È   .`  _│         │!   ↟    │V   ⇇    │D   ↑    │L   ⇉    │J   ⤒   F│Z        │
│         │       F9│{     F10│      F11│      F12│_        │         │<       *│        7│        8│        9│        /│         │
│esc   res│b       —│é       –│p        │o       n│è        │bks      │.^      ~│v        │d       %│l       \│j       `│z     int│
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│Ç   Ça ça│A   æ   &│U   ù   |│I      .¨│E     bks│;   ’  ^x│         │C   ↡    │T   ←    │S   ↓    │R   →    │N   ⤓    │M        │
│(  shi   │   nav F5│   sup F6│   alt F7│   ctr F8│         │         │        +│   ctr  4│   alt  5│   sup  6│   nav  .│   shispa│
│ç        │a        │u        │i        │e       €│,        │         │c       @│t       +│s       -│r       /│n       *│m     int│
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│^  ⎵==⎵=⎵│À   >    │Y   }   °│X   ]    │:   )    │K        │         │?        │Q   (    │G   [    │H   {    │F   <    │W        │
│         │[      F1│       F2│       F3│       F4│         │         │        -│        1│        2│        3│        ,│         │
│=        │à        │y        │x        │.        │k        │ent      │'       "│q       #│g       $│h       «│f       »│w     int│
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│         │         │         │         │         │         │         │         │         │         │         │         │         │
│         │   ⇳na   │         │         │   ⇪pr   │   low   │   ⇪nu   │   rai  0│   ⇪pr   │         │         │         │         │
│cap      │         │ins      │del      │         │spa      │         │tab      │         │int      │int      │vol   vol│vol      │
└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAIN] = KEYMAP(
KC_ESC  , BP_B    , BP_ECUT , BP_P    , BP_O    , BP_EGRV , KC_BSPC , BP_DCRC , BP_V    , BP_D    , BP_L    , BP_J    , BP_Z    ,
SHF_CCED, NAV_BP_A, GUI_BP_U, ALT_BP_I, CTL_BP_E, BP_COMMA,           BP_C    , CTL_BP_T, ALT_BP_S, GUI_BP_R, NAV_BP_N, SHF_BP_M,
BP_EQUAL, BP_AGRV , BP_Y    , BP_X    , BP_DOT  , BP_K    , KC_ENTER, BP_APOS , BP_Q    , BP_G    , BP_H    , BP_F    , BP_W    ,
KC_CAPS , TG_NAV  , KC_INS  , KC_DEL  , TT_PROG , LOW_SPC , TT_NUM  , RAI_TAB , TT_PROG , KC_INT4 , KC_INT3 , KC_VOLD , KC_VOLU 
),

[PROG] = KEYMAP(
_______ , _______ , BP_LCBR , _______ , _______ , BP_UNDS , _______ , BP_LESS , _______ , _______ , _______ , _______ , _______ ,
SHF_LPRN, _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , BP_LBRC , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ 
),

[RAISED] = KEYMAP(
_______ , _______ , _______ , _______ , _______ , BP_UNDS , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
MCRO_0  , BP_AMPR , BP_PIPE , BP_DTRM , KC_BSPC , MCRO_2  ,           _______ , _______ , _______ , _______ , _______ , _______ ,
MCRO_3  , _______ , BP_DEGR , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ 
),

[LOWERED] = KEYMAP(
RESET   , _______ , BP_NDSH , _______ , BP_N    , _______ , _______ , BP_TILDE, _______ , BP_PERC , BP_BSLS , BP_GRAVE, KC_INT7 ,
_______ , _______ , _______ , _______ , BP_EURO , _______ ,           BP_AT   , BP_PLUS , BP_MINUS, BP_SLSH , BP_ASTR , KC_INT8 ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , BP_DQOT , BP_HASH , BP_DLR  , BP_LGIL , BP_RGIL , KC_INT9 ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MUTE , _______ 
),

[NUM] = KEYMAP(
_______ , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , BP_ASTR , BP_7    , BP_8    , BP_9    , BP_SLSH , _______ ,
_______ , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ ,           BP_PLUS , BP_4    , BP_5    , BP_6    , BP_DOT  , KC_SPC  ,
_______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , _______ , BP_MINUS, BP_1    , BP_2    , BP_3    , BP_COMMA, _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , BP_0    , _______ , _______ , _______ , _______ , _______ 
),

[NAV] = KEYMAP(
_______ , _______ , BP_DACT , _______ , BP_OE   , BP_DGRV , _______ , KC_PGUP , CS_LWKSP, KC_UP   , CS_RWKSP, KC_HOME , _______ ,
MCRO_1  , BP_AE   , BP_UGRV , _______ , _______ , BP_TAPO ,           KC_PGDN , KC_LEFT , KC_DOWN , KC_RIGHT, KC_END  , _______ ,
MCRO_4  , BP_GRTR , BP_RCBR , BP_RBRC , BP_RPRN , _______ , _______ , _______ , BP_LPRN , BP_LBRC , BP_LCBR , BP_LESS , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ 
),

[SUPL] = KEYMAP(
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ 
),


};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

//uint32_t layer_state_set_user(uint32_t state) {
//  return update_tri_layer_state(state, LOWERED, NAV, NUM);
//}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case MCRO_0:
        SEND_STRING("\\a");
        return false;
      case MCRO_1:
        SEND_STRING("|a");
        return false;
      case MCRO_2:
        SEND_STRING(SS_LCTRL("c"));
        return false;
      case MCRO_3:
        SEND_STRING(" - ");
        return false;
      case MCRO_4:
        SEND_STRING(" -- ");
        return false;
    }
  }
  return true;
  switch (keycode) {
    case LOW_SPC:
      if (record->event.pressed) {
        layer_on(LOWERED);
      } else {
        layer_off(LOWERED);
      }
      update_tri_layer(LOWERED, NAV, NUM);
      break;
    case NAV_BP_A:
      if (record->event.pressed) {
        layer_on(NAV);
      } else {
        layer_off(NAV);
      }
      update_tri_layer(LOWERED, NAV, NUM);
      break;
  }
  return true;
}

bool keycodes_for_key(uint16_t default_kc, uint8_t layer, uint8_t row, uint8_t col) {
  if (layer == PROG && default_kc == BP_LESS)
    return CMV(default_kc, BP_EXCLAIM, 0, 0);

  if (default_kc == BP_EQUAL)
    return CMV(default_kc, BP_CIRCUMFLEX, 0, 0);

  return true;
}
