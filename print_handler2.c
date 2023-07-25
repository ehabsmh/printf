#include "main.h"

/**
 * print_binary - prints binary digits
 * @args: pointer to the arguments list
 * @curr_index: index of buffer
 * @buffer: stores the output
 * Return: length of the string * Return: length of the string
 */
int print_binary(va_list args, int *curr_index, char *buffer)
{
	unsigned int num, length, i;

	char *binary_container = NULL;

	int base_2 = 2;

	num = va_arg(args, unsigned int);
	binary_container = base_handler(num, base_2, binary_container);
	length = _strlen(binary_container);

	for (i = 0; i < length; i++)
	{
		if (*curr_index < BUFFER_SIZE - 1)
		{
			buffer[*curr_index] = binary_container[i];
			(*curr_index)++;
		}

	}

	free(binary_container);

	buffer[*curr_index] = '\0';
	return (length);
}

/**
 * print_unsigned - prints unsigned int
 * @args:  va_list the arguments list
 *
 * Return: length of printed string
 */
int print_unsigned(va_list args, int *curr_index, char *buffer)
{
  unsigned int num, length, i;
  char unsigned_container[33];

  num = va_arg(args, unsigned int);

  length = unsigned_handler(num, unsigned_container);

  for (i = 0; i < length; i++)
  {
    if (*curr_index < BUFFER_SIZE - 1)
    {
      buffer[*curr_index] = unsigned_container[i];
      (*curr_index)++;
    }
  }

  return (length);
}
