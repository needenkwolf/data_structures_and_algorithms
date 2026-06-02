#include <stdio.h>
#include <stdlib.h>
#include "hashset.h"
#include "../array/array.h"
#include "../general/general.h"

struct hashset *createHashSet(int size)
{
	struct arr *array = createArray(NULL, size, sizeof(char*), TYPE_STRING);
	struct hashset *set = malloc(sizeof(struct hashset));

	set->array = array;
	setHashMod(set->array->size);
	return set;
}
