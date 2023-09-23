#include "main.h"

/**
 * scans - finds the format function
 * @s: string
 * Return: bytes printed
 */

int (*scans(char *s))(va_list args, para_t *para)
{
	frm_t choose[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_str},
		{"%", print_perc},
		{"b", print_bins},
		{"o", print_octs},
		{"u", print_un_int},
		{"x", print_hexa},
		{"X", print_HEXA},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (choose[i].c)
	{
		if (*s == choose[i].c[0])
		{
			return (choose[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * gets_print_func - finds format
 * @s: string
 * @args: argument pointer
 * @para: the parameters
 * Return: bytes printed
 */

int gets_print_func(char *s, va_list args, para_t *para)
{
	int (*f)(va_list, para_t *) = scans(s);

	if (f)
		return (f(args, para));
	return (0);
}

/**
 * gets_flags - finds the flag
 * @s: the string
 * @para: the parameters
 * Return: i
 */

int gets_flags(char *s, para_t *para)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = para->plus = 1;
			break;
		case ' ':
			i = para->space = 1;
			break;
		case '#':
			i = para->hashtag = 1;
			break;
		case '-':
			i = para->minus = 1;
			break;
		case '0':
			i = para->zero = 1;
			break;
	}
	return (i);
}

/**
 * gets_modifier - finds the modifier
 * @s: string
 * @para: parameter
 * Return: 0
 */

int gets_modifier(char *s, para_t *para)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = para->hei = 1;
			break;
		case 'l':
			i = para->lng = 1;
			break;
	}
	return (i);
}

/**
 * gets_width - gets the width
 * @s: string
 * @para: the parameters
 * @args: the argument
 * Return: new pointer
 */

char *gets_width(char *s, para_t *para, va_list args)
{
	int z = 0;

	if (*s == '*')
	{
		z = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			z = z * 10 + (*s++ - '0');
	}
	para->width = z;
	return (s);
}
