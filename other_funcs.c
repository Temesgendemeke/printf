#include "main.h"

/**
 * conv - converter
 * @nu: number
 * @b: base
 * @flags: flags
 * @para: paramater
 * Return: string
 */

char *conv(long int nu, int b, int flags, para_t *para)
{
	static char *arr;
	static char buff[50];
	char signs = 0;
	char *ptr;
	unsigned long no = nu;
	(void)para;

	if (!(flags & TO_UNSIGNED) && nu < 0)
	{
		no = -nu;
		signs = '-';
	}
	arr = flags & TO_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[no % b];
		no /= b;
	} while (no != 0);

	if (signs)
		*--ptr = signs;
	return (ptr);
}

/**
 * print_un_int - prints unsigned integer
 * @args: argument
 * @para: the parameters
 * Return: bytes printed
 */

int print_un_int(va_list args, para_t *para)
{
	unsigned long lng;

	if (para->lng)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (para->hei)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);
	para->unsign = 1;
	return (print_nums(conv(lng, 10, TO_UNSIGNED, para), para));
}



/**
 * print_address - prints address
 * @args: argument
 * @para: the parameters struct
 * Return: bytes printed
 */

int print_address(va_list args, para_t *para)
{
	unsigned long int no = va_arg(args, unsigned long int);
	char *str;

	if (!no)
		return (_puts("(nil)"));

	str = conv(no, 16, TO_UNSIGNED | TO_LOWERCASE, para);
	*--str = 'x';
	*--str = '0';
	return (print_nums(str, para));
}
