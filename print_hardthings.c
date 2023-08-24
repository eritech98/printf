#include "main.h"
/**
 * print_hardthings - prints int begining with space
 * @arguments: input string
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed
 */
int print_hardthings(va_list arguments, char *erick, unsigned int goodness)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		goodness = we_learnt_to_handle_buff(erick, '-', goodness);
	}
	else
	{
		int_in = int_input;
		goodness = we_learnt_to_handle_buff(erick, ' ', goodness);
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
	return (i + 1);
}
