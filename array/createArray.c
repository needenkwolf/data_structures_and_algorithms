#include <stdlib.h>
#include "array.h"

struct arr *createArray(void *data, int size, int sizePerItem, int type)
{
	struct arr *array = malloc(sizeof(struct arr));

	array->data = data;
	array->func = NULL;
	array->size = size;
	array->sizePerItem = sizePerItem;
	array->type = type;

	return array;
}
