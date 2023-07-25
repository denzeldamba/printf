#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
  va_list args;
  va_start(args, format);

  int chars_printed = 0;
  
 	while (*format != '\0') {
    	if (*format == '%') {
      			format++;
      	switch (*format) {
        case 'b':
          chars_printed += print_binary(va_arg(args, unsigned int));
        break;
        default:
        	format++; 
        break;
      }
    } else {
        chars_printed += printf("%c", *format);
        	format++;
    }
  }

  	va_end(args);
  return chars_printed;
}

int print_binary(unsigned int n) {
  int i, chars_printed = 0;

  for (i = sizeof(n) * 8 - 1; i >= 0; i--) {
    	chars_printed += printf("%d", (n >> i) & 1);
  }
  
  return chars_printed;
}
