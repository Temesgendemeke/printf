#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct choosing - format specifier
 * @c: pointer to the characters
 * @f: pointer to the functions
*/

struct choosing
{
	char *c;
	int (*f)(va_list);
};

typedef struct choosing frm_t;

int _printf(const char *format, ...);
int _putchar(char c);
int scans(const char *format, va_list args, frm_t *choose);

/* formatter functions */
int print_c(va_list);
int print_s(va_list);
int print_perc(va_list);
int print_int(va_list);
int print_nums(va_list);
int print_bin(va_list);

/*functions needed*/
unsigned int b_len(unsigned int nums, int b);
char *nr_string(char *s);
char *_memcpy(char *dest, char *src, unsigned int num);
void _put_base(char *str);

#endif

