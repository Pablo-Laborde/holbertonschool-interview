#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H


/* Macros */
	#define SLIDE_LEFT 0
	#define SLIDE_RIGHT 1


/* Libraries */
	#include <stdio.h>


/* Functions */
	int slide_line(int *line, size_t size, int direction);
	void sl(int *line, size_t size);
	void sr(int *line, size_t size);
	void slider(int *line, size_t size, size_t pr, size_t a, size_t add);


#endif
