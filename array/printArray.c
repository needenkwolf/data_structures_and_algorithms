#include <stdio.h>
#include "array.h"
#include "../general/general.h"

void printArray(void *array, int n, int sizePerItem, int type, void (*print)(void *))
{
	printf("array: ");
	for (int i = 0; i < n; i++) {
		switch (type) {
			case TYPE_INT:
				printf("%d ", *(int*)array);
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				printf("%f ", *(double*)array);
				break;
			case TYPE_CHAR:
				printf("%c ", *(char*)array);
				break;
			case TYPE_STRING:
				printf("%s ", *(char**)array);
				break;
			case TYPE_CUSTOM:
				print(array + i * sizePerItem);
				break;
			default:
				fprintf(stderr, "error (printArray): unknown type"); 
				break;
		}
	}
	printf("\n");
}
