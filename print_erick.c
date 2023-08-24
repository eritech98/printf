#include "main.h"
/**
 * print_erick - prints a long integer
 * @arguments: input string
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed.
 */
int print_erick(va_list arguments, char *erick, unsigned int goodness)
{
	long int int_input;
	unsigned long int int_in, int_temp, i, div, isneg;

	int_input = va_arg(arguments, long int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		goodness = we_learnt_to_handle_buff(erick, '-', goodness);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

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
	return (i + isneg);
}
