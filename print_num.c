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

/**
 * print_u_nums - prints unsigned number
 * @n: unsigned no
 * Return: length
*/

int print_u_nums(unsigned int n)
{
	int div, length;
	unsigned int nums;

	div = 1;
	length = 0;
	nums = n;
	for (; nums / div > 9; )
		div *= 10;
	for (; div != 0;)
	{
		length += _putchar('0' + nums / div);
		nums %= div;
		div /= 10;
	}
	return (length);
}
