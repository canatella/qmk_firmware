#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"

#define MAIN     0
#define RAISED   1
#define LOWERED  2
#define NAV      3
#define SUPL     4

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
[NAV] = 0,
[SUPL] = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAIN] = LAYOUT_ergodox(
KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,          
KC_ESC,          BP_B,            BP_E_ACUTE,      BP_P,            BP_O,            BP_E_GRAVE,      KC_BSPC,        
LSFT_T(BP_CCED), NAV_T(BP_A),     GUI_T(BP_U),     ALT_T(BP_I),     CTL_T(BP_E),     BP_COMMA,                        
BP_DQOT,         BP_A_GRAVE,      BP_Y,            BP_X,            BP_DOT,          BP_K,            KC_ENTER,       
KC_NO,           KC_HOME,         KC_END,          KC_INSERT,       KC_DELETE,                                        
                                                                                                                       KC_VOLD,         KC_VOLU,        
                                                                                                                                        KC_NO,          
                                                                                                      LOWER_T(KC_SPACE), KC_NO,           KC_NO,          

                                  KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,          
                                  KC_BSPC,         BP_DCRC,         BP_V,            BP_D,            BP_L,            BP_J,            BP_Z,           
                                                   BP_C,            CTL_T(BP_T),     ALT_T(BP_S),     GUI_T(BP_R),     SUPL_T(BP_N),    LSFT_T(BP_M),   
                                  KC_ENTER,        BP_APOS,         BP_Q,            BP_G,            BP_H,            BP_F,            BP_W,           
                                                                    KC_INT3,         KC_INT4,         KC_NO,           KC_NO,           KC_NO,          
KC_INT3,         KC_INT4,        
KC_NO,                           
KC_NO,           KC_NO,           RAISE_T(KC_TAB)
),

[RAISED] = LAYOUT_ergodox(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_F12,          KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,           KC_TRNS,        
KC_TRNS,         BP_1,            BP_2,            BP_3,            BP_4,            BP_5,                            
KC_TRNS,         KC_TRNS,         BP_DEGR,         BP_LCBR,         BP_RCBR,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                                          
                                                                                                                       KC_TRNS,         KC_TRNS,        
                                                                                                                                        KC_TRNS,        
                                                                                                      KC_TRNS,         KC_TRNS,         KC_TRNS,        

                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                  KC_TRNS,         KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          KC_F11,         
                                                   BP_6,            BP_7,            BP_8,            BP_9,            BP_0,            KC_TRNS,        
                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                                                    KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,        
KC_TRNS,                         
KC_TRNS,         KC_TRNS,         KC_TRNS
),

[LOWERED] = LAYOUT_ergodox(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         BP_EN_DASH,      BP_UNDS,         BP_LBRC,         BP_RBRC,         BP_PIPE,         KC_TRNS,        
KC_TRNS,         BP_LESS,         BP_GREATER,      BP_LPRN,         BP_RPRN,         KC_TRNS,                         
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                                          
                                                                                                                       KC_TRNS,         KC_TRNS,        
                                                                                                                                        KC_TRNS,        
                                                                                                      KC_TRNS,         KC_TRNS,         KC_TRNS,        

                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                  KC_TRNS,         BP_EQUAL,        BP_TILDE,        BP_PERCENT,      BP_BSLS,         BP_GRAVE,        KC_TRNS,        
                                                   BP_AT,           BP_PLUS,         BP_MINUS,        BP_SLSH,         BP_ASTR,         KC_TRNS,        
                                  KC_TRNS,         KC_TRNS,         BP_HASH,         BP_DOLLAR,       BP_AMPR,         KC_TRNS,         KC_TRNS,        
                                                                    KC_VOLD,         KC_VOLU,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,        
KC_TRNS,                         
KC_TRNS,         KC_TRNS,         KC_TRNS
),

[NAV] = LAYOUT_ergodox(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                         
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                                          
                                                                                                                       KC_TRNS,         KC_TRNS,        
                                                                                                                                        KC_TRNS,        
                                                                                                      KC_TRNS,         KC_TRNS,         KC_TRNS,        

                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                  KC_TRNS,         KC_PGUP,         CS_LWKSP,        KC_UP,           CS_RWKSP,        KC_TRNS,         KC_TRNS,        
                                                   KC_PGDOWN,       KC_LEFT,         KC_DOWN,         KC_RIGHT,        KC_TRNS,         KC_TRNS,        
                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                                                    KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,        
KC_TRNS,                         
KC_TRNS,         KC_TRNS,         KC_TRNS
),

[SUPL] = LAYOUT_ergodox(
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         BP_DACT,         KC_TRNS,         BP_OE,           BP_DGRV,         KC_TRNS,        
KC_TRNS,         BP_AE,           BP_UGRV,         BP_DTRM,         BP_EURO,         BP_TAPO,                         
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         BP_ELPS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,                                          
                                                                                                                       KC_TRNS,         KC_TRNS,        
                                                                                                                                        KC_TRNS,        
                                                                                                      KC_TRNS,         KC_TRNS,         KC_TRNS,        

                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                                   KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                  KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
                                                                    KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        
KC_TRNS,         KC_TRNS,        
KC_TRNS,                         
KC_TRNS,         KC_TRNS,         KC_TRNS
),

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
}
