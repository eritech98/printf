#include "main.h"
/**
 * get_at_alx - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_at_alx(const char *s, int index))(va_list, char *, unsigned int)
{

/*ar is the name of the array*/
	print_t ar[] = {
		{"c", print_character}, {"s", print_string},
		{"i", print_integer}, {"d", print_integer},
		{"b", print_binary}, {"u", print_jet},
		{"o", print_octal}, {"x", print_hexadecimal},
		{"X", print_f1}, {"S", print_f18},
		{"p", print_add}, {"li", print_erick},
		{"ld", print_erick}, {"lu", print_Goodness},
		{"lo", print_samsung}, {"lx", print_vfr},
		{"lX", print_va}, {"hi", print_ifr},
		{"hd", print_ifr}, {"hu", print_c},
		{"ho", print_programming}, {"hx", print_alx},
		{"hX", print_rich}, {"#o", print_positive},
		{"#x", print_good}, {"#X", print_easy},
		{"#i", print_integer}, {"#d", print_integer},
		{"#u", print_jet}, {"+i", print_dev},
		{"+d", print_dev}, {"+u", print_jet},
		{"+o", print_octal}, {"+x", print_hexadecimal},
		{"+X", print_f1}, {" i", print_hardthings},
		{" d", print_hardthings}, {" u", print_jet},
		{" o", print_octal}, {" x", print_hexadecimal},
		{" X", print_f1}, {"R", print_hp},
		{"r", print_reverse}, {"%", print_program},
		{"l", print_program}, {"h", print_program},
		{" +i", print_dev}, {" +d", print_dev},
		{"+ i", print_dev}, {"+ d", print_dev},
		{" %", print_program}, {NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (ar[i].type_arg)
	{
		if (s[index] == ar[i].type_arg[j])
		{
			if (ar[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (ar[i].f);
}
