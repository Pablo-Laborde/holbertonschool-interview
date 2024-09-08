#ifndef SUBSTRING_H
#define SUBSTRING_H


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Functions */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

int css(char const *s, char const **words, int nb_words, int *ssarr);
int coss(char const *s, char const *ss);


#endif
