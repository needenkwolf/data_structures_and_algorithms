#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "../general/general.h"

void deleteAtArrayBegin(void *array, int n, int sizePerItem, int type, void (*deleteBegin)(void*, int, int))
{
	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				((int*)array)[i] = ((int*)array)[i + 1];
				if (i == n - 1) ((int*)array)[i] = 0;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				((double*)array)[i] = ((double*)array)[i + 1];
				if (i == n - 1) ((double*)array)[i] = 0;
				break;
			case TYPE_CHAR:
				((char*)array)[i] = ((char*)array)[i + 1];
				if (i == n - 1) ((char*)array)[i] = 0;
				break;
			case TYPE_STRING:
				strcpy(((char**)array)[i], ((char**)array)[i + 1]);
				if (i == n - 1) strcpy(((char**)array)[i], "");
				break;
			case TYPE_CUSTOM:
				deleteBegin(array, i, n);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
}

void deleteAtArrayEnd(void *array, int n, int sizePerItem, int type, void (*deleteEnd)(void*, int, int))
{
	for (int i = n - 1; i >= 1; i--) {
		switch (type) {
			case TYPE_INT:
				if (((int*)array)[i] != 0) {
					((int*)array)[i] = 0;
					return;
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (((double*)array)[i] != 0) {
					((double*)array)[i] = 0;
					return;
				}
				break;
			case TYPE_CHAR:
				if (((char*)array)[i] != 0) {
					((char*)array)[i] = 0;
					return;
				}
				break;
			case TYPE_STRING:
				if (strcmp(((char**)array)[i], "") == 0) {
					strcpy(((char**)array)[i], "");
					return;
				}
				break;
			case TYPE_CUSTOM:
				deleteEnd(array, i, n);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
}

void deleteAtArrayPos(void *array, int pos, int n, int sizePerItem, int type, void (*deletePos)(void*, int, int))
{
	for (int i = pos; i < n - 1; i++) {
		switch (type) {
			case TYPE_INT:
				((int*)array)[i] = ((int*)array)[i + 1];
				if (i == n - 2) ((int*)array)[n - 1] = 0;
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				((double*)array)[i] = ((double*)array)[i + 1];
				if (i == n - 2) ((double*)array)[n - 1] = 0;
				break;
			case TYPE_CHAR:
				((char*)array)[i] = ((char*)array)[i + 1];
				if (i == n - 2) ((char*)array)[n - 1] = 0;
				break;
			case TYPE_STRING:
				strcpy(((char**)array)[i], ((char**)array)[i + 1]);
				if (i == n - 2) strcpy(((char**)array)[n - 1], "");
				break;
			case TYPE_CUSTOM:
				deletePos(array, i, n);
				break;
			default:
				fprintf(stderr, "error: invalid type");
				break;
		}
	}
}
