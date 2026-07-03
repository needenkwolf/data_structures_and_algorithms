#include <stdlib.h>
#include "array.h"

struct arr *createArray(void *data, int size, int sizePerItem, int type)
{
	struct arr *array = malloc(sizeof(struct arr));

	if (data == NULL) {
		void *_array = malloc(size * sizePerItem);
		array->data = _array;
	} else {
		array->data = data;
	}
	array->func = NULL;
	array->size = size;
	array->sizePerItem = sizePerItem;
	array->type = type;

	return array;
}

void freeArray(struct arr **array)
{
	free(*array);
	*array = NULL;
}

void freeArrayData(struct arr **array)
{
	free((*array)->data);
	free(*array);
	*array = NULL;
}
