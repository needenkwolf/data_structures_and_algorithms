#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void *lsearchArray(void *array, void *searching, int n, int type, void *(*search)(void*))
{
	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				if (*((int*)array + i) == *(int*)searching)	 		return (int*)array + i;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (*((double*)array + i) == *(double*)searching) 		return (double*)array + i;
				break;
			case TYPE_CHAR:
				if (*((char*)array + i) == *(char*)searching) 			return (char*)array + i;
				break;
			case TYPE_STRING:
				if (strcmp(*((char**)array + i), *(char**)searching) == 0) 	return (char**)array + i;
				break;
			case TYPE_CUSTOM:
				return search(array);
				break;
			default:
				fprintf(stderr, "error (lsearchArray): unknown type"); 
				break;

		}
	}

	return NULL;
}

void *bsearchArray(void *array, void *searching, int n, int sizePerItem, int type, int (*compare)(const void *, const void *))
{
	void *found_item = NULL;

	switch (type) {
		case TYPE_INT:
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			found_item = bsearch(searching, array, n, sizePerItem, compareNumeric);
			break;
		case TYPE_CHAR:
		case TYPE_STRING:
			found_item = bsearch(searching, array, n, sizePerItem, compareString);
			break;
		case TYPE_CUSTOM:
			found_item = bsearch(searching, array, n, sizePerItem, compare);
			break;
		default:
			fprintf(stderr, "error (bsearchArray): unknown type"); 
			break;
	}

	return found_item;
}
