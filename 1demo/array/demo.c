#include <stdio.h>
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

int main(int argc, char *argv[])
{
	int iArr[5] = {2, 73, 6, 32, 81};
	qsortArray(iArr, 5, sizeof(int), TYPE_INT, NULL);
	printArray(iArr, 5, sizeof(int), TYPE_INT, NULL);

	int to_search = 6;
	int *foundp = NULL; 
	foundp = (int*)lsearchArray(iArr, &to_search, 5, TYPE_INT, NULL);
	if (foundp != NULL)
		printf("value %d in index %ld\n", to_search, foundp - iArr);

	char *sArr[5] = {"say", "hello", "to", "the", "world"};

	char *to_search2 = "the";
	char **foundp2 = (char**)lsearchArray(sArr, &to_search2, 5, TYPE_STRING, NULL);
	if (foundp2 != NULL && (*foundp2) != NULL)
		printf("value \"%s\" in index %ld\n", to_search2, foundp2 - sArr);

	char *sArr2[5] = {"oranges", "apples", "bananas", "melons", "coconuts"};
	printArray(sArr2, 5, sizeof(char*), TYPE_STRING, NULL);
	qsortArray(sArr2, 5, sizeof(char*), TYPE_STRING, NULL);
	printArray(sArr2, 5, sizeof(char*), TYPE_STRING, NULL);

	struct person people[3] = {{"Matt", 21}, {"Andrew", 34}, {"John", 18}};
	printArrayPerson(people, 3);

	return 0;
}
