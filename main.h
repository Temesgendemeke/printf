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
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define TO_LOWERCASE	1
#define TO_UNSIGNED	2

/**
 * struct parameters - parameters struct
 * @unsign: unsigned value
 * @plus: plus
 * @space: space
 * @hashtag: hash
 * @zero: zero
 * @minus: "-"
 *
 * @width: width
 * @precision: precision
 *
 * @h: on if h_modifier is specified
 * @l: on if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus		: 1;
	unsigned int space		: 1;
	unsigned int hashtag		: 1;
	unsigned int zero		: 1;
	unsigned int minus		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h			: 1;
	unsigned int l			: 1;
} params_t;

/**
 * struct choosing - Struct to choose
 * @c: formats
 * @f: The function associated
 */

typedef struct choosing
{
	char *c;
	int (*f)(va_list, params_t *);
} frm_t;

int _isdigit(int c);
int _strlen(char *s);
int print_nums(char *str, params_t *params);
int print_numrs(char *str, params_t *params);
int print_numls(char *str, params_t *params);
void init_params(params_t *params, va_list args);
char *gets_precision(char *ptr, params_t *params, va_list args);
int _printf(const char *format, ...);

int _puts(char *str);
int _putchar(int c);
int print_char(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_str(va_list args, params_t *params);
int print_perc(va_list args, params_t *params);
int print_S(va_list args, params_t *params);
char *conv(long int num, int base, int flags, params_t *params);
int print_un_int(va_list args, params_t *params);
int print_address(va_list args, params_t *params);
int (*scans(char *s))(va_list args, params_t *params);
int gets_print_func(char *s, va_list args, params_t *params);
int gets_flags(char *s, params_t *params);
int gets_modifier(char *s, params_t *params);
char *gets_width(char *s, params_t *params, va_list args);
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);
int print_bins(va_list args, params_t *params);
int print_octs(va_list args, params_t *params);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);

#endif
