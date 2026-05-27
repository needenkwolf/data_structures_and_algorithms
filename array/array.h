#ifndef ARRAY_H
#define ARRAY_H

#define PRINT_ARRAY(array, n, toprint, ...) \
		printf("array: "); \
		for (int i = 0; i < n; i++) { \
			printf(toprint, __VA_ARGS__); \
		} \
		printf("\n");					


void printArray(void *array, int n, char data_type);

void *lsearchArray(void *array, void *searching, int n, char data_type);
void *bsearchArray(void *array, void *searching, int n, int sizePerItem, char data_type);

void qsortArray(void *array, int size, int sizePerItem, char data_type);

#endif
