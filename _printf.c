#include "main.h"

/**
 * _printf - like printf
 * @format: the format string
 * Return: bytes printed
 */

int _printf(const char *format, ...)
{
	int sums = 0;
	va_list args;
	char *ptr, *strt;

	para_t para = PARA_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *ptr; ptr++)
	{
		init_para(&para, args);
		if (*ptr != '%')
		{
			sums += _putchar(*ptr);
			continue;
		}
		strt = ptr;
		ptr++;
		while (gets_flags(ptr, &para))
		{
			ptr++;
		}
		ptr = gets_width(ptr, &para, args);
		ptr = gets_precision(ptr, &para, args);
		if (gets_modifier(ptr, &para))
			ptr++;
		if (!scans(ptr))
			sums += print_fm_to(strt, ptr,
					para.lng || para.hei ? ptr - 1 : 0);
		else
			sums += gets_print_func(ptr, args, &para);
	}
	_putchar(BUFF_FLUSH);
	va_end(args);
	return (sums);
}

/**
 * init_para - initiates parameters
 * @para: the parameters
 * @args: the argument
 */

void init_para(para_t *para, va_list args)
{
	para->unsign = 0;

	para->plus = 0;
	para->space = 0;
	para->hashtag = 0;
	para->zero = 0;
	para->minus = 0;

	para->width = 0;
	para->precision = UINT_MAX;

	para->hei = 0;
	para->lng = 0;
	(void)args;
}

