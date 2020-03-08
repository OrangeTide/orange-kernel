.PHONY : all clean
all : all.rpi2 # all.rpi1 all.rpi3
clean : clean.rpi2 # clean.rpi1 clean.rpi3
emu : emu.rpi2
all.% : Makefile.%
	$(MAKE) -f Makefile.$* all
emu.% : Makefile.%
	$(MAKE) -f Makefile.$* emu
clean.% : Makefile.%
	$(MAKE) -f Makefile.$* clean
