#include "main.h"

/**
 * rot13 - translate the string to rot13
 * @s: string to be translated
 *
 * Return: pointer to character
*/
char *rot13(char *s)
{
	int i, j;

	char *letters = "ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz";
	char *letters2 = "NOPQRSTUVWXYZnopqrstuvwxyzABCDEFGHIJKLMabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = letters2[j];
				break;
			}
		}
	}
	return (s);
}
