#ifndef HOL_H
#define HOL_H


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
* struct digit_s - list
* @c: char
* @pos: int
*/
struct digit_s
{
	int d;
	int pos;
	struct digit_s *next;
};
typedef struct digit_s dt;


/* Functions */
	dt *create_list(int range);
	void add_elem(dt *list, int num, int pos);
	int rr(dt *list);
	void free_list(dt *list);
	void print_list(dt *list);

	int check_num(char *num);
	void ex(void);


	int _putchar(char c);

#endif
