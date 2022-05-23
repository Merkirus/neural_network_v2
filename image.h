#ifndef IMAGE_H
#define IMAGE_H

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	Matrix* data;
	int label;
} Img;

Img** csv_to_imgs(char* file_string, int number_of_imgs);
void img_print(Img* img);

#endif