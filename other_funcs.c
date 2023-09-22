#include "main.h"

/**
 * conv - converter
 * @num: number
 * @base: base
 * @flags: flags
 * @params: paramater
 * Return: string
 */

char *conv(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & TO_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & TO_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_un_int - prints unsigned integer
 * @args: argument
 * @params: the parameters
 * Return: bytes printed
 */

int print_un_int(va_list args, params_t *params)
{
	unsigned long l;

	if (params->l)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	params->unsign = 1;
	return (print_nums(conv(l, 10, TO_UNSIGNED, params), params));
}



/**
 * print_address - prints address
 * @args: argument
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_address(va_list args, params_t *params)
{
	unsigned long int n = va_arg(args, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = conv(n, 16, TO_UNSIGNED | TO_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_nums(str, params));
}
