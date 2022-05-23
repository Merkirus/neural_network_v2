#include "image.h"

#define MAXCHAR 10000

/*No idea how it works xD but useful*/
Img** csv_to_imgs(char* file_string, int number_of_imgs)
{
	FILE *file;
	Img** imgs = malloc(number_of_imgs * sizeof(Img*));
	char row[MAXCHAR];
	file = fopen(file_string, "r");

	fgets(row, MAXCHAR, file);

	int i = 0;
	while (feof(file) != 1 && i < number_of_imgs)
	{
		imgs[i] = malloc(sizeof(Img));

		int j = 0;
		fgets(row, MAXCHAR, file);
		char* token = strtok(row, ",");
		imgs[i]->data = matrix_create(28,28);
		while (token != NULL)
		{
			if (j == 0)
				imgs[i]->label = atoi(token);
			else
				imgs[i]->data->entries[(j-1) / 28][(j-1) % 28] = atoi(token) / 256.0;
			token = strtok(NULL, ",");
			++j;
		}
		++i;
	}
	fclose(file);
	return imgs;
}

void img_print(Img* img)
{
	matrix_print(img->data);
	printf("Img Label: %d", img->label);
}