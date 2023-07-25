#include <stdarg.h>
#include <stdio.h>
#include "main.h"

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
				case 'c':
					printed_chars += printf("%c", va_arg(arguments, int));
					break;
				case 's':
					printed_chars += printf("%s", va_arg(arguments, char *));
					break;
				case '%':
					printed_chars += printf("%%");
					break;
				case 'd':
					printed_chars += printf("%d", va_arg(arguments, int));
					break;
				case 'i':
					printed_chars += printf("%i", va_arg(arguments, int));
					break;
				case 'b':
					print_binary(va_arg(arguments, unsigned int));
					break;
				default:
					printed_chars += printf("%c", *format);
			}
		}
		else
			printed_chars += printf("%c", *format);
		format++;
	}
	va_end(arguments);
	return (printed_chars);
}

/**
 * print_binary - Print an unsigned int in binary
 * @n: Number to print in binary
 *
 * Return: Chars printed
 */
void print_binary(unsigned int n)
{
	int i;

	for (i = sizeof(n) * 8 - 1; i >= 0; i--)
	{
		putchar(n >> i & 1 ? '1' : '0');
	}
}
