#include "main.h"

/**
 * get_precision - Calculates the precision
 * @frmt: Formatted string to print the arguments
 * @idx: List of arguments
 * @lst: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *frmt, int *idx, va_list lst)
{
	int curr_idx = *idx + 1;
	int prec = -1;

	if (frmt[curr_idx] != '.')
		return (prec);

	prec = 0;

	for (curr_idx += 1; frmt[curr_idx] != '\0'; curr_idx++)
	{
		if (is_digit(frmt[curr_idx]))
		{
			prec *= 10;
			prec += frmt[curr_idx] - '0';
		}
		else if (frmt[curr_idx] == '*')
		{
			curr_idx++;
			prec = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*idx = curr_idx - 1;

	return (prec);
}
