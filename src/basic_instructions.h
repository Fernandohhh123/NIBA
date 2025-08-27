#ifndef BASIC_INSTRUCTIONS_C
#define BASIC_INSTRUCTIONS_C

typedef enum{
	NOT = 0x00,
	NAND = 0x10,
	ADD = 0x20,
	LDA = 0x30,
	OUTA = 0x40,
	OUTB = 0x50,
	INA = 0x60,
	RD = 0x70,
	RA = 0x80,
	LDRA = 0x90,
	JPI = 0xC0,
	JPC = 0xD0,
	JPZ = 0xE0
}Basic_Instructions;

#endif
