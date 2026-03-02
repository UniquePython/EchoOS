void print_char(char c)
{
	__asm__ volatile (
		"movb $0x0E, %%ah \n"
		"int $0x10 \n"
		:
		: "a"(c)
	);
}

char read_char(void) {
    char c;
    __asm__ volatile (
        "movb $0x00, %%ah \n"
        "int $0x16        \n"
        : "=a"(c)
    );
    return c;
}

void kernel_main() {
    while(1) {
        char c = read_char();
        print_char(c);
    }
}
