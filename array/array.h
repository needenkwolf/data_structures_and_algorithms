#ifndef ARRAY_H
#define ARRAY_H

void printArray(void *array, int size, char data_type);

void *lsearchArray(void *array, void *searching, int size, char data_type);
void *bsearchArray(void *array, void *searching, int size, int sizePerItem, char data_type);

void qsortArray(void *array, int size, int sizePerItem, char data_type);

#endif
