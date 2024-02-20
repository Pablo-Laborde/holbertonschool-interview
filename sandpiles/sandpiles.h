#ifndef SANDPILE_H
#define SANDPILE_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int toppling(int grid1[3][3]);
int sum(int grid1[3][3], int grid2[3][3]);
void print_sum_sp(int grid1[3][3], int grid2[3][3]);
void print_sp(int grid1[3][3]);

#endif
