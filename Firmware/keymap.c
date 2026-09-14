#incude QMK_KEYBOARD_H

enum layers {
	_EDIT = 0,
	_BRUSH = 1
};

const unit 16_t PROGMEN keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_EDIT] = LAYOUT(
		LCTL(KC_Z),
		LCTL(KC_Y),
		KC_C,
		TG(_BRUSH),
		KC_V
	),
	
	[_BRUSH] = LAYOUT(
		KC_B,
		KC_E,
		KC_TRNS,
		TG(_EDIT),
		KC_TRNS
	)
};

#ifdef ENCODER_ENABLE
boll encoder_update_user(unit8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _EDIT:
			if (clockwise) {
				tap_code(KC_RGHT);
			} else {
				tap_code(KC_LEFT);
			}
			break:
			
		case _BRUSH:
			if (clockwise) {
				tap_code(KC_RBRC);
			} else {
				tap_code(KC_LBRC);
			}
			break:
	}
	return false;
}
#endif
	
#ifdef OLED_ENABLE
bool oled_task_user(void) {
	static unit8_t current_layer = 0;
	if (current_layer != get_highest_layer(layer_state)) {
		oled_clear();
		current_layer = get_highest_layer(layer_state);
	}
	
	switch (current_layer) {
		case _EDIT:
			oled_wire_ln_P(PSTR("== TIMELINE =="), false);
			oled_wire_ln_P(PSTR(""), false);
			oled_wire_ln_P(PSTR("Turn: Scrub"), false);
			oled_wire_ln_P(PSTR("Press: Select"), false);
			break;
		case _BRUSH:
			oled_wire_ln_P(PSTR("== BRUSH =="), false);
			oled_wire_ln_P(PSTR(""), false);
			oled_wire_ln_P(PSTR("Turn: Size"), false);
			oled_wire_ln_P(PSTR("Press: Default"), false);
			break;
	}
	return false;
}
#endif

void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(HSV_RED);
}

layer_state_t layer_state_set_user(layer_state_t state) {

	if (get_highest_layer(state) == _BRUSH) {
		rgblight_sethsv_noeeprom(HSV_BLUE);
	} else {
		rgblight_sethsv_noeeprom(HSV_RED);
	}
}