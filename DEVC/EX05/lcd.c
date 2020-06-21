#include "sys.h"
unsigned char count = 0;
unsigned char lcd_init(void)
{
	Add();
	printf("lcd_init()\n");
	return 0;
}

unsigned char lcd_write(unsigned char value)
{
	printf("lcd = %d\n", value);
	return 0;
}

unsigned char lcd_read_count(void)
{
	return count;
}
