#include "main.h"

/**
 * get_size - Calculates the precision for the formatted output
 * @format: Formatted string in which to print the arguments
 * @i: intger num
 *
 * Return: The calculated precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = SZ_LONG;
	else if (format[curr_i] == 'h')
		size = SZ_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
