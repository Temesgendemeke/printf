#include "main.h"

/**
 * nonPrintHex - non print to hexa
 * @args: the argument
 * Return: the bytes
 */

int nonPrintHex(va_list args)
{
	char *str;
	char hexS[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int i, head = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] > '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			head += 2;
			_putchar(92);
			_putchar('x');
			if (str[i] < 9)
				head += _putchar('0');
			head += recur_hexad(str[i], hexS);
		}
		else
			head += _putchar(str[i]);
	}

	return (head);
}

/**
 * print_rev - prints the reverse
 * @args: arguments
 * Return: chars printed
*/

int print_rev(va_list args)
{
	int length;
	char *s;
	char *p;

	s = va_arg(args, char *);
	if (s == NULL)
		return (-1);
	p = nr_string(s);
	if (p == NULL)
		return (-1);
	for (length = 0; p[length] != '\0'; length++)
		_putchar(p[length]);
	free(p);
	return (length);
}