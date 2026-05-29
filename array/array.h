#ifndef ARRAY_H
#define ARRAY_H

void printArray(void *array, int n, int sizePerItem, int type, void (*print)(void*));

void *lsearchArray(void *array, void *searching, int n, int sizePerItem, int type, void *(*check)(void*, void*));
void *bsearchArray(void *array, void *searching, int n, int sizePerItem, int type, int (*compare)(const void *, const void *));

void qsortArray(void *array, int n, int sizePerItem, int type, int (*compare)(const void*, const void*));

void insertAtArrayBegin(void *array, void *toInsert, int n, int sizePerItem, int type, void (*insertBegin)(void*, void*, int));
void insertAtArrayEnd(void *array, void *toInsert, int n, int sizePerItem, int type, void (*insertEnd)(void*, void*));
void insertAtArrayPos(void *array, void *toInsert, int pos, int n, int sizePerItem, int type, void (*insertPos)(void*, void*));

void deleteAtArrayBegin(void *array, int n, int sizePerItem, int type, void (*deleteBegin)(void*, int, int));
void deleteAtArrayEnd(void *array, int n, int sizePerItem, int type, void (*deleteEnd)(void*, int, int));
void deleteAtArrayPos(void *array, int pos, int n, int sizePerItem, int type, void (*deletePos)(void*, int, int));

#endif
