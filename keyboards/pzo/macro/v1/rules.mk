# This file intentionally left blank

MCU = STM32F411
#MCU_LDSCRIPT = STM32F411xE_tinyuf2_emu_EEPROM
# Bootloader selection
BOOTLOADER = tinyuf2
BOOTMAGIC_ENABLE = yes

# dev
CONSOLE_ENABLE = no

# custom matrix setup
CUSTOM_MATRIX = lite

# other drivers
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = analog_joystick
NKRO_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
#EEPROM_DRIVER = vendor

# flags


# other features
CAPS_WORD_ENABLE = yes
#DYNAMIC_MACRO_ENABLE = yes


#paths
VPATH += drivers/gpio
SRC += pca9505.c matrix.c ssd1306_sh1106.c
QUANTUM_LIB_SRC += i2c_master.c
