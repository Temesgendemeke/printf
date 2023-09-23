#include "main.h"

/**
 * print_bins - prints binary number
 * @args: the argument pointer
 * @para: the parameters
 * Return: bytes printed
 */

int print_bins(va_list args, para_t *para)
{
	unsigned int no = va_arg(args, unsigned int);
	char *str = conv(no, 2, TO_UNSIGNED, para);
	int c = 0;

	if (para->hashtag && no)
		*--str = '0';
	para->unsign = 1;
	return (c += print_nums(str, para));
}

/**
 * print_octs - prints octal numbers
 * @args: the argument
 * @para: the parameters
 * Return: bytes printed
 */

int print_octs(va_list args, para_t *para)
{
	unsigned long lng;
	char *str;
	int c = 0;

	if (para->lng)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (para->hei)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);
	str = conv(lng, 8, TO_UNSIGNED, para);

	if (para->hashtag && lng)
		*--str = '0';
	para->unsign = 1;
	return (c += print_nums(str, para));
}


/**
 * print_hexa - hexs in lowercase
 * @args: the argument pointer
 * @para: the parameters
 * Return: bytes printed
 */

int print_hexa(va_list args, para_t *para)
{
	unsigned long lng;
	int c = 0;
	char *str;

	if (para->lng)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (para->hei)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);

	str = conv(lng, 16, TO_UNSIGNED | TO_LOWERCASE, para);
	if (para->hashtag && lng)
	{
		*--str = 'x';
		*--str = '0';
	}
	para->unsign = 1;
	return (c += print_nums(str, para));
}

/**
 * print_HEXA - hexs in uppercase
 * @args: the argument pointer
 * @para: the parameters
 * Return: bytes printed
 */

int print_HEXA(va_list args, para_t *para)
{
	unsigned long lng;
	int c = 0;
	char *str;

	if (para->lng)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (para->hei)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);

	str = conv(lng, 16, TO_UNSIGNED, para);
	if (para->hashtag && lng)
	{
		*--str = 'X';
		*--str = '0';
	}
	para->unsign = 1;
	return (c += print_nums(str, para));
}
