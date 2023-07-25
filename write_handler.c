#include "main.h"

/**
 * int_to_str - converting integer to string
 * @n: the number to be converted
 * @converted_str: to store the converted integer
 *
 * Return: length of n plus the sign if n is negative
 */
char *int_to_str(int n, char *converted_str)
{
	int len_calculator, n_len = 0, abs_n = n, i = 0;
	int n_power, is_negative = 0;

	len_calculator = n;

	while (len_calculator)
	{
		n_len++;
		len_calculator /= 10;
	}

	if (n < 0)
	{
		is_negative = 1;
		abs_n = -n;
		n = -n;
	}
	converted_str = malloc(sizeof(char) * (n_len + is_negative + 1));
	if (!converted_str)
		return (0);

	if (n == 0)
	{
		converted_str[0] = '0';
		converted_str[1] = '\0';
		return (converted_str);
	}
	if (is_negative)
		converted_str[0] = '-';
	n_power = power_of_10(n_len);
	while (i < n_len)
	{
		n_power /= 10;
		abs_n = n / n_power;
		abs_n %= 10;
		converted_str[i + is_negative] = abs_n + '0';
		i++;
	}
	converted_str[i + is_negative] = '\0';
	return (converted_str);
}

/**
 * base_handler - converts the number to a specified base
 * @n: the number to be converted
 * @base: the base to be converted to
 * @converted_str: converted string
 *
 * Return: address of the string
*/
char *base_handler(unsigned int n, int base, char *converted_str)
{

	unsigned int i = 0, digit, n_cpy = n;

	/* store 0 in the converted_str if n is 0 */
	if (n == 0)
	{
		converted_str = malloc(sizeof(char) * 2);
		converted_str[0] = '0';
		converted_str[1] = '\0';
		return (converted_str);
	}

	/* calculate the length */
	while (n_cpy)
	{
		n_cpy /= base;
		i++;
	}

	converted_str = malloc(sizeof(char) * (i + 1));

	if (!converted_str)
		return (NULL);

	i = 0;

	while (n)
	{
		/* Extract the base digit */
		digit = n % base;

		/* Store it in the converted_str */
		converted_str[i] = digit + '0';
		n /= base;
		i++;
	}

	rev_string(converted_str);
	converted_str[i] = '\0';
	return (converted_str);
}

/**
 * unsigned_handler - converting integer to string
 * @n : the number to be converted
 * @converted_str: the converted_str to store the converted integer
 *
 * Return: length of n plus the sign if n is negative
 */
unsigned int unsigned_handler(unsigned int n, char *converted_str)
{
	unsigned int tens = 10, len_calculator = n, n_len = 0;
	unsigned int digit = n, n_power, i = 0;


	if (n == 0)
	{
		converted_str[0] = '0';
		return (1);
	}

	while (len_calculator)
	{
		n_len++;
		len_calculator /= tens;
	}

	n_power = power_of_10(n_len);

	while (i < n_len)
	{
		n_power /= 10;
		digit = n / n_power;
		digit %= 10;
		converted_str[i] = digit + '0';
		i++;
	}

	return (n_len);
}

/**
 * hexadecimal_handler - converting integer to hexadecimal
 * @n : the number to be converted
 * @converted_str: the converted_str to store the converted hex
 *@hex: the hexcode
 * Return: the converted string
 */
char *hexadecimal_handler(unsigned int n, char *converted_str, char *hex)
{
	unsigned int i = 0;
	unsigned int digit = 0;

	/* store 0 in the converted_str if n is 0 */
	if (n == 0)
	{
		converted_str[0] = '0';
		converted_str[1] = '\0';
		return (converted_str);
	}

	/* convert integer to its base */
	while (n)
	{
		/* Extract the base digit */
		digit = n % 16;

		/* Store it in the converted_str */
		converted_str[i] = hex[digit];

		n /= 16;
		i++;
	}

	rev_string(converted_str);
	converted_str[i] = '\0';

	return (converted_str);
}
