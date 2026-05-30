#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void fillArray(struct arr *array, void *toFill)
{
	void (*fill)(struct arr*, void*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				((int*)(array->data))[i] = *(int*)toFill;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				((double*)(array->data))[i] = *(double*)toFill;
				break;
			case TYPE_CHAR:
				((char*)(array->data))[i] = *(char*)toFill;
				break;
			case TYPE_STRING:
				strcpy(((char**)(array->data))[i], ((char**)toFill)[0]);
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				fill(array, toFill, i);
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
}

void resizeArray(struct arr *array, int new_size)
{		
	// void *(array->data) must be on the heap

	void *(*resize)(struct arr*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	void *new_array = NULL;
	switch (type) {
		case TYPE_INT:
			new_array = malloc(sizeof(int) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					((int*)new_array)[i] = ((int*)(array->data))[i];
				} else {
					((int*)new_array)[i] = 0;
				}
			}
			break;
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			new_array = malloc(sizeof(double) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					((double*)new_array)[i] = ((double*)(array->data))[i];
				} else {
					((double*)new_array)[i] = 0;
				}
			}
			break;
		case TYPE_CHAR:
			new_array = malloc(sizeof(char) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					((char*)new_array)[i] = ((char*)(array->data))[i];
				} else {
					((char*)new_array)[i] = 0;
				}
			}
			break;
		case TYPE_STRING:
			new_array = malloc(sizeof(char*) * new_size);
			for (int i = 0; i < new_size; i++) {
				if (i < n) {
					strcpy(((char**)new_array)[i], ((char**)(array->data))[i]);
				} else {
					strcpy(((char**)new_array)[i], "");
				}
			}
			break;
		case TYPE_CUSTOM:
			if (array->func == NULL) {
				fprintf(stderr, "error: invalid function\n");
				exit(1);
			}
			resize(array, new_size);
			break;
		default:
			fprintf(stderr, "error: invalid type\n");
			break;
	}

	if (array == NULL) return;

	free(array->data);
	array->data = new_array;
	array->size = new_size;
}

int isEmptyArray(struct arr *array)
{
	int (*isEmpty)(struct arr*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				if (((int*)(array->data))[i] != 0) return 0;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (((double*)(array->data))[i] != 0) return 0;
				break;
			case TYPE_CHAR:
				if (((char*)(array->data))[i] != 0) return 0;
				break;
			case TYPE_STRING:
				if (strcmp(((char**)(array->data))[i], "") == 0) return 0;
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				if (isEmpty(array, i) == 0) return 0;
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
	return 1;
}
