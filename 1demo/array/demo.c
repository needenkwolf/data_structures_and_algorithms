#include <stdio.h>
#include "../../array/array.h"

struct person {
	char *name;
	int age;
};

void printArrayPerson(void *array, int size)
{
	PRINT_ARRAY(array, size, "(%s, %d) ", 
			((struct person*)array + i)->name, 
			((struct person*)array + i)->age);
}

int main(int argc, char *argv[])
{
	int iArr[5] = {2, 73, 6, 32, 81};
	qsortArray(iArr, 5, sizeof(int), 'd');
	printArray(iArr, 5, 'd');

	int to_search = 6;
	int *foundp = NULL; 
	foundp = (int*)lsearchArray(iArr, &to_search, 5, 'd');
	if (foundp != NULL)
		printf("value %d in index %ld\n", to_search, foundp - iArr);

	char *sArr[5] = {"say", "hello", "to", "the", "world"};
	printArray(sArr, 5, 's');

	char *to_search2 = "the";
	char **foundp2 = (char**)lsearchArray(sArr, &to_search2, 5, 's');
	if (foundp2 != NULL && (*foundp2) != NULL)
		printf("value \"%s\" in index %ld\n", to_search2, foundp2 - sArr);

	char *sArr2[5] = {"oranges", "apples", "bananas", "melons", "coconuts"};
	printArray(sArr2, 5, 's');
	qsortArray(sArr2, 5, sizeof(char*), 's');
	printArray(sArr2, 5, 's');

	struct person people[3] = {{"Matt", 21}, {"Andrew", 34}, {"John", 18}};
	printArrayPerson(people, 3);

	return 0;
}
