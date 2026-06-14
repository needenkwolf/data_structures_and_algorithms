#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "general.h"

int arr_opts = PRINT_ARRAY_LABEL;

void printArray(struct arr *array)
{ 
	void (*print)(void*, int) = array->func;
	int n = array->size;
	int sizePerItem = array->sizePerItem;
	int type = array->type;

	if (arr_opts & PRINT_ARRAY_LABEL) printf("array: ");
	for (int i = 0; i < n; i++) {
		int printed = 0;
		switch (type) {
			case TYPE_INT:
				if (arr_opts & PRINT_NO_FILLERS
				&& *(((int*)(array->data)) + i) != 0) {
					printf("%d", *((int*)(array->data) + i));
					printed = 1;
				}
				else if (!(arr_opts & PRINT_NO_FILLERS)) {
					printf("%d", *((int*)(array->data) + i));
					printed = 1;
				}
				break;
			case TYPE_FLOAT:
			case TYPE_DOUBLE:
				if (arr_opts & PRINT_NO_FILLERS
				&& *(((double*)(array->data)) + i) != 0) {
					printf("%f", *((double*)(array->data) + i));
					printed = 1;
				}
				else if (!(arr_opts & PRINT_NO_FILLERS)) {
					printf("%f", *((double*)(array->data) + i));
					printed = 1;
				}
				break;
			case TYPE_CHAR:
				if (arr_opts & PRINT_NO_FILLERS
				&& *(((char*)(array->data)) + i) != 0) {
					printf("%c", *((char*)(array->data) + i));
					printed = 1;
				}
				else if (!(arr_opts & PRINT_NO_FILLERS)) {
					printf("%c", *((char*)(array->data) + i));
					printed = 1;
				}
				break;
			case TYPE_STRING:
				if (arr_opts & PRINT_NO_FILLERS
				&& strcmp(*(((char**)(array->data)) + i), "") != 0) {
					printf("%s", *((char**)(array->data) + i));
					printed = 1;
				}
				else if (!(arr_opts & PRINT_NO_FILLERS)) {
					printf("%s", *((char**)(array->data) + i));
					printed = 1;
				}
				break;
			case TYPE_CUSTOM:
				if (array->func == NULL) {
					fprintf(stderr, "error: invalid function\n");
					exit(1);
				}
				print(array->data, i);
				break;
			default:
				fprintf(stderr, "error (printArray): invalid type\n");
				return;
		}
		if (printed == 1 && (arr_opts & PRINT_INDEX)) printf("[%d]", i);
		if (printed == 1) printf(" ");
	}
	printf("\n");
}
