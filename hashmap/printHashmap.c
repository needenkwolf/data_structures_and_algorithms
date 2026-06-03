#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "../array/array.h"
#include "../general/general.h"

void printHashItem(void *item, int count)
{
	struct hmapitem *i = ((struct hmapitem**)item)[count];

	int can_print = 0;

	if (arr_opts & PRINT_NO_FILLERS
	&& i != NULL 
	&& i->value != NULL
	&& i->size != 0
	&& strcmp(i->key, "") != 0) {
		can_print = 1;
	}
	else if (i != NULL 
	&& i->value != NULL
	&& !(arr_opts & PRINT_NO_FILLERS)) {
		can_print = 1;
	}

	if (can_print) {
		printf("(%s, ", i->key); 
		switch (i->type) {
			case TYPE_INT:
				printf("%d", *(int*)i->value);
				break;
			case TYPE_STRING:
				printf("%s", *(char**)i->value);
				break;
		}
		printf(") ");
	}
}

void printHashMap(struct hashmap *map)
{
	int old = arr_opts;

	arr_opts |= PRINT_NO_FILLERS;
	arr_opts &= ~PRINT_ARRAY_LABEL;
	
	map->array->func = printHashItem;

	printf("map: ");
	printArray(map->array);

	arr_opts = old;
}
