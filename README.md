# LK IoT

This is a personal experiment using [Little Kernel](https://github.com/littlekernel/lk) building IoT apps with STM32 boards.

## Prerequisite

Depends on what the project you build. The default project (blink) requires this minimum software and hardware.

**Hardware**

- Development board: SMT32F103C8T6 Cortex M3 Blue Pill board
- Programmer: ST-Link V2
- Some

**Software**

- The ARM toolchain
- STMicroelectronics Stlink Tools

If you are Mac user and terminal is your style:

```bash
brew tap osx-cross/arm
brew install arm-gcc-bin
brew install stlink
```

### Setup and build

```
mkdir lk_root
cd lk_root
git clone https://github.com/littlekernel/lk.git
git clone https://github.com/jacobdam/lk-iot-apps.git
cd lk-iot-apps
cp lk_inc.mk.example lk_inc.mk
make blink-led
```

Read [LK wiki](https://github.com/littlekernel/lk/wiki) for more information.

