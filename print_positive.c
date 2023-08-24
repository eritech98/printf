#include "main.h"
/**
 * print_positive - print the number in octal begining with zero
 * @arguments: input string
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed
 */
int print_positive(va_list arguments, char *erick, unsigned int goodness)
{
	int int_input, i, isnegative, count, first_digit;
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
	goodness = we_learnt_to_handle_buff(erick, '0', goodness);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = also_this_is_for_binary(binary, int_input, isnegative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = this_will_fill_oct_array(binary, octal);
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
	return (count + 1);
}
