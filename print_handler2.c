#include "main.h"

/**
 * print_binary - prints binary digits
 * @args: pointer to the arguments list
 *
 * Return: length of the string
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
    buffer_filler(binary_container[i], buffer, *curr_index);
  }

  free(binary_container);

  buffer[*curr_index] = '\0';
  return (length);
}
