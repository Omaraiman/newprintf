#include "main.h"

/**
 * print_pointer - Print the value pointer variable
 * @args: List an arguments
 * @buf: Buffer array to print
 * @flgs:  Calculates flags
 * @wdth: get width
 * @prec: Precision
 * @sz: Size
 * Return: Number of chars
 */
int print_pointer(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(wdth);
	UNUSED(sz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buf[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flgs & FLG_ZERO) && !(flgs & FLG_MINUS))
		padd = '0';
	if (flgs & FLG_PLUS)
		extra_c = '+', length++;
	else if (flgs & FLG_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buf, ind, length,
		wdth, flgs, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa
 * @args: Lista of arguments
 * @buf: Buffer array to print
 * @flgs:  Calculates a flags
 * @wdth: get width
 * @prec: Precision
 * @sz: Size
 * Return: Number printed
 */
int print_non_printable(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flgs);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buf[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buf, i + offset);

		i++;
	}

	buf[i + offset] = '\0';

	return (write(1, buf, i + offset));
}
/**
 * print_reverse - Prints reverse
 * @args: List of arguments
 * @buf: Buffer array to print
 * @flgs:  Calculates flags
 * @wdth: get width
 * @prec: Precision
 * @sz: Size
 * Return: Numbers printed
 */

int print_reverse(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	char *str;
	int i, count = 0;

	UNUSED(buf);
	UNUSED(flgs);
	UNUSED(wdth);
	UNUSED(sz);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @args: List of arguments
 * @buf: Buffer array
 * @flgs:  Calculates flags
 * @wdth: get width
 * @prec: Precision
 * @sz: Size
 * Return: Numbers printed
 */
int print_rot13string(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buf);
	UNUSED(flgs);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
