/* hacks around bugs in qemu raspi2 emulation */
MEMORY
{
	ram : ORIGIN = 0x10000, LENGTH = 0x100000
}

SECTIONS
{
	START : { vectors.o } > ram
	.text : { *(.text*) } > ram
	.rodata : { *(.rodata .rodata.* .gnu.linkonce.r*) } > ram
	.data : { *(.data .data.*) } > ram
	.bss (NOLOAD) : { *(.bss .bss.*) } > ram
}

