#ifndef REGEX_H
#define REGEX_H


#include <stdio.h>
#include <string.h>

/* Functions */
int regex_match(char const *str, char const *pattern);
int regex_match_rec(char const *str, char const *pattern);
int spec_cases(char *str, char *pattern);


#endif
