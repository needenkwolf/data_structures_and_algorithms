#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "general.h"

void *lsearchArray(struct arr *array, void *searching)
{
	void *(*check)(struct arr*, void*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				if (*((int*)(array->data) + i) == *(int*)searching)	 		return (int*)(array->data) + i;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (*((double*)(array->data) + i) == *(double*)searching) 		return (double*)(array->data) + i;
				break;
			case TYPE_CHAR:
				if (*((char*)(array->data) + i) == *(char*)searching) 			return (char*)(array->data) + i;
				break;
			case TYPE_STRING:
				if (strcmp(*((char**)(array->data) + i), *(char**)searching) == 0) 	return (char**)(array->data) + i;
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				void *c = check(array, searching, i);
				if (c != NULL) return c;
				break;
			default:
				fprintf(stderr, "error (lsearchArray): invalid type\n"); 
				break;

		}
	}

	return NULL;
}

void *bsearchArray(struct arr *array, void *searching)
{
	int (*compare)(const void *, const void *) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	void *found_item = NULL;

	switch (type) {
		case TYPE_INT:
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			found_item = bsearch(searching, (array->data), n, sizePerItem, compareNumeric);
			break;
		case TYPE_CHAR:
		case TYPE_STRING:
			found_item = bsearch(searching, (array->data), n, sizePerItem, compareString);
			break;
		case TYPE_CUSTOM:
			if (array->func == NULL) {
				fprintf(stderr, "error: invalid function\n");
				exit(1);
			}
			found_item = bsearch(searching, (array->data), n, sizePerItem, compare);
			break;
		default:
			fprintf(stderr, "error (bsearchArray): invalid type\n"); 
			break;
	}

	return found_item;
}
