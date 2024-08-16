#include "holberton.h"


/**
* wildcmp- func
* @s1: char *
* @s2: char *
* Return: int
*/
int wildcmp(char *s1, char *s2)
{
	int a1 = 0;

	if (s2[0] == '*')
	{
		if (s2[1] == '\0')
			return (1);
		if (s1[0] == '\0')
			return (0);
		a1 = wildcmp(s1, s2 + 1);
		return ((!a1) ? (wildcmp(s1 + 1, s2)): 1);
	}
	if ((s1[0] == '\0') && (s2[0] == '\0'))
		return (1);
	else if ((s1[0] == '\0') || (s2[0] == '\0'))
		return (0);
	if (s1[0] != s2[0])
		return (0);
	return (1 * wildcmp(s1 + 1, s2 + 1));
}
