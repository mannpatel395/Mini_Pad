#prafma once

#include "config_common.h"

#define MATRIX_ROWS 1
#define MATRIX_COLS 5

#define Direct_Pins { \
	{GP3, GP4, GP2, GP1, GP28 } \
}

#define ENCODER_PAD_A {GP26}
#define ENCODER_PAD_B {GP27}
#define ENCODER_RESOLUTION 4

#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
#define I2C1_DRIVER I2CD1

#define RGB_DI_PIN GP29
#define RGBLED_NUM 1
#define RGBLIGHT_LIMIT_VAL 120