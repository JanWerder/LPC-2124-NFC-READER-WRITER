#include "stdio.h"
#include <libarm.h>
#include <stdbool.h>
#include <targets/LPC2000.h>
#include <keypad.h>


int main(void) {
        
        LCD_Init();
        LCD_Clear();

        char c;

        init_keypad();
        while (true)
        {
            LCD_Init();
            c = wait_and_get_key();
            LCD_WriteChar(c);
        }
}