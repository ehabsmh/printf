#include "main.h"

/**
 * format_handler - handling the format
 * @args: va_list
 * @format: the string at the first argument
 *
 * Return: length of the output
*/
int format_handler(va_list args, const char *format)
{
	int i, j, output_len = 0, buffer_index = 0;
	int (*ptr)(va_list, int *, char *);
	char buffer[BUFFER_SIZE];

	fmt format_sp[] = {
			{'c', print_char}, {'s', print_str}, {'%', print_percent},
			{'d', print_integer}, {'i', print_integer}, {'b', print_binary},
			{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
			{'X', print_hexadecimal_upper}, {'S', print_S}, {'p', print_address},
			{'r', print_reverse}, {'R', print_rot13},
			{'\0', NULL}};
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; format_sp[j].specifier != '\0'; j++)
			{
				if (format[i] == format_sp[j].specifier)
				{
					ptr = format_sp[j].print_format;
					output_len += (*ptr)(args, &buffer_index, buffer);
					break;
				}
			}
		}
		else
		{
			if (buffer_index < BUFFER_SIZE - 1)
			{
				buffer[buffer_index] = format[i];
				buffer_index++;
			}
			output_len++;
		}
	}
	buffer[buffer_index] = '\0';
	write(1, buffer, buffer_index);
	return (output_len);
}
