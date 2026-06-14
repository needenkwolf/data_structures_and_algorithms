#include <stdio.h>
#include <stdlib.h>
#include "hashset.h"
#include "array.h"
#include "general.h"

struct hashset *createHashSet(int size)
{
	struct arr *array = createArray(NULL, size, sizeof(char*), TYPE_STRING);
	struct hashset *set = malloc(sizeof(struct hashset));

	set->array = array;
	setHashMod(set->array->size);
	return set;
}

void deleteHashSet(struct hashset **set)
{
	int size = (*set)->array->size;


	if ((*set)->array->data != NULL) {   
		for (int i = size - 1; i >= 0; i--) {
			free(((char**)((*set)->array->data))[i]);
		}
		free(((char*)((*set)->array->data)));
	}

	free((*set)->array);
	free(*set);

	*set = NULL;
}
