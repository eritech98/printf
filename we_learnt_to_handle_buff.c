#include "main.h"

/**
 * we_learnt_to_handle_buff - concatenates the buffer characters
 * @erick: buffer pointer
 * @c: charcter to concatenate
 * @goodness: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int we_learnt_to_handle_buff(char *erick, char c, unsigned int goodness)
{
	if (goodness == 1024)
	{
		print_buffer(erick, goodness);
		goodness = 0;
	}
	erick[goodness] = c;
	goodness++;
	return (goodness);
}
