#include "gpio.h"


void init_pin_0(int pin)
{
    IO0DIR |= (1 << pin);
}


void init_pin_1(int pin)
{
    IO1DIR |= (1 << pin);
}


int get_pin_value_0(int pin)
{
    return (IO0PIN & (1 << pin));
}


int get_pin_value_1(int pin)
{
    return (IO1PIN & (1 << pin));
}


void set_pin_value(int pin, int status)
{
    *(status ? &IO0CLR : &IO0SET) |= (1 << pin);
}