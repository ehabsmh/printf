/**
 * _printf - formatted output conversion and print data.
 * @format: input char.
 *
 * Return: number of characters printed.
 */
#include "main.h"

int _printf(const char *format, ...)
{
	int output_len = 0;
	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	output_len = format_handler(args, format);
	/* flags */
	/* width */
	/* precision */
	va_end(args);

	return (output_len);
}
