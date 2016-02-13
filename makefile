 #Makfile Clock
SOURCE = source/c-data/main.c source/c-data/number.c source/h-data/number.h source/c-data/display.c source/h-data/display.h source/c-data/time.c source/h-data/time.h
OBJ = source/o-data/main.o source/o-data/number.o source/o-data/display.o source/o-data/time.o
ELF = source/elf-data/clock.elf
HEX = source/hex-data/clock.hex
MCU = atmega8515
all: clock clock_elf clock_hex

clock: $(SOURCE)
	avr-gcc -g -Os -mmcu=$(MCU) -c $(SOURCE)
	mv main.o source/o-data/main.o
	mv number.o source/o-data/number.o
	mv display.o source/o-data/display.o
	mv time.o source/o-data/time.o
clock_elf: clock $(OBJ)
	avr-gcc -g -mmcu=$(MCU) -o source/elf-data/clock.elf $(OBJ)
clock_hex: $(ELF)
	avr-objcopy -j .text -j .data -O ihex $(ELF) source/hex-data/clock.hex

programm:
	avrdude -c stk500v2 -p m8515 -P /dev/ttyACM0 -U flash:w:source/hex-data/clock.hex
