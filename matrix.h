#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef struct
{
	double** entries;
	int rows;
	int cols;
} Matrix;

Matrix* matrix_create(int row, int col);
void matrix_fill(Matrix* m, int n);
void matrix_free(Matrix* m);
void matrix_print(Matrix* m);
Matrix* matrix_copy(Matrix* m);
void martix_save(Matrix* m, char* file_string);
Matrix* matrix_load(char* file_string);
void matrix_randomize(Matrix* m, int n);
int matrix_argmax(Matrix* m);
double matrix_max(Matrix* m);
double matrix_min(Matrix* m);
Matrix* matrix_flatten(Matrix* m, int axis);

#endif