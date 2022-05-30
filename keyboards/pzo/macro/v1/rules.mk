# This file intentionally left blank

MCU = STM32F411
# Bootloader selection
BOOTLOADER = stm32-dfu

# custom matrix setup
CUSTOM_MATRIX = lite

# other drivers
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

#paths
VPATH += drivers/gpio
SRC += pca9505.c matrix.c
QUANTUM_LIB_SRC += i2c_master.c
