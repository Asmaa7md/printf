#include "main.h"

/**
 * _put  - prints a string with newline
 * @str:  string to print
 *
 * Return: void
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(int c)
{
	static int r;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || r >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, r);
		r = 0;
	}
	if (c != BUF_FLUSH)
		buf[r++] = c;
	return (1);
}
