### cross-compile configuration
CC = ${TOOLPREFIX}gcc
AS = ${TOOLPREFIX}as
LD = ${TOOLPREFIX}ld
OBJCOPY = ${TOOLPREFIX}objcopy
OBJDUMP = ${TOOLPREFIX}objdump
STRIP = ${TOOLPREFIX}strip
AR = ${TOOLPREFIX}ar
RANLIB = ${TOOLPREFIX}ranlib

### Rules

%.img : %.elf
	$(OBJDUMP) -d -s $< > $*.list
	$(OBJCOPY) $< -O binary $*.img

%.dis : %.img
	arm-none-eabi-objdump -b binary -D -marm $< > $@

# %.elf : %.o
#	$(LD) $^ -T ${KERNEL_LDS} -o $@

### macros & functions

# turns source filenames into .o filenames
src2objs = $(patsubst %.S,%.o,$(patsubst %.s,%.o,$(patsubst %.cpp,%.o,$(patsubst %.c,%.o,$1))))
