#include "shell.h"

/**
 * _strlen - returns length of the string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strdup - duplicates string
 * @src: string to be duplicated
 * Return: 0 on Success
 */
char *_strdup(const char *src)
{
	char *dst;
	size_t len;
	size_t i;

	len = 0;
	while (src[len] != '\0')
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dst[i] = src[i];
	return (dst);
}
