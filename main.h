#ifndef OUR_MAIN
#define OUR_MAIN

/*The starg.h header is for the va_list arg e.tc functions*/
#include <stdarg.h>

/*The stdio.h header is for the printing functions e.g printf*/
#include <stdio.h>

/*The unistd.h is for the putchar functions*/
#include <unistd.h>


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


/*This are the Macros or the flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


/*Tis are the sizes macros*/
#define S_LONG 2
#define S_SHORT 1



/**
 * struct fmt - The struct fmt function
 *
 * @fmt: formart variable
 * @fn: function that returns a value of an integer
 */



struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};




/**
 * typedef struct fmt fmt_t - This is the struct operation
 *
 * @fmt: The format
 * @fm_t: The associated variable
 */


typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/*********OUR FUNCTIONS*****/

/* This functions will print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/*This Functions will print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


/*This functions will print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* This functions will  print memory adress */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/*This functions will handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);


/*This Functions wil print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/*This functions will print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/*This are the width handlers*/
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);



/****************** UTILITIES*********/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


#endif /*This line ends our main.h file*/
