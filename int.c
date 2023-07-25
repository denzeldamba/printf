#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list arguments;

	va_start(arguments, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'i':
					printed_chars += printf("%i", va_arg(arguments, int));
					break;
				case 'd':
					printed_chars += printf("%d", va_arg(arguments, int));
					break;
			}
		}
		format++;
	}

	va_end(arguments);
	return (printed_chars);
}
