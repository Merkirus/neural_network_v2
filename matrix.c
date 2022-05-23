#include "matrix.h"

#define MAXCHAR 100

Matrix* matrix_create(int row, int col)
{
	Matrix* matrix = malloc(sizeof(Matrix));
	matrix->rows = row;
	matrix->cols = col;
	matrix->entries = malloc(row * sizeof(double*));
	for (int i = 0; i < row; ++i)
	{
		matrix->entries[i] = malloc(col * sizeof(double));
	}
	return matrix;
}

void matrix_fill(Matrix* m, int n)
{
	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			m->entries[i][j] = n;
		}
	}
}

void matrix_free(Matrix* m)
{
	for (int i = 0; i < m->rows; ++i)
	{
		free(m->entries[i]);
	}
	free(m->entries);
	free(m);
	m = NULL;
}

void matrix_print(Matrix* m)
{
	printf("Rows: %d Columns: %d\n", m->rows, m->cols);
	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			printf("%.2f ", m->entries[i][j]);
		}
		printf("\n");
	}
}

Matrix* matrix_copy(Matrix* m)
{
	Matrix* matrix = matrix_create(m->rows, m->cols);
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->cols; ++j)
		{
			matrix->entries[i][j] = m->entries[i][j];
		}
	}
	return matrix;
}

void martix_save(Matrix* m, char* file_string)
{
	FILE* file = fopen(file_string, "w");
	if (file == NULL)
	{
		fprintf(stderr, "ERROR: could not open the file %s\n", file_string);
		exit(1);
	}
	fprintf(file, "%d\n", m->rows);
	fprintf(file, "%d\n", m->cols);
	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			fprintf(file, "%.6f\n", m->entries[i][j]);
		}
	}
	printf("Successfully saved matrix to %s\n", file_string);
	fclose(file);
}

Matrix* matrix_load(char* file_string)
{
	FILE* file = fopen(file_string, "w");
	if (file == NULL)
	{
		fprintf(stderr, "ERROR: could not open the file %s\n", file_string);
		exit(1);
	}
	char entry[MAXCHAR];
	fgets(entry, MAXCHAR, file);
	int rows = atoi(entry);
	fgets(entry, MAXCHAR, file);
	int cols = atoi(entry);
	Matrix* matrix = matrix_create(rows, cols);
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->cols; ++j)
		{
			matrix->entries[i][j] = strtod(entry, NULL);
		}
	}
	printf("Successfully loaded matrix from %s\n", file_string);
	fclose(file);
	return matrix;
}

double uniform_distribution(double low, double high)
{
	double difference = high - low;
	int scale = 10000;
	int scaled_difference = (int)(difference * scale);
	return low * (1.0 * (rand() % scaled_difference) / scale);
}

void matrix_randomize(Matrix* m, int n)
{
	double min = -1.0 / sqrt(n);
	double max = 1.0 / sqrt(n);
	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			m->entries[i][j] = uniform_distribution(min, max);
		}
	}
}

int matrix_argmax(Matrix* m)
{
	int max = INT_MIN;
	int max_ind = INT_MIN;
	for (int i = 0; i < m->rows; ++i)
	{
		if (m->entries[i][0] > max)
		{
			max = m->entries[i][0];
			max_ind = i;
		}
	}
	return max_ind;
}

double matrix_max(Matrix* m)
{
	double max = INT_MIN;
	for (int i = 0; i < m->rows; ++i)
	{
		if (m->entries[i][0] > max)
			max = m->entries[i][0];
	}
	return max;
}

double matrix_min(Matrix* m)
{
	double min = INT_MAX;
	for (int i = 0; i < m->rows; ++i)
	{
		if (m->entries[i][0] < min)
			min = m->entries[i][0];
	}
	return min;
}

Matrix* matrix_flatten(Matrix* m, int axis)
{
	Matrix* matrix;
	if (axis == 0)
	{
		matrix = matrix_create(m->rows * m->cols, 1);
	}
	else if (axis == 1)
	{
		matrix = matrix_create(1, m->rows * m->cols);	
	}
	else
	{
		printf("Invalid argument - must be 0 or 1\n");
		return NULL;
	}
	for (int i = 0; i < m->rows; ++i)
	{
		for (int j = 0; j < m->cols; ++j)
		{
			if (axis == 0)
				matrix->entries[i * m->cols + j][0] = m->entries[i][j];
			else
				matrix->entries[0][i * m->cols + j] = m->entries[i][j];
		}
	}
	return matrix;
}
