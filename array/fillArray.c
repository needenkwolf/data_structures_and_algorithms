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
