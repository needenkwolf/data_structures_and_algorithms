#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void insertAtArrayBegin(struct arr *array, void *toInsert)
{
	void (*insertBegin)(struct arr*, void*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = n - 1; i >= 0; i--) {
		switch (type) {
			case TYPE_INT:
				*((int*)(array->data) + i + 1) = *((int*)(array->data) + i);
				if (i == 0) *(int*)(array->data) = *(int*)toInsert;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				*((double*)(array->data) + i + 1) = *((double*)(array->data) + i);
				if (i == 0) *(double*)(array->data) = *(double*)toInsert;
				break;
			case TYPE_CHAR:
				*((char*)(array->data) + i + 1) = *((char*)(array->data) + i);
				if (i == 0) *(char*)(array->data) = *(char*)toInsert;
				break;
			case TYPE_STRING:
				*((char**)(array->data) + i + 1) = *((char**)(array->data) + i);
				if (i == 0) *(char**)(array->data) = *(char**)toInsert;
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				insertBegin(array, toInsert, i);
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
}


void insertAtArrayEnd(struct arr *array, void *toInsert)
{
	void (*insertEnd)(struct arr*, void*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				if (((int*)(array->data))[i] == 0) {
					((int*)(array->data))[i] = ((int*)toInsert)[0];
					return;
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (((double*)(array->data))[i] == 0) {
					((double*)(array->data))[i] = ((double*)toInsert)[0];
					return;
				}
				break;
			case TYPE_CHAR:
				if (((char*)(array->data))[i] == 0) {
					((char*)(array->data))[i] = ((char*)toInsert)[0];
					return;
				}
				break;
			case TYPE_STRING:
				if (strcmp(((char**)(array->data))[i], "") == 0) {
					((char**)(array->data))[i] = ((char**)toInsert)[0];
					return;
				}
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				insertEnd(array, toInsert, i);
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
}

void insertAtArrayPos(struct arr *array, void *toInsert, int pos)
{
	void (*insertPos)(struct arr*, void*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	if (pos < 0) return;
	if (pos == 0 && type == TYPE_CUSTOM) return;
	if (pos == 0 && type != TYPE_CUSTOM) return insertAtArrayBegin(array, toInsert);
	
	for (int i = n - 1; i >= 1; i--) {
		switch (type) {
			case TYPE_INT:
				if (i == pos) {
					((int*)(array->data))[i] = ((int*)toInsert)[0];
				} else if (i > pos) {
					((int*)(array->data))[i] = ((int*)array)[(i - 1)];
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (i == pos) {
					((double*)(array->data))[i] = ((double*)toInsert)[0];
				} else if (i > pos) {
					((double*)(array->data))[i] = ((double*)array)[(i - 1)];
				}
				break;
			case TYPE_CHAR:
				if (i == pos) {
					((char*)(array->data))[i] = ((char*)toInsert)[0];
				} else if (i > pos) {
					((char*)(array->data))[i] = ((char*)array)[(i - 1)];
				}
				break;
			case TYPE_STRING:
				if (i == pos) {
					strcpy(((char**)(array->data))[i], ((char**)toInsert)[0]);
				} else if (i > pos) {
					strcpy(((char**)(array->data))[i], ((char**)array)[(i - 1)]);
				}
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				insertPos(array, toInsert, i);
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
}
