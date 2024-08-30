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
	int i = 0;

	if (!str || !pattern)
		return (0);
	while (pattern[i] && (pattern[i] != str[0]))
		i++;
	return (regex_match_rec(str, pattern + i));
}


/**
* regex_match_rec- func
* @str: char *
* @pattern: char const
* Return: int
*/
int regex_match_rec(char const *str, char const *pattern)
{
	int a1 = 0;

	if (pattern[0] == '.')
		return (1 * regex_match_rec(str + 1, pattern + 1));
	if (pattern[0] == '*')
	{
		if (pattern[1] == '\0')
			return (1);
		a1 = regex_match_rec(str, pattern + 1);
		return ((!a1) ? (regex_match_rec(str + 1, pattern)) : 1);
	}
	if (!str[0] && !pattern[0])
		return (1);
	else if (!str[0] || !pattern[0])
		return (0);
	else if (str[0] != pattern[0])
		return (0);
	return (regex_match_rec(str + 1, pattern + 1));
}


/*
int regex_match(char const *str, char const *pattern)
{
	int a = 0,i = 0, j = 0, k = 0;

	if (!str || !pattern)
		return (0);
	while (pattern[i])
	{
		if (!str[j + k] && !pattern[i + j + a])
			return (1);
		if (!str[0] || !pattern[i + j + a])
			return (0);
		if (pattern[i + j + a] == '.')
			j++;
		else if (pattern[i + j + a] == '*')
		{
			// Missing case "*."
			if (pattern[i + j + a + 1] == '*')
				a++;
			if (pattern[i + j + a + 1] == '\0')
				return (1);
			if (pattern[i + j + a + 1] == str[j + k])
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
*/
