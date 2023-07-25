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

	if (*curr_index < BUFFER_SIZE - 1)
	{
		buffer[*curr_index] = c;
		(*curr_index)++;
	}

	buffer[*curr_index] = '\0';

	return (1);
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
		if (*curr_index < BUFFER_SIZE - 1)
		{
			buffer[*curr_index] = str[i];
			(*curr_index)++;
		}
	}
	buffer[*curr_index] = '\0';
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

	if (*curr_index < BUFFER_SIZE - 1)
	{
		buffer[*curr_index] = '%';
		(*curr_index)++;
	}
	buffer[*curr_index] = '\0';
	return (1);
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

	int_container = int_to_str(n, int_container);

	/* fill the integer converted to string in the buffer */
	for (i = 0; int_container[i] != '\0'; i++)
	{
		if (*curr_index < BUFFER_SIZE - 1)
		{
			buffer[*curr_index] = int_container[i];
			(*curr_index)++;
		}
	}

	buffer[*curr_index] = '\0';

	free(int_container);
	return (i);
}
