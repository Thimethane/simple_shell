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

/**
 * _strcmp - compares two strings
 * @s1:string 1
 * @s2:string 2
 * Return:strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - compares two strings up to a given number
 *
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: maximum number of characters to compare
 *
 * Return: an integer less than, equal to, or greater than
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}

/**
 * _strchr - Locate character in string.
 *
 * @s: String to search for character
 * @c: Character to locate.
 *
 * Return: Pointer to the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
