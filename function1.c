#include "main.h"

/**
 * print_unsgnd - Prints an unsigned number
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed.
 */
int print_unsgnd(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buf, flgs, wdth, prec, sz));
}

/**
 * print_oct - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_oct(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wdth);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flgs & FG_HASH && init_num != 0)
		buf[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buf, flgs, wdth, prec, sz));
}
/**
 * print_hex - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_hex(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	return (print_hexa(args, "0123456789abcdef", buf,
		flgs, 'x', wdth, prec, sz));
}

/**
 * print_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @wdth: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_hex_upper(va_list args, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	return (print_hexa(args, "0123456789ABCDEF", buf,
		flgs, 'X', wdth, prec, sz));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buf: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @flag_ch: Flag character
 * @wdth: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list args, char map_to[], char buf[],
	int flgs, char flag_ch, int wdth, int prec, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wdth);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flgs & FG_HASH && init_num != 0)
	{
		buf[i--] = flag_ch;
		buf[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buf, flgs, wdth, prec, sz));
}
