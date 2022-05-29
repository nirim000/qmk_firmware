# This file intentionally left blank

MCU = STM32F411
# Bootloader selection
BOOTLOADER = stm32-dfu

# custom matrix setup
CUSTOM_MATRIX = lite

VPATH += drivers/gpio
SRC += pca9505.c matrix.c
QUANTUM_LIB_SRC += i2c_master.c
