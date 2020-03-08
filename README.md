# Orange Kernel

## Introduction

A small kernel for booter games, micro applications, and dedicated emulators.

## Status

It's a "Hello World"

## Goals

Support goals:
  * support complete set of Raspberry Pi products.
  * support i686 PC (Pentium II or better)
  * support x86\_64 (AMD and Intel)

Strech goals:
  * Allwinner A64
    * Banana Pi BPI-M64
    * Pine A64

Not supported:
  * Intel Celeron J4105
    * Odroid H2
  * Intel Celeron J3160
  * Intel Celeron 2955U
    * HP Chromebox CB1
  * Intel Celeron 3865U
    * ASUS Chromebox 3 (N017U)
  * Qualcomm IPQ4019
    * Google Nest Wifi (gen1)
  * Qualcomm QCS404 & QCS405
    * Google Nest Wifi (gen2)
  * Samsung Exynos5422
    * Odroid XU4
  * Amlogic S905
    * Odroid C2
  * Amlogic S805
    * Odroid C1+
  * Allwinner A20
    * Banana Pi BPI-M1
  * Allwinner H3
    * Banana Pi BPI-M2+
  * Allwinner H2+
    * Banana Pi BPI-M2 Zero
    * Banana Pi BPI-P2 Zero
  * Allwinner R40/V40
    * Banana Pi BPI-M2 Ultra
    * Banana Pi BPI-M2 Berry
  * Allwinner R16
    * Banana Pi BPI-M2 Magic
  * Allwinner A83t
    * Banana Pi BPI-M3
  * Realtek RTD1395
    * Banana Pi BPI-M4

# Building

By default the system builds for RPi2. Some tweaking can target RPi1. And significant reworking can be used for RPi3.

## Prerequisites

### Debian
```
apt install binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi
```

### Arch

```
sudo pacman -S arm-none-eabi-{gcc,binutils,gdb,newlib}
```

### see also

 * libnewlib-doc
 * libnewlib-nano-arm-none-eabi
 * libstdc++-arm-none-eabi-newlib

## Make

```
make
```

# Running

```
make emu
```

# Hardware

| Supported? | Board               | SoC     | CPU        | Speed   | ISA     |
| --- | ------------------- | ------- | ---------- | ------- | ------- |
| :x: | Raspberry Pi 1      | BCM2835 | ARM1176    | 700 MHz | ARMv6Z  |
| :heavy_check_mark: | Raspberry Pi 2 V1.1 | BCM2836 | Cortex-A7  | 900 MHz | ARMv7-A |
| :x: | Raspberry Pi 2 V1.2 | BCM2837 | Cortex-A53 | 900 MHz | ARMv8-A |
| :x: | Raspberry Pi 3 B/B+ | BCM2837 | Cortex-A53 | 1.2 GHz | ARMv8-A |
| :x: | Raspberry Pi Zero   | BCM2835 | ARM1176    | 1 GHz   | ARMv6Z  |
| :x: | Raspberry Pi Zero W | BCM2835 | ARM1176    | 1 GHz   | ARMv6Z  |
| :x: | Raspberry Pi 4      | BCM2711 | Cortex-A72 | 1.5 GHz | ARMv8-A |

# See Also

## Hardware Documentation

 * [BCM2835](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2835/README.md)
   * [ARM1176JZF-S Technical Reference Manual](http://infocenter.arm.com/help/topic/com.arm.doc.ddi0301h/DDI0301H_arm1176jzfs_r0p7_trm.pdf)
   * [BCM2835 datasheet errata](https://elinux.org/BCM2835_datasheet_errata)
   * [BCM2835 GPIOs](https://elinux.org/RPi_BCM2835_GPIOs)
 * [BCM2836](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2836/README.md)
   * [Cortex-A7 MPcore TRM](http://infocenter.arm.com/help/topic/com.arm.doc.ddi0464f/DDI0464F_cortex_a7_mpcore_r0p5_trm.pdf)
   * [BCM2836 ARM-local peripherials](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2836/QA7_rev3.4.pdf)
 * [BCM2837](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2837/README.md)
   * [Cortex-A53 MPcore TRM](http://infocenter.arm.com/help/topic/com.arm.doc.ddi0500d/DDI0500D_cortex_a53_r0p2_trm.pdf)

## Software Documentation

 * [Booting ARM Linux](http://www.simtec.co.uk/products/SWLINUX/files/booting_article.html)
 * [Procedure Call Standards for the ARM Architecture](https://developer.arm.com/docs/ihi0042/latest)

## Links

 * [TinyOS](http://www.tinyos.net/)
 * [RIOT](http://www.riot-os.org/)
 * [Bare metal Raspberry Pi 3 tutorials](https://github.com/bztsrc/raspi3-tutorial)
 * [Raspberry Pi OS](https://github.com/s-matyukevich/raspberry-pi-os)
 * [Xv6](https://pdos.csail.mit.edu/6.828/2019/xv6.html), a simple Unix-like teaching operating system
 * [COHERENT Unix source](http://www.nesssoftware.com/home/mwc/source.php)
 * [LiteOS](https://www.huawei.com/liteos)
 * [NarcOS](https://github.com/forkachild/NarcOS), Bare metal ultralight kernel for Raspberry Pi 3 (BCM2837)
 * [github.com/multipi](https://github.com/jeffreyantony/multipi), Multi Core examples for Raspberry Pi 2
