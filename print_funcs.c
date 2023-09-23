#include "main.h"

/**
 * print_char - prints character
 * @args: argument
 * @params: the parameters
 * Return: chars printed
 */

int print_char(va_list args, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(args, int);

	if (params->minus)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @args: argument
 * @params: the parameters
 * Return: chars printed
 */

int print_int(va_list args, params_t *params)
{
	long l;

	if (params->l)
		l = va_arg(args, long);
	else if (params->h)
		l = (short int)va_arg(args, int);
	else
		l = (int)va_arg(args, int);
	return (print_nums(conv(l, 10, 0, params), params));
}

/**
 * print_str - prints string
 * @args: argument
 * @params: the parameters
 * Return: chars printed
 */

int print_str(va_list args, params_t *params)
{
	char *str = va_arg(args, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_perc - prints %
 * @args: argument
 * @params: the parameters
 * Return: chars printed
 */

int print_perc(va_list args, params_t *params)
{
	(void)args;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @args: argument
 * @params: the parameters
 * Return: chars printed
 */

int print_S(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = conv(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}