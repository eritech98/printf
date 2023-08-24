#include "main.h"

/**
 * print_buffer - prints buffer
 * @erick: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buffer(char *erick, unsigned int nbuf)
{
	return (write(1, erick, nbuf));
}
