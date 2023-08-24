#include "main.h"

/**
 * and_print_buff - prints buffer
 * @erick: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int and_print_buff(char *erick, unsigned int nbuf)
{
	return (write(1, erick, nbuf));
}
