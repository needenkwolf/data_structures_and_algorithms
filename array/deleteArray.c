#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void deleteAtArrayBegin(struct arr *array)
{
	void (*deleteBegin)(struct arr*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				((int*)(array->data))[i] = ((int*)(array->data))[i + 1];
				if (i == n - 1) ((int*)(array->data))[i] = 0;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				((double*)(array->data))[i] = ((double*)(array->data))[i + 1];
				if (i == n - 1) ((double*)(array->data))[i] = 0;
				break;
			case TYPE_CHAR:
				((char*)(array->data))[i] = ((char*)(array->data))[i + 1];
				if (i == n - 1) ((char*)(array->data))[i] = 0;
				break;
			case TYPE_STRING:
				strcpy(((char**)(array->data))[i], ((char**)(array->data))[i + 1]);
				if (i == n - 1) strcpy(((char**)(array->data))[i], "");
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				deleteBegin(array, i);
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
}

void deleteAtArrayEnd(struct arr *array)
{
	void (*deleteEnd)(struct arr*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = n - 1; i >= 1; i--) {
		switch (type) {
			case TYPE_INT:
				if (((int*)(array->data))[i] != 0) {
					((int*)(array->data))[i] = 0;
					return;
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (((double*)(array->data))[i] != 0) {
					((double*)(array->data))[i] = 0;
					return;
				}
				break;
			case TYPE_CHAR:
				if (((char*)(array->data))[i] != 0) {
					((char*)(array->data))[i] = 0;
					return;
				}
				break;
			case TYPE_STRING:
				if (strcmp(((char**)(array->data))[i], "") == 0) {
					strcpy(((char**)(array->data))[i], "");
					return;
				}
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				deleteEnd(array, i);
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
}

void deleteAtArrayPos(struct arr *array, int pos)
{
	void (*deletePos)(struct arr*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	for (int i = pos; i < n - 1; i++) {
		switch (type) {
			case TYPE_INT:
				((int*)(array->data))[i] = ((int*)(array->data))[i + 1];
				if (i == n - 2) ((int*)(array->data))[n - 1] = 0;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				((double*)(array->data))[i] = ((double*)(array->data))[i + 1];
				if (i == n - 2) ((double*)(array->data))[n - 1] = 0;
				break;
			case TYPE_CHAR:
				((char*)(array->data))[i] = ((char*)(array->data))[i + 1];
				if (i == n - 2) ((char*)(array->data))[n - 1] = 0;
				break;
			case TYPE_STRING:
				strcpy(((char**)(array->data))[i], ((char**)(array->data))[i + 1]);
				if (i == n - 2) strcpy(((char**)(array->data))[n - 1], "");
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				deletePos(array, i);
				break;
			default:
				fprintf(stderr, "error: invalid type\n");
				break;
		}
	}
}
