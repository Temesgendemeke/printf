#include "main.h"

/**
 * scans - finds the format function
 * @s: string
 * Return: bytes printed
 */

int (*scans(char *s))(va_list args, params_t *params)
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
		{"x", print_hex},
		{"X", print_HEX},
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
 * @params: the parameters
 * Return: bytes printed
 */

int gets_print_func(char *s, va_list args, params_t *params)
{
	int (*f)(va_list, params_t *) = scans(s);

	if (f)
		return (f(args, params));
	return (0);
}

/**
 * gets_flags - finds the flag
 * @s: the string
 * @params: the parameters
 * Return: i
 */

int gets_flags(char *s, params_t *params)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus = 1;
			break;
		case ' ':
			i = params->space = 1;
			break;
		case '#':
			i = params->hashtag = 1;
			break;
		case '-':
			i = params->minus = 1;
			break;
		case '0':
			i = params->zero = 1;
			break;
	}
	return (i);
}

/**
 * gets_modifier - finds the modifier
 * @s: string
 * @params: parameter
 * Return: 0
 */

int gets_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h = 1;
			break;
		case 'l':
			i = params->l = 1;
			break;
	}
	return (i);
}

/**
 * gets_width - gets the width
 * @s: string
 * @params: the parameters
 * @args: the argument
 * Return: new pointer
 */

char *gets_width(char *s, params_t *params, va_list args)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
