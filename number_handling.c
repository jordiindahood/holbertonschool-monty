#include "monty.h"
/**
 * _atoi - check the code
 * Description: convert a string to integer
 * @s: pointer to string
 * Return: vaule converted from string
 */
int _atoi(char *s)
{
	unsigned int res = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			res = (res * 10) + (*s - '0');
		else if (res > 0)
			break;
	} while (*s++);
	return (res * sign);
}
/**
 * count_digits_or_chars - count characters
 * @c: char*
 * Return:
 * - pos if only digits,
 * - neg if only non-number characters
 * - 0 if mixed
 */
int count_digits_or_chars(char *c)
{
	int i, digits = 0, chars = 0;

	for (i = 0; c[i]; i++)
		if (c[i] >= '0' && c[i] <= '9')
			digits++;
		else
			chars++;

	/*only digits*/
	if (digits > 0 && chars == 0)
		return (digits);

	/*only characters*/
	if (chars > 0 && digits == 0)
		return (-1 * chars);

	return (0);
}
