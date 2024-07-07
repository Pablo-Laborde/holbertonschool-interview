#include "holberton.h"


/**
* main- func
* @ac: int
* @av: char **
* Return: int
*/
int main(int ac, char **av)
{
	int ln = 0, lm = 0, i = 0, j = 0, a = 0;
	dt *list = NULL;

	if (ac != 3)
		ex();
	ln = check_num(av[1]);
	lm = check_num(av[2]);
	if (!ln || !lm)
		ex();
	list = create_list(ln + lm);
	if (!list)
		ex();
	for (; i < ln; i++)
		for (j = 0; j < lm; j++)
		{
			a = (av[1][i] - '0') * (av[2][j] - '0');
			add_elem(list, a, lm + ln - i - j);
			rr(list);
		}
	print_list(list);
	free_list(list);
	return (0);
}


/**
* create_list- func
* @pos: int
* Return: dt *
*/
dt *create_list(int pos)
{
	dt *list = NULL;

	if (pos > 0)
	{
		list = malloc(sizeof(dt));
		if (!list)
			ex();
		list->d = 0;
		list->pos = pos;
		list->next = create_list(pos - 1);
		return (list);
	}
	return (NULL);
}


/**
* add_elem- func
* @list: dt *
* @num: int
* @pos: int
* Return: void
*/
void add_elem(dt *list, int num, int pos)
{
	if (num > 0)
	{
		if (list->pos > pos)
			add_elem(list->next, num, pos);
		else
		{
			list->d += (num / 10);
			list->next->d += (num % 10);
		}
	}
}


/**
* rr- func
* @list: dt *
* Return: int
*/
int rr(dt *list)
{
	int a = 0, b = 0;

	if (list)
	{
		a = rr(list->next);
		list->d += a;
		b = list->d;
		list->d %= 10;
		return (b / 10);
	}
	return (0);
}


/**
* free_list- func
* @list: dt *
* Return: void
*/
void free_list(dt *list)
{
	dt *aux = NULL;

	while (list)
	{
		aux = list;
		list = list->next;
		free(aux);
	}
}


/**
* print_list- func
* @list: dt *
* Return: void
*/
void print_list(dt *list)
{
	while (list->d == 0)
		list = list->next;
	while (list)
	{
		_putchar('0' + list->d);
		list = list->next;
	}
	_putchar('\n');
}


/**
* check_num- func
* @num: char **
* Return: int
*/
int check_num(char *num)
{
	int pos = 0;

	for (; num[pos]; pos++)
		if ((num[pos] < 48) || (57 < num[pos]))
			return (0);
	return (pos);
}


/**
* ex- func
* Return: void
*/
void ex(void)
{
	int i = 0;
	char *msg = "Error\n";

	for (; msg[i]; i++)
		_putchar(msg[i]);
	exit(98);
}
