#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "../general/general.h"

void printArray(struct arr *array)
{ 
	void (*print)(void*) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	printf("array: ");
	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				printf("%d ", *((int*)(array->data) + i));
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%f ", *((double*)(array->data) + i));
				break;
			case TYPE_CHAR:
				printf("%c ", *((char*)(array->data) + i));
				break;
			case TYPE_STRING:
				printf("%s ", *((char**)(array->data) + i));
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				print((array->data) + i * sizePerItem);
				break;
			default:
				fprintf(stderr, "error (printArray): invalid type\n"); 
				break;
		}
	}
	printf("\n");
}
