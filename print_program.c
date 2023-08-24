#include "main.h"
#include <stdio.h>
/**
 * print_program - writes the character c to stdout
 * @a: input char
 * @erick: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int print_program(va_list a __attribute__((unused)), char *erick, unsigned int i)
{
	we_learnt_to_handle_buff(erick, '%', i);

	return (1);
}
