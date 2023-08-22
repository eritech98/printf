#include "main.h"

/**
* is_printable - Evaluate character that is printable
* @g: Character that is to be evaluated.
*
* Return: 1 if g is printable, 0 otherwise
*/
int is_printable(char g)
{
	if (g >= 32 && g < 127)
	return (1);

	return (0);
}

/**
* append_hexa_code - Append ascci hexadecimal
* @buffer: Array of chars
* @i: Index to use for appending
* @ascii_code: ASSCI CODE.
* Return: 3
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
	ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
* is_digit - Verify char if it is a digit
* @g: Char to evaluated
*
* Return: 1 if g is a digit, 0 otherwise
*/
int is_digit(char g)
{
	if (g >= '0' && g <= '9')
	return (1);

	return (0);
}

/**
* convert_size_number - Casts num specified size
* @num: Num to be casted.
* @size: Num indicating type to be casted.
*
* Return: Casted value of a num
*/
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size == S_SHORT)
	return ((short)num);

	return ((int)num);
}

/**
* convert_size_unsgnd - Cast num specified size
* @num: Num to be casted
* @size: Num indicating type to be casted
*
* Return: Casted value of num
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size == S_SHORT)
	return ((unsigned short)num);
	return ((unsigned int)num);
}
