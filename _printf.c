#include "main.h"

/**
 * _printf - prints all the text and the formated ones
 * @format: string of chars
 * Return: no of chars printed
*/

int _printf(const char *format, ...)
{
	int chars;

	frm_t choose[] = {{"c", print_c}, {"s", print_s},
			{"%", print_perc}, {"d", print_int},
			{"i", print_int}, {"b", print_bin},
			{"o", print_oct}, {"x", print_hexa},
			{"X", print_heXA}, {"u", print_un_int},
			{"r", print_rev}, {"R", rot13},
			{"S", nonPrintHex},
			{NULL, NULL}};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	chars = scans(format, args, choose);
	va_end(args);
	return (chars); /*needs to be modified later*/
}

/**
 * scans - just a scanner
 * @format: formatter
 * @args: list of arguments
 * @choose: choose
 * Return: err
*/

int scans(const char *format, va_list args, frm_t choose[])
{
	int chars, j, ret_value;
	int i = 0;

	chars = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			for (j = 0; choose[j].c != NULL; j++)
			{
				if (format[i + 1] == choose[j].c[0])
				{
					ret_value = choose[j].f(args);
					if (ret_value == -1)
						return (-1);
					chars += ret_value;
					break;
				}
			}
			if (choose[j].c == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					chars += 2;
				} else
					return (-1);
			}
			i++;
		} else
		{
			_putchar(format[i]);
			chars++;
		}
		i++;
	}
	return (chars);
}

/**
 * print_rev - prints the reverse
 * @args: arguments
 * Return: chars printed
*/

int print_rev(va_list args)
{
	int length;
	char *s;
	char *p;

	s = va_arg(args, char *);
	if (s == NULL)
		return (-1);
	p = nr_string(s);
	if (p == NULL)
		return (-1);
	for (length = 0; p[length] != '\0'; length++)
		_putchar(p[length]);
	free(p);
	return (length);
}

/**
 * rot13 - to rot13
 * @args: the argument
 * Return: no of conve string
*/

int rot13(va_list args)
{
	int i, j;
	char *str;
	char abyz[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char nolm[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (str[i] == abyz[j])
			{
				_putchar(nolm[j]);
				break;
			}
		}
		if (j == 53)
			return (str[i]);
	}
	return (i);
}
