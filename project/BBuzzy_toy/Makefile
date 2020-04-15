# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

all: blink.elf
#additional rules for files

blink.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o switches.o buzzer.o buzzyMain.o blink.o song.o    switch_leds_assembly.o toggle_red.o stateMachines.o switch_machine.o led.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blink.elf
	msp430loader.sh blink.elf

clean:
	rm -f *.o *.elf


led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h
stateMachines.o: led.h stateMachines.h

buzzer.c: buzzer.h
buzzyMain.c: buzzer.h
