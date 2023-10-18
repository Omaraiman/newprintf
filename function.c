#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_character - Prints a character
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_character(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buf, flgs, wdth, prec, sz));
}
/************************* PRINT A STRING *************************/
/**
 * print_str - Prints a string
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_str(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buf);
	UNUSED(flgs);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prec >= 0 && prec < length)
		length = prec;

	if (wdth > length)
	{
		if (flgs & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = wdth - length; i > 0; i--)
				write(1, " ", 1);
			return (wdth);
		}
		else
		{
			for (i = wdth - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wdth);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_percent(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	UNUSED(args);
	UNUSED(buf);
	UNUSED(flgs);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sz);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_integer - Print integer
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_integer(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, sz);

	if (n == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buf, flgs, wdth, prec, sz));
}

/************************* PRINT BINARY *************************/
/**
 * print_bin - Prints an unsigned number
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: get width.
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Numbers of characters printed.
 */
int print_bin(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buf);
	UNUSED(flgs);
	UNUSED(wdth);
	UNUSED(prec);
	UNUSED(sz);

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
