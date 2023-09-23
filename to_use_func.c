#include "main.h"

/**
 * print_fm_to - prints a range of char addresses
 * @strt: strting address
 * @stp: stpping address
 * @excpt: excpt address
 * Return: bytes printed
 */

int print_fm_to(char *strt, char *stp, char *excpt)
{
	int sums = 0;

	while (strt <= stp)
	{
		if (strt != excpt)
			sums += _putchar(*strt);
		strt++;
	}
	return (sums);
}

/**
 * print_rev - prints string in reverse
 * @args: string
 * @para: the parameters
 * Return: bytes printed
 */

int print_rev(va_list args, para_t *para)
{
	int length, sums = 0;
	char *str = va_arg(args, char *);
	(void)para;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			sums += _putchar(*str);
	}
	return (sums);
}

/**
 * print_rot13 - prints string in rot13
 * @args: string
 * @para: the parameters
 * Return: bytes printed
 */

int print_rot13(va_list args, para_t *para)
{
	int i, ind;
	int count1 = 0;
	char arrs[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(args, char *);
	(void)para;

	i = 0;
	ind = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			ind = a[i] - 65;
			count1 += _putchar(arrs[ind]);
		}
		else
			count1 += _putchar(a[i]);
		i++;
	}
	return (count1);
}

/**
 * gets_precision - gets the precision
 * @s: thestring
 * @para: the parameters
 * @args: the argument
 * Return: new pointer
*/

char *gets_precision(char *s, para_t *para, va_list args)
{
	int z = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		z = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			z = z * 10 + (*s++ - '0');
	}
	para->precision = z;
	return (s);
}

