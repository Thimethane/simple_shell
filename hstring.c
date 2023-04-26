#include "shell.h"

/**
 * _strlen - returns length of the string
 * @s: string
 * Return: length
 */
int _strlen(const char *s)
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
 * _strcmp - compares two strings
 * @s1:string 1
 * @s2:string 2
 * Return:strings
 */
int _strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * *_strcat - concatenates two strings
 * @dest:destination
 * @src:source
 * Return:pointer
 */
char *_strcat(char *dest, char *src)
{
	char *dest_end = dest;

	while (*dest_end != '\0')
	{
		dest_end++;
	}

	while (*src != '\0')
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}

	*dest_end = '\0';
	return (dest);
}
/**
 * _strspn - counts the length of input string segment
 * @s: input string
 * @accept: A delimeter specifie
 *
 * Return - 0 (Success)
 */
size_t _strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = s; *p != '\0'; ++p)
	{
		for (a = accept; *a != '\0'; ++a)
		{
			if (*p == *a)
				break;
			if (*a == '\0')
				return (count);
			++count;
		}
	}
	return (count);
}

/**
 * _strdup - duplicates string
 * @src: string to be duplicated
 *
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
