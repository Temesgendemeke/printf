#include "main.h"

/**
 * print_bins - prints binary number
 * @args: the argument pointer
 * @params: the parameters
 * Return: bytes printed
 */

int print_bins(va_list args, params_t *params)
{
	unsigned int n = va_arg(args, unsigned int);
	char *str = conv(n, 2, TO_UNSIGNED, params);
	int c = 0;

	if (params->hashtag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_nums(str, params));
}

/**
 * print_octs - prints octal numbers
 * @args: the argument
 * @params: the parameters
 * Return: bytes printed
 */

int print_octs(va_list args, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	str = conv(l, 8, TO_UNSIGNED, params);

	if (params->hashtag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_nums(str, params));
}


/**
 * print_hex - hexs in lowercase
 * @args: the argument pointer
 * @params: the parameters
 * Return: bytes printed
 */

int print_hex(va_list args, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = conv(l, 16, TO_UNSIGNED | TO_LOWERCASE, params);
	if (params->hashtag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_nums(str, params));
}

/**
 * print_HEX - hexs in uppercase
 * @args: the argument pointer
 * @params: the parameters
 * Return: bytes printed
 */

int print_HEX(va_list args, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = conv(l, 16, TO_UNSIGNED, params);
	if (params->hashtag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_nums(str, params));
}
