#include "main.h"

/**
 * jack_bauer - prints every minute of the day
 *
 * Return: Always 0 Success
 */
int jack_bauer(void)
{
	int i;
	int mins;
	int hrs;

	for (i = 0; i < 1440; i++)
	{
		mins = i % 60;
		hrs = i / 60;
		if (hrs < 10)
		{
			_putchar('0');
			_putchar(hrs + '0');
		}
		else
		{
			_putchar((hrs / 10) + '0');
			_putchar((hrs % 10) + '0');
		}
		_putchar(':');
		if (mins < 10)
		{
			_putchar('0');
			_putchar(mins + '0');
		}
		else
		{
			_putchar((mins / 10) + '0');
			_putchar((mins % 10) + '0');
		}
		_putchar('\n');
	}
	return (0);
}
