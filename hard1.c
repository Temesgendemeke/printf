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
