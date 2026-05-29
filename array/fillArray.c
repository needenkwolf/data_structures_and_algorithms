#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void fillArray(void *array, void *toFill, int n, int sizePerItem, int type, void (*fill)(void*, void*))
{
	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				((int*)array)[i] = *(int*)toFill;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				((double*)array)[i] = *(double*)toFill;
				break;
			case TYPE_CHAR:
				((char*)array)[i] = *(char*)toFill;
				break;
			case TYPE_STRING:
				strcpy(((char**)array)[i], ((char**)toFill)[0]);
				break;
			case TYPE_CUSTOM:
				fill(array + i, toFill);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
}

void resizeArray(void *array, int new_size, int n, int sizePerItem, int type, void *(*resize)(void*, int, int))
{		
	// void *array must be on the heap

	void *new_array = NULL;
	switch (type) {
		case TYPE_INT:
			new_array = malloc(sizeof(int) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					((int*)new_array)[i] = (*((int**)array))[i];
				} else {
					((int*)new_array)[i] = 0;
				}
			}
			free(*(int**)array);
			*(int**)array = (int*)new_array;
			break;
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			new_array = malloc(sizeof(double) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					((double*)new_array)[i] = (*(double**)array)[i];
				} else {
					((double*)new_array)[i] = 0;
				}
			}
			free(*(double**)array);
			*(double**)array = (double*)new_array;
			break;
		case TYPE_CHAR:
			new_array = malloc(sizeof(char) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					((char*)new_array)[i] = (*(char**)array)[i];
				} else {
					((char*)new_array)[i] = 0;
				}
			}
			free(*(char**)array);
			*(char**)array = (char*)new_array;
			break;
		case TYPE_STRING:
			new_array = malloc(sizeof(char*) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					strcpy(((char**)new_array)[i], (*((char***)array))[i]);
				} else {
					strcpy(((char**)new_array)[i], "");
				}
			}
			free(*(char***)array);
			*(char***)array = (char**)new_array;
			break;
		case TYPE_CUSTOM:
			resize(array, n, new_size);
			break;
		default:
			fprintf(stderr, "error: invalid type");
			break;
	}
}

int isEmptyArray(void *array, int n, int sizePerItem, int type, void (*isEmpty)(void*))
{
	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				if (((int*)array)[i] != 0) return 0;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (((double*)array)[i] != 0) return 0;
				break;
			case TYPE_CHAR:
				if (((char*)array)[i] != 0) return 0;
				break;
			case TYPE_STRING:
				if (strcmp(((char**)array)[i], "") == 0) return 0;
				break;
			case TYPE_CUSTOM:
				isEmpty(array + i);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
	return 1;
}
