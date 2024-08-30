#include "regex.h"
#include <stdio.h>

/**
* regex_match- func
* @str: char *
* @pattern: char const
* Return: int
*/
int regex_match(char const *str, char const *pattern)
{
	int a = 0,i = 0, j = 0, k = 0;

	if (!str || !pattern)
		return (0);
	if (!str[0] && !pattern[0])
		return (1);
	if (!str[0])
		return (0);
	while (pattern[i])
	{
		if (!str[j + k])
			return (1);
		if (!pattern[i + j + a])
			return (0);
		if (pattern[i + j + a] == '.')
			j++;
		else if (pattern[i + j + a] == '*')
		{
			if (pattern[i + j + a + 1] == '\0')
				return (1);
			if (pattern[i + j + a + 1] == '*')
				a++;
			else if (pattern[i + j + a + 1] == str[j + k])
				a++;
			else
				k++;
		}
		else if (pattern[i + j + a] == str[j])
			j++;
		else
		{
			a = 0;
			j = 0;
			k = 0;
			i++;
		}
	}
	return (0);
}


/*
int regex_match(char const *str, char const *pattern)
{
	int i = 0, rv = 0;

	if (str[0] == '\0')
	{
		return (0);
	printf("c\n");
	for (; pattern[i]; i++)
	{
		rv = regex_match_rec(str, pattern + i);
		printf("c%d\n", i);
		if (rv)
			return (1);
	}
	return (rv);
	}
}
*/


/**
* regex_match_rec- func
* @str: char *
* @pattern: char const
* Return: int
*/
/*
int regex_match_rec(char const *str, char const *pattern)
{
	int a1 = 0;

	if (!str[0])
		return (1);
	if (pattern[0] == '.')
		return (1 * regex_match(str + 1, pattern + 1));
	if (pattern[0] == '*')
	{
		if (pattern[1] == '\0')
			return (1);
		if (str[0] == '\0')
			return (0);
		a1 = regex_match(str, pattern + 1);
		return ((!a1) ? (regex_match(str + 1, pattern)) : 1);
	}
	if (pattern[0] == '\0')
		return (0);
	if (str[0] != pattern[0])
		return (0);
	return (regex_match(str + 1, pattern + 1));
}
*/
