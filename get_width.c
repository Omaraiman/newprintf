#include "main.h"

/**
 * get_width - a function that calculates the width of the output
 * @frmt: a pointer to the format string
 * @idx: a pointer to the index of the current character in the format string
 * @lst: a list of arguments
 *
 * Return: the width of the output
 */
int get_width(const char *frmt, int *idx, va_list lst)
{
	int curr_idx;
	int wdth = 0;

	for (curr_idx = *idx + 1; frmt[curr_idx] != '\0'; curr_idx++)
	{
		if (is_digit(frmt[curr_idx]))
		{
			wdth *= 10;
			wdth += frmt[curr_idx] - '0';
		}
		else if (frmt[curr_idx] == '*')
		{
			curr_idx++;
			wdth = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*idx = curr_idx - 1;

	return (wdth);
}
