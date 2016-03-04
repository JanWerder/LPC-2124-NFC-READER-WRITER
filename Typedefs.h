#ifndef __TYPEDEFS_h__
#define __TYPEDEFS_h__

#include<targets/lpc2000.h>

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef unsigned short int uint16;
typedef signed char int8;
typedef signed short int int16;
typedef signed int int32;
typedef signed short int bool;

#define false -1
#define true   1

typedef struct {
    short unsigned int MSEL_BIT :4;
    short unsigned int PSEL_BIT :2;
}PLLCON_REG;


#endif