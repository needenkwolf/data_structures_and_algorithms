#include <stdio.h>
#include "hashset.h"
#include "../array/array.h"
#include "../general/general.h"

void printHashSet(struct hashset *set)
{
	int old = arr_opts;

	arr_opts |= PRINT_NO_FILLERS;
	arr_opts &= ~PRINT_ARRAY_LABEL;

	printf("set: ");
	printArray(set->array);

	arr_opts = old;
}
