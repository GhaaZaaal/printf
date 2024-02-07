#ifndef MAIN_H
#define MAIN_H

/* to use the printf func to test*/
#include <stdio.h>
/* to use the write func to print*/
#include <unistd.h>
/* to use the va_list functions */
#include <stdarg.h>
/* to use the log10 functions */
#include <math.h>
/* to use the malloc*/
#include <stdlib.h>
/* to use isalpha */
#include <ctype.h>
/* testing */
#include <limits.h>
/* to use the memset */
#include <string.h>

/**
 * go_to_specifier_function - struct to combine the function in an array
 *		of types of specifiers and their function to call
 *arg_executed - struct name
 *@type: the specifier holder
 *@function_for_type: the function to be called
 */
typedef struct go_to_specifier_function
{
	char type;
	char *(*function_for_type)(int);
} arg_executed;

typedef struct specifier_function_str
{
	char type;
	char *(*function_for_type)(const char *);
} specifier_str;

int _printf(const char *format, ...);
char *for_binary(int number);
char *for_int(int);
char *for_unsigned(int);
char *for_char(int);
char *for_octal(int number);
char *for_hex(int number);
char *for_HEX(int number);
char *for_rot13(const char *string);
char *for_string(const char *string);
char *for_reverse(const char *string);
int num_digits(int num);
void buffer_out(char *buffer, unsigned int index);

char *(*specifiers_int(char is_it_specifier))(int);
char *for_module(int a);
char *(*specifiers_str(char is_it_specifier))(const char *);

#endif /* MAIN_H */
