extern kernel_main

BITS 16

MOV AX, 0x0000
MOV SS, AX
MOV SP, 0x7C00

CALL kernel_main

hang:
	JMP hang
