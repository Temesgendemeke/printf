#include "main.h"

/**
 * _isdigit - checks ifitis digit
 * @u: the character to check
 * Return: 1 or 0
 */

int _isdigit(int u)
{
	return (u >= '0' && u <= '9');
}

/**
 * _strlen - length of a string
 * @str: the string
 * Return: length
 */

int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}

/**
 * print_nums - prints a number
 * @str: a string
 * @para: the parameter
 * Return: chars printed
 */

int print_nums(char *str, para_t *para)
{
	unsigned int a = _strlen(str);
	int negs = (!para->unsign && *str == '-');

	if (!para->precision && *str == '0' && !str[1])
		str = "";
	if (negs)
	{
		str++;
		a--;
	}
	if (para->precision != UINT_MAX)
		while (a++ < para->precision)
			*--str = '0';
	if (negs)
		*--str = '-';

	if (!para->minus)
		return (print_numrs(str, para));
	else
		return (print_numls(str, para));
}

/**
 * print_numrs - prints a number
 * @str: a string
 * @para: the parameter
 * Return: chars printed
 */

int print_numrs(char *str, para_t *para)
{
	unsigned int n = 0, negs1, negs2, i = _strlen(str);
	char pads_chars = ' ';

	if (para->zero && !para->minus)
		pads_chars = '0';
	negs1 = negs2 = (!para->unsign && *str == '-');
	if (negs1 && i < para->width && pads_chars == '0' && !para->minus)
		str++;
	else
		negs1 = 0;
	if ((para->plus && !negs2) ||
		(!para->plus && para->space && !negs2))
		i++;
	if (negs1 && pads_chars == '0')
		n += _putchar('-');
	if (para->plus && !negs2 && pads_chars == '0' && !para->unsign)
		n += _putchar('+');
	else if (!para->plus && para->space && !negs2 &&
		!para->unsign && para->zero)
		n += _putchar(' ');
	while (i++ < para->width)
		n += _putchar(pads_chars);
	if (negs1 && pads_chars == ' ')
		n += _putchar('-');
	if (para->plus && !negs2 && pads_chars == ' ' && !para->unsign)
		n += _putchar('+');
	else if (!para->plus && para->space && !negs2 &&
		!para->unsign && !para->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_numls - prints a number
 * @str: a string
 * @para: the parameter struct
 * Return: chars printed
 */

int print_numls(char *str, para_t *para)
{
	unsigned int no = 0, negs1, negs2, i = _strlen(str);
	char pads_chars = ' ';

	if (para->zero && !para->minus)
		pads_chars = '0';
	negs1 = negs2 = (!para->unsign && *str == '-');
	if (negs1 && i < para->width && pads_chars == '0' && !para->minus)
		str++;
	else
		negs1 = 0;

	if (para->plus && !negs2 && !para->unsign)
		no += _putchar('+'), i++;
	else if (para->space && !negs2 && !para->unsign)
		no += _putchar(' '), i++;
	no += _puts(str);
	while (i++ < para->width)
		no += _putchar(pads_chars);
	return (no);
}
