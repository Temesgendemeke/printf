#include "main.h"

/**
 * _strlen - get string length.
 * @str: string.
 * Return: length of string.
*/
int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * recur_hexad - recur
 * @num: number
 * @hex: hex pointer
 * Return: anb this was
 */

int recur_hexad(unsigned int num, char *hex)
{
	int rem, bytes = 0;
	char c;

	if (num / 16 == 0)
	{
		c = '0' + num;
		if (num > 9)
		{
			unsigned int j, k = 0;

			_putchar('0');
			for (j = 10; j <= 15; j++, k++)
			{
				if (num == j)
					_putchar(hex[k]);
			}
			return (2);
		}
		else
			_putchar('0' + num);

		return (1);
	}
	rem = num % 16;
	if (rem > 9)
	{
		int j2, k2 = 0;

		for (j2 = 10; j2 <= 15; j2++, k2++)
		{
			if (rem == j2)
				c = hex[k2];
		}
	}
	else
		c = '0' + rem;
	num /= 16;
	bytes += recur_hexad(num, hex);
	bytes += _putchar(c);
	return (bytes);
}

/**
 * rotat_it - totates here
 * @str: the string
 * @rot: rotation of the earth
 * @length: the len
 */

void rotat_it(char *rot, char *str, int length)
{
	int i;
	char c;

	for (i = 0; str[i]; i++)
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
		{
			if (c + 13 > 'z')
			{
				c = 'z' - c;
				c = 13 - c;
				rot[i] = 'a' + c - 1;
			}
			else
				rot[i] = c + 13;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (c + 13 > 'Z')
			{
				c = 'Z' - c;
				c = 13 - c;
				rot[i] = 'A' + c - 1;
			}
			else
				rot[i] = c + 13;
		}
		else
			rot[i] = c;
	}
	rot[length] = '\0';
	for (i = 0; rot[i]; i++)
		_putchar(rot[i]);
}

/**
 * rot13 - print by 13 rotated of
 * @args: string.
 * Return: byte written.
 */

int rot13(va_list args)
{
	char *str, *rot;
	int length;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	length = _strlen(str);
	rot = malloc(sizeof(char) * (length + 1));
	if (rot == NULL)
		return (-1);

	rotat_it(rot, str, length);
	free(rot);
	return (length);
}
