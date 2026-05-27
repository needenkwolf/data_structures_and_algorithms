#include <stdio.h>
#include "../../array/array.h"

int main(int argc, char *argv[])
{
	int iArr[5] = {2, 73, 6, 32, 81};
	printArray(iArr, 5, 'd');
	qsortArray(iArr, 5 * sizeof(int), sizeof(int), 'd');
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
	qsortArray(sArr2, 5 * sizeof(char*), sizeof(char*), 's');
	printArray(sArr2, 5, 's');
	return 0;
}
