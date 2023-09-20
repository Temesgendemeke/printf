#include "main.h"

/**
 * print_nums - prints numbers
 * @args: the args
 * Return: the length
*/

int print_nums(va_list args)
{
	int n, div, length;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	length = 0;

	if (n < 0)
	{
		length += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		length += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (length);
}
