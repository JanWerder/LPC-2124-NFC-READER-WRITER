/**
	Keypad driver
*/


#include "gpio.h"

#include <targets/LPC2000.h>
#include <stdbool.h>


typedef enum {
	COL_4 = 18,
	COL_3 = COL_4 + 1,
	COL_2,
	COL_1,
	ROW_4,
	ROW_3,
	ROW_2,
	ROW_1
} KEYPAD_PIN;


void init_keypad();

char wait_and_get_key();