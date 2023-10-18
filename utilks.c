#include "main.h"

/**
 * is_printable - if a char is able to printed
 * @ch: Char
 *
 * Return: 1 or 0 otherwise
 */
int is_printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - ascci to hexadecimal code to buffer
 * @buf: Array .
 * @idx: Index
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buf[], int idx)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buf[idx++] = '\\';
	buf[idx++] = 'x';

	buf[idx++] = map_to[ascii_code / 16];
	buf[idx] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - if a char is a digit
 * @ch: Char
 *
 * Return: 1 or 0
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to size
 * @num: Number
 * @sz: size
 *
 * Return: num
 */
long int convert_size_number(long int num, int sz)
{
	if (sz == SZ_LONG)
		return (num);
	else if (sz == SZ_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to size
 * @num: Number
 * @sz: size
 * Return: num
 */
long int convert_size_unsgnd(unsigned long int num, int sz)
{
	if (sz == SZ_LONG)
		return (num);
	else if (sz == SZ_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
