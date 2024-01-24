#include QMK_KEYBOARD_H

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase                                   //Working
    L_BRD,              //LED Brightness Decrease                                   //Working
    L_EDG_I,            //LED Edge Brightness Increase                              //Working
    L_EDG_D,            //LED Edge Brightness Decrease                              //Working
    L_EDG_M,            //LED Edge lighting mode
    L_PTN,              //LED Pattern Select Next                                   //Working
    L_PTP,              //LED Pattern Select Previous                               //Working
    L_PSI,              //LED Pattern Speed Increase                                //Working
    L_PSD,              //LED Pattern Speed Decrease                                //Working
    L_RATIOD,
    L_RATIOI,
    L_T_MD,             //LED Toggle Mode                                           //Working
    L_T_ONF,            //LED Toggle On / Off                                       //Working
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect                                  //Working
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction                    //Working
    U_T_AGCR,           //USB Toggle Automatic GCR control                          //Working
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    DBG_FAC,            //DEBUG Factory light testing (All on white)
    MD_BOOT             //Restart into bootloader after hold timeout                //Working
};

#define QWERTY 0
#define DVORAK 1
#define ARROWS_NUMPAD 2
#define SPECIALS 3
#define BOARD_OPTS 4
#define LAYER_SWITCH 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────────────────┬──────┬──────┬───┬───┬───┬───┬───┬───┬───┬──────┬────────────────┬──────┬──────┬──────┐
//    │           `            │  1   │  2   │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │  0   │       -        │  =   │ bspc │ del  │
//    ├────────────────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼────────────────┼──────┼──────┼──────┤
//    │ LT(ARROWS_NUMPAD, tab) │  q   │  w   │ e │ r │ t │ y │ u │ i │ o │  p   │       [        │  ]   │  \   │ mply │
//    ├────────────────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼────────────────┴──────┼──────┼──────┤
//    │   LT(SPECIALS, esc)    │  a   │  s   │ d │ f │ g │ h │ j │ k │ l │  ;   │           '           │ ent  │ mnxt │
//    ├────────────────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼───────────────────────┼──────┼──────┤
//    │          lsft          │  z   │  x   │ c │ v │ b │ n │ m │ , │ . │  /   │         rsft          │  up  │ mprv │
//    ├────────────────────────┼──────┼──────┼───┴───┴───┴───┴───┴───┴───┼──────┼────────────────┬──────┼──────┼──────┤
//    │          lctl          │ lalt │ lgui │            spc            │ rgui │ MO(BOARD_OPTS) │ left │ down │ rght │
//    └────────────────────────┴──────┴──────┴───────────────────────────┴──────┴────────────────┴──────┴──────┴──────┘
[QWERTY] = LAYOUT_65_ansi_blocker(
  KC_GRV                    , KC_1    , KC_2    , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8    , KC_9   , KC_0    , KC_MINS        , KC_EQL  , KC_BSPC , KC_DEL             ,
  LT(ARROWS_NUMPAD, KC_TAB) , KC_Q    , KC_W    , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I    , KC_O   , KC_P    , KC_LBRC        , KC_RBRC , KC_BSLS , KC_MEDIA_PLAY_PAUSE,
  LT(SPECIALS, KC_ESC)      , KC_A    , KC_S    , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K    , KC_L   , KC_SCLN ,         KC_QUOT          , KC_ENT  , KC_MEDIA_NEXT_TRACK,
  KC_LSFT                   , KC_Z    , KC_X    , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH ,         KC_RSFT          , KC_UP   , KC_MEDIA_PREV_TRACK,
  KC_LCTL                   , KC_LALT , KC_LGUI ,                       KC_SPC                        , KC_RGUI , MO(BOARD_OPTS) , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌────────────────────────┬──────┬──────┬───┬───┬───┬───┬───┬───┬───┬──────┬────────────────┬──────┬──────┬──────┐
//    │           `            │  1   │  2   │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │  0   │       [        │  ]   │ bspc │ del  │
//    ├────────────────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼────────────────┼──────┼──────┼──────┤
//    │ LT(ARROWS_NUMPAD, tab) │  '   │  ,   │ . │ p │ y │ f │ g │ c │ r │  l   │       /        │  =   │  \   │ mply │
//    ├────────────────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼────────────────┴──────┼──────┼──────┤
//    │   LT(SPECIALS, esc)    │  a   │  o   │ e │ u │ i │ d │ h │ t │ n │  s   │           -           │ ent  │ mnxt │
//    ├────────────────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼───────────────────────┼──────┼──────┤
//    │          lsft          │  ;   │  q   │ j │ k │ x │ b │ m │ w │ v │  z   │         rsft          │  up  │ mprv │
//    ├────────────────────────┼──────┼──────┼───┴───┴───┴───┴───┴───┴───┼──────┼────────────────┬──────┼──────┼──────┤
//    │          lctl          │ lalt │ lgui │            spc            │ rgui │ MO(BOARD_OPTS) │ left │ down │ rght │
//    └────────────────────────┴──────┴──────┴───────────────────────────┴──────┴────────────────┴──────┴──────┴──────┘
[DVORAK] = LAYOUT_65_ansi_blocker(
  KC_GRV                    , KC_1    , KC_2    , KC_3   , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0    , KC_LBRC        , KC_RBRC , KC_BSPC , KC_DEL             ,
  LT(ARROWS_NUMPAD, KC_TAB) , KC_QUOT , KC_COMM , KC_DOT , KC_P , KC_Y , KC_F , KC_G , KC_C , KC_R , KC_L    , KC_SLSH        , KC_EQL  , KC_BSLS , KC_MEDIA_PLAY_PAUSE,
  LT(SPECIALS, KC_ESC)      , KC_A    , KC_O    , KC_E   , KC_U , KC_I , KC_D , KC_H , KC_T , KC_N , KC_S    ,         KC_MINS          , KC_ENT  , KC_MEDIA_NEXT_TRACK,
  KC_LSFT                   , KC_SCLN , KC_Q    , KC_J   , KC_K , KC_X , KC_B , KC_M , KC_W , KC_V , KC_Z    ,         KC_RSFT          , KC_UP   , KC_MEDIA_PREV_TRACK,
  KC_LCTL                   , KC_LALT , KC_LGUI ,                      KC_SPC                      , KC_RGUI , MO(BOARD_OPTS) , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌─────┬─────┬──────┬──────┬──────┬─────┬──────┬──────┬──────┬──────┬──────────────────┬─────┬─────┬─────┬─────┐
//    │     │     │      │      │      │     │      │      │ kp_/ │ kp_* │                  │     │     │     │     │
//    ├─────┼─────┼──────┼──────┼──────┼─────┼──────┼──────┼──────┼──────┼──────────────────┼─────┼─────┼─────┼─────┤
//    │     │     │      │  up  │      │     │      │ kp_7 │ kp_8 │ kp_9 │       kp_-       │     │     │     │     │
//    ├─────┼─────┼──────┼──────┼──────┼─────┼──────┼──────┼──────┼──────┼──────────────────┼─────┴─────┼─────┼─────┤
//    │     │     │ left │ down │ rght │     │ spc  │ kp_4 │ kp_5 │ kp_6 │       kp_+       │           │     │     │
//    ├─────┼─────┼──────┼──────┼──────┼─────┼──────┼──────┼──────┼──────┼──────────────────┼───────────┼─────┼─────┤
//    │     │     │      │      │      │     │ kp_. │ kp_1 │ kp_2 │ kp_3 │       kp_=       │           │     │     │
//    ├─────┼─────┼──────┼──────┴──────┴─────┴──────┴──────┴──────┴──────┼──────────────────┼─────┬─────┼─────┼─────┤
//    │     │     │      │                     kp_0                      │ MO(LAYER_SWITCH) │     │     │     │     │
//    └─────┴─────┴──────┴───────────────────────────────────────────────┴──────────────────┴─────┴─────┴─────┴─────┘
[ARROWS_NUMPAD] = LAYOUT_65_ansi_blocker(
  _______ , _______ , _______ , _______ , _______  , _______ , _______   , _______ , KC_KP_SLASH , KC_KP_ASTERISK , _______          , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , KC_UP   , _______  , _______ , _______   , KC_KP_7 , KC_KP_8     , KC_KP_9        , KC_KP_MINUS      , _______ , _______ , _______ , _______,
  _______ , _______ , KC_LEFT , KC_DOWN , KC_RIGHT , _______ , KC_SPC    , KC_KP_4 , KC_KP_5     , KC_KP_6        , KC_KP_PLUS       ,      _______      , _______ , _______,
  _______ , _______ , _______ , _______ , _______  , _______ , KC_KP_DOT , KC_KP_1 , KC_KP_2     , KC_KP_3        , KC_KP_EQUAL      ,      _______      , _______ , _______,
  _______ , _______ , _______ ,                                      KC_KP_0                                      , MO(LAYER_SWITCH) , _______ , _______ , _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────────────────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │     │     │     │     │                  │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────────────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │  ^  │  $  │  %  │  *  │     │     │                  │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────────────┼─────┴─────┼─────┼─────┤
//    │     │     │  [  │  {  │  (  │  |  │  &  │  )  │  }  │  ]  │                  │           │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────────────┼───────────┼─────┼─────┤
//    │     │     │     │     │  <  │     │  >  │     │     │     │                  │           │     │     │
//    ├─────┼─────┼─────┼─────┴─────┴─────┴─────┴─────┴─────┴─────┼──────────────────┼─────┬─────┼─────┼─────┤
//    │     │     │     │                                         │ MO(LAYER_SWITCH) │     │     │     │     │
//    └─────┴─────┴─────┴─────────────────────────────────────────┴──────────────────┴─────┴─────┴─────┴─────┘
[SPECIALS] = LAYOUT_65_ansi_blocker(
  _______ , _______ , _______ , _______ , _______ , _______   , _______ , _______ , _______ , _______ , _______          , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , KC_CIRC , KC_DOLLAR , KC_PERC , KC_ASTR , _______ , _______ , _______          , _______ , _______ , _______ , _______,
  _______ , _______ , KC_LBRC , KC_LCBR , KC_LPRN , KC_PIPE   , KC_AMPR , KC_RPRN , KC_RCBR , KC_RBRC , _______          ,      _______      , _______ , _______,
  _______ , _______ , _______ , _______ , KC_LT   , _______   , KC_GT   , _______ , _______ , _______ , _______          ,      _______      , _______ , _______,
  _______ , _______ , _______ ,                                _______                                , MO(LAYER_SWITCH) , _______ , _______ , _______ , _______
),

//    ┌─────────┬────────┬─────────┬───────┬─────────┬─────────┬─────────┬─────┬─────┬─────┬──────────────────┬──────┬──────┬──────────────┬──────┐
//    │   esc   │   f1   │   f2    │  f3   │   f4    │   f5    │   f6    │ f7  │ f8  │ f9  │       f10        │ f11  │ f12  │ system_sleep │ mute │
//    ├─────────┼────────┼─────────┼───────┼─────────┼─────────┼─────────┼─────┼─────┼─────┼──────────────────┼──────┼──────┼──────────────┼──────┤
//    │ L_T_BR  │ L_PSD  │  L_BRI  │ L_PSI │ L_EDG_I │         │         │     │     │     │       pscr       │ sCRL │ paus │              │      │
//    ├─────────┼────────┼─────────┼───────┼─────────┼─────────┼─────────┼─────┼─────┼─────┼──────────────────┼──────┴──────┼──────────────┼──────┤
//    │ L_T_PTD │ L_PTP  │  L_BRD  │ L_PTN │ L_EDG_D │         │         │     │     │     │                  │             │              │ volu │
//    ├─────────┼────────┼─────────┼───────┼─────────┼─────────┼─────────┼─────┼─────┼─────┼──────────────────┼─────────────┼──────────────┼──────┤
//    │         │ L_T_MD │ L_T_ONF │       │ L_EDG_M │ MD_BOOT │ NK_TOGG │     │     │     │  LGUI(LSFT(m))   │             │     pgup     │ vold │
//    ├─────────┼────────┼─────────┼───────┴─────────┴─────────┴─────────┴─────┴─────┴─────┼──────────────────┼──────┬──────┼──────────────┼──────┤
//    │         │        │         │                        DBG_FAC                        │ MO(LAYER_SWITCH) │      │ home │     pgdn     │ end  │
//    └─────────┴────────┴─────────┴───────────────────────────────────────────────────────┴──────────────────┴──────┴──────┴──────────────┴──────┘
[BOARD_OPTS] = LAYOUT_65_ansi_blocker(
  KC_ESC  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10           , KC_F11  , KC_F12  , KC_SYSTEM_SLEEP , KC_MUTE,
  L_T_BR  , L_PSD   , L_BRI   , L_PSI   , L_EDG_I , _______ , _______ , _______ , _______ , _______ , KC_PSCR          , KC_SCRL , KC_PAUS , _______         , _______,
  L_T_PTD , L_PTP   , L_BRD   , L_PTN   , L_EDG_D , _______ , _______ , _______ , _______ , _______ , _______          ,      _______      , _______         , KC_VOLU,
  _______ , L_T_MD  , L_T_ONF , _______ , L_EDG_M , MD_BOOT , NK_TOGG , _______ , _______ , _______ , LGUI(LSFT(KC_M)) ,      _______      , KC_PGUP         , KC_VOLD,
  _______ , _______ , _______ ,                               DBG_FAC                               , MO(LAYER_SWITCH) , _______ , KC_HOME , KC_PGDN         , KC_END
),

//    ┌────────────┬────────────┬───────────────────┬──────────────┬────────────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
//    │ TO(QWERTY) │ TO(DVORAK) │ TO(ARROWS_NUMPAD) │ TO(SPECIALS) │ TO(BOARD_OPTS) │     │     │     │     │     │     │     │     │     │     │
//    ├────────────┼────────────┼───────────────────┼──────────────┼────────────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │            │            │                   │              │                │     │     │     │     │     │     │     │     │     │     │
//    ├────────────┼────────────┼───────────────────┼──────────────┼────────────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┤
//    │            │            │                   │              │                │     │     │     │     │     │     │           │     │     │
//    ├────────────┼────────────┼───────────────────┼──────────────┼────────────────┼─────┼─────┼─────┼─────┼─────┼─────┼───────────┼─────┼─────┤
//    │            │            │                   │              │                │     │     │     │     │     │     │           │     │     │
//    ├────────────┼────────────┼───────────────────┼──────────────┴────────────────┴─────┴─────┴─────┴─────┴─────┼─────┼─────┬─────┼─────┼─────┤
//    │            │            │                   │                                                             │     │     │     │     │     │
//    └────────────┴────────────┴───────────────────┴─────────────────────────────────────────────────────────────┴─────┴─────┴─────┴─────┴─────┘
[LAYER_SWITCH] = LAYOUT_65_ansi_blocker(
  TO(QWERTY) , TO(DVORAK) , TO(ARROWS_NUMPAD) , TO(SPECIALS) , TO(BOARD_OPTS) , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______    , _______    , _______           , _______      , _______        , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______    , _______    , _______           , _______      , _______        , _______ , _______ , _______ , _______ , _______ , _______ ,      _______      , _______ , _______,
  _______    , _______    , _______           , _______      , _______        , _______ , _______ , _______ , _______ , _______ , _______ ,      _______      , _______ , _______,
  _______    , _______    , _______           ,                                     _______                                     , _______ , _______ , _______ , _______ , _______
)
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static uint8_t scroll_effect = 0;

    switch (keycode) {
        case L_BRI ... U_T_AGCR:
            if (record->event.pressed) {
                md_led_changed();
            }
            break;
    }

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_EDG_M:
            if (record->event.pressed) {
                led_edge_mode++;
                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            return false;
        case L_EDG_I:
            if (record->event.pressed) {
                led_edge_brightness += 0.1;
                if (led_edge_brightness > 1) { led_edge_brightness = 1; }
            }
            return false;
        case L_EDG_D:
            if (record->event.pressed) {
                led_edge_brightness -= 0.1;
                if (led_edge_brightness < 0) { led_edge_brightness = 0; }
            }
            return false;
        case L_RATIOI:
            if (record->event.pressed) {
                led_ratio_brightness += 0.2;
                if (led_ratio_brightness > 2.0) { led_ratio_brightness = 2.0; }
            }
            return false;
        case L_RATIOD:
            if (record->event.pressed) {
                led_ratio_brightness -= 0.2;
                if (led_ratio_brightness < 0.0) { led_ratio_brightness = 0.0; }
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                scroll_effect++;
                if (scroll_effect == 1) {               //Patterns with scroll move horizontal (Right to left)
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                } else if (scroll_effect == 2) {        //Patterns with scroll move vertical (Top to bottom)
                    led_animation_direction = 1;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 3) {        //Patterns with scroll move vertical (Bottom to top)
                    led_animation_direction = 0;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 4) {        //Patterns with scroll explode from center
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else if (scroll_effect == 5) {        //Patterns with scroll implode on center
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else {                                //Patterns with scroll move horizontal (Left to right)
                    scroll_effect = 0;
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                }
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_FAC:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                led_lighting_mode = LED_MODE_NORMAL;
                led_edge_brightness = 1;
                led_edge_mode = LED_EDGE_MODE_ALL;
                led_animation_breathing = 0;
                led_animation_id = 7; //led_programs.c led_setups leds_white index
                gcr_desired = LED_GCR_MAX;
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
    // LEDs are normally inactive
    //
    // all key LEDs (right to left)
    //     (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //     (id2  67 -  65: 0000 0000 0000 0000 0000 0000 0000 0111 = 0x00000007)
    //
    // all edge LEDs (right to left)
    //     (id2  95 -  68: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    //     (id3 105 -  96: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)


    // QWERTY
    // All keys off
    { .flags = LED_FLAG_MATCH_LAYER, .layer = QWERTY },


    // DVORAK
    // All keys off
    { .flags = LED_FLAG_MATCH_LAYER, .layer = DVORAK },


    // ARROWS_NUMPAD
    // White on arrows & numpad
    //    key LEDs  (id0: 0000 0001 1100 0100 0000 0000 0000 0000 = 0x01C40000)
    //    key LEDs  (id1: 0000 0000 0011 1000 0000 0000 1110 0111 = 0x003800E7)
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0x01C40000, .id1 = 0x003800E7, .r = 255, .g = 255, .b = 255, .layer = ARROWS_NUMPAD },


    // SPECIALS
    // White on specials keys
    //    key LEDs  (id0: 0000 0000 0111 1000 0000 0000 0000 0000 = 0x00780000)
    //    key LEDs  (id1: 0000 0000 0000 0101 0000 0000 1111 1111 = 0x000500FF)
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0x00780000, .id1 = 0x000500FF, .r = 255, .g = 255, .b = 255, .layer = SPECIALS },


    // BOARD_OPTS
    // Rotate pattern all keys
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN, .layer = BOARD_OPTS },


    // LAYER_SWITCH
    // White on layer switch keys
    //    key LEDs  (id0: 0000 0000 0000 0000 0000 0000 0001 1111 = 0x0000001F)
    //    key LEDs  (id1: 0000 0000 0000 0000 0000 0000 0000 0000 = 0x00000000)
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0x0000001F, .r = 255, .g = 255, .b = 255, .layer = LAYER_SWITCH },
    // Rotate pattern on edge
    //    edge LEDs (id2: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    //    edge LEDs (id3: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN, .id2 = 0xFFFFFFF8, .id3 = 0x000003FF, .layer = LAYER_SWITCH },


    // Must end with this
    { .end = 1 }
};
