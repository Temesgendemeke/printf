#include "main.h"

/**
 * _put_base - prints it
 * @str: the string
*/

void _put_base(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _memcpy - copies
 * @dest: the destination
 * @src: the source
 * @num: no of bytes
 * Return: dest
*/

char *_memcpy(char *dest, char *src, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * nr_string - reverse
 * @s: the string
 * Return: dest
*/

char *nr_string(char *s)
{
	int length, idk;
	char temp;
	char *dest;

	length = 0;
	while (s[length] != '\0')
		length++;
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, length);
	for (idk = 0; idk < length; idk++, length--)
	{
		temp = dest[length - 1];
		dest[length - 1] = dest[idk];
		dest[idk] = temp;
	}
	return (dest);
}

/**
 * b_len - cals the length
 * @nums: no of the length
 * @b: inp to cal
 * Return: length i
*/

unsigned int b_len(unsigned int nums, int b)
{
	unsigned int i;

	for (i = 0; nums > 0; i++)
		nums /= b;
	return (i);
}

