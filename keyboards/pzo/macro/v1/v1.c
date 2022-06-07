
#include "v1.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {  0, 1, 2 },
  {  3, 4, 5 },
  {  6, 7, 8 },
  {  9, 10, 11 },
  {  12, 13, 14 },
  {  NO_LED, NO_LED, NO_LED }
}, {
  // LED Index to Physical Position
  { 0,  0 }, { 0,  1 }, { 0,  2 }, { 1,  0 }, {  1,  1 }, { 1,  2 }, { 2,  0 }, { 2,  1 }, {  2,  2 }, {  3,  0 }, { 3,  1 }, { 3,  2 }, { 4,  0 }, {  4,  1 }, {  4,  2 }
}, {
  // LED Index to Flag
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
#endif
