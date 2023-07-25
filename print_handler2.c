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

/**
 * print_octal - prints octal 
 * @args:  va_list the arguments list
 *
 * Return: length of printed string
 */
int print_octal(va_list *args, int *curr_index, char *buffer)
{
  unsigned int num, length, i;
  int base_8 = 8;
  char *octal_container = NULL;

  num = va_arg(*args, unsigned int);
  octal_container = base_handler(num, base_8, octal_container);

  if (!octal_container)
    return (0);

  length = _strlen(octal_container);

  for (i = 0; i < length; i++)
  {
    if (*curr_index < BUFFER_SIZE - 1)
    {
      buffer[*curr_index] = octal_container[i];
      (*curr_index)++;
    }
  }

  buffer[*curr_index] = '\0';
  free(octal_container);

  return (length);
}

/**
 * print_hexadecimal - prints hexadecimal 
 * @args:  va_list the arguments list
 *
 * Return: length of printed string
 */
int print_hexadecimal(va_list *args, int *curr_index, char *buffer)
{
  unsigned int num, length, i;
  char hexadecimal_container[33];
  char *hexadecimal;
  char *hex = "0123456789abcdef";

  num = va_arg(*args, unsigned int);
  hexadecimal = hexadecimal_handler(num, hexadecimal_container, hex);
  length = _strlen(hexadecimal);

  for (i = 0; i < length; i++)
  {
    if (*curr_index < BUFFER_SIZE - 1)
    {
      buffer[*curr_index] = hexadecimal_container[i];
      (*curr_index)++;
    }
  }

  return (length);
}

/**
 * print_hexadecimal_upper - prints hexadecimal upper
 * @args:  va_list the arguments list
 *
 * Return: length of printed string
 */
int print_hexadecimal_upper(va_list *args, int *curr_index, char *buffer)
{
  unsigned int num, length, i;
  char hexadecimal_container[33];
  char *hexadecimal;
  char *hex = "0123456789ABCDEF";

  num = va_arg(*args, unsigned int);
  hexadecimal = hexadecimal_handler(num, hexadecimal_container, hex);
  length = _strlen(hexadecimal);

  for (i = 0; i < length; i++)
  {
    if (*curr_index < BUFFER_SIZE - 1)
    {
      buffer[*curr_index] = hexadecimal_container[i];
      (*curr_index)++;
    }
  }

  return (length);
}

