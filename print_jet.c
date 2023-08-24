#include "main.h"
/**
 * print_jet - prints an unsigned int
 * @arguments: number to print
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed.
 */
int print_jet(va_list arguments, char *erick, unsigned int goodness)
{
	unsigned int int_in, int_temp, i, div;

	int_in = va_arg(arguments, unsigned int);
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		goodness = we_learnt_to_handle_buff(erick, ((int_in / div) % 10) + '0', goodness);
	}
	return (i);
}
