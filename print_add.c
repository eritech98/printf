#include "main.h"
#include <stdio.h>
/**
 * print_add - prints the address of an input variable
 * @arguments: input address.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int print_add(va_list arguments, char *erick, unsigned int goodness)
{
	void *add;
	long int int_input;
	int i, count, first_digit, isnegative;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));
	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			goodness = we_learnt_to_handle_buff(erick, nill[i], goodness);
		return (5);
	}
	int_input = (intptr_t)add;
	isnegative = 0;
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = also_this_is_for_binary(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = this_will_hex_array(binary, hexadecimal, 0, 16);
	goodness = we_learnt_to_handle_buff(erick, '0', goodness);

	goodness = we_learnt_to_handle_buff(erick, 'x', goodness);
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
	return (count + 2);
}
