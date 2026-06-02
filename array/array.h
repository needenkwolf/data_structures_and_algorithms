#ifndef ARRAY_H
#define ARRAY_H

#define PRINT_NO_FILLERS	1
#define PRINT_INDEX		2
#define PRINT_ARRAY_LABEL	4

struct arr {
	void *data;
	void *func;
	int size;
	int sizePerItem;
	int type;
};

extern int arr_opts;

void printArray(struct arr *array);

void *lsearchArray(struct arr *array, void *searching);
void *bsearchArray(struct arr *array, void *searching);

void qsortArray(struct arr *array);

void insertAtArrayBegin(struct arr *array, void *toInsert);
void insertAtArrayEnd(struct arr *array, void *toInsert);
void insertAtArrayPos(struct arr *array, void *toInsert, int pos);

void deleteAtArrayBegin(struct arr *array);
void deleteAtArrayEnd(struct arr *array);
void deleteAtArrayPos(struct arr *array, int pos);

void fillArray(struct arr *array, void *toFill);
void resizeArray(struct arr *array, int new_size);
int isEmptyArray(struct arr *array);

struct arr *createArray(void *data, int size, int sizePerItem, int type);

#endif
