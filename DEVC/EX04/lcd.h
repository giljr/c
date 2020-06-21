#ifndef __LCD__H__
#define __LCD__H__
#include "calc.h"
unsigned char lcd_init(void);
unsigned char lcd_write(unsigned int value);
unsigned char led_read_count(void);
#endif
