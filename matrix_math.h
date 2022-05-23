#ifndef MATRIX_MATH_H
#define MATRIX_MATH_H

#include "matrix.h"
#include <stdlib.h>

Matrix* multiply(Matrix* m1, Matrix* m2);
Matrix* add(Matrix* m1, Matrix* m2);
Matrix* subtract(Matrix* m1, Matrix* m2);
Matrix* scale(Matrix* m, double n);
Matrix* transpose(Matrix* m);
Matrix* apply(Matrix* m, double(*func)(double));
Matrix* addScalar(Matrix* m, double n);

#endif