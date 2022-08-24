#ifndef _MAIN_H_
#define _MAIN_H_
#define <stdarg.h>

typedef struct Cspecs {
	char cs;
	void (*f)();
} cs_t;

void _putchar_c(char c);
void _putchar(va_list a);
void print_str(va_list a);
int _printf(const char *format, ...);

#endif
