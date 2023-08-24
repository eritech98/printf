#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print -This is a struct for printer functions
 * @type_arg:This is the identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */

/*Must include this */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

/*our simple prototypes
*Our function names will be our file  names
*/


int _printf(const char *format, ...);
int print_program(va_list __attribute__((unused)), char *, unsigned int);
int print_character(va_list arguments, char *erick, unsigned int goodness);
int print_string(va_list arguments, char *erick, unsigned int goodness);
int print_integer(va_list arguments, char *erick, unsigned int goodness);
int print_binary(va_list arguments, char *erick, unsigned int goodness);
int print_jet(va_list arguments, char *erick, unsigned int goodness);
int print_octal(va_list arguments, char *erick, unsigned int goodness);
int print_hexadecimal(va_list arguments, char *erick, unsigned int goodness);
int print_f1(va_list arguments, char *erick, unsigned int goodness);
int print_f18(va_list arguments, char *erick, unsigned int goodness);
int print_add(va_list arguments, char *erick, unsigned int goodness);
int print_reverse(va_list arguments, char *erick, unsigned int goodness);
int print_hp(va_list arguments, char *erick, unsigned int goodness);
int print_erick(va_list arguments, char *erick, unsigned int goodness);
int print_Goodness(va_list arguments, char *erick, unsigned int goodness);
int print_samsung(va_list arguments, char *erick, unsigned int goodness);
int print_vfr(va_list arguments, char *erick, unsigned int goodness);
int print_va(va_list arguments, char *erick, unsigned int goodness);
int print_ifr(va_list arguments, char *erick, unsigned int goodness);
int print_c(va_list arguments, char *erick, unsigned int goodness);
int print_programming(va_list arguments, char *erick, unsigned int goodness);
int print_alx(va_list arguments, char *erick, unsigned int goodness);
int print_rich(va_list arguments, char *erick, unsigned int goodness);
int print_dev(va_list arguments, char *erick, unsigned int goodness);
int print_positive(va_list arguments, char *erick, unsigned int goodness);
int print_good(va_list arguments, char *erick, unsigned int goodness);
int print_easy(va_list arguments, char *erick, unsigned int goodness);
int print_hardthings(va_list arguments, char *erick, unsigned int goodness);

/*has a func called geta_at_alx which takes two argument and returns a pointer to.int(*).*/
int (*get_at_alx(const char *s, int index))(va_list, char *, unsigned int);

int print_buffer(char *buf, unsigned int nbuf);

/*The functions will be the name of the files we create*/

int at_alx(const char *s, int index);
unsigned int we_learnt_to_handle_buff(char *erick, char c, unsigned int goodness);
int and_print_buff(char *erick, unsigned int nbuf);
char *also_this_is_for_binary(char *binary, long int int_in, int isneg, int limit);
char *this_will_fill_oct_array(char *binary, char *oct);
char *this_will_fill_long_oct_array(char *binary, char *oct);
char *will_fill_short_oct_array(char *binary, char *oct);
char *this_will_hex_array(char *bnr, char *hexadecimal, int isupp, int limit);

#endif
