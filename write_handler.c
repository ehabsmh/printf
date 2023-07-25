#include "main.h"

/**
 * int_to_str - converting integer to string
 * @n : the number to be converted
 * @converted_str: to store the converted integer
 *
 * Return: length of n plus the sign if n is negative
 */
char *int_to_str(int n, char *converted_str)
{
	int n_len = 0, is_negative = 0, n_copy, i;

	if (n == 0)
	{
		converted_str[0] = '0';
		converted_str[1] = '\0';
		return (converted_str);
	}

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	/* Calculate the length of the number */
	n_copy = n;
	while (n_copy)
	{
		n_len++;
		n_copy /= 10;
	}

	/* Start filling the converted_str buffer */
	i = n_len + is_negative;
	converted_str[i] = '\0';

	while (i-- > is_negative)
	{
		converted_str[i] = n % 10 + '0';
		n /= 10;
	}

	if (is_negative)
		converted_str[0] = '-';

	return (converted_str);
}
