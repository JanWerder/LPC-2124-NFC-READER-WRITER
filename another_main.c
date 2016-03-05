/**
    NFC Reader/Writer
    J./E./J., 2016

    This does stuff.
*/


#include "gpio/gpio.h"
#include "keypad/keypad.h"
#include "lcd/lcd.h"

#include <stdio.h>
#include <libarm.h>


int main(void)
{
    LCD_Init();
    LCD_Clear();
    Keypad_Init();

    char c;

    while (true) {
        c = Keypad_WaitAndGetKey();
        LCD_AppendCharToScreen(c);
    }
}
