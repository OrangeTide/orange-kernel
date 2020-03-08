#ifndef HW_H_
#define HW_H_
#include <stdint.h>
void periph_wr32(uint32_t adr, uint32_t val);
uint32_t periph_rd32(uint32_t adr);
void delay(unsigned count);
void serial_init(void);
void serial_putc_raw(unsigned char ch);
void serial_putc(unsigned char ch);
unsigned char serial_getc(void);
void serial_puts(const char *s);
#endif
