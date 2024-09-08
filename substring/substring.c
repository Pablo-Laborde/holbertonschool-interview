#include "substring.h"


/**
* find_substring- func
* @s: char const
* @words: char const
* @nb_words: char const
* @n: int
* Return: int
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *ssarr = NULL, *rarr = NULL, i = 0 , j = 0, c = 0;

	ssarr = malloc(sizeof(int) * nb_words);
	if (!ssarr)
		exit(errno);
	while (s[i])
	{
		for (j = 0; j < nb_words; j++)
			ssarr[j] = 0;
		if (css(s + i, words, nb_words, ssarr))
		{
			c++;
			rarr = realloc(rarr, c);
			if (!rarr)
				exit(errno);
			rarr[c - 1] = i;
		}
		i++;
	}
	*n = c;
	free(ssarr);
	return (rarr);
}


/**
* css- func
* @s: char const *
* @words: char const **
* @nb_words: int
* @ssarr: int *
* Return: int
*/
int css(char const *s, char const **words, int nb_words, int *ssarr)
{
	int i = 0, j = 0, len = 0, rv = 1;

	while (j < nb_words)
	{
		if ((s[i] == words[j][0]) && !ssarr[j])
		{
			len = coss(s + i, words[j]);
			if (!len)
				return (0);
			i += len;
			ssarr[j] = 1;
			j = 0;
		}
		else
			j++;
	}
	for (j = 0; j < nb_words; j++)
		rv *= ssarr[j];
	return (rv);
}


/**
* coss- func
* @s: char const
* @ss: char const
* Return: int
*/
int coss(char const *s, char const *ss)
{
	int j = 0;

	for (; ss[j]; j++)
		if (ss[j] != s[j])
			return (0);
	return (j);
}
