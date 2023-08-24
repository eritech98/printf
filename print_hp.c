#include "main.h"

/**
 * print_hp - writes the str in ROT13
 * @arguments: input string
 * @erick: buffer pointer
 * @goodness: index for buffer pointer
 * Return: number of chars printed.
 */

int print_hp(va_list arguments, char *erick, unsigned int goodness)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(avyy)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			goodness = we_learnt_to_handle_buff(erick, nill[i], goodness);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				goodness = we_learnt_to_handle_buff(erick, rot[j], goodness);
				break;
			}
		}
		if (k == 0)
			goodness = we_learnt_to_handle_buff(erick, str[i], goodness);
	}
	return (i);
}
