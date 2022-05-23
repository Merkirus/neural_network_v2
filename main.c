#include "matrix.h"
#include "matrix_math.h"

int main(int argc, char const *argv[])
{
	Matrix* m1 = matrix_create(2,3);
	Matrix* m2 = matrix_create(3,2);
	Matrix* m3 = transpose(m1);

	matrix_print(m1);
	matrix_print(m2);
	matrix_print(m3);

	matrix_free(m1);
	matrix_free(m2);
	matrix_free(m3);

	return 0;
}