#include "main.h"

/**
 * handle_buffer - Storing the charaters in the buffer
 * @c: The character to store
 * @buffer: The buffer
 * @buff_i: The buffer index
 *
 * Return: index
 */
int handle_buffer(char c, char *buffer, int *buff_i)
{
	if (*buff_i >= BUFFER_SIZE)
	{
		write(1, &buffer, *buff_i);
		*buff_i = 0;
	}
	else
	{
		buffer[*buff_i] = c;
		(*buff_i)++;
	}
	return (1);
}
