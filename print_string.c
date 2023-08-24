#include "main.h"

/**
 * print_string - writes the string to stdout
 * @arguments: input string
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: On success 1.
 */
int print_string(va_list arguments, char *erick, unsigned int goodness)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			goodness = we_learnt_to_handle_buff(erick, nill[i], goodness);
		return (6);
	}
	for (i = 0; str[i]; i++)
		goodness = we_learnt_to_handle_buff(erick, str[i], goodness);
	return (i);
}
