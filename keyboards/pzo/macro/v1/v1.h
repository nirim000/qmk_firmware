#pragma once

#include "quantum.h"

#define LAYOUT_base( \
	K00, K01, K02, \
	K03, K04, K05, \
    K06, K07, K08, \
	K09, K10, K11, \
	K12, K13, K14  \
) { \
	{ K00, K01, K02 }, \
	{ K03, K04, K05 }, \
    { K06, K07, K08 }, \
	{ K09, K10, K11 }, \
	{ K12, K13, K14 }  \
}



#define LAYOUT LAYOUT_base
