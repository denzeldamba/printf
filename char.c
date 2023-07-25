#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Print formated output
 * @format: Format string to print
 *
 * Return: Number of characters to be printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
		}
			switch (*format)
			{
				case 'c':
					printed_chars += printf("%c", va_arg(arguments, int));
					break;
				case 's':
					printed_chars += printf("%s", va_args(arguments, char*));
					break;
				case '%':
					printed_chars += printf("%%");
					break;
				default:
					printed_chars += printf("%c", *format);
			}
			else
			{
				printed_chars += printf("%c", *format);
			}
			format++;
		}
		va_end(arguments);
		return (printed_chars);
}
