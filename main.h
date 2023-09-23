#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define BUFF_FLUSH -1
#define NULL_STRING "(null)"
#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define TO_LOWERCASE	1
#define TO_UNSIGNED	2

/**
 * struct para - para struct
 * @unsign: unsigned value
 * @plus: plus
 * @space: space
 * @hashtag: hash
 * @zero: zero
 * @minus: "-"
 * @width: width
 * @precision: precision
 * @hei: on if h_mod is specified
 * @lng: on if l_mod is specified
 */

typedef struct para
{
	unsigned int unsign			: 1;

	unsigned int plus		: 1;
	unsigned int space		: 1;
	unsigned int hashtag		: 1;
	unsigned int zero		: 1;
	unsigned int minus		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int hei		: 1;
	unsigned int lng		: 1;
} para_t;

/**
 * struct choosing - Struct to choose
 * @c: formats
 * @f: function associated
 */

typedef struct choosing
{
	char *c;
	int (*f)(va_list, para_t *);
} frm_t;

int _isdigit(int c);
int _strlen(char *s);
int print_nums(char *str, para_t *para);
int print_numrs(char *str, para_t *para);
int print_numls(char *str, para_t *para);
void init_para(para_t *para, va_list args);
char *gets_precision(char *ptr, para_t *para, va_list args);
int _printf(const char *format, ...);

int _puts(char *str);
int _putchar(int c);
int print_char(va_list args, para_t *para);
int print_int(va_list args, para_t *para);
int print_str(va_list args, para_t *para);
int print_perc(va_list args, para_t *para);
int print_S(va_list args, para_t *para);
char *conv(long int num, int base, int flags, para_t *para);
int print_un_int(va_list args, para_t *para);
int print_address(va_list args, para_t *para);
int (*scans(char *s))(va_list args, para_t *para);
int gets_print_func(char *s, va_list args, para_t *para);
int gets_flags(char *s, para_t *para);
int gets_modifier(char *s, para_t *para);
char *gets_width(char *s, para_t *para, va_list args);
int print_hexa(va_list args, para_t *para);
int print_HEXA(va_list args, para_t *para);
int print_bins(va_list args, para_t *para);
int print_octs(va_list args, para_t *para);
int print_fm_to(char *start, char *stop, char *except);
int print_rev(va_list args, para_t *para);
int print_rot13(va_list args, para_t *para);

#endif
