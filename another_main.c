#include "stdio.h"
#include <libarm.h>
#include <targets/LPC2000.h>

#include <Membrane_Switch/keypad.h>
#include <LPC-2124-HD44780U-Display-Driver/HD44780U.h>


int main(void) {
        
        LCD_Init();
        LCD_Clear();
        Keypad_Init();

        char c;

        while (true)
        {
            c = Keypad_WaitAndGetKey();
            LCD_AppendCharToScreen(c);
        }
}
