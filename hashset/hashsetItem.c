#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashset.h"
#include "../array/array.h"
#include "../general/general.h"

#define STRING_SIZE 80

int addHashSetItem(struct hashset *set, char *item)
{
	int size = set->array->size;
	int sizePerItem = set->array->sizePerItem;

	if (set->array->data == NULL) {
		set->array->data = malloc(size * sizePerItem);
		for (int i = 0; i < size; i++) {
			((char**)(set->array->data))[i] = malloc((STRING_SIZE + 1) * sizeof(char));
		}
		char *tofill = "";
		fillArray(set->array, &tofill);
	}

	int hashcode = hash(item);

	while (hashcode < size) {
		if (strcmp(((char**)(set->array->data))[hashcode], "") == 0) {
			((char**)(set->array->data))[hashcode] = item;
			return 1;
		} else {
			hashcode++;
		}
	}

	return 0;
}

int removeHashSetItem(struct hashset *set, char *item)
{
	return 0;
}

int containsHashSetItem(struct hashset *set, char *item)
{
	if (set->array->data == NULL) return -1;

	int hashcode = hash(item);
	int size = set->array->size;

	while (hashcode < size) {
		if (strcmp(((char**)(set->array->data))[hashcode], item) == 0) {
			return 1;
		} else {
			hashcode++;
		}
	}

	return 0;
}
