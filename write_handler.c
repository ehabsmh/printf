#include "main.h"

/**
 * int_to_str - converting integer to string
 * @n: the number to be converted
 *
 * Return: length of n plus the sign if n is negative
 */
char *int_to_str(int n)
{
	char *converted_str;
	int n_len = n == 0 ? 1 : 0;
	int is_negative = n < 0 ? 1 : 0;
	int abs_n = n < 0 ? -n : n;
	int n_power = 1, i = 0;

	while (abs_n / n_power > 0)
	{
		n_len++;
		n_power *= 10;
	}

	converted_str = malloc((n_len + is_negative + 1) * sizeof(char));
	if (!converted_str)
		return (NULL);

	if (is_negative)
		converted_str[i++] = '-';

	n_power /= 10;
	while (n_power > 0)
	{
		int digit = abs_n / n_power;

		converted_str[i++] = digit + '0';
		abs_n %= n_power;
		n_power /= 10;
	}

	converted_str[i] = '\0';
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

	if (n == 0)
	{
		converted_str = malloc(sizeof(char) * 2);
		if (!converted_str)
			return (NULL);

		converted_str[0] = '0';
		converted_str[1] = '\0';
		return (converted_str);
	}

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
		digit = n % base;

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
	unsigned int len_calculator = n, n_len = 0;
	unsigned int digit = n, n_power, i = 0;

	while (len_calculator)
	{
		n_len++;
		len_calculator /= 10;
	}

	if (n == 0)
	{
		converted_str[0] = '0';
		converted_str[1] = '\0';
		return (1);
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
	unsigned int i = 0, digit, n_cpy = n;

	if (n == 0)
	{
		converted_str = malloc(sizeof(char) * 2);
		if (converted_str == NULL)
			return (NULL);

		converted_str[0] = '0';
		converted_str[1] = '\0';
		return (converted_str);
	}

	while (n_cpy)
	{
		n_cpy /= 16;
		i++;
	}

	converted_str = malloc(sizeof(char) * (i + 1));
	if (!converted_str)
		return (NULL);

	i = 0;
	while (n)
	{
		digit = n % 16;

		converted_str[i] = hex[digit];
		n /= 16;
		i++;
	}

	rev_string(converted_str);
	converted_str[i] = '\0';
	return (converted_str);
}
