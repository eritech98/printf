#include "main.h"
/**
 * print_hexadecimal - prints a decimal in hexadecimal
 * @arguments: input string
 * @erick: buffer pointer
 * @igoodness: index for buffer pointer
 * Return: number of chars printed
 */
int print_hexadecimal(va_list arguments, char *erick, unsigned int goodness)
{
	int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = also_this_is_for_binary(binary, int_input, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = this_will_hex_array(binary, hexadecimal, 0, 8);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			goodness = we_learnt_to_handle_buff(erick, hexadecimal[i], goodness);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}
