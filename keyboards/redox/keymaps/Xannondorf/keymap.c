#include QMK_KEYBOARD_H
//#include <print.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _WORKMAN   0 //default layer
#define _SYMBOLS   1 //number pad on the right side and related symbols on the left
#define _FUNCTIONS 2 //This is for extra functions that aren't used as often
#define _QWERTY    3 //for games

// Shortcut to make keymap more readable
#define SYMENTER  LT(1, KC_ENT)
#define SYMSPACE  LT(1, KC_SPC)
#define FUNCOMMA  LT(2, KC_COMM)
#define FUNDOT    LT(2, KC_DOT)
#define CUT       LCTL(KC_X)
#define COPY      LCTL(KC_C)
#define PASTE     LCTL(KC_V)
#define SAVE      LCTL(KC_S)
#define UNDO      LCTL(KC_Z)
#define REDO      LCTL(KC_Y)
#define FIND      LCTL(KC_F)
#define SHAREX    LCTL(LSFT(KC_X))



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WORKMAN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,DYN_REC_START1 ,DYN_REC_START2 ,DYN_REC_STOP ,DYN_MACRO_PLAY1 ,DYN_MACRO_PLAY2 ,         KC_F16  ,KC_F17  ,KC_F18  ,KC_F19  ,KC_F20  ,KC_F21  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_D    ,KC_R    ,KC_W    ,KC_B    ,TG(_QWERTY),                       _______ ,KC_J    ,KC_F    ,KC_U    ,KC_P    ,KC_BSPC ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_A    ,KC_S    ,KC_H    ,KC_T    ,KC_G    ,TG(_SYMBOLS),                      KC_F13  ,KC_Y    ,KC_N    ,KC_E    ,KC_O    ,KC_I    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SGUI(KC_S),KC_LSPO, KC_X  ,KC_M    ,KC_C    ,_______ ,FUNCOMMA,KC_BSPC ,        _______ ,FUNDOT  ,_______ ,KC_L    ,KC_K    ,KC_Z    ,KC_RSPC ,KC_SLSH ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LGUI ,KC_LALT ,KC_V    ,     KC_LCTL     ,SYMENTER,KC_SPC  ,        KC_ENT  ,SYMSPACE,    KC_RCTL ,    _______ ,_______  ,LCTL(LGUI(KC_LEFT)) ,LCTL(LGUI(KC_RGHT))  
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            KC_CIRC ,KC_LBRC ,KC_PIPE ,KC_RBRC ,KC_PAST ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_COLN ,KC_PERC ,KC_LCBR ,KC_RCBR ,KC_DLR  ,_______ ,                          _______ ,KC_EQL  ,KC_7    ,KC_8    ,KC_9    ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_SCLN ,KC_LEFT ,KC_UP   ,KC_RGHT ,KC_HASH ,KC_TRNS ,                          KC_F14  ,KC_UNDS ,KC_4    ,KC_5    ,KC_6    ,KC_PPLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LSFT ,KC_QUES ,KC_DOWN ,KC_EXLM ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_1    ,KC_2    ,KC_3    ,KC_PMNS ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,KC_AT   ,KC_GRV  ,KC_AMPR ,     _______ ,    _______ ,_______ ,        KC_ENT  ,KC_SPC  ,    KC_0    ,     KC_PDOT ,KC_PSLS ,KC_BSLS ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_F16  ,KC_F17  ,KC_F18  ,KC_F19  ,KC_F20  ,KC_F21  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_N    ,KC_Q    ,KC_M    ,KC_E    ,KC_R   ,_______ ,                          _______ ,KC_J    ,KC_F    ,KC_U    ,KC_P    ,KC_BSPC ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_LSFT ,KC_A    ,KC_W    ,KC_D    ,KC_F    ,KC_T    ,                          KC_F16  ,KC_Y    ,KC_N    ,KC_E    ,KC_O    ,KC_I    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_I    ,KC_LCTL ,KC_X    ,KC_S    ,KC_V    ,KC_B    ,FUNCOMMA,KC_BSPC ,        _______ ,FUNDOT  ,_______ ,KC_L    ,KC_K    ,KC_Z    ,KC_RSPC ,KC_SLSH ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_P    ,KC_Z    ,KC_LALT ,KC_C    ,     KC_LCTL     ,SYMSPACE,KC_ENT  ,        KC_ENT  ,SYMSPACE,    KC_RCTL ,    _______ ,_______  ,LCTL(LGUI(KC_LEFT)) ,LCTL(LGUI(KC_RGHT))  
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUNCTIONS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     SHAREX  ,_______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HOME ,KC_END  ,KC_MYCM ,FIND    ,KC_MUTE ,KC_F5   ,                          KC_F6   ,KC_PGUP ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,CUT     ,COPY    ,PASTE   ,UNDO    ,KC_MSTP ,_______ ,                          KC_F15  ,KC_PGDN ,KC_LEFT ,KC_UP   ,KC_RGHT ,_______ ,KC_INS  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HOME ,KC_END  ,SAVE    ,REDO    ,KC_MPLY ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,KC_DOWN ,_______ ,_______ ,KC_NLCK ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤,
     RESET   ,EEP_RST ,KC_CALC ,KC_MYCM ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,DEBUG   ,RESET 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
/* 
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
  print("WOOOO\n");
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  return true;
} */