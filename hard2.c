#include "main.h"

/**
 * recur_hexad - recur
 * @num: number
 * @hex: hex pointer
 * Return: anb this was
 */

int recur_hexad(unsigned int num, char *hex)
{
	int rem, bytes = 0;
	char c;

	if (num / 16 == 0)
	{
		c = '0' + num;
		if (num > 9)
		{
			unsigned int j, k = 0;

			_putchar('0');
			for (j = 10; j <= 15; j++, k++)
			{
				if (num == j)
					_putchar(hex[k]);
			}
			return (2);
		}
		else
			_putchar('0' + num);

		return (1);
	}
	rem = num % 16;
	if (rem > 9)
	{
		int j2, k2 = 0;

		for (j2 = 10; j2 <= 15; j2++, k2++)
		{
			if (rem == j2)
				c = hex[k2];
		}
	}
	else
		c = '0' + rem;
	num /= 16;
	bytes += recur_hexad(num, hex);
	bytes += _putchar(c);
	return (bytes);
}
