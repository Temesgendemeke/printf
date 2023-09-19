#include "main.h"

/**
 * print_bin - prints binary
 * @args: the args
 * Return: length
*/

int print_bin(va_list args)
{
	int i, length;
	unsigned int nums;
	char *str;
	char *ns_print;

	nums = va_arg(args, unsigned int);
	if (nums == 0)
		return (_putchar('0'));
	if (nums < 1)
		return (-1);
	length = b_len(nums, 2);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (-1);
	for (i = 0; nums > 0; i++)
	{
		if (nums % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		nums = nums / 2;
	}
	str[i] = '\0';
	ns_print = nr_string(str);
	if (ns_print == NULL)
		return (-1);
	_put_base(ns_print);
	free(str);
	free(ns_print);
	return (length);
}

