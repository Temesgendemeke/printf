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
 * print_address - prints the address
 * @args: the argument
 * Return: byte
 */

int print_address(va_list args)
{
	unsigned long int nums;
	int i, byte;

	byte = 0;
	nums = va_arg(args, unsigned long int);
	if (nums <= 0)
	{
		char *str = "(nil)";

		for (i = 0; str[i]; i++)
			byte += _putchar(str[i]);
		return (byte);
	}

	_putchar('0');
	_putchar('x');
	byte += 2;
	byte += l_hex(nums);

	return (byte);
}

/**
 * l_hex - num to hexa
 * @num: the no
 * Return: the bytes
 */

int l_hex(unsigned long int num)
{
	int byte = 0;
	char hex[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	byte = recur_l_hex(num, hex);

	return (byte);
}

/**
 * recur_l_hex - rec for addr
 * @nums: nos
 * @hex: pointer to hexals
 * Return: byte
 */

int recur_l_hex(unsigned long int nums, char *hex)
{
	int rem, byte;
	char c;

	byte = 0;
	if (nums / 16 == 0)
	{
		c = '0' + nums;
		if (nums > 9)
		{
			unsigned int j, k = 0;

			for (j = 10; j <= 15; j++, k++)
			{
				if (nums == j)
					_putchar(hex[k]);
			}
		}
		else
			_putchar('0' + nums);

		return (1);
	}

	rem = nums % 16;
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
	nums /= 16;
	byte += recur_l_hex(nums, hex);
	byte += _putchar(c);
	return (byte);
}

