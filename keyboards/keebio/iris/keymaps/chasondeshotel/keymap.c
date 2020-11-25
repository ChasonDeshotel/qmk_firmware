#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

//#define TAPPING_TERM 135

#define DEFAULT 0
#define NAVI 1
//mouse keys
//#define MSK 2
#define NUM 3
#define ABLETON 4 //bableton

enum custom_keycodes {
	ADDTRK = SAFE_RANGE
	, ADDMIDI
	,	HIDEPLUGS 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DEFAULT] = LAYOUT( // layer 0
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_BSPC, KC_LPRN, KC_MINS, TG(ABLETON),
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼───────┤
     MO(NAVI), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,          KC_LCTL, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(NAVI),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  KC_LSFT,  KC_ENT,									KC_SPC, KC_RSFT, TG(NUM)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	)

  , [NAVI] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PIPE,                              KC_NO,   KC_NO,   KC_DEL,    KC_8, KC_PLUS, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_NO,   KC_TAB,  KC_LBRC, KC_RBRC, KC_EQUAL,														KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,  KC_NO,   KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,                            KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,    KC_TAB,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F4,   KC_NO,   KC_NO,   KC_NO,   LSFT(KC_SCLN),LSFT(KC_MINS), KC_NO,   KC_NO,   KC_NO, KC_LEFT, KC_NO,    KC_DOT,  KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(NAVI),   KC_NO,   KC_SPC,                  KC_ENT,  KC_NO,   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  , [NUM] = LAYOUT( // layer 3
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_MOD, KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_ASTR,   KC_NO,  KC_BSPC, KC_NO, KC_NO, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_HUI, RGB_HUD, KC_TAB,  KC_LPRN, KC_RPRN, KC_NO,                              KC_PLUS,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
  //├────────┼───────┼──────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_SAI, RGB_SAD, KC_ASTR, KC_LBRC, KC_RBRC, KC_MINS,                            KC_MINS,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
  //├────────┼───────┼──────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_VAI, RGB_VAD, KC_NO,   KC_NO,   LSFT(KC_SCLN),LSFT(KC_MINS), KC_NO,   KC_NO, KC_PERC,   KC_1,   KC_2,    KC_3,  KC_DOT,  TG(NUM),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_NO,   KC_LSFT,   KC_NO,                     KC_NO,  KC_0,   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
  
	, [ABLETON] = LAYOUT( // layer 3
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, RGB_MOD, KC_NO,   KC_NO,   KC_NO,   KC_NO,                              ADDTRK,   ADDMIDI,  KC_BSPC, KC_NO,   KC_NO,   TG(ABLETON),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_HUI, RGB_HUD, KC_NO,  KC_NO, KC_NO, KC_NO,                              	KC_HOME, KC_PGDN, KC_PGUP,  KC_END,    KC_NO,   KC_NO,
  //├────────┼───────┼──────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_SAI, RGB_SAD, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,   KC_NO,   KC_NO,
  //├────────┼───────┼──────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_VAI, RGB_VAD, KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,                HIDEPLUGS, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_NO,   KC_LSFT,   KC_NO,                     KC_NO,  KC_0,   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )


//  , [MSK] = LAYOUT( // layer 2
//  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_DEL,
//  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//     _______, _______, KC_TAB,  KC_LPRN, KC_RPRN, _______,                            KC_MS_D, KC_MS_R, KC_PGUP, KC_END,  _______, _______,
//  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//     _______, _______, KC_ASTR, KC_LBRC, KC_RBRC, KC_MINS,                            KC_MS_U, KC_NO,   KC_UP,   KC_RIGHT, _______, _______,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
// _______, _______, _______, _______, LSFT(KC_SCLN),LSFT(KC_MINS), KC_NO,    _______, _______, KC_MS_L, _______, _______, _______, TG(MSK),
//  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                    KC_NO,  _______, KC_NO,                    KC_BTN1, KC_BTN2, TG(MSK)
//                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case ADDTRK:
			if (record->event.pressed) {
					// when keycode is pressed
				} else {
					// when keycode is released
					//char track_name[10] = "test";
						switch (keycode) {
							// pressed again then we need to make the track
							if (record->event.pressed) {
							case ADDTRK:
								SEND_STRING(SS_LGUI("t"));
								SEND_STRING(SS_LGUI("r"));
								//SEND_STRING(keycode);
								//SS_TAP(X_ENTER);
								return true;
							}
						return true;
				}
				return false;
				break;
//		
//		case ADDMIDI:
//			if (record->event.pressed) {
//					// when keycode is pressed
//					SEND_STRING(SS_LSFT(SS_LGUI("t")));
//				} else {
//					// when keycode is released
//				}
//				return false;
//				break;
//		
//		case HIDEPLUGS:
//			if (record->event.pressed) {
//					// when keycode is pressed
//					SEND_STRING(SS_RALT(SS_LGUI("p")));
//				} else {
//					// when keycode is released
//				}
//				return false;
//				break;
//	}
	return true;
};

//layer_state_t layer_state_set_user(layer_state_t state) {
//		switch (get_highest_layer(state)) {
//		case DEFAULT:
//				rgblight_sethsv (18, 168, 31);
//				break;
//		case NAVI:
//				rgblight_sethsv (226,	184, 103);
//				break;
//		case NUM:
//				rgblight_sethsv (42, 248, 103);
//				break;
//		case ABLETON:
//				rgblight_sethsv (250,	128, 31);
//				break;
//		default: //	for any other layers, or the default layer
//				rgblight_sethsv (0, 0, 0);
//				break;
//		}
//	return state;
//}

//
//	if(!process_action_delayed_lt(keycode,record)){ return false; }
//
//	return true;	
//};



//
//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
//{
//	case 100:
//	if (record->event.pressed) {
//			if (record->tap.count && !record->tap.interrupted) {
//					register_code(KC_ENT);
//			} else {
//					layer_on(3);
//			}
//	} else {
//			if(record->tap.count && !record->tap.interrupted) {
//					unregister_code(KC_QUOT);
//			} else {
//					layer_off(3);
//			}
//	}
//	break;
//}

//const uint16_t PROGMEM fn_actions[] = {
//    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPC)
//    , [1] = ACTION_LAYER_TAP_KEY(2, KC_ESC) //symbol layer
//    , [2] = ACTION_LAYER_TAP_KEY(3, KC_N)   //numpad
//
// //   [1] = DLT(2, KC_ENT),
// //   [1] = ACTION_MACRO_TAP(100)
//};

