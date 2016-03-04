/**
    GPIO driver
*/


#include <targets/LPC2000.h>


void init_pin_0(int pin);

void init_pin_1(int pin);

int get_pin_value_0(int pin);

int get_pin_value_1(int pin);

void set_pin_value(int pin, int status);