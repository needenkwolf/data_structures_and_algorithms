#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void insertAtArrayBegin(void *array, void *toInsert, int n, int sizePerItem, int type, void (*insertBegin)(void*, void*, int))
{
	for (int i = n - 1; i >= 0; i--) {
		switch (type) {
			case TYPE_INT:
				*((int*)array + i + 1) = *((int*)array + i);
				if (i == 0) *(int*)array = *(int*)toInsert;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				*((double*)array + i + 1) = *((double*)array + i);
				if (i == 0) *(double*)array = *(double*)toInsert;
				break;
			case TYPE_CHAR:
				*((char*)array + i + 1) = *((char*)array + i);
				if (i == 0) *(char*)array = *(char*)toInsert;
				break;
			case TYPE_STRING:
				*((char**)array + i + 1) = *((char**)array + i);
				if (i == 0) *(char**)array = *(char**)toInsert;
				break;
			case TYPE_CUSTOM:
				insertBegin(array, toInsert, i);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
}


void insertAtArrayEnd(void *array, void *toInsert, int n, int sizePerItem, int type, void (*insertEnd)(void*, void*))
{
	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				if (((int*)array)[i] == 0) {
					((int*)array)[i] = ((int*)toInsert)[0];
					return;
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (((double*)array)[i] == 0) {
					((double*)array)[i] = ((double*)toInsert)[0];
					return;
				}
				break;
			case TYPE_CHAR:
				if (((char*)array)[i] == 0) {
					((char*)array)[i] = ((char*)toInsert)[0];
					return;
				}
				break;
			case TYPE_STRING:
				if (strcmp(((char**)array)[i], "") == 0) {
					((char**)array)[i] = ((char**)toInsert)[0];
					return;
				}
				break;
			case TYPE_CUSTOM:
				insertEnd(array - (n + 1) * sizePerItem, toInsert);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
}

void insertAtArrayPos(void *array, void *toInsert, int pos, int n, int sizePerItem, int type, void (*insertPos)(void*, void*))
{
	if (pos < 0) return;
	if (pos == 0 && type == TYPE_CUSTOM) return;
	if (pos == 0 && type != TYPE_CUSTOM) return insertAtArrayBegin(array, toInsert, n, sizePerItem, type, NULL);
	
	for (int i = n - 1; i >= 1; i--) {
		switch (type) {
			case TYPE_INT:
				if (i == pos) {
					((int*)array)[i] = ((int*)toInsert)[0];
				} else if (i > pos) {
					((int*)array)[i] = ((int*)array)[(i - 1)];
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (i == pos) {
					((double*)array)[i] = ((double*)toInsert)[0];
				} else if (i > pos) {
					((double*)array)[i] = ((double*)array)[(i - 1)];
				}
				break;
			case TYPE_CHAR:
				if (i == pos) {
					((char*)array)[i] = ((char*)toInsert)[0];
				} else if (i > pos) {
					((char*)array)[i] = ((char*)array)[(i - 1)];
				}
				break;
			case TYPE_STRING:
				if (i == pos) {
					strcpy(((char**)array)[i], ((char**)toInsert)[0]);
				} else if (i > pos) {
					strcpy(((char**)array)[i], ((char**)array)[(i - 1)]);
				}
				break;
			case TYPE_CUSTOM:
				insertPos(array + i * sizePerItem, toInsert);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
}
