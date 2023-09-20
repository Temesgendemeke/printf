#include "main.h"

/**
 * print_c - prints char
 * @args: args
 * Return: no of chars printed
*/

int print_c(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_s - prints string
 * @args: args
 * Return: no of printed chars
*/

int print_s(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_perc - prints percent
 * @args: arguments
 * Return: no of chars printed
*/

int print_perc(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}

/**
 * print_int - prints integer
 * @args: the arguments
 * Return: the length
*/

int print_int(va_list args)
{
	int length;

	length = print_nums(args);
	return (length);
}

/**
 * print_un_int - prints unsigned int
 * @args: arguments
 * Return: no of nums
*/

int print_un_int(va_list args)
{
	unsigned int nums;

	nums = va_arg(args, unsigned int);
	if (nums == 0)
		return (print_u_nums(nums));
	if (nums < 1)
		return (-1);
	return (print_u_nums(nums));
}

