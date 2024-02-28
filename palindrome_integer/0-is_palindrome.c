#include "palindrome.h"


/**
* is_palindrome- func
* @n: unsigned long
* Return: int
*/
int is_palindrome(unsigned long n)
{
	int rv = 0, f = 0, l = 0;
	unsigned long aux = n;

	while ((aux > 9) && !rv)
	{
		f = get_first(aux);
		l = get_last(aux);
		del_first(&aux);
		del_last(&aux);
		rv += f;
		rv -= l;
	}
	return (!rv);
}


/**
* get_first- func
* @n: unsigned long
* Return: int
*/
int get_first(unsigned long n)
{
	while (n > 9)
		n /= 10;
	return (n);
}


/**
* get_last- func
* @n: unsigned long
* Return: int
*/
int get_last(unsigned long n)
{
	return (n % 10);
}


/**
* del_first- func
* @n: unsigned long *
* Return: void
*/
void del_first(unsigned long *n)
{
	unsigned long aux = *n, divisor = 1;

	while (aux > 9)
	{
		divisor *= 10;
		aux /= 10;
	}
	*n %= divisor;
}


/**
* del_last- func
* @n: unsigned long *
* Return: void
*/
void del_last(unsigned long *n)
{
	*n /= 10;
}
