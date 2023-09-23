#include "main.h"

/**
 * print_char - prints character
 * @args: argument
 * @para: the parameters
 * Return: chars printed
 */

int print_char(va_list args, para_t *para)
{
	char pads_chars = ' ';
	unsigned int pads = 1, sums = 0, chrs = va_arg(args, int);

	if (para->minus)
		sums += _putchar(chrs);
	while (pads++ < para->width)
		sums += _putchar(pads_chars);
	if (!para->minus)
		sums += _putchar(chrs);
	return (sums);
}

/**
 * print_int - prints integer
 * @args: argument
 * @para: the parameters
 * Return: chars printed
 */

int print_int(va_list args, para_t *para)
{
	long lng;

	if (para->lng)
		lng = va_arg(args, long);
	else if (para->hei)
		lng = (short int)va_arg(args, int);
	else
		lng = (int)va_arg(args, int);
	return (print_nums(conv(lng, 10, 0, para), para));
}

/**
 * print_str - prints string
 * @args: argument
 * @para: the parameters
 * Return: chars printed
 */

int print_str(va_list args, para_t *para)
{
	char *str = va_arg(args, char *), pads_chars = ' ';
	unsigned int pads = 0, sums = 0, a = 0, b;

	(void)para;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	b = pads = _strlen(str);
	if (para->precision < pads)
		b = pads = para->precision;

	if (para->minus)
	{
		if (para->precision != UINT_MAX)
			for (a = 0; a < pads; a++)
				sums += _putchar(*str++);
		else
			sums += _puts(str);
	}
	while (b++ < para->width)
		sums += _putchar(pads_chars);
	if (!para->minus)
	{
		if (para->precision != UINT_MAX)
			for (a = 0; a < pads; a++)
				sums += _putchar(*str++);
		else
			sums += _puts(str);
	}
	return (sums);
}

/**
 * print_perc - prints %
 * @args: argument
 * @para: the parameters
 * Return: chars printed
 */

int print_perc(va_list args, para_t *para)
{
	(void)args;
	(void)para;
	return (_putchar('%'));
}

/**
 * print_S - format specifier
 * @args: argument
 * @para: the parameters
 * Return: chars printed
 */

int print_S(va_list args, para_t *para)
{
	char *str = va_arg(args, char *);
	char *hexa;
	int sums = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sums += _putchar('\\');
			sums += _putchar('x');
			hexa = conv(*str, 16, 0, para);
			if (!hexa[1])
				sums += _putchar('0');
			sums += _puts(hexa);
		}
		else
		{
			sums += _putchar(*str);
		}
	}
	return (sums);
}
