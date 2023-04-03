#include "main.h"

/**
 * _strstr -  locates a substring.
 *
 * @haystack: a string to seearch for substring
 *
 * @needle: substring
 *
 * Return:  pointer to the beginning of the located substring
 */
char *_strstr(char *haystack, char *needle)
{
	char *p, *q;

	while (*haystack != '\0')
	{
		p = haystack;
		q = needle;
		while (*p == *q && *p != '\0' && *q != '\0')
		{
			p++;
			q++;
		}
		if (*q == '\0')
			return (haystack);
		haystack++;
	}
	return (0);
}
