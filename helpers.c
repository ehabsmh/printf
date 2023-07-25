#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Evaluates the length of a string
 * @s: array of strings
 *
 * Return: the length of the string
 */

int _strlen(char *s) /* char *s = str; */
{
	unsigned int str_len = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		str_len++;
	}

	return (str_len);
}

/**
 * power_of_10 - returns the power of 10 raised to n
 * @n_len: the length of the number to be raised
 *
 * Return: power of 10, n times
 */
int power_of_10(int n_len)
{
	int i, x = 1;

	for (i = 0; i < n_len; i++)
	{
		x = x * 10;
	}
	return (x);
}

/**
 * rev_string - prints a reversed string
 * @s: string to be printed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i, len = 0, temp;

	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}

	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

/**
 * _strcpy - copies the string pointed to by src
 * to the buffer pointed to by dest
 * @dest: Pointer to the buffer
 * @src: pointer to string
 *
 * Return: pointer to the string which copied
 */

char *_strcpy(char *dest, char *src)
{
	char *str;

	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	str = dest;

	return (str);
}
