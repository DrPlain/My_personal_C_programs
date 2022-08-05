#include "main.h"
#include <stdarg.h>

int _printf(const char * const format, ...)
{
    va_list args;
    int i = 0;
    int num_displayed = 0;
    char *pstr;
    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            num_displayed++;
        }
        else
        {
            if (format[i + 1] == 'c')
            {
                _putchar(va_arg(args, int));
                num_displayed++;
                i++;
            }
            else if (format[i + 1] == 's')
            {
                pstr = va_arg(args, char *);
                while (*pstr != '\0')
                {
                    _putchar(*pstr);
                    num_displayed++;
                    pstr++;
                }
                i++;
            }
            else if (format[i + 1] == 'i')
            {
                _putchar(va_arg(args, int));
                num_displayed++;
                i++;
            }
            else if (format[i + 1] == '%')
            {
                _putchar(format[i]);
                num_displayed++;
                i++;
            }
        }
        i++;
    }
    va_end(args);
    return (num_displayed);
}