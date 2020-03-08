include common.mk

TOOLPREFIX = arm-none-eabi-

CFLAGS = -Wall -W -O2 -nostdlib -nostartfiles -ffreestanding
LDFLAGS = -nostdlib -nostartfiles
ARFLAGS = rvU

.PHONY : all clean emu
all :: ${KERNEL}
clean ::
	$(RM) ${KERNEL}
