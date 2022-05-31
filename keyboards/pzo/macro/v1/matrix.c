/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "matrix.h"
#include "pca9505.h"
#include "quantum.h"

#include "debug.h"

// PCA9505 slave addresses
#define IC1 0x20
uint8_t current_row = 0;

//_____Utility funcs___________________________________________________________

static void init_pins(void) {
  // reverse all cols - IC2 all inverted
  pca9505_set_polarity(IC1, PCA9505_PORT0, ALL_INVERTED);//same as initial state
  pca9505_set_polarity(IC1, PCA9505_PORT1, ALL_INVERTED);//same as initial state
 // pca9505_set_polarity(IC1, PCA9505_PORT2, ALL_INVERTED);//same as initial state
  //pca9505_set_polarity(IC1, PCA9505_PORT3, ALL_INVERTED);//same as initial state
  //pca9505_set_polarity(IC1, PCA9505_PORT4, ALL_INVERTED);//same as initial state
// init all cols low - IC2 all input
  pca9505_set_config(IC1, PCA9505_PORT0, ALL_INPUT);//same as initial state
  pca9505_set_config(IC1, PCA9505_PORT1, ALL_INPUT);//same as initial state
  //pca9505_set_config(IC1, PCA9505_PORT2, ALL_INPUT);//same as initial state
  //pca9505_set_config(IC1, PCA9505_PORT3, ALL_INPUT);//same as initial state
  //pca9505_set_config(IC1, PCA9505_PORT4, ALL_INPUT);//same as initial state

}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {

  uint8_t state_1 = 0;
  uint8_t state_2 = 0;
  //uint8_t state_3 = 0;
  //uint8_t state_4 = 0;
  //uint8_t state_5 = 0;
  pca9505_readPins(IC1, PCA9505_PORT0, &state_1);
  pca9505_readPins(IC1, PCA9505_PORT1, &state_2);
  //pca9505_readPins(IC1, PCA9505_PORT2, &state_3);
  //pca9505_readPins(IC1, PCA9505_PORT3, &state_4);
  //pca9505_readPins(IC1, PCA9505_PORT4, &state_5);

  // For the XD96 the pins are mapped to port expanders as follows:
  //   all 8 pins port 0 IC2, first 6 pins port 1 IC2, first 4 pins port 1 IC1
  uint16_t state_u = ((((uint16_t)state_2 & 0b01111111) << 8) | (uint16_t)state_1);

  // Store last value of row prior to reading
  matrix_row_t last_row_value = current_matrix[current_row];

  // Clear data in matrix row
  current_matrix[current_row] = 0;

      switch (current_row)
    {
        case 0:
            current_matrix[current_row] = ((uint16_t)state_u & 0b0000000000000111);
            break;
        case 1:
            current_matrix[current_row] = (((uint16_t)state_u & 0b0000000000111000) >> 3);
            break;
        case 2:
            current_matrix[current_row] = (((uint16_t)state_u & 0b0000000111000000) >> 6);
            break;
        case 3:
            current_matrix[current_row] = (((uint16_t)state_u & 0b0000111000000000) >> 9);
            break;
        case 4:
            current_matrix[current_row] = (((uint16_t)state_u & 0b0111000000000000) >> 12);
            break;
    }

  // No need to Unselect row as the next `select_row` will blank everything

  return (last_row_value != current_matrix[current_row]);
}

//_____CUSTOM MATRIX IMPLEMENTATION____________________________________________________

void matrix_init_custom(void) {
  pca9505_init(IC1);
  init_pins();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
  bool changed = false;
  for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
    changed |= read_cols_on_row(current_matrix, current_row);
  }
  return changed;
}
