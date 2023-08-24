#include "main.h"

/**
 * print_reverse - writes the str in reverse
 * @arguments: input string
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed.
 */
int print_reverse(va_list arguments, char *erick, unsigned int goodness)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nill[] = "(llun)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
		goodness = we_learnt_to_handle_buff(erick, nill[i], goodness);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		goodness = we_learnt_to_handle_buff(erick, str[j], goodness);
	}
	return (i);
}
