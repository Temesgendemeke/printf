#include "main.h"

/**
 * _printf - like printf
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list args;
	char *ptr, *start;

	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *ptr; ptr++)
	{
		init_params(&params, args);
		if (*ptr != '%')
		{
			sum += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (gets_flags(ptr, &params))
		{
			ptr++;
		}
		ptr = gets_width(ptr, &params, args);
		ptr = gets_precision(ptr, &params, args);
		if (gets_modifier(ptr, &params))
			ptr++;
		if (!scans(ptr))
			sum += print_from_to(start, ptr,
					params.l || params.h ? ptr - 1 : 0);
		else
			sum += gets_print_func(ptr, args, &params);
	}
	_putchar(BUFF_FLUSH);
	va_end(args);
	return (sum);
}

/**
 * init_params - initiates parameters
 * @params: the parameters
 * @args: the argument
 */

void init_params(params_t *params, va_list args)
{
	params->unsign = 0;

	params->plus = 0;
	params->space = 0;
	params->hashtag = 0;
	params->zero = 0;
	params->minus = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h = 0;
	params->l = 0;
	(void)args;
}

