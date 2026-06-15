#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#include "general.h"

struct person {
	char *name;
	int age;
};

void printItemPerson(void *item, int i)
{
	printf("(%s, %d) ", (((struct person**)item)[i])->name, 
		   	    (((struct person**)item)[i])->age);
}

void printArrayPerson(struct arr *array)
{
	array->func = printItemPerson;
	printArray(array);
	array->func = NULL;
}

void *lsearchCheckPerson(struct arr *array, void *searching, int i)
{
	if (strcmp((((struct person*)(array->data)) + i)->name, *(char**)searching) == 0) 
		return (struct person*)array->data + i;
	else 
		return NULL;
}

int qsortPersonByName(const void *item1, const void *item2)
{
	return strcmp(((struct person*)item1)->name, ((struct person*)item2)->name);
}


int main(int argc, char *argv[])
{
	int _iArr[5] = {2, 73, 6, 32, 81};
	struct arr *iArr = createArray(_iArr, 5, sizeof(int), TYPE_INT);
	printArray(iArr);

	setItemArray(iArr, 3, &(int){256});

	printArray(iArr);

	printf("iArr n2: %d\n", getItemArrayInt(iArr, 2));

	freeArray(&iArr);

	return 0;
}
