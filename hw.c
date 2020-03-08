/*
 * Copyright (c) 2020 Jon Mayo
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 */
#include "hw.h"
#include <stdint.h>

#if defined(CONFIG_RPI3) || defined(CONFIG_RPI2)
#  define PBASE 0x3F000000
#elif defined(CONFIG_RPI1)
#  define PBASE 0x20000000
#else
#  error Must define CONFIG_RPI1, CONFIG_RPI2, or CONFIG_RPI3
#endif

#define GPFSEL1 0x200004
#define GPSET0 0x20001C
#define GPCLR0 0x200028
#define GPPUD 0x200094
#define GPPUDCLK0 0x200098

#define AUX_ENABLES 0x215004
#define AUX_MU_IO_REG 0x215040
#define AUX_MU_IER_REG 0x215044
#define AUX_MU_IIR_REG 0x215048
#define AUX_MU_LCR_REG 0x21504C
#define AUX_MU_MCR_REG 0x215050
#define AUX_MU_LSR_REG 0x215054
#define AUX_MU_MSR_REG 0x215058
#define AUX_MU_SCRATCH 0x21505C
#define AUX_MU_CNTL_REG 0x215060
#define AUX_MU_STAT_REG 0x215064
#define AUX_MU_BAUD_REG 0x215068

void
periph_wr32(uint32_t adr, uint32_t val)
{
	*(uint32_t*)(uintptr_t)(PBASE + adr) = val;
}

uint32_t
periph_rd32(uint32_t adr)
{
	return *(uint32_t*)(uintptr_t)(PBASE + adr);
}

void
delay(unsigned count)
{
	while (count) {
		asm volatile("nop");
		count--;
	}
}

void
serial_putc_raw(unsigned char ch)
{
	while ((periph_rd32(AUX_MU_LSR_REG) & 0x20) == 0)
		asm volatile("nop");
	periph_wr32(AUX_MU_IO_REG, ch);
}

void
serial_putc(unsigned char ch)
{
	/* convert LF to CR/LF pair */
	if (ch == '\n')
		serial_putc_raw('\r');
	serial_putc_raw(ch);
}

unsigned char
serial_getc(void)
{
	while ((periph_rd32(AUX_MU_LSR_REG) & 0x01) == 0)
		asm volatile("nop");
	return periph_rd32(AUX_MU_IO_REG);
}

void
serial_puts(const char *s)
{
	while (*s) {
		serial_putc(*s);
		s++;
	}
}

void
serial_init(void)
{
	/* UART initialize : enable, 8N1, 115000bps */
	periph_wr32(AUX_ENABLES, 1u); /* enable UART1 */
	periph_wr32(AUX_MU_IER_REG, 0);
	periph_wr32(AUX_MU_CNTL_REG, 0);
	periph_wr32(AUX_MU_LCR_REG, 3u); /* 8 */
	periph_wr32(AUX_MU_MCR_REG, 0);
	periph_wr32(AUX_MU_IER_REG, 0);
	periph_wr32(AUX_MU_IIR_REG, 0xC6u); /* disable interrupts */
	periph_wr32(AUX_MU_BAUD_REG, 270u); /* 115200 bps */

	/* route UART1 to GPIOs */
	uint32_t tmp = periph_rd32(GPFSEL1);
	tmp &= ~((7u << 12) | (7u << 15)); //gpio14, gpio15
	tmp |= (2u << 12) | (2u << 15);    //alt5
	periph_wr32(GPFSEL1, tmp);

	periph_wr32(GPPUD, 0); /* enable pin 14 and 15 */
	delay(150);
	periph_wr32(GPPUDCLK0, (1u << 14) | (1u << 15));
	delay(150);
	periph_wr32(GPPUDCLK0, 0);

	periph_wr32(AUX_MU_CNTL_REG, 3u); /* enable Tx/Rx */
}
