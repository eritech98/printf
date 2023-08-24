#include "main.h"
/**
 * print_programming - prints long decimal number in octal
 * @arguments: input number
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed.
 */
int print_programming(va_list arguments, char *erick, unsigned int goodness)
{
	short int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;
	if (int_input == 0)
	{
		goodness = we_learnt_to_handle_buff(erick, '0', goodness);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (16 + 1));
	binary = also_this_is_for_binary(binary, int_input, isnegative, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = will_fill_short_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
		goodness = we_learnt_to_handle_buff(erick, octal[i], goodness);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
