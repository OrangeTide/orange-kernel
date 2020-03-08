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

unsigned orange_version = 0x0100;

static void
print_a_to_z(void)
{
	unsigned i;

	serial_putc('\n');
	for (i = 'A'; i <= 'Z'; i++) {
		serial_putc(i);
	}
	serial_putc('\n');
}

static void
print_num(unsigned n)
{
	/* convert number into ASCII characters from right-to-left */
	char buf[20];
	unsigned i = sizeof(buf);
	do {
		buf[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);

	/* print left-to-right */
	for (;i < sizeof(buf); i++) {
		serial_putc(buf[i]);
	}
}

static
void
print_version(void)
{
	/* print the version number */
	serial_putc('V');
	serial_putc('e');
	serial_putc('r');
	print_num(orange_version / 256);
	serial_putc('.');
	print_num(orange_version % 256);
	serial_putc('\n');
}

static
void
print_pc(void)
{
	uint32_t pc;

	asm("mov %0, lr" : "=r" (pc) : );

	/* print the PC */
	serial_putc('P');
	serial_putc('C');
	serial_putc('=');
	print_num(pc);
	serial_putc('\n');
}

void
kernel_start(void)
{
	serial_init();

	print_version();

	serial_puts("Hello World!\n");

	print_pc();

	delay(100000000);

	print_a_to_z();

	// TODO: we shouldn't return ...
}
