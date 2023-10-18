#include "main.h"

/**
 * get_flags - Calculates flags
 * @frmt: Formatted string
 * @idx: take a parameter.
 * Return: flag:
 */
int get_flags(const char *frmt, int *idx)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_idx;
	int flgs = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FG_MINUS, FG_PLUS, FG_ZERO, FG_HASH, FG_SPACE, 0};


	for (curr_idx = *idx + 1; frmt[curr_idx] != '\0'; curr_idx++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (frmt[curr_idx] == FLAGS_CH[j])
			{
				flgs |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*idx = curr_idx - 1;

	return (flgs);
}
