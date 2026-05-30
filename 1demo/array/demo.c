#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../array/array.h"
#include "../../general/general.h"

struct person {
	char *name;
	int age;
};

void printItemPerson(void *item)
{
	printf("(%s, %d) ", ((struct person*)item)->name, 
		   	    ((struct person*)item)->age);
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
	qsortArray(iArr);
	printArray(iArr);

	int to_search = 6;
	int *foundp = NULL; 
	foundp = (int*)bsearchArray(iArr, &to_search);
	if (foundp != NULL)
		printf("value %d in index %ld\n", to_search, foundp - (int*)(iArr->data));

	char *_sArr[5] = {"say", "hello", "to", "the", "world"};
	struct arr *sArr = createArray(_sArr, 5, sizeof(char*), TYPE_STRING);

	char *to_search2 = "the";
	char **foundp2 = (char**)lsearchArray(sArr, &to_search2);
	if (foundp2 != NULL && (*foundp2) != NULL)
		printf("value \"%s\" in index %ld\n", to_search2, foundp2 - (char**)(sArr->data));

	char *_sArr2[5] = {"oranges", "apples", "bananas", "melons", "coconuts"};
	struct arr *sArr2 = createArray(_sArr2, 5, sizeof(char*), TYPE_STRING);
	printArray(sArr2);
	qsortArray(sArr2);
	printArray(sArr2);

	struct person people[3] = {{"Matt", 21}, {"Andrew", 34}, {"John", 18}};
	struct arr *pArr = createArray(people, 3, sizeof(struct person), TYPE_CUSTOM);
	printArrayPerson(pArr);

	char *to_search3 = "Andrew";
	pArr->func = lsearchCheckPerson;
	struct person *found3 = (struct person*)lsearchArray(pArr, &to_search3);
	printItemPerson(found3);
	printf("\n");

	pArr->func = qsortPersonByName;
	qsortArray(pArr);

	printArrayPerson(pArr);

	int *_iArr2 = malloc(sizeof(int) * 5);
	struct arr *iArr2 = createArray(_iArr2, 5, sizeof(int), TYPE_INT);
	_iArr2[0] = 52;
	_iArr2[1] = 32;
	printArray(iArr2);

	int number_two = 2;
	int number_three = 3;
	int number_four = 4;
	int zero = 0;

	insertAtArrayEnd(iArr2, &number_two);
	printArray(iArr2);
	insertAtArrayBegin(iArr2, &number_two);
	printArray(iArr2);
	insertAtArrayPos(iArr2, &number_four, 2);
	printArray(iArr2);
	deleteAtArrayPos(iArr2, 1);
	printArray(iArr2);
	deleteAtArrayBegin(iArr2);
	printArray(iArr2);
	fillArray(iArr2, &zero);
	printArray(iArr2);
	zero = -1;
	printArray(iArr2);
	printf("is iArr2 empty? %s\n", isEmptyArray(iArr2) ? "yes" : "no");
	insertAtArrayEnd(iArr2, &number_two);
	printArray(iArr2);
	printf("is iArr2 empty? %s\n", isEmptyArray(iArr2) ? "yes" : "no");
	resizeArray(iArr2, 20);
	printArray(iArr2);

	return 0;
}
