#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "../general/general.h"

void qsortArray(void *array, int n, int sizePerItem, int type, int (*compare)(const void*, const void*))
{
	switch (type) {
		case TYPE_INT:
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			qsort(array, n, sizePerItem, compareNumeric);
			break;
		case TYPE_STRING:
			qsort(array, n, sizePerItem, compareString);
			break;
		case TYPE_CUSTOM:
			qsort(array, n, sizePerItem, compare);
			break;
		default:
			fprintf(stderr, "error (qsortArray): invalid type"); 
			break;
	}
}
