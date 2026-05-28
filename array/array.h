#ifndef ARRAY_H
#define ARRAY_H

void printArray(void *array, int n, int sizePerItem, int type, void (*print)(void*));

void *lsearchArray(void *array, void *searching, int n, int sizePerItem, int type, void *(*check)(void*, void*));
void *bsearchArray(void *array, void *searching, int n, int sizePerItem, int type, int (*compare)(const void *, const void *));

void qsortArray(void *array, int n, int sizePerItem, int type, int (*compare)(const void*, const void*));

#endif
