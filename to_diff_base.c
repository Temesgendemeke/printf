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

/**
 * print_oct - prints in octal
 * @args: the arguments
 * Return: no of chars
*/

int print_oct(va_list args)
{
	unsigned int nums;
	int length;
	char *octs;
	char *nc_print;

	nums = va_arg(args, unsigned int);
	if (nums == 0)
		return (_putchar('0'));
	if (nums < 1)
		return (-1);
	length = b_len(nums, 8);

	octs = malloc(sizeof(char) * length + 1);
	if (octs == NULL)
		return (-1);
	for (length = 0; nums > 0; length++)
	{
		octs[length] = (nums % 8) + 48;
		nums /= 8;
	}
	octs[length] = '\0';
	nc_print = nr_string(octs);
	if (nc_print == NULL)
		return (-1);
	_put_base(nc_print);
	free(octs);
	free(nc_print);
	return (length);
}

/**
 * if_hex - upp or low
 * @nums: the number
 * @x: which
 * Return: 0
*/

int if_hex(int nums, char x)
{
	char *hexa = "abcdef";
	char *Hexa = "ABCDEF";

	nums -= 10;
	if (x == 'x')
		return (hexa[nums]);
	else
		return (Hexa[nums]);
	return (0);
}

/**
 * print_hexa - prints in lowercase
 * @args: arguments
 * Return: 0
*/

int print_hexa(va_list args)
{
	unsigned int nums;
	int length, numsr;
	char *hexs;
	char *nh_print;

	nums = va_arg(args, unsigned int);
	if (nums == 0)
		return (_putchar('0'));
	if (nums < 1)
		return (-1);
	length = b_len(nums, 16);
	hexs = malloc(sizeof(char) * length + 1);
	if (hexs == NULL)
		return (-1);
	for (length = 0; nums > 0; length++)
	{
		numsr = nums % 16;
		if (numsr > 9)
		{
			numsr = if_hex(numsr, 'x');
			hexs[length] = numsr;
		}
		else
			hexs[length] = numsr + 48;
		nums /= 16;
	}
	hexs[length] = '\0';
	nh_print = nr_string(hexs);
	if (nh_print == NULL)
		return (-1);
	_put_base(nh_print);
	free(hexs);
	free(nh_print);
	return (length);
}

/**
 * print_heXA - prints in uppercase
 * @args: arguments
 * Return: no of chars
*/

int print_heXA(va_list args)
{
	unsigned int nums;
	int length, numsr;
	char *hexs;
	char *nh_print;

	nums = va_arg(args, unsigned int);
	if (nums == 0)
		return (_putchar('0'));
	if (nums < 1)
		return (-1);
	length = b_len(nums, 16);
	hexs = malloc(sizeof(char) * length + 1);
	if (hexs == NULL)
		return (-1);
	for (length = 0; nums > 0; length++)
	{
		numsr = nums % 16;
		if (numsr > 9)
		{
			numsr = if_hex(numsr, 'X');
			hexs[length] = numsr;
		}
		else
			hexs[length] = numsr + 48;
		nums /= 16;
	}
	hexs[length] = '\0';
	nh_print = nr_string(hexs);
	if (nh_print == NULL)
		return (-1);
	_put_base(nh_print);
	free(hexs);
	free(nh_print);
	return (length);
}

