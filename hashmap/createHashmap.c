#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
#include "array.h"
#include "general.h"

struct hashmap *createHashMap(int size)
{
	struct hmapitem **_array = malloc(sizeof(struct hmapitem*) * size);

	for (int i = 0; i < size; i++) {
		_array[i] = malloc(sizeof(struct hmapitem));
		(_array[i])->value = NULL;
	}

	struct arr *array = createArray(_array, size, sizeof(struct hmapitem*), TYPE_CUSTOM);

	struct hashmap *map = malloc(sizeof(struct hashmap));
	map->array = array;

	return map;
}

void deleteHashMap(struct hashmap **map)
{
	int asize = (*map)->array->size;

	for (int i = 0; i < asize; i++) {
		struct hmapitem *item = ((struct hmapitem**)((*map)->array->data))[i];
		if (item != NULL && item->value != NULL) {
			free(item->value);
		}
		if (item != NULL) {
			free(item);
		}
	}

	free((*map)->array->data);
	free((*map)->array);
	free((*map));

	*map = NULL;
}
