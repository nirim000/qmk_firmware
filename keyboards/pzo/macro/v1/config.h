// Copyright 2022 nirim000 (@nirim000)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xC79C   // "Nirim00"
#define PRODUCT_ID      0xD034   // "Kitty00"
#define DEVICE_VER      0x0001
#define MANUFACTURER    nirim000
#define PRODUCT         pzo_macro

// i2c_master defines
#define I2C1_SCL_PIN B6 // A2 on pinout = B0
#define I2C1_SDA_PIN B7 // A3 on pinout = B1

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 3

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
