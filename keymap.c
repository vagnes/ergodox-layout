#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define QWRT 3 // qwerty
#define SYMB 1 // symbols
#define MDIA 2 // media

enum custom_keycodes {
	GGWP = SAFE_RANGE,
	RGB_SLD,
	NOR_AA,
	NOR_AE,
	NOR_OE,
};		

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_9)), // Alt+0229 → å
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_7)), // Alt+0197 → Å
    },
    {
		SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_0)), // Alt+0230 → æ
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_8)), // Alt+0198 → Æ
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_8)), // Alt+0248 → ø
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_6)), // Alt+0216 → Ø
    },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | VLK  |   1  |   2  |   3  |   4  |   5  | GGWP |           | TG(3)|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  =/+   | '/"  |   ,  |   .  |   P  |   Y  | Home |           | PgUp |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ;/:   |   A  | O/L1 |   E  |   U  |   I  |------|           |------|   D  | H/L2 |   T  | N/L1 |   S  |   -    |
 * |--------+------+------+------+------+------| End  |           | PgDn |------+------+------+------+------+--------|
 * | LSh/CL | Ctrl |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | CAPS |       | Alt  |  Esc   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | Ins  |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | LGui |       | RGui |        |      |
 *                                 `--------------------'       `----------------------'
 */

[BASE] = LAYOUT_ergodox(  // layer 0 : default
				// left hand
				VLK_TOG,        KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   GGWP,
				KC_EQL,         KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_HOME,
				KC_SCLN,        KC_A,           LT(SYMB, KC_O),    KC_E,   KC_U,   KC_I,
				KC_LSHIFT,      KC_LCTL,        KC_Q,    KC_J,   KC_K,   KC_X,   KC_END,
				LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT), KC_LEFT, KC_RGHT,
																							ALT_T(KC_APP),  KC_CAPS,
																											KC_DELT,
																							KC_SPC, KC_BSPC,KC_LGUI,
				// right hand
				TG(3),       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,         KC_BSLS,
				KC_PGUP,     KC_F,   KC_G,   KC_C,   KC_R,   KC_L,         KC_SLSH,
							 KC_D,   LT(MDIA, KC_H), KC_T,   LT(SYMB, KC_N),   KC_S, KC_MINS,
				KC_PGDN,     KC_B,   KC_M,   KC_W,   KC_V,   CTL_T(KC_Z),  KC_RSFT,
									 KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,      KC_FN1,
				KC_LALT, KC_ESC,
				KC_INS,
				KC_RGUI, KC_TAB, KC_ENT
		),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       | Sat+ |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       | Sat- |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
			 // left hand
			 KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
			 KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
			 KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
			 KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
			 KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
																	RGB_MOD, KC_TRNS,
																			 KC_TRNS,
															RGB_VAD,RGB_VAI, KC_TRNS,
			 // right hand
			 KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
			 KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
								KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
			 KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
												 KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
			 RGB_TOG, RGB_SLD,
			 RGB_SAI,
			 RGB_SAD, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      | PrOn |           | PrOf |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |   æ  |  ø   |   å  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |  ..  |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           | Wake |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      | MwUp |       |MwDown|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
			 RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, PRINT_ON,
			 KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
			 KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
			 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
																					 KC_TRNS, KC_TRNS,
																										KC_TRNS,
																	KC_BTN1, KC_BTN2, KC_WH_U,
		// right hand
			 PRINT_OFF,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			 KC_TRNS,  KC_TRNS, KC_TRNS, NOR_AE, NOR_OE, NOR_AA, KC_TRNS,
								 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
			 KC_WAKE,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
													KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
			 KC_TRNS, KC_TRNS,
			 KC_TRNS,
			 KC_WH_D, KC_TRNS, KC_WBAK
),
/* Keymap 3: qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | TG(1)|           | TG(3)|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | Grv  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWRT] = LAYOUT_ergodox(  // layer 0 : default
				// left hand
				KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(1),
				KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
				KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
				KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
				KC_LCTL,        KC_GRV,       LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
																							ALT_T(KC_APP),  KC_LGUI,
																															KC_HOME,
																							 KC_SPC,KC_BSPC,KC_END,
				// right hand
						 TG(3),     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
						 TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
													KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
						 MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
																	KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
						 KC_LALT,        CTL_T(KC_ESC),
						 KC_PGUP,
						 KC_PGDN,KC_TAB, KC_ENT
		),
};

const uint16_t PROGMEM fn_actions[] = {
		[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) 
		return true;

	switch(keycode) {
		case GGWP:
			SEND_STRING("ggwp");
			return false; break;
		case NOR_AA: 
		case NOR_AE: 
		case NOR_OE: {
			uint16_t index = keycode - NOR_AA;
			uint8_t shift = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

			unregister_code(KC_LSFT);
			unregister_code(KC_RSFT);

			send_string(alt_codes[index][(bool)shift]);

			if (shift & MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
			if (shift & MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

			return false;
		};
	default:
		return true;
	};
};

// Runs just one time when the keyboard initializes.
// void matrix_init_user(void) {
// 	set_unicode_input_mode(UC_WINC);
	// REPLACE UC_XXXX with the Unicode Input Mode for your OS.
	// UC_WINC: Windows using WinCompose.
	// UC_OSX:  MacOS using Unicode Hex Input. Can also send `UC_OSX_RALT` to use the Right Alt key.
	// UC_LNX:  Linux using Unicode input method.
	// Read more at https://jayliu50.github.io/qmk-cheatsheet/
// };

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

		uint8_t layer = biton32(layer_state);

		ergodox_board_led_off();
		ergodox_right_led_1_off();
		ergodox_right_led_2_off();
		ergodox_right_led_3_off();
		switch (layer) {
				case 1:
						ergodox_right_led_1_on();
						break;
				case 2:
						ergodox_right_led_2_on();
						break;
				case 3:
						ergodox_right_led_3_on();
						break;
				default:
						// none
						break;
		}
};