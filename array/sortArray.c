#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "general.h"

void qsortArray(struct arr *array)
{ 
	int (*compare)(const void*, const void*) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	switch (type) {
		case TYPE_INT:
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			qsort((array->data), n, sizePerItem, compareNumeric);
			break;
		case TYPE_STRING:
			qsort((array->data), n, sizePerItem, compareString);
			break;
		case TYPE_CUSTOM:
			if (array->func == NULL) {
				fprintf(stderr, "error: invalid function\n");
				exit(1);
			}
			qsort((array->data), n, sizePerItem, compare);
			break;
		default:
			fprintf(stderr, "error (qsortArray): invalid type\n"); 
			break;
	}
}
