#include "keypad.h"


void init_keypad()
{
	PINSEL0 = 0;

	IO0DIR = 0x000003FF;
	IO1DIR = (1 << ROW_1) | (1 << ROW_2) | (1 << ROW_3) | (1 << ROW_4);
}


/**
	TODO make this work right
*/
char wait_and_get_key()
{
	while (true)
	{
		IO1CLR |= (1 << ROW_4);
		IO1SET |= (1 << ROW_3) | (1 << ROW_2) | (1 << ROW_1);

		if (!get_pin_value_1(COL_4)) {
			while (!get_pin_value_1(COL_4));
			return 'D';
		}
		if (!get_pin_value_1(COL_3)) {
			while (!get_pin_value_1(COL_3));
			return '#';
		}
		if (!get_pin_value_1(COL_2)) {
			while (!get_pin_value_1(COL_2));
			return '0';
		}
		if (!get_pin_value_1(COL_1)) {
			while (!get_pin_value_1(COL_1));
			return '*';
		}

		IO1CLR |= (1 << ROW_3);
		IO1SET |= (1 << ROW_2) | (1 << ROW_4) | (1 << ROW_1);

		if (!get_pin_value_1(COL_4)) {
			while (!get_pin_value_1(COL_4));
			return 'C';
		}
		if (!get_pin_value_1(COL_3)) {
		   while	(!get_pin_value_1(COL_3));
		   return	'9';
		}
		if (!get_pin_value_1(COL_2)) {
			while (!get_pin_value_1(COL_2));
			return '8';
		}
		if (!get_pin_value_1(COL_1)) {
			while (!get_pin_value_1(COL_1));
			return '7';
		}

		IO1CLR |= (1 << ROW_2);
		IO1SET |= (1 << ROW_4) | (1 << ROW_3) | (1 << ROW_1);

		if (!get_pin_value_1(COL_4)) {
			while (!get_pin_value_1(COL_4));
			return 'B';
		}
		if (!get_pin_value_1(COL_3)) {
			while (!get_pin_value_1(COL_3));
			return '6';
		}
		if (!get_pin_value_1(COL_2)) {
			while (!get_pin_value_1(COL_2));
			return '5';
		}
		if (!get_pin_value_1(COL_1)) {
			while (!get_pin_value_1(COL_1));
			return '4';
		}

		IO1CLR |= (1 << ROW_1); // "row 1 low"?
		IO1SET |= (1 << ROW_4) | (1 << ROW_3) | (1 << ROW_2); // "rest 1"?

		if (!get_pin_value_1(COL_4)) {
			while (!get_pin_value_1(COL_4)); // don't return until key is released
			return 'A';
		}
		if (!get_pin_value_1(COL_3)) {
			while (!get_pin_value_1(COL_3));
			return '3';
		}
		if (!get_pin_value_1(COL_2)) {
			while (!get_pin_value_1(COL_2));
			return '2';
		}
		if (!get_pin_value_1(COL_1)) {
			while (!get_pin_value_1(COL_1));
			return '1';
		}
	}
}