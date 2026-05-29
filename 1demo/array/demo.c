#include <stdio.h>
#include <string.h>
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

void printArrayPerson(void *array, int n)
{
	printArray(array, n, sizeof(struct person), TYPE_CUSTOM, printItemPerson);
}

void *lsearchCheckPerson(void *array, void *searching)
{
	if (strcmp(((struct person*)array)->name, *(char**)searching) == 0) return array;
	else return NULL;
}

int qsortPersonByName(const void *item1, const void *item2)
{
	return strcmp(((struct person*)item1)->name, ((struct person*)item2)->name);
}


int main(int argc, char *argv[])
{
	int iArr[5] = {2, 73, 6, 32, 81};
	printArray(iArr, 5, sizeof(int), TYPE_INT, NULL);
	qsortArray(iArr, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr, 5, sizeof(int), TYPE_INT, NULL);

	int to_search = 6;
	int *foundp = NULL; 
	foundp = (int*)bsearchArray(iArr, &to_search, 5, sizeof(int), TYPE_INT, NULL);
	if (foundp != NULL)
		printf("value %d in index %ld\n", to_search, foundp - iArr);

	char *sArr[5] = {"say", "hello", "to", "the", "world"};

	char *to_search2 = "the";
	char **foundp2 = (char**)lsearchArray(sArr, &to_search2, 5, sizeof(int), TYPE_STRING, NULL);
	if (foundp2 != NULL && (*foundp2) != NULL)
		printf("value \"%s\" in index %ld\n", to_search2, foundp2 - sArr);

	char *sArr2[5] = {"oranges", "apples", "bananas", "melons", "coconuts"};
	printArray(sArr2, 5, sizeof(char*), TYPE_STRING, NULL);
	qsortArray(sArr2, 5, sizeof(char*), TYPE_STRING, NULL);
	printArray(sArr2, 5, sizeof(char*), TYPE_STRING, NULL);

	struct person people[3] = {{"Matt", 21}, {"Andrew", 34}, {"John", 18}};
	printArrayPerson(people, 3);

	char *to_search3 = "Andrew";
	struct person *found3 = (struct person*)lsearchArray(people, &to_search3, 3, sizeof(struct person), TYPE_CUSTOM, lsearchCheckPerson);
	printItemPerson(found3);
	printf("\n");

	qsortArray(people, 3, sizeof(struct person), TYPE_CUSTOM, qsortPersonByName);
	printArrayPerson(people, 3);

	int iArr2[5] = {52, 32, 0, 0, 0};
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);

	int number_two = 2;
	int number_three = 3;
	int number_four = 4;
	int zero = 0;

	insertAtArrayEnd(iArr2, &number_two, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	insertAtArrayBegin(iArr2, &number_three, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	insertAtArrayPos(iArr2, &number_four, 2, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	deleteAtArrayPos(iArr2, 1, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	deleteAtArrayBegin(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	fillArray(iArr2, &zero, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	zero = -1;
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	printf("is iArr2 empty? %s\n", isEmptyArray(iArr2, 5, sizeof(int), TYPE_INT, NULL) ? "yes" : "no");
	insertAtArrayEnd(iArr2, &number_two, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr2, 5, sizeof(int), TYPE_INT, NULL);
	printf("is iArr2 empty? %s\n", isEmptyArray(iArr2, 5, sizeof(int), TYPE_INT, NULL) ? "yes" : "no");
	return 0;
}
