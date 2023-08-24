#include "main.h"
/**
 * print_f18 - prints a string and values of
 * non-printed chars
 * @arguments: input string
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed
 */
int print_f18(va_list arguments, char *erick, unsigned int goodness)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(arguments, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			goodness = we_learnt_to_handle_buff(erick, '\\', goodness);
			goodness = we_learnt_to_handle_buff(erick, 'x', goodness);
			op = str[i];
			binary = also_this_is_for_binary(binary, op, 0, 32);
			hexadecimal = this_will_hex_array(binary, hexadecimal, 1, 8);
			goodness = we_learnt_to_handle_buff(erick, hexadecimal[6], goodness);
			goodness = we_learnt_to_handle_buff(erick, hexadecimal[7], goodness);
			sum += 3;
		}
		else
			goodness = we_learnt_to_handle_buff(erick, str[i], goodness);
	}
	free(binary);
	free(hexadecimal);
	return (i + sum);
}
