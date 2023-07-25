#include "main.h"
#include <stdint.h>

/**
 * print_address - prints the address
 * @args:  va_list the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output
 *
 * Return: length of printed string
 */
int print_address(va_list args, int *curr_index, char *buffer)
{
	void *ptr;
	char *address, *hex = "0123456789abcdef";
	int num_zeroes, i;
	size_t num_digits;

	ptr = va_arg(args, void *);
	address = malloc(sizeof(char) * (64 + 1));

	if (address == NULL)
	{
		return (0);
	}

	hexadecimal_handler((uintptr_t)ptr, address, hex);

	num_digits = sizeof(void *) * 2;
	num_zeroes = num_digits - _strlen(address);

	for (i = 0; i < num_zeroes; i++)
	{
		if (*curr_index < BUFFER_SIZE - 1)
		{
			buffer[*curr_index] = '0';
			(*curr_index)++;
		}
	}

	for (i = 0; address[i] != '\0'; i++)
	{
		if (*curr_index < BUFFER_SIZE - 1)
		{
			buffer[*curr_index] = address[i];
			(*curr_index)++;
		}
	}

	buffer[*curr_index] = '\0';
	free(address);

	return (i);
}

/**
 * print_reverse - prints reversed string
 * @args:  va_list the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output
 *
 * Return: length of printed string
 */
int print_reverse(va_list args, int *curr_index, char *buffer)
{
	int i;
	int str_len;
	char *str_cpy;

	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	str_len = _strlen(str);

	str_cpy = malloc(sizeof(char) * (str_len + 1));
	if (str_cpy == NULL)
		return (0);


	_strcpy(str_cpy, str);

	rev_string(str_cpy);

	for (i = 0; str_cpy[i] != '\0'; i++)
	{
		if (*curr_index < BUFFER_SIZE - 1)
		{
			buffer[*curr_index] = str_cpy[i];
			(*curr_index)++;
		}
	}
	buffer[*curr_index] = '\0';
	return (i);
}

/**
 * print_rot13 - prints rot13 of a string
 * @args:  va_list the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output
 *
 * Return: length of printed string
 */
int print_rot13(va_list args, int *curr_index, char *buffer)
{
	char *str;
	int str_len, i;
	char *str_cpy;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	str_len = _strlen(str);

	str_cpy = malloc(sizeof(char) * (str_len + 1));
	if (str_cpy == NULL)
		return (0);

	_strcpy(str_cpy, str);

	rot13(str_cpy);

	for (i = 0; str_cpy[i] != '\0'; i++)
	{
		if (*curr_index < BUFFER_SIZE - 1)
		{
			buffer[*curr_index] = str_cpy[i];
			(*curr_index)++;
		}
	}
	buffer[*curr_index] = '\0';
	return (i);

}
