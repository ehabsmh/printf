#include "main.h"

/**
 * print_char - prints a character from argument list
 * @args: pointer to the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output
 *
 * Return: 1 byte
 */
int print_char(va_list args, int *curr_index, char *buffer)
{
	int c;

	c = va_arg(args, int);

	return (handle_buffer(c, buffer, curr_index));
}

/**
 * print_str - prints the string from argument list
 * @args: pointer to the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output
 *
 * Return: length of the string
 */
int print_str(va_list args, int *curr_index, char *buffer)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		handle_buffer(str[i], buffer, curr_index);
	}
	return (i);
}

/**
 * print_percent - prints a percent character
 * @args: unused
 * @curr_index: index of buffer
 * @buffer: stores the output
 *
 * Return: 1 byte
 */
int print_percent(va_list args __attribute__((unused)), int *curr_index,
									char *buffer)
{
	return (handle_buffer('%', buffer, curr_index));
}

/**
 * print_integer - prints an integer
 * @args: pointer to the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output * Return: length of the string
 *
 * Return: length
 */
int print_integer(va_list args, int *curr_index, char *buffer)
{
	int n, i;

	char *int_container = NULL;

	n = va_arg(args, int);

	int_container = int_to_str(n);

	/* fill the integer converted to string in the buffer */
	for (i = 0; int_container[i] != '\0'; i++)
	{
		handle_buffer(int_container[i], buffer, curr_index);
	}

	free(int_container);
	return (i);
}

/**
 * print_S - prints the string from argument list
 * @args: pointer to the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output * Return: length of the string
 *
 * Return: length of the string
 */
int print_S(va_list args, int *curr_index, char *buffer)
{
	int i, j;
	char *str = va_arg(args, char *);
	char *hex = "0123456789ABCDEF";
	char *hexadecimal;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (*curr_index < BUFFER_SIZE - 1)
		{
			if (str[i] < 32 || str[i] >= 127)
			{
				buffer[*curr_index] = '\\';
				(*curr_index)++;
				buffer[*curr_index] = 'x';
				(*curr_index)++;
				buffer[*curr_index] = '0';
				(*curr_index)++;
				hexadecimal = hexadecimal_handler(str[i], hexadecimal, hex);
				for (j = 0; hexadecimal[j] != '\0'; j++)
				{
					buffer[*curr_index] = hexadecimal[j];
					(*curr_index)++;
				}
			}
			else
			{
				buffer[*curr_index] = str[i];
				(*curr_index)++;
			}
		}
	}
	buffer[*curr_index] = '\0';
	return (i);
}
