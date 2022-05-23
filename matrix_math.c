#include "matrix_math.h"

Matrix* multiply(Matrix* m1, Matrix* m2)
{
	if (m1->cols != m2->rows)
		return NULL;

	Matrix* matrix = matrix_create(m1->rows, m2->cols);

	for (int i = 0; i < m1->rows; ++i)
	{
		for (int j = 0; j < m2->cols; ++j)
		{
			double sum = 0;
			for (int k = 0; k < m1->cols; ++k)
			{
				sum += m1->entries[i][k] * m2->entries[k][j];
			}
			matrix->entries[i][j] = sum;
		}
	}
	return matrix;
}

Matrix* add(Matrix* m1, Matrix* m2)
{
	if (m1->rows != m2->rows && m1->cols != m2->cols)
		return NULL;

	Matrix* matrix = matrix_create(m1->rows, m1->cols);

	for (int i = 0; i < m1->rows; ++i)
	{
		for (int j = 0; j < m1->cols; ++j)
		{
			matrix->entries[i][j] = m1->entries[i][j] + m2->entries[i][j];
		}
	}
	return matrix;
}

Matrix* subtract(Matrix* m1, Matrix* m2)
{
	if (m1->rows != m2->rows && m1->cols != m2->cols)
		return NULL;

	Matrix* matrix = matrix_create(m1->rows, m1->cols);

	for (int i = 0; i < m1->rows; ++i)
	{
		for (int j = 0; j < m1->cols; ++j)
		{
			matrix->entries[i][j] = m1->entries[i][j] - m2->entries[i][j];
		}
	}
	return matrix;
}

Matrix* scale(Matrix* m, double n)
{
	Matrix* matrix = matrix_create(m->rows, m->cols);

	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			matrix->entries[i][j] = m->entries[i][j] * n;
		}
	}
	return matrix;
}

Matrix* transpose(Matrix* m)
{
	Matrix* matrix = matrix_create(m->cols, m->rows);

	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			matrix->entries[j][i] = m->entries[i][j];
		}
	}
	return matrix;
}

Matrix* apply(Matrix* m, double(*func)(double))
{
	Matrix* matrix = matrix_copy(m);

	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->cols; ++j)
		{
			matrix->entries[i][j] = (*func)(m->entries[i][j]);
		}
	}
	return matrix;
}

Matrix* addScalar(Matrix* m, double n)
{
	Matrix* matrix = matrix_create(m->rows, m->cols);

	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			matrix->entries[i][j] = m->entries[i][j] + n;
		}
	}
	return matrix;
}
