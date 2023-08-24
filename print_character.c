#include "main.h"
#include <stdio.h>
/**
 * print_character - writes the character c to stdout
 * @arguments: input char
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: On success 1.
 */
int print_character(va_list arguments, char *erick, unsigned int goodness)
{
	char c;

	c = va_arg(arguments, int);
	we_learnt_to_handle_buff(erick, c, goodness);

	return (1);
}
