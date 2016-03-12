/*
    LPC2124 NFC Reader/Writer
*/

#include <stdio.h>
#include <libarm.h>
#include <targets/LPC2000.h>

#include "keypad.h"
#include "HD44780U.h"
#include "PN532.h"
#include "i2c.h"


/**
    The main function.
    This is called on startup and contains the main loop.
*/
int main(void)
{        
    LCD_Init();
    LCD_Clear();
    Keypad_Init();
    i2c_Init();
    PN532_init();
        
    char c;
    int writeMode = 0;
    char buffer[32] = "";

    while (1) {

        c = Keypad_WaitAndGetKey();        

        // * key pressed: toggle write mode
        if (c == '*') {
            LCD_ClearBuffer();
            buffer[0] = '\0';
            writeMode = 1 - writeMode;
            LCD_WriteString(writeMode ? "Write mode..." : "Write ended.");
        }

        // # key pressed while not in write mode: read from NFC
        else if (c == '#' && !writeMode) {
              
            LCD_WriteString("Read from NFC...");
              
            if (readStringFromNFC(buffer)) {
                LCD_WriteString(buffer); 
            } else {
               LCD_WriteString("No Data"); 
            }
              
        }

        // any key other than * pressed while in write mode: write to NFC
        else if (writeMode) {
            LCD_AppendCharToScreen(c);

            int len = strlen(buffer);
            buffer[len] = c;
            buffer[len + 1] = '\0';
            if (!writeStringToNFC(buffer)) {
                LCD_WriteString("Error 63."); 
            }
        }
        
        // otherwise: just show the pressed key
        else {
            LCD_AppendCharToScreen(c);
        }    
    }
}
