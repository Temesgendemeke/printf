#include "main.h"

/**
 * _puts - prints a string
 * @str: the string
 * Return: (str-a)
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - character c to stdout
 * @c: character to print
 * Return: 1
 */

int _putchar(int c)
{
	static int a;
	static char buff[BUFF_SIZE];

	if (c == BUFF_FLUSH || a >= BUFF_SIZE)
	{
		write(1, buff, a);
		a = 0;
	}
	if (c != BUFF_FLUSH)
		buff[a++] = c;
	return (1);
}
