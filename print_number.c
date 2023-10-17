#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: character
 * Return: 1 if digit, 0 otherwise
*/
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: length of string
*/
int _strlen(char *s)
{
	int x = 0;

	while (*s++)
		x++;
	return (x);
}

/**
 * print_number - prints a number with options
 * @str: base number as a string
 * @params: the parameter struct
 * Return: characters printed
*/
int print_number(char *str, params_t *params)
{
	unsigned int x = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		x--;
	}
	if (params->precision != UINT_MAX)
		while (x++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints number with options
 * @str: the base number as a string
 * @params: the parameter struct
 * Return: chars printed
*/
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int x = 0, neg, neg2, y = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && y < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		y++;
	if (neg && pad_char == '0')
		x += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		x += _putchar(' ');
	while (y++ < params->width)
		x += _putchar(pad_char);
	if (neg && pad_char == ' ')
		x += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		x += _putchar(' ');
	x += _put(str);
	return (x);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 * Return: characters printed
*/
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int x = 0, neg, neg2, y = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && y < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		x += _putchar('+'), y++;
	else if (params->space_flag && !neg2 && !params->unsign)
		x += _putchar(' '), y++;
	x += _put(str);
	while (y++ < params->width)
		x += _putchar(pad_char);
		return (x);
}
